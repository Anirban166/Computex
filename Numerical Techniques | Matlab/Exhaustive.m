a = input('What is the lower limit? ');
b = input('What is the upper limit? ');
n = input('What is the number of intermediate points? ');
delta_x = (b-a)/n; % Increment in x
c = max(a,b) 
x1 = a;
x2 = x1 + delta_x; 
x3 = x2 + delta_x; 

str = input('Give an equation in x: ','s'); % the user types in, for instance 2*x^2-3*x+4
f = inline(str,'x') ;

while (x3 <= b)
    y1 = feval(f,x1); 
    y2 = feval(f,x2);
    y3 = feval(f,x3); 
    if y1>y2 && y2<y3 
        fprintf('The solution lies betwee %f & %f \n The solution is (approximately)%f: \n',x1,x3,x2);
        break
    else
        x1 = x2;
        x2 = x3;
        x3 = x2 + delta_x;
    end
    fplot (f,[a b], 'b')% Plotting the function
    grid on
    hold on
    plot(x2,y2,'*') % Plotting the minimum pooint
    hold off
end
