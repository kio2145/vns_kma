#ifndef CONNECTS_H
#define CONNECTS_H
#include "QString"
#include <string>
#include "QTextStream"
#include <QFile>
#include <QMessageBox>
class connects
{
    QString con_begin;
    QString con_end;
public:

    connects();
    void addconfig(QString f,QString endd)
    {
        set_con_begin();
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::Append | QIODevice::Text) )
              {
                 QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<"con";
            t<< "\n";
            t<<con_begin;
            t<<"\n";
            t<<endd;
            t<<"\n";
            t<<"type";
            t<<"\n";
            t<<"name";
            t<<"\n";
            file.close();

        }
    }
    void set_con_begin()
    {
        QFile file("connect.txt");
        QTextStream t( &file );
        if ( !file.open(QIODevice::ReadOnly) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
        while ( !t.atEnd())
        { // считування файлу для подальшої роботи

            con_begin = t.readLine();
        }
        file.close();
        }
    }
    QString getbegin()
    {
        set_con_begin();
        return con_begin;
    }
    void begining(QString mac)
    {
        QFile file("connect.txt");
        QTextStream t( &file );
        if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<mac;
            t<<"\n";
        }
        set_con_begin();
        file.close();
    }
};

#endif // CONNECTS_H
