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

    // Create state machine
    auto stateMachine = new QStateMachine{ this };

    // Create states
    auto Unlocked = new QState{ stateMachine };

    auto Startup = new QState{ Unlocked };
    auto Open = new QState{ Unlocked };
    auto View = new QState{ Unlocked };
    auto Edit = new QState{ Unlocked };
    auto Save = new QState{ Unlocked };
    auto Error = new QState{ Unlocked };

    auto Locked = new QState{ stateMachine };

    // Set appropriate 'assignProperty'
    Unlocked->assignProperty(ui->pbToggle, "text", "Lock");
    Unlocked->assignProperty(ui->pbOpen, "enabled", true);
    Unlocked->assignProperty(ui->pbSave, "enabled", true);
    Unlocked->assignProperty(ui->teText, "enabled", true);

    Startup->assignProperty(ui->pbOpen, "enabled", true);
    Startup->assignProperty(ui->pbSave, "enabled", false);
    Startup->assignProperty(ui->teText, "enabled", false);
    Startup->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    View->assignProperty(ui->pbOpen, "enabled", true);
    View->assignProperty(ui->pbSave, "enabled", false);
    View->assignProperty(ui->teText, "enabled", true);

    Edit->assignProperty(ui->pbOpen, "enabled", false);
    Edit->assignProperty(ui->pbSave, "enabled", true);
    Edit->assignProperty(ui->teText, "enabled", true);

    Error->assignProperty(ui->pbOpen, "enabled", true);
    Error->assignProperty(ui->pbSave, "enabled", false);
    Error->assignProperty(ui->teText, "enabled", false);
    Error->assignProperty(ui->teText, "placeholderText", "Error ocured. Open file to start editing...");

    Locked->assignProperty(ui->pbToggle, "text", "Unlocked");
    Locked->assignProperty(ui->pbOpen, "enabled", false);
    Locked->assignProperty(ui->pbSave, "enabled", false);
    Locked->assignProperty(ui->teText, "enabled", false);

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
    // Show file dialog & Save file name in 'fileName'
    auto name = QFileDialog::getOpenFileName(this, tr("Open file"), "/home/student");

    // Open selected file
    QFile file{ name };
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Emit 'error' if opening failed
        emit error();
    }
    else {
        // Set text and emit 'opened' if suceeded
        auto content = file.readAll();
        QString text{ content };

        ui->teText->setPlaceholderText(text);
        emit opened();
    }

    // Save file name in 'fileName'
    this->fileName = name;
    file.close();
}

void MainWindow::save()
{
    // TODO: Open 'fileName' for writing
    QFile file{ this->fileName };
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Emit 'error' if opening failed
        emit error();
    }
    else {
        // Save file and emit 'saved' if succeeded
        file.write(ui->teText->placeholderText().toUtf8());
        emit saved();
    }
}
