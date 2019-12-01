#include "Spider.h"

Spider::Spider(QTimer* timer, QObject* parent):Enemy(timer, parent){

    randHor = 100 + rand()%900;
    randVer = 50 + rand()%300;
    health = 50;
    dropRate = 20;

    pix = QPixmap(":/image/enemyBlack1.png");

    setPixmap(pix);
    setStep(2);
    setPos(randHor, 0);
    setScale(0.5);



}


void Spider::emitEnemyProjectileIsLaunchedSignal()
{
//    cout << "projectile is launched" << endl;
    int randNum = rand()%200;

    if(randNum == 1)
        emit enemyProjectileIsLaunched(x()+pixmap().width()/4, y());

}



void Spider::move(){

    if(y()>=randVer){

//        disconnect(refreshRate, SIGNAL(timeout()), this, SLOT(move()));
////        refreshRate = new QTimer(this);
////        refreshRate->start(2000);
//        connect(refreshRate, SIGNAL(timeout()), this, SLOT(emitEnemyProjectileIsLaunchedSignal()));

        emitEnemyProjectileIsLaunchedSignal();

    }else


        setPos(x(), y()+step);

}