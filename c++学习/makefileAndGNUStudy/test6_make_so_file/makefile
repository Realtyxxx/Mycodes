# 如果想创建一个动态链接库，可以使用 GCC 的-shared选项。输入文件可以是源文件、汇编文件或者目标文件。
# 另外还得结合-fPIC选项。-fPIC 选项作用于编译阶段，告诉编译器产生与位置无关代码（Position-Independent Code）；
# 这样一来，产生的代码中就没有绝对地址了，全部使用相对地址，所以代码可以被加载器加载到内存的任意位置，都可以正确的执行。这正是共享库所要求的，共享库被加载时，在内存的位置不是固定的。
all:
	gcc -fPIC -c add.c sub.c div.c 
	gcc -shared add.o sub.o div.o -o libfunc.so

install:
	gcc main.c libfunc.so -o main.out 

clean:
	rm add.o div.o sub.o libfunc.so main.out