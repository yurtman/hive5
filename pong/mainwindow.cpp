#include <iostream>
#include <cassert>
#include <QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// set boolean to true so paddles go up and ball goes up left
    this->leftpaddle_up = true;
    this->rightpaddle_up = true;
    this->ball_right = false;
    this->ball_up = true;

// create a timer for the game
    QTimer * const timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timer()));
    timer->setInterval(10);
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//this happens when the timer runs
void MainWindow::timer()
{
    this->standardball();
    this->standardleftpaddle();
    this->standardrightpaddle();
}

//dit is het standaard gedrag van de bal
void MainWindow::standardball()
{
    //define ball variables (stepsize (x and y), current top, current bottom, current left, current right)
    //define window variables (current top, current bottom)
    //define left paddle variables (top, bottom, left, right)
    //define right paddle variables (top, bottom, left, right)

    //if ball goes beyond top, change ball_up to false
    //if ball goes beyond bottom, change ball_up to true
    //if ball goes beyond left, add score to P2 and reinitialise
    //if ball goes beyond right, add score to P1 and reinitialise

//dit is het standaard gedrag van de leftpaddle
}
void MainWindow::standardleftpaddle()
{

}

//dit is het standaard gedrag van de rightpaddle
void MainWindow::standardrightpaddle()
{
    //hetzelde als leftpaddle maar dan een vaste afstand van rechter kant
}

//dit gebeurt er als de knop is ingedrukt
void MainWindow::on_button_pressed()
{
//verander de boolean van left paddle
    //als die true is moet ie false zijn
    //als ie false is moet ie true zijn
}
void MainWindow::reinitialise()
{
    //start standard behavior again after a delay
}
