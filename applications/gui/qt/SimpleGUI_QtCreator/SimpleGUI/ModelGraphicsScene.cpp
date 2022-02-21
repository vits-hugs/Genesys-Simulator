/*
 * The MIT License
 *
 * Copyright 2022 rlcancian.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * File:   ModelGraphicsScene.cpp
 * Author: rlcancian
 *
 * Created on 16 de fevereiro de 2022, 09:52
 */

#include <qt5/QtWidgets/qgraphicssceneevent.h>
#include <QTreeWidget>
#include <QMessageBox>
#include "ModelGraphicsScene.h"
#include "GraphicalModelComponent.h"
#include "ModelGraphicsView.h"
#include "GraphicalComponentPort.h"
#include "GraphicalConnection.h"

ModelGraphicsScene::ModelGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent) : QGraphicsScene(x, y, width, height, parent) {
    // grid
    _grid.pen.setWidth(1);
    _grid.pen.setStyle(Qt::DotLine);
}

ModelGraphicsScene::ModelGraphicsScene(const ModelGraphicsScene& orig) {
}

ModelGraphicsScene::~ModelGraphicsScene() {
}

GraphicalModelComponent* ModelGraphicsScene::addModelComponent(Plugin* plugin, ModelComponent* component, qreal x, qreal y, QColor color) {
    GraphicalModelComponent* graphComp = new GraphicalModelComponent(plugin, component, x, y, color);
    addItem(graphComp);
    return graphComp;
}

void ModelGraphicsScene::showGrid() {
    // remove xisting grid
    for (QGraphicsLineItem* line : *_grid.lines) {
        removeItem((QGraphicsItem*) line);
    }
    _grid.lines->clear();
    // add new grid
    for (unsigned int i = 0; i < width(); i += _grid.interval) {
        QGraphicsLineItem* line = addLine(i, 0, i, height(), _grid.pen);
        _grid.lines->insert(_grid.lines->end(), line);
    }
    for (unsigned int j = 0; j < height(); j += _grid.interval) {
        QGraphicsLineItem* line = addLine(0, j, width(), j, _grid.pen);
        _grid.lines->insert(_grid.lines->end(), line);
    }
}

void ModelGraphicsScene::beginConnection(){
    _connectingStep = 1;
    ((QGraphicsView* )this->parent())->setCursor(Qt::CrossCursor);
}


//-------------------------
// PROTECTED VIRTUAL FUNCTIONS
//-------------------------

void ModelGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    QGraphicsScene::mousePressEvent(mouseEvent);
    if (_connectingStep>0){
        QGraphicsItem* item = this->itemAt(mouseEvent->scenePos(), QTransform());
        if (item!=nullptr) {
            GraphicalComponentPort* port = dynamic_cast<GraphicalComponentPort*>(item);
            if (port != nullptr) {
                if (_connectingStep==1 && !port->isInputPort()){
                    _sourcePortConnection = port;
                    _connectingStep = 2;
                    return;
                 } else if (_connectingStep==2 && port->isInputPort()) {
                    _connectingStep = 3;
                    // create connection
                    GraphicalConnection* graphicconnection = new GraphicalConnection(_sourcePortConnection, port);
                    _sourcePortConnection->addGraphicalConnection(graphicconnection); // to update connection on port position change
                    graphicconnection->setPos(_sourcePortConnection->scenePos());
                    port->addGraphicalConnection(graphicconnection);
                    addItem(graphicconnection);
                    //
                    ((ModelGraphicsView *) (this->parent()))->unsetCursor();
                    _connectingStep = 0;
                    return;
                }
            }
        }
        ((ModelGraphicsView *) (this->parent()))->unsetCursor();
        _connectingStep = 0;
    }
}

void ModelGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}


void ModelGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mouseMoveEvent(mouseEvent);
    ((ModelGraphicsView *) (this->parent()))->notifySceneMouseEventHandler(mouseEvent); // to show coords
    if (_connectingStep>0){
        QGraphicsItem* item = this->itemAt(mouseEvent->scenePos(), QTransform());
        if (item!=nullptr) {
            GraphicalComponentPort* port = dynamic_cast<GraphicalComponentPort*>(item);
            if (port != nullptr) {
                if (_connectingStep==1 && !port->isInputPort()) {
                    ((ModelGraphicsView *) (this->parent()))->setCursor(Qt::PointingHandCursor);
                } else if (_connectingStep==2 && port->isInputPort()) {
                    ((ModelGraphicsView *) (this->parent()))->setCursor(Qt::PointingHandCursor);
                }
                return;
            }
        }
        if (_connectingStep>1) {
            ((ModelGraphicsView *) (this->parent()))->setCursor(Qt::ClosedHandCursor);
        } else {
            ((ModelGraphicsView *) (this->parent()))->setCursor(Qt::CrossCursor);
        }
    }
}
void ModelGraphicsScene::dropEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dropEvent(event);
    if (this->_objectBeingDragged != nullptr) {
        QTreeWidgetItem* treeItem = /*dynamic_cast<QTreeWidgetItem*>*/(_objectBeingDragged);
        if (treeItem != nullptr) {
            QColor color = treeItem->textColor(0);
            QString pluginname = treeItem->whatsThis(0);
            Plugin* plugin = _simulator->getPlugins()->find(pluginname.toStdString());
            if(plugin != nullptr) {
                if (plugin->getPluginInfo()->isComponent()) {
                    event->setDropAction(Qt::IgnoreAction);
                    event->accept();
                    _addModelComponent(plugin, event->scenePos(), color);
                    return;
                }
            }
        }
    }
    event->setAccepted(false);
}

void ModelGraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragEnterEvent(event);
    //QString name;
    //Plugin* plugin = _simulator->getPlugins()->find(name.toStdString());
    //if(true) {//(plugin != nullptr) {
    event->setDropAction(Qt::CopyAction);
    event->accept();
    //}
}

void ModelGraphicsScene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragLeaveEvent(event);
    event->setDropAction(Qt::CopyAction);
    event->accept();
}

void ModelGraphicsScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragMoveEvent(event);
    event->setDropAction(Qt::CopyAction);
    event->accept();
}

void ModelGraphicsScene::keyPressEvent(QKeyEvent *keyEvent){
    QList<QGraphicsItem*> selected = this->selectedItems();
    if (keyEvent->key()==Qt::Key_Delete && selected.size()>0) {
        QMessageBox::StandardButton reply = QMessageBox::question(this->_parentWidget, "Delete COmponent", "Are you sure you want to delete the selected components?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
        Model* model = _simulator->getModels()->current();
        for (QGraphicsItem* item: selected) {
            ModelComponent* component = ((GraphicalModelComponent*)item)->getComponent();
            model->remove(component);
            ((GraphicalModelComponent*)item)->~GraphicalModelComponent();
        }
    }
}

//--------------------------
//
//--------------------------

void ModelGraphicsScene::setObjectBeingDragged(QTreeWidgetItem* objectBeingDragged)
{
    _objectBeingDragged = objectBeingDragged;
}

void ModelGraphicsScene::setSimulator(Simulator *simulator){
    _simulator = simulator;
}

//------------------------
// Private
//------------------------

void ModelGraphicsScene::_addModelComponent(Plugin* plugin, QPointF position, QColor color) {
    ModelComponent* component = (ModelComponent*) plugin->newInstance(_simulator->getModels()->current());
    this->addModelComponent(plugin, component, position.x(), position.y(), color);
}

unsigned short ModelGraphicsScene::connectingStep() const
{
    return _connectingStep;
}

void ModelGraphicsScene::setConnectingStep(unsigned short connectingStep)
{
    _connectingStep = connectingStep;
}

void ModelGraphicsScene::setParentWidget(QWidget *parentWidget)
{
    _parentWidget = parentWidget;
}
