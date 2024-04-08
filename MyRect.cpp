#include "MyRect.h"
#include "Bullet.h"
#include <QDebug>
#include <QGraphicsScene>
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        break;
    case Qt::Key_Left:
        if(pos().x()>0 ){
            setPos(x()-10,y());
        }
        break;
    case Qt::Key_Right:
        if(pos().x() < scene()->width()-rect().width() ){
            setPos(x()+10,y());
        }
        break;
    case Qt::Key_Space:
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        break;

    }
}

void MyRect::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
