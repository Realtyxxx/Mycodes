import numpy as np
a=np.random.randn(5)    #a.shape=(5,)这不是 列向量，这是一个秩为1的矩阵，即rank 1 array
print(a.shape)
print(a.T)
print(np.dot(a,a.T))
a=np.random.randn(5,1)      #a.shape=(5,1) 5x1矩阵 solumn vector 列向量 ；又如a=np.random.randn(5,1) 1x5矩阵 row vector 行向量
print(a.shape)
print(a)
print(a.T)
print(np.dot(a,a.T))

assert(a.shape==(5,1))
print('-'*30)
a=a.reshape(1,5)
assert(a.shape==(5,1))

#这趟课程主要是为了避免bug，避免使用秩为1的数组矩阵，而是用1xn或者nx1的局长你来表示单位向量，另外可以使用assert来检查自己矩阵和数组的维度