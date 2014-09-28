/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *chat;
    QHBoxLayout *horizontalLayout;
    QLineEdit *sendText;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *quitButton;
    QPushButton *connectButton;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(MainWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chat = new QTextEdit(MainWindow);
        chat->setObjectName(QStringLiteral("chat"));
        chat->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(chat);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sendText = new QLineEdit(MainWindow);
        sendText->setObjectName(QStringLiteral("sendText"));

        horizontalLayout->addWidget(sendText);

        sendButton = new QPushButton(MainWindow);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setDefault(true);

        horizontalLayout->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        quitButton = new QPushButton(MainWindow);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout_2->addWidget(quitButton);

        connectButton = new QPushButton(MainWindow);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout_2->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Talking...", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
