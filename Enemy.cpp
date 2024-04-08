#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>


Enemy::Enemy()
{
    int randomNumber = rand() % 700;
    setPos(randomNumber,0);

    setRect(0,0,100,100);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y()+rect().height() > scene()->height()){
        scene()->removeItem(this);
        delete this;
        qDebug()<< "ENEMY DELETED";
    }
}

