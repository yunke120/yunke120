#include "mscene.h"

#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include "mitem.h"
#include "reflect.h"

int MScene::count = 0;

MScene::MScene(QObject *parent)
    : QGraphicsScene(parent)
{
    this->setBackgroundBrush(QColor("#cdcdcd"));
    MScene::count ++;
}

MScene::~MScene()
{

}

QByteArray MScene::getItemClassName(QByteArray &name) const
{
    const char *c = "MItem";
    return QByteArray(c) + name;
}

void MScene::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasFormat("items"))
        event->setAccepted(true);
}

void MScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasFormat("items"))
        event->setAccepted(true);
}

void MScene::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QByteArray data = event->mimeData()->data("items");
    QByteArray classname = getItemClassName(data);

    MItem *item = dynamic_cast<MItem*>(Reflect::createObject(classname));
    if(item)
    {
        qDebug() << QString("Add a %1 item.").arg(item->nameString());
        item->setPos(event->scenePos());
        this->addItem(item);
    }
    else
        qDebug() << "No item: " << classname;
}

void MScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void MScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

