from numpy import *
from line_search import find_step_length

def quasi_newton(f, fd, x, max_iterations, precision, callback):
  I = identity(x.size)
  H = I
  x_prev = x
  f_prev = f
  fd_prev = fd
  
  for i in range(1, max_iterations):
    gradient = fd(x)
    direction = -H * matrix(gradient).T
    direction = squeeze(asarray(direction))
    
    alpha = find_step_length(f, fd, x, 1.0, direction, c2=0.9)
    x_prev = x
    x = x + alpha*direction
    
    callback(i, direction, alpha, x)
    
    if linalg.norm(x - x_prev) < precision:
      break
    
    s = matrix(x - x_prev).T
    y = matrix(fd(x) - fd(x_prev)).T
    rho = float(1 / (y.T*s))
    H = (I - rho*s*y.T)*H*(I - rho*y*s.T) + rho*s*s.T
  return x
