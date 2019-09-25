% Done By : Anirban Chetia
function[dwdt]=odefile_AC(t,w)
f1=w(2);
f2=7*t^2*w(2)-6*sqrt(t^2+1)*w(1)+t^2-2*t+3;
dwdt=[f1;f2];

% plot commands in command window :
ic=[-2,1];
range=[0 10];
[t,w]=ode45(@odefile_AC,range,ic);
plot(t,w(:,1),'-r');
hold on
plot(t,w(:,2),'-b');
axis([0 1 -3 6])
% or
axis([0 1 -1 3])

% 3rd order Runge for u'''-(7e^(-6t))u''-(e^(-t^2))u'+(6/(t^2))u=0.
