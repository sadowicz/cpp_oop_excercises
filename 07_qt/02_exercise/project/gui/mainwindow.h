#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_displacamentButton_clicked();

private:
    Ui::MainWindow *ui;

    Displacement displacement{};
    Speed speed{};
    Acceleration acceleration{};
};
#endif // MAINWINDOW_H
