from IPython import get_ipython;   
get_ipython().magic('reset -sf')

a = 1 # The lower limit
b = 5 # The upper limit
n = 10000 # The number of intermediate points in the range

x1 = a
dx = (b-a)/n # The increment in x
x2 = x1 + dx
x3 = x2 + dx

def equation(x):
    return x**2 + 54/x # Change the equation as per your need

while (x3 <= b):
    y1 = equation(x1)
    y2 = equation(x2)
    y3 = equation(x3)
    if y1>=y2 and y2<=y3:
         print ('The minimum point lies between ',x1,' & ',x3)
         break
    else:
        x1 = x2
        x2 = x3
        x3 = x2 + dx
        
import numpy as np
x = np.arange(a,b,1e-6)
y = equation(x)
import matplotlib.pyplot as plt
plt.figure()
plt.plot (x,y,'g--',label = '$the function$')
plt.plot(x1,y1,'r*',label = '$lower point$')
plt.plot(x3,y3,'bo',label = '$higher point$')
plt.xlabel('x')
plt.ylabel('f(x)')
plt.legend()
plt.savefig('exhaustive search method')
