function P = findiff_imp_am_put(S,K,r,sigma,time,no_S_steps,no_t_steps)
     sigma_sqr = sigma^2;
     M=no_S_steps + rem(no_S_steps,2); # need no_S_steps to be even:
     delta_S = 2.0*S/double(M);
     S_values = delta_S* (1:M+1)';
     N=no_t_steps;
     delta_t = time/N;
     A = zeros(M+1,M+1);
     A(1,1)=1.0;
     for j=2:M
	A(j,j-1) = 0.5*j*delta_t*(r-sigma_sqr*j);   
	A(j,j)   = 1.0 + delta_t*(r+sigma_sqr*j*j); 
	A(j,j+1) = 0.5*j*delta_t*(-r-sigma_sqr*j);  
    endfor
    A(M+1,M+1)=1.0;
    B = max(0,K-S_values);
    F = inv(A)*B;
    for  t=N-1:-1:1
	B = F;
	F = inv(A)*B;
        F=max(F,K-S_values);
    endfor
   P= F(M/2);
endfunction
