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
    int* x;
    int* y;
    QString* dev;
    QString* mac;
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
    int movstart(QString f)
    {
       QFile file(f);
       QString line;
       int u;
       QTextStream t( &file );
       if ( !file.open(QIODevice::ReadOnly) )
       {
             QMessageBox::warning(0,"Warning", "файл пошкоджено");
       }
             while ( !t.atEnd())
             {
                 line = t.readLine();
             }
         file.close();
         u=(line.toInt());
        return u;
    }
    void movs(QString f)
    {
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<"1";
            t<<"\n";
        }
        file.close();

    }
    void movstop(QString f)
    {
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<"0";
            t<<"\n";
        }
        file.close();

    }

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
    void rewritedata(QString str,int dc,int pos ,qreal newx,qreal newy)
    {

        QFile file(str);
        QTextStream t( &file );
        if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            for(int i=0;i<dc;i++)
            {
                if(i!=pos)
                {
            t<<dev[i];
            t<< "\n";
            t<<x[i];
            t<<"\n";
            t<<y[i];
            t<<"\n";
            t<<mac[i];
            t<<"\n";
                }
                else
                {
                    t<<dev[i];
                    t<< "\n";
                    t<<newx;
                    t<<"\n";
                    t<<newy;
                    t<<"\n";
                    t<<mac[i];
                    t<<"\n";
                }
            }

            file.close();
        }
    }
};
#endif // PARSANDDROW_H
