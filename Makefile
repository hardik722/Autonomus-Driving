CC = gcc

thread : thread_1.c
	$(CC) -o thread thread_1.c -pthread
	
clean:
	rm thread
