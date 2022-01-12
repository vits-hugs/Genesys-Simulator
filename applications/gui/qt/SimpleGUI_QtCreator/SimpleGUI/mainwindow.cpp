#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
    //        ui->progressBar, SLOT(setValue(int)));

    //simulator =  new Simulator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::_simulatorTraceHandler(TraceEvent e) {
    //ui->tex
}
