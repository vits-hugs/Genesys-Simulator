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

private slots:
    void on_actionNew_triggered();

    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void on_actionStop_triggered();

private: // VIEW

private: // simulator based
    void _simulatorTraceHandler(TraceEvent e);
    void _insertPluginUI(Plugin* plugin);
    void _insertFakePlugins();
    void _actualizeWidgets();
private:
    Ui::MainWindow *ui;
    Simulator* simulator;
};
#endif // MAINWINDOW_H
