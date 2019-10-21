function[Area]=S38rule(f,a,b,n)
if mod(n,3)==1
 n=n+2;
end
if mod(n,3)==2
 n=n+1;
end
h=(b-a)/2;
x=a+[O:n]*h;
fval=f(x);
fval(find(fval==inf))=realmax;
fval(find(fval==-inf))=-realmax;
area=3*h/8*(fval(1)+fval(n+1)+3*sum(fval(2:n))-sum(fval(4:3:n-2)));
