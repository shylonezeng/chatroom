#ifndef CLIENT_H
#define CLIENT_H


//#include "/unpv13e/lib/unp.h"
#include "my_lib/mylib.h"
#include <queue>
#include <iostream>
#include <cstring>
#include <pthread.h>
#include <error.h>
#include <QString>
#include <time.h>
#include <QDebug>
#define MAXSIZE 1024
#define localhost "127.0.0.1"
#define IPLEN 20

class Client
{
public:
    Client();

    ~Client();

    bool _connect();
    void sendmsg(char*) ;
    void ready_for_data();
    void disconnect();
    void addto_queue(char * recvline);
    void* str_cli( );
    bool rcvqueue_empty(){rcv_queue.empty();}
    //attributions
public:
    static void erro(QString);
    static void* subthread_pro(void*);

    static std::queue<char*> rcv_queue;
    static std::queue<char*> send_queue;
    // void
public:
    //operate with recieve and send queue
    char* &  popfrom_rcv(char*&);
    bool pushto_send(char*);
    int getsockfd(){return sockfd; }
private:
    //sock  and addrss
    struct sockaddr_in servAddr;
    int port;
    char *ip;
    int sockfd;
    pthread_t tid;
    // bool newmsg=false;
};
#endif // CLIENT_H
