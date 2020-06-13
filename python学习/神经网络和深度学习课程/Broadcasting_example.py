import numpy as np
A = np.array([[56.0, 0.0, 4.4, 68.0],
             [1.2, 104.0, 52.0, 8.0],
             [1.8, 135.0, 99.0, 0.9]])
print(A)

cal=A.sum(axis=0)       #轴表示我希望Python在竖直方向求和-sum vertically,  水平轴 axis=1。
print(cal)
percentage=100*A/cal.reshape(1,4)      #实际上这里cal已经是一个1x4的矩阵了，后面部分都可以省略即.reshape(1,4)但当我们不完全确定是什么矩阵时候，可以用该命令进行编译，reshape O(1)。
print(percentage)