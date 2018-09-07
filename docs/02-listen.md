# listen.c

Simple socket listener taken from https://www.tutorialspoint.com/unix_sockets/socket_server_example.htm

## Building and running the program

    gcc -c listen.c
    gcc listen.o -o listen.exe

    ./listen.exe

## Testing

In another terminal:

    curl localhost:5001
