% Question: Given set of values of x and y (5,12),(6,13),(9,14),(11,16)
% Find the value of x corresponding to y=15 using lagrange interpolation

clc;
  clear all;
  close all;
  y=[12 13 14 16]; %Change here for different function
  x=[5 6 9 11];
  a=15;

%Applying Lagrange's Interpolation:
  ans1=((a-y(2))*(a-y(3))*(a-y(4)))*x(1)/((y(1)-y(2))*(y(1)-y(3))*(y(1)-y(4)));
  ans2=((a-y(1))*(a-y(3))*(a-y(4)))*x(2)/((y(2)-y(1))*(y(2)-y(3))*(y(2)-y(4)));
  ans3=((a-y(1))*(a-y(2))*(a-y(4)))*x(3)/((y(3)-y(1))*(y(3)-y(2))*(y(3)-y(4)));
  ans4=((a-y(1))*(a-y(2))*(a-y(3)))*x(4)/((y(4)-y(1))*(y(4)-y(2))*(y(4)-y(3)));

 m=ans1+ans2+ans3+ans4;

y
x
fprintf('The value of x corresponding to y=15 is %f.',m);
