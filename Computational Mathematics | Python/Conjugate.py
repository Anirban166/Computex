from numpy import *
from line_search import find_step_length

def conjugate_gradient(f, fd, x, max_iterations, precision, callback):
  direction = -fd(x)
  gradient = None
  gradient_next = matrix(fd(x)).T
  x_prev = None
  
  for i in range(1, max_iterations):
    alpha = find_step_length(f, fd, x, 1.0, direction, c2=0.1)
    x_prev = x
    x = x + alpha*direction
    
    callback(i, direction, alpha, x)
    
    gradient = gradient_next
    gradient_next = matrix(fd(x)).T
    
    if linalg.norm(x - x_prev) < precision:
      break
    
    BFR = (gradient_next.T * gradient_next) / (gradient.T * gradient)
    BFR = squeeze(asarray(BFR))
    
    direction = -squeeze(asarray(gradient_next)) + BFR*direction
  return x
