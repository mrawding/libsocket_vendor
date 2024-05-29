#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include "libsocket/exception.hpp"
#include "libsocket/inetserverstream.hpp"
#include "libsocket/select.hpp"
#include "libsocket/socket.hpp"
#include <achr_bridge_cpp/message_definitions.hpp>

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 7002
#define SA struct sockaddr

/*
 * This server is a bit more complicated than
 * what you will need later. It uses the selectset class
 * to demonstrate how to use it.
 * When a client connects we first send a message and
 * receive the client's answer afterwards.
 */

int main(void) {
    using std::string;
    using std::unique_ptr;

    using libsocket::inet_stream;
    using libsocket::inet_stream_server;
    using libsocket::selectset;

    string host = "127.0.0.1";
    string port = "1235";
    string answ;

    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    socklen_t len = sizeof(cli);
    
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
    {
        printf("Server listening..\n");
    }
   
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
    {
        printf("server accept the client...\n");
    }


            



            achr_header* header = new achr_header;

           // int bytes_received = cl1->rcv((char*)header, sizeof(*header), 0);

            #define COUNT 2222
            
            header->type = TRACKS;

            tracks* tracks_ = new tracks;
            header->count = COUNT;
            tracks_->header = *header;
            
            


            printf("%d",tracks_->header.type);

            tracks_->track_header.active_tracks = 54;

            char buff[68];
            buff[0] = 0x00;
            buff[1] = 0x00;
            buff[2] = 0xc3;
            buff[3] = 0x50;
            buff[4] = 0x00;
            buff[5] = 0x00;
            buff[6] = 0x00;
            buff[7] = 0x07;
            buff[8] = 0x00;
            buff[9] = 0x00;
            buff[10] = 0x00;
            buff[11] = 0x01;
            buff[12] = 0x00;
            buff[13] = 0x00;
            buff[14] = 0x00;
            buff[15] = 0x44;
            buff[16] = 0x0b;
            buff[17] = 0x10;
            buff[18] = 0x02;
            buff[19] = 0x06;
            buff[20] = 0x00;
            buff[21] = 0x00;
            buff[22] = 0x00;
            buff[23] = 0x00;
            buff[24] = 0x00;
            buff[25] = 0x00;
            buff[26] = 0x06;
            buff[27] = 0x00;
            buff[28] = 0x00;
            buff[29] = 0x00;
            buff[30] = 0x8e;
            buff[31] = 0x00;
            buff[32] = 0x00;
            buff[33] = 0x00;
            buff[34] = 0x02;
            buff[35] = 0x02;
            buff[36] = 0x00;
            buff[37] = 0x00;
            buff[38] = 0x00;
            buff[39] = 0x00;
            buff[40] = 0x00;
            buff[41] = 0x00;
            buff[42] = 0x00;
            buff[43] = 0x00;
            buff[44] = 0x00;
            buff[45] = 0x00;
            buff[46] = 0x00;
            buff[47] = 0x00;
            buff[48] = 0x00;
            buff[49] = 0x00;
            buff[50] = 0x00;
            buff[51] = 0x00;
            buff[52] = 0x00;
            buff[53] = 0x00;
            buff[54] = 0x00;
            buff[55] = 0x00;
            buff[56] = 0x00;
            buff[57] = 0x00;
            buff[58] = 0x00;
            buff[59] = 0x00;
            buff[60] = 0x00;
            buff[61] = 0x00;
            buff[62] = 0x00;
            buff[63] = 0x00;
            buff[64] = 0x00;
            buff[65] = 0x00;
            buff[66] = 0x00;
            buff[67] = 0x00;
            

            

            for(;;)
            {   
                write(connfd,&buff, 68);
            
            }
            // cl1 is closed automatically when leaving the scope!

    return 0;
}