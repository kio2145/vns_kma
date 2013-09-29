#ifndef PC_H
#define PC_H
#include "QString"
#include <string>
#include "QTextStream"
#include <QFile>
class pc
{
public:
QString name;
QString mac;
QString ip;
QString arrayofconnect;
QString other;
    pc();
    void add(QString n,QString m,QString i,QString o)
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

#endif // PC_H
