#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../../../../kernel/simulator/Simulator.h"
#include "../../../../../kernel/simulator/TraceManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void _simulatorTraceHandler(TraceEvent e);
private:
    Ui::MainWindow *ui;
    Simulator* simulator;
};
#endif // MAINWINDOW_H
