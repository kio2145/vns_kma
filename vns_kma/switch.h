#ifndef SWITCH_H
#define SWITCH_H
#include "QString"
#include <string>
#include "QTextStream"
#include <QFile>
class switches
{
public:
    QString name;
    QString mac;
    QString ip;
    QString arrayofconnect;
    QString other;
    int connects;
    int friconnects;
    switches();
    void addnew(QString n,QString m,QString i,QString o)
    {
        name=n;
        mac=m;
        ip=i;
        other=o;
    }
    void addconfig(QString f)
    {
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::ReadOnly) )
              {
                 QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
                 //запись в конец файла допилить
        }
    }
};
#endif // SWITCH_H
