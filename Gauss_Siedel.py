# My Gauss Siedel Program implemented in Python submitted to GeeksforGeeks: (under review)

import numpy as np

# Iteration Limit.
Limit = 10
"""
Co-efficients of matrix considered : (LHS vectors)
[[10., -1., 2., 0.],[-1., 11., -1., 3.],[2., -1., 10., -1.],[0., 3., -1., 8.]]=A
Corresponding constants of equation on other side: (RHS vector)
[6., 25., -11., 15.]=B
-> We will solve for Ax=B, where x=[x1,x2,x3,x4]
"""

# Initialize the matrix we want to perform Gauss Siedel Method on.
A = np.array([[10., -1., 2., 0.],
              [-1., 11., -1., 3.],
              [2., -1., 10., -1.],
              [0., 3., -1., 8.]])
# Initialize the RHS column vector.
b = np.array([6., 25., -11., 15.])

print("System of equations:")
# Displaying in matrix form, x1*(co-efficient) + x2*(co-efficient) +...
for i in range(A.shape[0]):
    row = ["{0:3g}*x{1}".format(A[i, j], j + 1) for j in range(A.shape[1])]
    print("[{0}] = [{1:3g}]".format(" + ".join(row), b[i]))

# Returning array of zeros for RHS vector (b) for initial approximation.
x = np.zeros_like(b)
for it_count in range(1, Limit):
    x_new = np.zeros_like(x)
    # Display solution-vector/approximate values of x1,x2,x3,x4 for each iteration.
    print("Iteration {0}: {1}".format(it_count, x))
    for i in range(A.shape[0]):
        s1 = np.dot(A[i, :i], x_new[:i])
        s2 = np.dot(A[i, i + 1:], x[i + 1:])
        x_new[i] = (b[i] - s1 - s2) / A[i, i]
     
     # Using tolerance limit to reach closer approximation to answer and checking if desired accuracy is obtained. (considering relative tolerance/error limit=1e-8, and checking between arrays x and new x) if desired accuracy is obtained, break.

    if np.allclose(x, x_new, rtol=1e-8):
        break
    x = x_new
    
# Solution to our matrix, vector x=[x1,x2,x3,x4]
print("Solution: {0}".format(x))
error = np.dot(A, x) - b
# Approximation error.
print("Error: {0}".format(error))
