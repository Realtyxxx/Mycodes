import numpy as np
a=np.random.randn(5)    #a.shape=(5,)这不是 列向量，这是一个秩为1的矩阵，即rank 1 array
print(a.shape)
print(a.T)
print(np.dot(a,a.T))
a=np.random.randn(5,1)
print(a)
print(a.T)
print(np.dot(a,a.T))