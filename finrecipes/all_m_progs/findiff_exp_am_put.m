function P = findiff_exp_am_put(S,K,r,sigma,time,no_S_steps,no_t_steps)
     sigma_sqr = sigma^2;
     M=no_S_steps + rem(no_S_steps,2); # need no_S_steps to be even:
     delta_S = 2*S/M;
     S_values = delta_S * (0:M)';
     N=no_t_steps;
     delta_t = time/N;

     r1=1/(1+r*delta_t);
     r2=delta_t/(1+r*delta_t);
    
     a=zeros(M-1,1);
     b=zeros(M-1,1);
     c=zeros(M-1,1);
     for j=1:M-1
	a(j) = r2*0.5*j*(-r+sigma_sqr*j);
	b(j) = r1*(1.0-sigma_sqr*j*j*delta_t);
	c(j) = r2*0.5*j*(r+sigma_sqr*j);
    endfor
    f_next = max(0,K-S_values);
    for  t=N-1:-1:0
        f = [ K; a.*f_next(1:M-1)+b.*f_next(2:M)+c.*f_next(3:M+1); 0];
        f = max(f,K-S_values);
        f_next=f;
     endfor
     P=f(1+M/2);
endfunction
