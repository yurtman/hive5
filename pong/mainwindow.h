#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
  void timer();
  void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
  bool leftpaddle_up;
  bool rightpaddle_up;
  bool ball_direction_right;
  bool ball_direction_up;
  void standardball();
  void AI_simple_leftpaddle();
  void AI_perfect_leftpaddle();
  void AI_human_leftpaddle();
  void AI_simple_rightpaddle();
  void AI_perfect_rightpaddle();
  void AI_human_rightpaddle();
  void reinitialise();
  void fieldalign();
};

#endif // MAINWINDOW_H
