% Done By : Anirban Chetia
function[it_used,root]=Bisection_AC(f,a,b,maxiter,tol)
pr=a;
for k=1:maxiter
    f1=f(a);
    f2=f(b);
    m=(a+b)/2;
    fm=f(m);
    nr=m;
    if abs((nr-pr)/nr)<tol
        break;
    else if f1*fm<0
            b=m;
        elseif f2*fm<0
            a=m;
        end;
    end;
    pr=nr;
    it_used=k;
end;
root=nr;
