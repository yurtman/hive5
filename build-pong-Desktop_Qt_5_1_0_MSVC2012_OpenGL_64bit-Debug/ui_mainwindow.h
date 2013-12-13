/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *leftpaddle;
    QLabel *rightpaddle;
    QLabel *ball;
    QSpinBox *leftscore;
    QSpinBox *rightscore;
    QPushButton *pushButton;
    QLabel *net;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(619, 261);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        MainWindow->setAnimated(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        leftpaddle = new QLabel(centralWidget);
        leftpaddle->setObjectName(QStringLiteral("leftpaddle"));
        leftpaddle->setGeometry(QRect(50, 30, 20, 100));
        leftpaddle->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        rightpaddle = new QLabel(centralWidget);
        rightpaddle->setObjectName(QStringLiteral("rightpaddle"));
        rightpaddle->setGeometry(QRect(550, 160, 20, 100));
        rightpaddle->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        ball = new QLabel(centralWidget);
        ball->setObjectName(QStringLiteral("ball"));
        ball->setGeometry(QRect(290, 60, 20, 20));
        ball->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        leftscore = new QSpinBox(centralWidget);
        leftscore->setObjectName(QStringLiteral("leftscore"));
        leftscore->setGeometry(QRect(130, 0, 30, 30));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        leftscore->setFont(font);
        leftscore->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        leftscore->setButtonSymbols(QAbstractSpinBox::NoButtons);
        rightscore = new QSpinBox(centralWidget);
        rightscore->setObjectName(QStringLiteral("rightscore"));
        rightscore->setGeometry(QRect(400, 0, 30, 30));
        rightscore->setFont(font);
        rightscore->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        rightscore->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(250, 10, 101, 23));
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 170, 0);"));
        net = new QLabel(centralWidget);
        net->setObjectName(QStringLiteral("net"));
        net->setGeometry(QRect(300, 20, 1, 200));
        net->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralWidget);
        leftscore->raise();
        rightscore->raise();
        leftpaddle->raise();
        rightpaddle->raise();
        ball->raise();
        net->raise();
        pushButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        leftpaddle->setText(QString());
        rightpaddle->setText(QString());
        ball->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Change Direction", 0));
        net->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
