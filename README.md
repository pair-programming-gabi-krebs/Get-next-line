# Get Next Line - GNL

This project is part of école 42 projects.

## About

```get_next_line(int fd)``` function read from a file descriptor and print on the screen the result with the ```\n``` if there is any.<br>
The ```read``` function, from unistd.io library, read a certain amount of bytes from the passed file descriptor. These bytes are passed as BUFFER_SIZE at the compile time.<br>
The <strong>expected behaviour</strong> is that the function must read and return BUFFER_SIZE bytes until a ```\n``` or end of file (EOF), and must keep remaining bytes (if there is any) for a possible second call (or many other calls until EOF).

## How to compile it

```clang -D BUFFER_SIZE=5 get_next_line.c get_next_line_utils.c main.c -I. && ./a.out```

- The get_next_line.c has the main function.
- The get_next_line_utils.c has auxiliary functions.
- The get_next_line.h has the header with the prototypes of utils.