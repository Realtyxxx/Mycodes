import numpy as np

a=np.array([1,2,3,4])
print(a)


import time

a=np.random.rand(1000000)
b=np.random.rand(1000000)

tic=time.time()
c=np.dot(a,b)
toc=time.time()

print("Vectorized version:"+str(1000*(toc-tic)))
