#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "Enemy.h"

Bullet::Bullet()
{
    setRect(0,0,10,50); //draw the rectangle

    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    //Bullet collide detection
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y()+rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

