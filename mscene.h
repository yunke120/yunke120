#ifndef MSCENE_H
#define MSCENE_H

#include <QGraphicsScene>

class MScene : public QGraphicsScene
{
public:
    explicit MScene(QObject *parent = nullptr);
    ~MScene() override;
    static int count; /* 引用计数 */
private:
    QByteArray getItemClassName(QByteArray &name) const;

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

//    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

};

#endif // MSCENE_H
