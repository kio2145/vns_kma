#ifndef PARSANDDROW_H
#define PARSANDDROW_H
#include "QString"
#include <string>
class parsanddrow
{
    int* x;
    int* y;
    QString* dev;
    QString* mac;
    QString* name;
    QString* fromconnectmac1;
    QString* fromconnectmac2;

    public:
    int c;
    parsanddrow();

    int count(QString f);

    void startconnect(QString f); //перед выбором елементів зеднання

    void connecting(QString f);//процес зьеднання малювання звязку

    int movstart(QString f);

    void movs(QString f);

    void stop(QString f);

    void cord(QString f);

    int getx(int i);

    int gety(int i);

    QString getdev(int i);

    QString getmac(int i);

    QString getname(int i);

    QString gatmacconnect1(int i);

    QString gatmacconnect2(int i);

    void deletemas();

    void rewritedata(QString f,int pos ,qreal newx,qreal newy);

    void startdel(QString f);//початок видалення

    void delate(QString f,int pos ); //видалення обладнання основна процедура


    int coutofdev(QString typeofdev);


};
#endif // PARSANDDROW_H
