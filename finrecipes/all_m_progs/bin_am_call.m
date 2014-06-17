function c =  bin_am_call( S, K, r, sigma,t,steps)
    R = exp(r*(t/steps));
    Rinv = 1.0/R;    
    u = exp(sigma*sqrt(t/steps)); 
    d = 1.0/u;
    p_up = (R-d)/(u-d);
    p_down = 1.0-p_up;
    prices = zeros(steps+1);

    prices(1) = S*(d^steps);
    uu = u*u;
    for i=2:steps
       prices(i) = uu*prices(i-1);
    end

   call_values = max(0.0, (prices-K));
   for step=steps:-1:1
      for i=1:step+1
   	 call_values(i) = (p_up*call_values(i+1)+p_down*call_values(i))*Rinv;
	 prices(i) = d*prices(i+1);
	 call_values(i) = max(call_values(i),prices(i)-K);
      end
   end
   c= call_values(1);
end

