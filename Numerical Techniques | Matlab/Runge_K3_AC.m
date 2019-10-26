% Done By : Anirban Chetia
function[dwdt]=odefile_AC(t,w)
f1=w(2);
f2=w(3);
f3=(-7*e^(-6*t))*w(3)-(e^(-t^2))*w(2)+(6/(t^2))*w(1);
dwdt=[f1;f2;f3];

% plot commands in command window below :
ic=[-2,1];
range=[0 10];
[t,w]=ode45(@odefile_AC,range,ic);
plot(t,w(:,1),'-r');
hold on
plot(t,w(:,2),'-b');
plot(t,w(:,3),'-gr');

% 3rd order Runge for u'''-(7e^(-6t))u''-(e^(-t^2))u'+(6/(t^2))u=0.
 
