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
    const int dy = 1;
    const int current_ball_right = ui->
    //define window variables (current top, current bottom)
    //define left paddle variables (top, bottom, right)
    //define right paddle variables (top, bottom, left)

    //if ball goes beyond top, change ball_up to false
    //if ball goes beyond bottom, change ball_up to true
    //if ball goes beyond left, add score to P2 and reinitialise
    //if ball goes beyond right, add score to P1 and reinitialise
    //if ball hits left paddle, reverse x direction
    //if ball hits right paddle, reverse x direction

//dit is het standaard gedrag van de leftpaddle
}
void MainWindow::standardleftpaddle()
{
    //define leftpaddle variables (stepsize y, current top, current bottom)
    //define window variables (top, bottom)

    //if paddle hits top, reverse y direction of leftpaddle
    //if paddle hits bottom, reverse y direction of leftpaddle
}

//dit is het standaard gedrag van de rightpaddle
void MainWindow::standardrightpaddle()
{
    //hetzelde als leftpaddle maar dan een vaste afstand van rechter kant

    //define rightpaddle variables (stepsize y, current top, current bottom)
    //define window variables (top, bottom)

    //if button is pressed reverse y direction of rightpaddle
    //if paddle hits top, reverse y direction of rightpaddle
    //if paddle hits bottom, reverse y direction of rightpaddle
}

//dit gebeurt er als de knop is ingedrukt
void MainWindow::on_button_pressed()
{
//change boolean of left paddle
    //if true, make false
    //if false, make true
}
void MainWindow::reinitialise()
{
    //start standard behavior again after a delay
}
