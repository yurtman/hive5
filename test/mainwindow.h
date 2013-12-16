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
  void on_knop_clicked();
  void OnTimer();

private:
  Ui::MainWindow *ui;
  bool m_go_right;
};

#endif // MAINWINDOW_H
