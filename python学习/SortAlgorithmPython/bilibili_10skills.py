print('----------------分隔符-------------------------------')
a=23
b=24
a,b=b,a
print('----------------分隔符-------------------------------')
print(a,b)
name ='Rose'
country='China'
age=28
print(f"Hi I'm {name}.I 'm from {country}. And I'm {age+1}.")
print("Hi I'm {0}.Yes,I 'm {0}. And I'm {1}.".format(name,age))

print('----------------分隔符-------------------------------')
# def fibonacci(n):
#     a=0
#     b=1
#     nums=[]
#     for _ in range(n):
#         nums.append(a)
#         a,b=b,a+b
#     return nums
# for i in fibonacci(10):
#     print(i)
print('----------------分隔符-------------------------------')
def fibonacci(n):
    a=0
    b=1
    for _ in range(n):
        yield a #每当计算出一个数立马将他送出去
        a,b=b,a+b
for i in fibonacci(10):
    print(i)
print('----------------分隔符-------------------------------')
fruit=["apple","pear","pineapple","orange","banana"]
for i in range(len(fruit)):
    fruit[i]=fruit[i].upper()
print(fruit)
print('----------------分隔符-------------------------------')
fruit1=["apple","pear","pineapple","orange","banana"]
fruit1=[x.upper() for x in fruit1]
print(fruit1)
print('----------------分隔符-------------------------------')
fruit2=["apple","pear","pineapple","orange","banana"]
filtered_fruit=[]
for f in fruit2:
    if f.startswith("a"):
        filtered_fruit.append(f)
print(filtered_fruit)
print('----------------分隔符-------------------------------')
filtered_fruit1=[x for x in fruit2 if x.startswith("b")]
print(filtered_fruit1)
print('----------------分隔符-------------------------------')
print('----------------enumerate---------------------------')
for i,x in enumerate(fruit2):
    print(i,x)
print('----------------分隔符-------------------------------')
print('----------------looping backwards-------------------')
for i,x in enumerate(reversed(fruit2)):
    print(i,x)
print('----------------分隔符-------------------------------')
print('----------------looping in sorted order-------------')
for i,x in enumerate(sorted(fruit2)):
    print(i,x)
print('----------------分隔符-------------------------------')
print('----------------Dictionary Merging------------------')
a={"ross":"123456","xiaoming":"abc123"}
b={"lilei":"111111","zhangsan":"12345678"}
c={}
for k in a:
    c[k]=a[k]
for k in b:
    c[k]=b[k]
print(c)
d={**a,**b}     #**在python中叫做unpacking解包，相当于将a,b直接放在这里
print(d)
print('----------------分隔符-------------------------------')
print('----------------Ternary Operator--------------------')
score=int(input())
s="pass" if score>60 else "fail"
print(s)
print('----------------分隔符-------------------------------')
print('----------------Sequence Unpacking------------------')
#list\tuple\range
name ='San Zhang'
# str_list=name.split()
# first_name=str_list[0]
# last_name=str_list[1]
first_name,last_name = name.split()
print(first_name,last_name)
print('----------------分隔符-------------------------------')
print('----------------With Statement----------------------')
# f=open("hello.txt","r")
# s=f.read()
# print(s)
# f.close()
with open("hello.txt","r") as f:
    s=f.read()
    print(s)