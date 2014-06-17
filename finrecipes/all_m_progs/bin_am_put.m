function p =  bin_am_put( S, K, r, sigma, t, steps)
    R = exp(r*(t/steps));
    Rinv = 1.0/R; 
    u = exp(sigma*sqrt(t/steps)); 
    d = 1.0/u;
    p_up = (R-d)/(u-d);
    p_down = 1.0-p_up;

    prices = zeros(steps+1,1);
    prices(1) = S*(d^steps);
    uu = u*u;
    for i=2:steps+1
      prices(i) = uu*prices(i-1);
    end
    values = max(0.0, (K-prices));
    for step=steps:-1:1
       values = Rinv * ( p_up*values(2:step+1) + p_down*values(1:step) );
       prices = u*prices(1:step);
       values = max(values,K-prices);
   end
   p=values(1);
end

