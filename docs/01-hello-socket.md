# hello-socket.c

Creates a socket and makes an HTTP GET request.

## Building and running the program

    gcc -c hello-socket.c
    gcc hello-socket.o -o hello-socket.exe

    ./hello-socket.exe

## The code

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

## Notes

Here's the same request using `curl`:

```
curl -v 130.89.10.12

* Rebuilt URL to: 130.89.10.12/
*   Trying 130.89.10.12...
* TCP_NODELAY set
* Connected to 130.89.10.12 (130.89.10.12) port 80 (#0)
> GET / HTTP/1.1
> Host: 130.89.10.12
> User-Agent: curl/7.52.1
> Accept: */*
> 
< HTTP/1.1 200 OK
< Date: Sun, 08 Jul 2018 18:06:47 GMT
< Server: Apache/2.2.17 (Linux/SUSE)
< Last-Modified: Sun, 08 Jul 2018 08:03:27 GMT
< ETag: "77a9b-1be7-5707854fc997f"
< Accept-Ranges: bytes
< Content-Length: 7143
< Content-Type: text/html
< 
<HTML>
<HEAD>
<TITLE>Homepage Server</TITLE>
<LINK rev="made" href="mailto:webmaster%5C@cs.utwente.nl">
</HEAD>
<BODY>
<A name="Top"></A>
<IMG SRC="Homepage%20Server_files/utlogo.gif" ALIGN="LEFT">
<H1>University of Twente</H1>
<hr size="4">
<H1>
Department of Computer Science<br>
...
```

Here's the GET request:

```
GET / HTTP/1.1
> Host: 130.89.10.12
> User-Agent: curl/7.52.1
> Accept: */*
```

The request has a request line followed by three header fields. The request line
includes the path of the URI (`/`). The `Host` header field holds the address
of the host.
