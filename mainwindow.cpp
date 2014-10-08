#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindow)
{
    //
    connect_ok=false;
    //connect to server
    ui->setupUi(this);
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connect_to_server())) ;
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit_and_exit()));
    connect(this, SIGNAL(sig_updatechat(QString)),
         this,SLOT(updatechat(QString)),Qt::QueuedConnection);

}

void MainWindow::connect_to_server()
{
    //begin connect to server

    if(!clt._connect())
    {
        erro("connection error");
        return;
    }
    connect_ok=true;
    emit sig_updatechat("connected, start to chat!");
    clt.ready_for_data();
    pthread_t tid;
    pthread_create(&tid,NULL,&MainWindow::pthread_func,this);
}
void *MainWindow::pthread_func(void *arg)
{
    return reinterpret_cast<MainWindow*>(arg)->rcv_and_print();
}
//receive data form socket and print in chat screen
void* MainWindow::rcv_and_print()
{
    emit sig_updatechat("listen data from server");
    std::cout<<"listen data from server"<<std::endl;

    while(true)
    {
        if(clt.rcvqueue_empty())
            continue;
        char* one_line;
        clt.popfrom_rcv(one_line
                        );
        std::cout<<"recieved: "<<one_line<<std::endl;
        emit sig_updatechat(one_line);
    }
}

void MainWindow::sendMessage()
{
    //send message to server and show in the text box
    if(!connect_ok)
        erro("connection not prepared");
    QString msg=ui->sendText->text();
    char *str=new char[MAXSIZE];
    const char *temp = msg.toLocal8Bit().data();
    sprintf(str,"socketfd %d: %s",clt.getsockfd(),temp);
    clt.pushto_send(str);
#ifdef DEBUG
   // wtochat(QString("sendqueue count:"+clt.sendmsg()));
    std::cout<<"sendqueue count:"<<clt.send_queue.size();
#endif
    //  wtochat(str);
}
void MainWindow::updatechat(QString s)
{
    wtochat(s);
}

void MainWindow::quit_and_exit()
{
    //close connection and deallocate
    erro("quit and exit");
    accept();

}
void MainWindow::disconnect()
{}
void MainWindow::erro(QString erro_info)
{
    emit sig_updatechat("#");
    emit sig_updatechat(erro_info);
}

//write to chat text screen
void MainWindow::wtochat(QString text)
{
    ui->chat->append(text);
    //QString buff(buff);
    //emit sig_updatechat(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}
