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
 * File:   ModelGraphicsScene.h
 * Author: rlcancian
 *
 * Created on 16 de fevereiro de 2022, 09:52
 */

#ifndef MODELGRAPHICSSCENE_H
#define MODELGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QGraphicsRectItem>
#include <QTreeWidgetItem>
#include "GraphicalModelComponent.h"
#include "GraphicalComponentPort.h"
#include "../../../../../kernel/simulator/ModelComponent.h"
#include "../../../../../kernel/simulator/Simulator.h"
#include "../../../../../kernel/simulator/Plugin.h"


class ModelGraphicsScene : public QGraphicsScene {
public:
    ModelGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    ModelGraphicsScene(const ModelGraphicsScene& orig);
    virtual ~ModelGraphicsScene();
public:
    GraphicalModelComponent* addModelComponent(Plugin* plugin, ModelComponent* component, qreal x, qreal y, QColor color=Qt::blue);
    void showGrid();
    void beginConnection();
    void setSimulator(Simulator *simulator);
    void setObjectBeingDragged(QTreeWidgetItem* objectBeingDragged);
    void setParentWidget(QWidget *parentWidget);

    unsigned short connectingStep() const;
    void setConnectingStep(unsigned short connectingStep);

protected: // virtual functions
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    //virtual void	inputMethodEvent(QInputMethodEvent *event)
    virtual void keyPressEvent(QKeyEvent *keyEvent);
    //virtual void keyReleaseEvent(QKeyEvent *keyEvent);
private:
    void _addModelComponent(Plugin* plugin, QPointF position, QColor color=Qt::blue);

private:

    struct GRID {
        unsigned int interval = 20;
        QPen pen = QPen(Qt::gray);
        std::list<QGraphicsLineItem*>* lines = new std::list<QGraphicsLineItem*>();
    } _grid;
    Simulator* _simulator = nullptr;
    QTreeWidgetItem* _objectBeingDragged = nullptr;
    QWidget* _parentWidget;

private:
    unsigned short _connectingStep = 0; //0:nothing, 1:waiting click on source, 2: waiting click on destination and after that creates the connection and backs to 0
    GraphicalComponentPort* _sourcePortConnection;
};

#endif /* MODELGRAPHICSSCENE_H */

