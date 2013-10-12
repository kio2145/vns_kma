#ifndef PC_H
#define PC_H
#include "QString"
#include <string>
#include "QTextStream"
#include <QFile>
#include <QMessageBox>
class pc
{

QString name;
QString mac;
QString ip;
QString arrayofconnect;
QString other;
public:
    pc();
    void add(QString n,QString m,QString i,QString o)
    {
        name=n;
        mac=m;
        ip=i;
        other=o;
    }
    void addconfig(QString f,int x,int y,QString mac,QString name)
    {
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::Append | QIODevice::Text) )
              {
                 QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<"pc";
            t<< "\n";
            t<<x;
            t<<"\n";
            t<<y;
            t<<"\n";
            t<<mac;
            t<<"\n";
            t<<name;
            t<<"\n";
            file.close();
            //запись в конец файла допилить
        }
    }
};

#endif // PC_H
