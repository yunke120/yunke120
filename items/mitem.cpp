﻿#include "mitem.h"

#include <QPainter>
MItem::MItem(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

MItem::~MItem()
{

}

QString MItem::nameString() const
{
    return name;
}

/**********
 *                   Rect
**********/

MItemRect::MItemRect(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Rect";
}

QRectF MItemRect::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void MItemRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->drawRect(this->boundingRect());
}

/**********
 *                   Ellipse
**********/

MItemEllipse::MItemEllipse(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Ellipse";
}

QRectF MItemEllipse::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void MItemEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED(widget);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->drawEllipse(this->boundingRect());
}


/**********
 *                   Text
**********/
MItemText::MItemText(QGraphicsObject *parent)
    : MItem(parent)
{
    name = "Text";
    m_text = name;
    m_font.setPixelSize(8);
}

QRectF MItemText::boundingRect() const
{
    int size = m_font.pixelSize();
    int count = m_text.size();
    return QRectF(-size/2*count/2,-size/2,size*count/2,size);
}

void MItemText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget); Q_UNUSED(option);

    painter->setRenderHint(QPainter::TextAntialiasing, true);
    painter->setFont(m_font);
    painter->drawText(this->boundingRect(), m_text);
}
#include <QInputDialog>
void MItemText::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    bool ok;
    QString text = QInputDialog::getText(nullptr, nullptr,
                                        tr("Input:"), QLineEdit::Normal,nullptr, &ok);
    if (ok && !text.isEmpty())
    {
        m_text = text;
        update();
    }
}
