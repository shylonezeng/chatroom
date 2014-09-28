#include "client.h"
#include "my_lib/mylib.h"
#define queue std::queue<char*>
void* str_cli(void *para);
queue Client::rcv_queue;
queue Client::send_queue;

Client::Client()
{
    sockfd=-1;
    this->port=PORT;
    this->ip=localhost;
    //Client::rcv_queue.empty();
    //Client::send_queue.empty();
}

Client::~Client()
{
    //delete the malloc string of both queue
    this->disconnect();
}

//connect to serverusing
bool Client::_connect()
{
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
        err_sys("socket fault");

    bzero(&servAddr,sizeof(servAddr));
    servAddr.sin_family=AF_INET;
    servAddr.sin_port=htons(PORT);
    if(inet_pton(AF_INET,ip,&servAddr.sin_addr)<=0)
        err_quit("inet_pton erro");

    if(connect(sockfd,(const sockaddr*)&servAddr,sizeof(servAddr))<0)
    {
        err_sys("connect erro");
        return false;
    }
    return true;

}    void static addto_queue(char * recvline);

//send socket message
void Client::sendmsg(char *cltline)
{
    write(sockfd,cltline,strlen(cltline));

}
struct thread_info {    /* Used as argument to thread_start() */
    pthread_t thread_id;        /* ID returned by pthread_create() */
    int       thread_num;       /* Application-defined thread # */
    char     *argv_string;      /* From command-line argument */
};

//create a new thread and keep waiting for new data from server
void Client::ready_for_data()
{
    /*#here interrupped#
    *tasks: complete the function
    *  add prefix
    *  shengming member func
    *  add to mainwindow*/

    pthread_create(&tid, 0,&Client::subthread_pro,this);
    //   std::thread t(Client::str_cli,this);

    // t.join();
}

void Client::disconnect()
{

    //stop sub thread
    //close connetion and release other resource
    close(sockfd);
    pthread_kill(tid,9);
}
void* Client::subthread_pro(void *arg)
{
    return reinterpret_cast<Client*>(arg)->str_cli();
}

//private:
void* Client::str_cli()
{
    //char cltline[MAXSIZE];

    char* recvline;

    // long _sockfd=(long)para;
    int sockfd=(int)sockfd;
    //         FD_SET(
    fd_set fset;
    FD_ZERO(&fset);
    int stdioeof=0; // improve effecient
    while(true)
    {
        //send message to socket if there some
        if(!Client::send_queue.empty())
        {
            sendmsg(Client::send_queue.front());
            Client::send_queue.pop();
            //  Client::send_queue.pop();
        }

        // recevive from socket
        FD_SET(sockfd,&fset);
        int maxfdp;
        maxfdp=sockfd+1;
        struct timeval outtime;
        outtime.tv_sec=0;
        outtime.tv_usec=500;
        int fd=select(maxfdp,&fset,NULL,NULL,&outtime);

        if(fd>0 && FD_ISSET(sockfd,&fset))
        {
            //signal from socket
            int n;
            recvline=new char[MAXSIZE];
            if((n=read(sockfd,recvline,MAXLINE))>0)
                Client::rcv_queue.push(recvline);//addto_queue(recvline); //write text area
            else if(n==0)
            {
                if(stdioeof==1)
                    pthread_exit(NULL);

                else
                    err_quit("server is terminated!");
            }
            else
            {
                //err happened; do something
            }
#ifdef DEBUG
            std::cout<<"rcvqueue count:"<< rcv_queue.size()<<std::endl;
#endif

        }
        //send message if exist
    }
    pthread_exit(NULL);

}
/*
        if(FD_ISSET(fileno(fp),&fset))
        {
void
            if(read(fileno(fp),cltline,MAXSIZE)==0)
            {return
                stdioeof=1;
                shutdown(sockfd,SHUT_WR);
                FD_CLR(fileno(fp),&fset);
                continue;
            }
            write(sockfd,cltline,sizeof(cltline));

        }

*/

void Client::popfrom_rcv(char* top)
{
    top=rcv_queue.front();
    rcv_queue.pop();
}
bool Client::pushto_send(char* recvline)
{
    send_queue.push(recvline);
}



