#ifndef ROUTER_H
#define ROUTER_H
#include "QString"
#include <string>
#include "QTextStream"
#include <QFile>
#include <QMessageBox>
class router
{
    QString name;
    QString mac;
    QString ip;
    QString arrayofconnect;
    QString other;
public:
    router();
    void addnew(QString n,QString m,QString i,QString o)
    {
        name=n;
        mac=m;
        ip=i;
        other=o;
    }
    void addconfig(QString f,int x, int y, QString mac)
    {
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::Append | QIODevice::Text) )
              {
                 QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<"modem";
            t<< "\n";
            t<<x;
            t<<"\n";
            t<<y;
            t<<"\n";
            t<<mac;
            t<<"\n";
            file.close();
        }
    }
};

#endif // ROUTER_H
