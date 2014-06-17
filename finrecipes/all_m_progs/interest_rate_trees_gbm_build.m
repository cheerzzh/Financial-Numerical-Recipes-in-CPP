function tree = interest_rate_trees_gbm_build(r0,u,d,n)
     r=[r0];
     tree=[r];
     rtop=r0;
     for i=1:n
        rtop = u * rtop;
        r = [rtop;d*r];
        tree=[ [zeros(1,i);tree] r ];
     endfor
endfunction
