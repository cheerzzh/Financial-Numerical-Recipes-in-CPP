function t = treynor(r, rm, rf)
     beta = cov(r,rm)/var(rm);
     t = (mean(r-rf))/beta;
endfunction
