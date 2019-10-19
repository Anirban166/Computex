% Roll No. : 170103007

a = input('Enter lower limit');
b = input('Enter upper limit');
epsilon = input('Please enter a small number: '); %A very small number to check whether the loop would be executed or not
c = max(a,b);
L = b-a; 
str = input('Give an equation in x: ','s'); % the user types in, for instance 2*x^2-3*x+4
f = inline(str,'x');
while (abs (L) > epsilon)
    xm = (a+b)/2;
    ym = feval(f,xm);
    x1 = a+(L/4);
    x2 = b-(L/4);
    y1 = feval(f,x1);
    y2 = feval(f,x2);
    if y1<ym
        b = xm;
        xm = x1;
        break
    elseif y2<ym
        a = xm;
        xm = x2;
        break
    else
        a = x1;
        b = x2;
    end
    L = b-a;
end
fprintf('The solution lies between %f & %f \n',a,b);
fplot (f,[a b], 'r')
grid on
