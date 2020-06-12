#重点：Whenever possible,avoid explicit for-loops
import numpy as np

a=np.array([1,2,3,4])
print(a)


import time

a=np.random.rand(1000000)
b=np.random.rand(1000000)

tic=time.time()
c=np.dot(a,b)
toc=time.time()
print(c) 
print("Vectorized version:"+str(1000*(toc-tic))+"ms")

print('-'*50)

c=0
tic=time.time()
for i in range(1000000):
    c+=a[i]*b[i]
toc=time.time()
print(c)
print("For loop:"+str(1000*(toc-tic))+"ms")


#向量化加速代码（这里是矩阵运算）
# 使用类似内置函数类似 np.functions或者其他能让你显示去除for循环的函数，这样python的numpy能够充分利用并行化去更快的计算；
# 在GPU和CPU上都是可行的，GPU更擅长SIMD计算CPU也不会很差但是没有GPU擅长，SIMD：single instruction multiple data		单指令流多数据流