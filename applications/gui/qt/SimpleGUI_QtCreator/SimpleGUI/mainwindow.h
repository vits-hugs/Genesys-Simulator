#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTreeWidgetItem>
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
    void on_actionCheck_triggered();
    void on_actionAbout_triggered();
    void on_actionLicence_triggered();
    void on_actionGet_Involved_triggered();
    void on_textCodeEdit_Model_textChanged();
	void on_tabWidget_Model_tabBarClicked(int index);
    void on_tabWidget_Debug_currentChanged(int index);
    void on_horizontalSlider_Zoom_valueChanged(int value);
    void on_checkBox_ShowElements_stateChanged(int arg1);
    void on_checkBox_ShowInternals_stateChanged(int arg1);
    void on_checkBox_ShowRecursive_stateChanged(int arg1);
    void on_checkBox_ShowLevels_stateChanged(int arg1);
    void on_pushButton_clicked();
    void on_pushButton_Breakpoint_Insert_clicked();
    void on_pushButton_Breakpoint_Remove_clicked();
    void on_tabWidget_Debug_tabBarClicked(int index);
    void on_tabWidgetCentral_currentChanged(int index);
    void on_tabWidgetCentral_tabBarClicked(int index);
    void on_treeWidget_Plugins_itemDoubleClicked(QTreeWidgetItem *item, int column);

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
    void _onEntityCreateHandler(SimulationEvent* re);
    void _onEntityRemoveHandler(SimulationEvent* re);
private:
    void _setOnEventHandlers();
    void _insertPluginUI(Plugin* plugin);
    void _insertFakePlugins();
    void _actualizeWidgets();
    void _actualizeModelTextHasChanged(bool hasChanged);
    void _actualizeSimulationEvents(SimulationEvent * re);
    void _actualizeDebugVariables(bool force);
    void _actualizeDebugEntities(bool force);
    void _actualizeDebugBreakpoints(bool force);
    void _insertCommandInConsole(std::string text);
    void _clearModelEditors();
    //bool _checkStartSimulation();
    bool _setSimulationModelBasedOnText();
    bool _createModelGraphicPicture();
    std::string _adjustName(std::string name);
    void _insertTextInDot(std::string text, unsigned int compLevel, unsigned int compRank, std::map<unsigned int, std::map<unsigned int, std::list<std::string>*>*>* dotmap, bool isNode = false);
    void _recursiveCreateModelGraphicPicture(ModelDataDefinition* componentOrData, std::list<ModelDataDefinition*>* visited, std::map<unsigned int, std::map<unsigned int, std::list<std::string>*>*>* dotmap);
private:
    Ui::MainWindow *ui;
    Simulator* simulator;
    bool _textModelHasChanged;
    QString _modelfilename;
private:
    const struct CONST_STRUC {
        const unsigned int TabModelIndex = 0;
        const unsigned int TabModelTextIndex = 0;
        const unsigned int TabModelImageIndex = 1;
        const unsigned int TabModelGraphicEditIndex = 2;
        const unsigned int TabDebugIndex = 1;
        const unsigned int TabDebugBreakpointIndex = 0;
        const unsigned int TabDebugVarableIndex = 1;
        const unsigned int TabDebugEntityIndex = 2;
        const unsigned int TabSimulationIndex = 2;
        const unsigned int TabSimulationTraceIndex = 0;
        const unsigned int TabSimulationEventsIndex = 1;
        const unsigned int TabReportIndex = 3;
        const unsigned int TabReporTextIndex = 0;
        const unsigned int TabReporGraphictIndex = 1;
    } CONST;
    CodeEditor* textCodeEdit_Model;
};
#endif // MAINWINDOW_H
