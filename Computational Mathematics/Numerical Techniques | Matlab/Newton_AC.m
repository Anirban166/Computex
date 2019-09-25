% Done By : Anirban Chetia
function[it_used,root]=Newton_AC(f,der,x0,maxiter,tol)
pv=x0;
for k=1:maxiter
    fv=f(x0);
    fder=der(x0);
    nv=pv-fv/fder;
    if abs((pv-nv)/nv)<tol
        break;
    else
        x0=nv;
    end;
    pv=nv;
    it_used=k;
end
root=nv;
