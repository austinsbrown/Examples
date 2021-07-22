CC = g++

adt: main.o linkedList.o queue.o stack.o 
	$(CC) main.o linkedList.o queue.o stack.o -o adt

main.o: main.cpp linkedList.h queue.h stack.h
	$(CC) -c main.cpp

linkedList.o: linkedList.cpp linkedList.h
	$(CC) -c linkedList.cpp

queue.o: queue.cpp queue.h
	$(CC) -c queue.cpp

stack.o: stack.cpp stack.h
	$(CC) -c stack.cpp

clean:
	rm *.o adt