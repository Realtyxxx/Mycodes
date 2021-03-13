main:run.o staticLinkedList.o
	gcc -g run.o staticLinkedList.o -o main

run.o: run.c staticLinkedList.h
	gcc -c run.c staticLinkedList.h

staticLinkedList.o: staticLinkedList.c staticLinkedList.h
	gcc -c staticLinkedList.c staticLinkedList.h

clean:
	rm main *.o