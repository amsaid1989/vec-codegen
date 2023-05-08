CC=clang
CFLAGS=-g -Wall -Werror -pedantic
META_OUT=./codegen
MAIN_OUT=main

main: codegen vec.c main.c
	$(CC) $(CFLAGS) vec.c main.c -o $(MAIN_OUT)

codegen: codegen.c
	$(CC) $(CFLAGS) codegen.c -o $(META_OUT)
	$(META_OUT) vec
