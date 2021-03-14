main: run.o staticLinkedList.o
	gcc -g run.o staticLinkedList.c -o main
	rm -rf main.dSYM *.gch

run.o: run.c 
	gcc -c run.c 

staticLinkedList.o: staticLinkedList.c 
	gcc -c staticLinkedList.c 

clean:
	rm main *.o 