function delta = black_scholes_delta_put(S,K,r,sigma,time) 
    time_sqrt = sqrt(time);
    d1 = (log(S/K)+r*time)/(sigma*time_sqrt) + 0.5*sigma*time_sqrt;
    delta = normal_cdf(d1)-1;
endfunction


