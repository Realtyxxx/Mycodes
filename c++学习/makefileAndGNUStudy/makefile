main: main.o , my.o, my.hpp

my.o: my.cc

main.o :main.cc , my.hpp

all: 
	gcc  main.cc -c 
	gcc  my.cc -c 

install: 
	gcc  -save-temps -lstdc++ -shared-libgcc main.o my.o -o main

OK:
	gcc -E -C main.cc -o main.i

clean:
	-rm main main.o my.o main.s main.i

#gcc -MM 看依赖关系
#"g++" equals "to gcc -lstdc++ -shared-libgcc"