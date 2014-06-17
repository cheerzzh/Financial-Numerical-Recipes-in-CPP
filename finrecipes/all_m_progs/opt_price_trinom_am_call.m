function C = opt_price_trinom_am_call(S, K, r, q, sigma, t, steps)
     delta_t = t/steps;
     sigma_sqr=sigma^2;
     Rinv = exp(-r*delta_t);
     u = exp(sigma*sqrt(3.0*delta_t));
     d = 1.0/u;
     p_u = 1/6 + sqrt(delta_t/(12*sigma_sqr)) * (r-q-0.5*sigma_sqr);
     p_m = 2/3;
     p_d = 1/6 - sqrt(delta_t/(12*sigma_sqr)) * (r-q-0.5*sigma_sqr);

     Svec  = [ S ];
     Stree = [ Svec ];
     Su = S;
     Sd = S;
     for step=1:steps+1
        Su = Su*u;
        Sd = Sd*d;
        Svec = [ Sd; Svec; Su ];
        Stree=[ [Stree; zeros(2,step)] Svec ];
     end
     values_next = max(0,Svec-K);
     for step = steps:-1:0
        m = 2*step+1;
        values = Rinv*(p_u*values_next(3:m+2)+p_m*values_next(2:m+1)+p_d*values_next(1:m));
        values = max(values, Stree(1:m,step+1)-K);
        values_next = values;
      end
   end
   C = values;
end

