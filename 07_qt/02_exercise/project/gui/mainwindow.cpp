#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &speed, SLOT(notify(float)));

    QObject::connect(&displacement, SIGNAL(sendVal(float)),
                     &acceleration, SLOT(notify(float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_displacamentButton_clicked()
{
    displacement.set(ui->displacementEdit->text().toFloat());
    ui->displacementEdit->setText("");

    try
    {
        ui->speedLcd->display(speed.get());
        ui->accelerationLcd->display(acceleration.get());
    }
    catch (std::logic_error& excpt) {}

}
