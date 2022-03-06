build:
	gcc -o test main.c matrix.c utils.c

run: build
	./test
