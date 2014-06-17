function w = min_variance_portfolio(e,V,r)
   n = length(e);
   a = ones(1,n)*inv(V)*e;
   b = e'*inv(V)*e;
   c = ones(1,n)*inv(V)*ones(n,1);
   A = [b a;a c];
   d = det(A);
   g = 1/d*(b*ones(1,n) - a*e')*inv(V);
   h = h = 1/d*(c*e' - a*ones(1,n))*inv(V);
   w=g+h*r;
end
