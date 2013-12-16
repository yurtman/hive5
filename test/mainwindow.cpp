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
  this->m_go_right = true;

  QTimer * const timer = new QTimer(this);
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(OnTimer()));
  timer->setInterval(1);
  timer->start();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::OnTimer()
{
  //Dit gebreurt er als de timer tiks
  this->on_knop_clicked();
}

void MainWindow::on_knop_clicked()
{
  const int dx = 1;
  const int cur_left  = ui->josje->geometry().x();
  const int cur_right = ui->josje->geometry().right();
  const int maxx = this->geometry().width();

  bool new_go_right = m_go_right;

  //Will Josje leave the screen on the right? If yes, let her move left in the next statement
  if (cur_right + dx > maxx)
  {
    new_go_right = false;
  }

  //Will Josje leave the screen on the left? If yes, let her move right in the next statement
  if (cur_left - dx < 0)
  {
    new_go_right = true;
  }

  //Let Josje move in the correct dimension
  int next_left = -1;
  if (new_go_right == true)
  {
    next_left = cur_left + dx;
  }
  else
  {
    next_left = cur_left - dx;
  }

  //Set her picture's coordinats to the new coordinats
    this->ui->josje->setGeometry(
    next_left,
    this->ui->josje->geometry().y(),  //cur y
    this->ui->josje->geometry().width(), //cur width
    this->ui->josje->geometry().height()  //cur height
  );

  //Store her direction for next time
  this->m_go_right = new_go_right;
}
