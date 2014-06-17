function s= sharpe(r,rf)
    s=(mean(r)-mean(rf))/std(r-rf);
endfunction

