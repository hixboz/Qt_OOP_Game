#include <QApplication>
#include <MyRect.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include<QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);


    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(scene->width()/2 - player->rect().width()/2 , scene->height() - player->rect().height());

    //spawn Enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1500);


    view->show();


    return a.exec();
}
