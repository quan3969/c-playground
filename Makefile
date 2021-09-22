all:
	gcc -g main.c my_function.c test_function.c -o test

clean:
	rm -rf test.exe 