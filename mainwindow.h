#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "client.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void erro(QString);
signals:
    void sig_updatechat(QString );
private slots:
    void sendMessage();
    void connect_to_server();
    void disconnect();
    void quit_and_exit();
    void updatechat(QString);
public :
   static void * pthread_func(void*);
   void* rcv_and_print();
private:
    Ui::MainWindow *ui;
    void wtochat(QString text);
    Client clt;
    bool connect_ok;
    //other definetion
};

#endif // MAINWINDOW_H
