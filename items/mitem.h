#ifndef MITEM_H
#define MITEM_H

#include <QGraphicsItem>

class MItem : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit MItem(QGraphicsObject *parent = nullptr);
    virtual ~MItem();

    QString nameString() const;

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) = 0 ;

protected:
    virtual void drawSelectedRect(QPainter *painter) ; /* 画虚线框 */
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) ;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

protected:
    QString name;
};


class MItemRect : public MItem
{
    Q_OBJECT
public:
    explicit MItemRect(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};


class MItemEllipse : public MItem
{
    Q_OBJECT
public:
    explicit MItemEllipse(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#include <QFont>
class MItemText : public MItem
{
    Q_OBJECT
public:
    explicit MItemText(QGraphicsObject *parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QFont m_font;
    QString m_text;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MITEM_H
