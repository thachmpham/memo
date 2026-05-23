all: malloc thread test_malloc

malloc:
	gcc -g -o libmem.so -fPIC -shared mem.c -ldl

thread:
	gcc -g -o libthread.so -fPIC -shared -pthread thread.c -ldl

test:
	gcc -g -o test_malloc test_malloc.c
	gcc -g -o test_thread test_thread.c


clean:
	rm -f $(TARGETS)

.PHONY: all clean