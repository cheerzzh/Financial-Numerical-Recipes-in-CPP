function alpha = jensen(r, rm, rf)
   beta = cov(r,rm)/var(rm);
   alpha = mean(r) - (rf+beta*(mean(rm)-rf));
endfunction

