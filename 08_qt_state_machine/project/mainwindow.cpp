#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // TODO: Create state machine
    // TODO: Create states
    // TODO: Set appropriate 'assignProperty'
    // TODO: Set state transitions including this class events and slots
    // TODO: Set initial state
    // TODO: Start state machine
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    // TODO: Show file dialog
    // TODO: Open selected file
    // TODO: Emit 'error' if opening failed
    // TODO: Set text and emit 'opened' if suceeded
    // TODO: Save file name in 'fileName'
}

void MainWindow::save()
{
    // TODO: Open 'fileName' for writing
    // TODO: Emit 'error' if opening failed
    // TODO: Save file and emit 'saved' if succeeded
}
