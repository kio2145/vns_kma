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
    QString* name;
    public:
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
    {  //переміщення старт
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
    void stop(QString f)
    {  // зупинка видалення або переміщення
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
        name=new QString[dowj];
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
        { // считування файлу для подальшої роботи

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
            }
            if(i==5)
            {
                name[j]=line;
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
    QString getname(int i)
    {
        return name[i];
    }

    void deletemas()
    {
        delete x;
        delete y;
        delete dev;
        delete name;
    }
    void rewritedata(QString f,int dc,int pos ,qreal newx,qreal newy)
    {
    // процедура перезапису данних після перемішення
        QFile file(f);
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
            t<<name[i];
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
                    t<<name[i];
                    t<<"\n";
                }
            }

            file.close();
        }
    }
    void startdel(QString f)//початок видалення
    {
        QFile file(f);
        QTextStream t( &file );
        if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
              {
              QMessageBox::warning(0,"Warning", "файл пошкоджено");
              }
        else
        {
            t<<"3";
            t<<"\n";
        }
        file.close();
    }
    void delate(QString f,int dc,int pos ) //видалення обладнання основна процедура
    {
        QFile file(f);
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
            t<<name[i];
            t<<"\n";
                }
            }

            file.close();
        }
    }
    int coutofdev(QString typeofdev, int dd)
    {
        int devcount=0;
        for(int i=0;i<dd;i++)
        {
            if (dev[i]==typeofdev)
            {
                devcount++;
            }
        }
        return devcount;
    }
};
#endif // PARSANDDROW_H
