main: main.o , my.o, my.hpp

my.o: my.cc

main.o :main.cc , my.hpp

all: 
	gcc  main.cc -c 
	gcc  my.cc -c 

install: 
	gcc  -save-temps -lstdc++ -shared-libgcc main.o my.o -o main

E:
	gcc -E -C main.cc -o main.i

S:
	gcc -S main.cc -o main.s

clean:
	-rm main main.o my.o main.s main.i

#gcc -MM 看依赖关系

#"g++" equals "to gcc -lstdc++ -shared-libgcc"

# "gcc -S -fverbose-asm " let you know more about what's in the ".s" file

# "gcc -E would preprocess the code with -C it could output .i file"

# "gcc -c would compile and assemble the specified source file, but do not link."
