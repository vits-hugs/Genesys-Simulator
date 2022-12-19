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
 * File:   QModelGraphicView.cpp
 * Author: rlcancian
 *
 * Created on 15 de fevereiro de 2022, 21:12
 */

#include "ModelGraphicsView.h"
#include "ModelGraphicsScene.h"
#include "GraphicalModelComponent.h"
#include <Qt>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <fstream>
#include <streambuf>

ModelGraphicsView::ModelGraphicsView(QWidget *parent) : QGraphicsView(parent) {
	setInteractive(true);
	setEnabled(false);
	// scene
	ModelGraphicsScene* scene = new ModelGraphicsScene(-1024, -1024, 1024 * 2, 1024 * 2, this);
	setScene(scene);
}

ModelGraphicsView::ModelGraphicsView(const ModelGraphicsView& orig) {
}

ModelGraphicsView::~ModelGraphicsView() {
}


//------------------------------------------------------------------

bool ModelGraphicsView::addGraphicalModelComponent(Plugin* plugin, ModelComponent* component, QPointF position) {
	GraphicalModelComponent* item = ((ModelGraphicsScene*) scene())->addGraphicalModelComponent(plugin, component, position);
	return item != nullptr;
}

void ModelGraphicsView::showGrid() {
	((ModelGraphicsScene*) scene())->showGrid();
}

void ModelGraphicsView::clear() {
	scene()->clear();
}

void ModelGraphicsView::beginConnection() {
	((ModelGraphicsScene*) scene())->beginConnection();
}

void ModelGraphicsView::selectModelComponent(ModelComponent* component) {
	QList<QGraphicsItem*>* list = ((ModelGraphicsScene*) scene())->getGraphicalModelComponents();
	for (QGraphicsItem* item : *list) {
		GraphicalModelComponent* gmc = (GraphicalModelComponent*) item;
		if (gmc->getComponent() == component) {
			gmc->setSelected(true);
			//return;
		} else {
			gmc->setSelected(false);
		}
	}
}

void ModelGraphicsView::setSimulator(Simulator* simulator) {
	_simulator = simulator;
	((ModelGraphicsScene*) scene())->setSimulator(simulator);
}

void ModelGraphicsView::setEnabled(bool enabled) {
	QGraphicsView::setEnabled(enabled);
	QBrush background;
	if (enabled) {
		// background
		//unsigned int colorVal1 = 255 * 13.0 / 16.0;
		//unsigned int colorVal2 = 255 * 15.0 / 16.0;
		background = QColor(255, 255, 128, 64);
	} else {
		// background
		background = Qt::lightGray;
	}
	background.setStyle(Qt::SolidPattern);
	setBackgroundBrush(background);

}
//---------------------------------------------------------

void ModelGraphicsView::notifySceneMouseEventHandler(QGraphicsSceneMouseEvent* mouseEvent) {
	this->_sceneMouseEventHandler(mouseEvent);
}

void ModelGraphicsView::notifySceneGraphicalModelEventHandler(GraphicalModelEvent* modelGraphicsEvent) {
	this->_sceneGraphicalModelEventHandler(modelGraphicsEvent);
}


//---------------------------------------------------------

void ModelGraphicsView::dragEnterEvent(QDragEnterEvent *event) {
	QGraphicsView::dragEnterEvent(event);
	QString name = event->source()->objectName();
	//std::cout << "View source name: " << name.toStdString()<< std::endl;
	QWidget* widget = dynamic_cast<QWidget*> (event->source());
	if (widget != nullptr) {
		QTreeWidget* tree = dynamic_cast<QTreeWidget*> (widget);
		if (tree != nullptr) {
			if (tree->selectedItems().size() == 1) {
				QTreeWidgetItem* treeItem = tree->selectedItems().at(0);
				QString name = treeItem->whatsThis(0);
				//std::cout << "Drop name: " << name.toStdString() << std::endl;
				Plugin* plugin = _simulator->getPlugins()->find(name.toStdString());
				if (plugin != nullptr) {
					event->setDropAction(Qt::CopyAction);
					event->accept();
					((ModelGraphicsScene*) scene())->setObjectBeingDragged(treeItem);
					return;
				}
			}
		}
	}
	event->setAccepted(false);
}

void ModelGraphicsView::setParentWidget(QWidget *parentWidget) {
	_parentWidget = parentWidget;
	((ModelGraphicsScene*) scene())->setParentWidget(parentWidget);
}

//------------------------------------------------------

void ModelGraphicsView::changed(const QList<QRectF> &region) {
	int i = 0;
}

void ModelGraphicsView::focusItemChanged(QGraphicsItem *newFocusItem, QGraphicsItem *oldFocusItem, Qt::FocusReason reason) {
	int i = 0;
}

void ModelGraphicsView::sceneRectChanged(const QRectF &rect) {
	int i = 0;
}

void ModelGraphicsView::selectionChanged() {
	int i = 0;
}

//------------------------------------------------------

QList<QGraphicsItem *> ModelGraphicsView::selectedItems() {
	return ((ModelGraphicsScene*) scene())->selectedItems();
}

