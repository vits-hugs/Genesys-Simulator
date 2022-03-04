#ifndef PROPERTYEDITOR_H
#define PROPERTYEDITOR_H

#include <QTreeWidget>
#include <QObject>

class PropertyEditor : public QTreeWidget
{
public:
    PropertyEditor(QWidget *parent = nullptr);
};

#endif // PROPERTYEDITOR_H
