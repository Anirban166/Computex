sc = inputdlg('Type an expression that is a function of x ' );    
s = sc{:};                                                        
f = str2func(['@(x) ' s]);
a = input ('Enter lower boundary point: ');
b = input ('Enter upper boundary point: ');
sn = input ('Enter a very small number: ');
k = 2;
a_new = a;
b_new = b;
Lw = b - a;
aw = (a_new - a)/(b  - a);
bw = (b_new - a)/(b  - a);
Lw = bw - aw;
w1 = aw + .618 * Lw;
w2 = bw - .618 * Lw;
y1 = feval(f,(w1));
y2 = feval(f,(w2));
while Lw > sn
    aw = (a_new - a)/(b  - a);
    bw = (b_new - a)/(b  - a);
    Lw = bw - aw;
    w1 = aw + .618 * Lw;
    w2 = bw - .618 * Lw;
    if mod (Lw,2) == 0
        y1 = feval(f,(w1));
    else
        y2 = feval(f,(w2));
    end
    if y1 > y2
        a_new = w1;
    else
        b_new = w2;
    end
    c = 0.5*(a+b);
    k = k + 1;
end
fprintf ('The minimum value is: %f \n',c);
