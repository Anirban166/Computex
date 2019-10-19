import numpy

def find_step_length(f, fd, x, alpha, direction, c2):
  g = lambda alpha: f(x+alpha*direction)
  gd = lambda alpha: numpy.dot(fd(x + alpha*direction), direction)
  return interpolation(g, gd, alpha, c2)

def wolf1(f, fd, alpha):
  c1 = 1e-4
  return f(alpha) <= f(0) + c1*alpha*fd(alpha)

def wolf_strong(f, fd, alpha, c2):
  return abs(fd(alpha)) <= -c2*fd(0)

def simple_backtracking(f, fd, alpha, c2):
  rate = 0.5
  while not (wolf1(f, fd, alpha) or wolf_strong(f, fd, alpha, c2)):
    alpha = rate*alpha
  return alpha

def interpolation(f, fd, alpha, c2):
  lo = 0.0
  hi = 1.0
    
  for i in range(0, 20):
    if wolf1(f, fd, alpha):
      if wolf_strong(f, fd, alpha, c2):
        return alpha
    
    half = (lo+hi)/2.0
    alpha = - (fd(lo)*hi*hi) / (2*(f(hi)-f(lo)-fd(lo)*hi))
    
    if alpha < lo or alpha > hi: # quadratic interpolation failed. reduce by half instead
      alpha = half
    if fd(alpha) > 0:
      hi = alpha
    elif fd(alpha) <= 0:
      lo = alpha
  return alpha
