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
  void on_button_pressed();
  void timer();

private:
    Ui::MainWindow *ui;
  bool leftpaddle_up;
  bool rightpaddle_up;
  bool ball_right;
  bool ball_up;
  void standardball();
  void standardleftpaddle();
  void standardrightpaddle();
  void reinitialise();
};

#endif // MAINWINDOW_H
