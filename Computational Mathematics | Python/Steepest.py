from numpy import *
from line_search import find_step_length

def steepest_descent(f, fd, x, max_iterations, precision, callback):
  for i in range(0, max_iterations):
    direction = - fd(x)
    alpha = find_step_length(f, fd, x, 1.0, direction, c2=0.9)
    x = x + alpha*direction
    callback(i, direction, alpha, x)
    if linalg.norm(direction) < precision:
      break
  return x
