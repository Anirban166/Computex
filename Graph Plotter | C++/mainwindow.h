#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

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
    void on_btnPlott_clicked();

    void on_btnClear_clicked();

private:
    Ui::MainWindow *ui;
    void plotGraph(std::string inputString, int times);
    void clearAllGraph();
};

#endif // MAINWINDOW_H
