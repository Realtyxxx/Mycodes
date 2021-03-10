all:
	gcc -E -C hello.c -o hello.i
	ls
	gcc -S  -fverbose-asm hello.c 
	ls
	gcc -c hello.c
	ls
	gcc -g hello.c -o hello
	ls

clean:
	-rm  -rf hello.i hello.s hello.o hello hello.bc a.out hello.dYSM

show_temps:
	gcc -save-temps hello.c