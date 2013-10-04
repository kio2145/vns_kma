#ifndef PARSANDDROW_H
#define PARSANDDROW_H
#include "mainwindow.h"
#include <QFile>
#include "QString"
#include <string>
#include "QTextStream"
#include <QMessageBox>
#include <QMainWindow>
class parsanddrow
{
    QFile filer;
    public:
    int counts;
    parsanddrow();
    int count(QString f)
    {
       int coun=0;
       QFile file(f);
       QTextStream t( &file );
       if ( !file.open(QIODevice::ReadOnly) )
             {
                QMessageBox::warning(0,"Warning", "файл пошкоджено");
             }
       else
       {
       while ( !t.atEnd() )
       {
           t.readLine();
           coun++;
       }
       }

       return coun;
    }
    void setcount(int co)
    {
        counts=co;
    }

    int* x;
    int* y;
    QString* dev;//[10];
    QString* mac;//[10];
    void cord(QString f,int dc)
    {
        QFile file(f);
        int dowj=dc;
        QTextStream t( &file );
        x=new int[dowj];
        y=new int[dowj];
        dev=new QString[dowj];
        mac=new QString[dowj];
        QString line;
        int i=0;
        int j=0;
        if ( !file.open(QIODevice::ReadOnly) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
        while ( !t.atEnd() && j<dc)
        {

            line = t.readLine();
            i++;
            if(i==1)
            {
                dev[j]=line;
            }
            if(i==2)
            {
                x[j]=(line.toInt());
            }
            if(i==3)
            {
                y[j]=(line.toInt());
            }

            if(i==4)
            {
                mac[j]=line;
                j++;
                i=0;
            }
        }
          }
        file.close();
    }
    int getx(int i)
    {
        return x[i];
    }
    int gety(int i)
    {
        return y[i];
    }
    QString getdev(int i)
    {
        return dev[i];
    }
    QString getmac(int i)
    {
        return mac[i];
    }
    void deletemas()
    {
        delete x;
        delete y;
        delete dev;

    }

};

#endif // PARSANDDROW_H
