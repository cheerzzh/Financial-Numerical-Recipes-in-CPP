function p = black_scholes_put(S,K,r,sigma,time) 
    time_sqrt = sqrt(time);
    d1 = (log(S/K)+r*time)/(sigma*time_sqrt) + 0.5*sigma*time_sqrt;
    d2 = d1-(sigma*time_sqrt);
    p = K * exp(-r*time) * normal_cdf(-d2) - S * normal_cdf(-d1);
endfunction


