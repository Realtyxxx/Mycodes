import functools
from collections.abc import Iterable
dictA = {'pro': 'student', 'school': 'hunan university'}
dictA['name'] = 'realtyxxx'
dictA['age'] = 23
# print(dictA)
# print(len(dictA))
# print(type(dictA))
# print(dictA['name'])
dictA.update({'name': 'tyx'})
# print(dictA)
dictA['name'] = 'Michael Jordan'
dictA['school'] = 'NorthCarolina'
dictA['pro'] = 'player'
dictA.update({'age': '50'})
print(dictA)
# print(dictA.keys())
# print(dictA.values())
# print(dictA.items())
#
# for key,value in dictA.items():
#     print('{}=={}'.format(key,value))
# for item in dictA.items():
#     print(item)
# print('-------------------------------------checkpoint---------------------------')
# del dictA['age']
# dictA.pop('pro')
print(dictA)
print(
    '-------------------------------------checkpoint---------------------------'
)
print(sorted(dictA.items(), key=lambda d: d[0]))
print(sorted(dictA.items(), key=lambda d: d[1]))
# print('-------------------------------------checkpoint---------------------------')
# import copy
# dictB=copy.copy(dictA)
# dictC=copy.deepcopy(dictA)
# print(id(dictA))
# print(id(dictB))
# print(id(dictC))
# dictB['name']='peter'
# dictC['name']='kobe'
# print(dictA)
# print(dictB)
# print(dictC)
# def keyFunc(**kwargs):
#     print(kwargs)
#     pass
# dictA={'name':'leo','age':35}
# # keyFunc(dictA)
# keyFunc(name='leo',age=35)
# def complexFunc(*args,**kwargs):
#     print(args,end=" ")
#     print(kwargs)
# complexFunc(1,2,3,4,5,name='good',)
# complexFunc(age=36)
# def person(name,age,*,city,job):    #限制传入关键字参数的名字
#     print(name,age,city,job)
# person('jack',23,city='BeiJing',job='Engineer')
# def person(name,age,*,city='BeiJing',job):    #限制传入关键字参数的名字
#     print(name,age,city,job)
# person('jack',23,job='Engineer')
# def calc(*numbers):
#     sum=0
#     for n in numbers:
#         sum+=n*n
#     print(sum)
#     pass
# calc(1,2)
# nums=[0,1,2,3,4]
# nums1=(0,1,2,3,4)
# calc(*nums)
# calc(*nums1)
print(isinstance('abc', Iterable))
print(isinstance((x for x in range(10)), Iterable))

g = (x * x for x in range(10))
for i in g:
    # print(i)
    pass


def fib(max):
    n, a, b = 0, 1, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1
    return 'done'


def odd():
    print('step 1')
    yield 1
    print('step 2')
    yield 2
    print('step 3')
    yield 3


o = odd()
for i in range(3):
    print(next(o))  # 可以被next()函数调用并不断返回下一个之的对象：迭代器
print('-----------------------------------')
for n in fib(6):
    print(n)
print('-----------------------------------')
print('------------------闭包以及返回函数：')


def count(n):
    def f(j):
        def g():
            return j * j

        return g()

    fs = []
    for i in range(n):
        fs.append(f(i))
    return fs


print(count(5))
print('--------------匿名函数-------------')


def sum(x, y): return x + y


print(sum(15, 60))
print('-------------偏函数----------------')
max2 = functools.partial(max, 10)
ans = max2(6, 7, 8, 9)
print(ans)
