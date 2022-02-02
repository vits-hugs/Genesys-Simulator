#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include "../../../../../kernel/simulator/Simulator.h"
#include "../../../../../kernel/simulator/TraceManager.h"
#include "CodeEditor.h"

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

    void on_actionSave_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void on_actionStop_triggered();

    void on_actionStart_triggered();

    void on_actionStep_triggered();

    void on_actionPause_triggered();

    void on_actionResume_triggered();

    void on_actionOpen_triggered();

    void on_textCodeEdit_Model_textChanged();

    void on_listWidget_Plugins_itemClicked(QListWidgetItem *item);

    void on_listWidget_Plugins_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_Plugins_doubleClicked(const QModelIndex &index);

    void on_listWidget_Plugins_clicked(const QModelIndex &index);

    void on_actionCheck_triggered();

    void on_actionAbout_triggered();

    void on_actionLicence_triggered();

    void on_pushButton_clicked();

    void on_tabWidgetModel_2_tabBarClicked(int index);

    void on_checkBox_ShowElements_stateChanged(int arg1);

    void on_checkBox_ShowInternals_stateChanged(int arg1);

private: // VIEW

private: // trace handlers
    void _simulatorTraceHandler(TraceEvent e);
    void _simulatorTraceErrorHandler(TraceErrorEvent e);
    void _simulatorTraceSimulationHandler(TraceSimulationEvent e);
    void _simulatorTraceReportsHandler(TraceEvent e);
private: // event handlers
    void _onReplicationStartHandler(SimulationEvent* re);
    void _onSimulationStartHandler(SimulationEvent* re);
    void _onSimulationPausedHandler(SimulationEvent* re);
    void _onSimulationResumeHandler(SimulationEvent* re);
    void _onSimulationEndHandler(SimulationEvent* re);
    void _onProcessEventHandler(SimulationEvent* re);
private:
    void _setOnEventHandlers();
    void _insertPluginUI(Plugin* plugin);
    void _insertFakePlugins();
    void _actualizeWidgets();
    void _actualizeModelTextHasChanged(bool hasChanged);
    void _insertCommandInConsole(std::string text);
    void _clearModelEditors();
    bool _checkStartSimulation();
    bool _setSimulationModelBasedOnText();
    bool _createModelGraphicPicture();
    std::string _recursiveCreateModelGraphicPicture(ModelComponent* component, std::list<ModelDataDefinition*>* visited);
private:
    Ui::MainWindow *ui;
    Simulator* simulator;
    bool _textModelHasChanged;
private:
    CodeEditor* textCodeEdit_Model;
};
#endif // MAINWINDOW_H
