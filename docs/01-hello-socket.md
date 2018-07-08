# hello-socket.c

Creates a socket and makes an HTTP GET request.

## Building and running the program

    gcc -c hello-socket.c
    gcc hello-socket.o -o hello-socket.exe

    ./hello-socket.exe

## Notes

The `socket` function creates a socket and returns a file descriptor.
For information about the `socket` function and the `sockaddr_in` struct, see
[https://linux.die.net/man/7/socket](https://linux.die.net/man/7/socket).

```
sockfd = socket(AF_INET, SOCK_STREAM, 0);
```

This next block of code specifies the host and port:

```
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = inet_addr("130.89.10.12");
serv_addr.sin_port = htons(80);
```

The [connect](https://linux.die.net/man/2/connect) function connects the
socket file descriptor to the host address and port.

```
connect(  sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)  );
```

To make a GET request, write to the socket.

```
write(sockfd, "GET / \r\n", 8);
```

To get the response, read from the socket into `buffer`. Also write each
character to stdout.

```
while( (i=read(sockfd, buffer, 8196)) > 0)
   write(1, buffer, i);
}
```
