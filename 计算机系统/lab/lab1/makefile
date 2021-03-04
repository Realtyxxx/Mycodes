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
	rm hello.i hello.s hello.o hello
