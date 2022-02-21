#include "GraphicalConnection.h"
#include <QPainter>

GraphicalConnection::GraphicalConnection(GraphicalComponentPort* sourceGraphicalPort, GraphicalComponentPort* destinationGraphicalPort, QColor color, QGraphicsItem *parent) : QGraphicsObject(parent){
    ModelComponent* sourceComp = sourceGraphicalPort->graphicalComponent()->getComponent();
    ModelComponent* destComp=destinationGraphicalPort->graphicalComponent()->getComponent();
    //Connection* sourceConnection = new Connection({sourceComp,sourceGraphicalPort->portNum()});
    Connection* destinationConnection = new Connection({destComp,destinationGraphicalPort->portNum()});
    sourceComp->getConnections()->insertAtRank(sourceGraphicalPort->portNum(), destinationConnection);
    _sourceGraphicalPort = sourceGraphicalPort;
    _destinationGraphicalPort = destinationGraphicalPort;
    _color = color;
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
    setAcceptHoverEvents(true);
    setAcceptTouchEvents(true);
    setActive(true);
    setSelected(false);
    updateDimensions();
    //sourceGraphicalPort->
}

GraphicalConnection::GraphicalConnection(const GraphicalConnection& orig){

}

GraphicalConnection::~GraphicalConnection(){

}

void GraphicalConnection::updateDimensions() {
    qreal x1, x2, y1, y2;
    x1 = _sourceGraphicalPort->scenePos().x();
    x2 = _destinationGraphicalPort->scenePos().x();
    y1 = _sourceGraphicalPort->scenePos().y();
    y2 = _destinationGraphicalPort->scenePos().y();
    _width = abs(x2-x1);
    _height = abs(y2-y1);
    update();
}

QRectF GraphicalConnection::boundingRect() const {
    return QRectF(0,0,_width,_height);
}

void GraphicalConnection::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    updateDimensions();
    QPen pen = QPen(_color);
    pen.setWidth(2);
    painter->setPen(pen);
    QPainterPath path;
    QPointF inipos;
    QPointF endpos;
    qreal x1, x2, y1, y2;
    if (_sourceGraphicalPort->scenePos().x()<_destinationGraphicalPort->scenePos().x()){
        x1 = _sourceGraphicalPort->width()/2.0;
        x2 = _width;//-_sourceGraphicalPort->width()/2.0;
    } else {
        x2 = _sourceGraphicalPort->width()/2.0;
        x1 = _width;//-_sourceGraphicalPort->width()/2.0;
    }
    if (_sourceGraphicalPort->scenePos().y()<_destinationGraphicalPort->scenePos().y()){
        y1 = _sourceGraphicalPort->height()/2.0;
        y2 = _height;//-_sourceGraphicalPort->height()/2.0;
    } else {
        y2 = _sourceGraphicalPort->height()/2.0;
        y1 = _height;//-_sourceGraphicalPort->height()/2.0;
    }
    inipos= QPointF(x1,y1);//QPointF(_sourceGraphicalPort->pos());//_sourceGraphicalPort->pos().x()+_sourceGraphicalPort->width()/2.0, _sourceGraphicalPort->pos().y()+_sourceGraphicalPort->height()/2.0
    endpos = QPointF(x2,y2);//QPointF(_destinationGraphicalPort->pos());// _destinationGraphicalPort->pos().x()+_destinationGraphicalPort->width()/2.0, _destinationGraphicalPort->pos().y()+_destinationGraphicalPort->height()/2.0
    path.moveTo(inipos);
    path.lineTo(endpos);
    painter->drawPath(path);
}

Connection* GraphicalConnection::getSource() const{

}
Connection* GraphicalConnection::getDestination() const{

}

bool GraphicalConnection::sceneEvent(QEvent *event){

}
