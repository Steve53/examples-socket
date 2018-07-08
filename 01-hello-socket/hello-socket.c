#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
   char buffer[8196];
   static struct sockaddr_in serv_addr;
   int i;
   int sockfd;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = inet_addr("130.89.10.12");
   serv_addr.sin_port = htons(80);

   connect(  sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)  );

   write(sockfd, "GET / \r\n", 8);
   // write(sockfd, "GET /~arnoldf/ \r\n", 17);

   while( (i=read(sockfd,buffer,8196)) > 0)
      write(1,buffer,i);
}

// https://www.gnu.org/software/libc/manual/html_node/index.html
// https://linux.die.net/man/2/socket
// The socket function returns a file descriptor.
// The serv_addr.xxx lines look complicated, but all they do is specify the host address and port.
// Connect the file descriptor to the server address.
