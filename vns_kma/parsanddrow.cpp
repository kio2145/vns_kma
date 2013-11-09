#include "parsanddrow.h"
#include "mainwindow.h"
#include <QFile>
#include "QString"
#include <string>
#include "QTextStream"
#include <QMessageBox>
#include <QMainWindow>
int* x;
int* y;
QString* dev;
QString* mac;
QString* name;
QString* fromconnectmac1;
QString* fromconnectmac2;
int c;
parsanddrow::parsanddrow()
{
}
int parsanddrow::count(QString f)
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
   if(coun>=1)
   {
   c=coun/5;
   }
   else
   c=0;
   return c;
}
void parsanddrow::startconnect(QString f) //перед выбором елементів зеднання
{
    QFile file(f);
    QTextStream t( &file );
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
          {
          QMessageBox::warning(0,"Warning", "файл пошкоджено");
          }
    else
    {
        t<<"4";
        t<<"\n";
    }
    file.close();
}
void parsanddrow::connecting(QString f)//процес зьеднання малювання звязку
{
    QFile file(f);
    QTextStream t( &file );
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
          {
          QMessageBox::warning(0,"Warning", "файл пошкоджено");
          }
    else
    {
        t<<"5";
        t<<"\n";
    }
    file.close();
}
int parsanddrow::movstart(QString f)
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
void parsanddrow::movs(QString f)
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
void parsanddrow::stop(QString f)
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

void parsanddrow::cord(QString f)
{
    QFile file(f);
    QTextStream t( &file );
    x=new int[c];
    y=new int[c];
    dev=new QString[c];
    mac=new QString[c];
    name=new QString[c];
    fromconnectmac1=new QString[c];
    fromconnectmac2=new QString[c];
    QString line;
    int i=0;
    int j=0;
    if ( !file.open(QIODevice::ReadOnly) )
          {
          QMessageBox::warning(0,"Warning", "файл пошкоджено");
          }
    else
    {
    while ( !t.atEnd() && j<c)
    { // считування файлу для подальшої роботи

        line = t.readLine();
        i++;
        if(i==1)
        {
            dev[j]=line;
        }
        if(i==2)
        {
            if(dev[j]!="con")
            {
            x[j]=(line.toInt());
            }
            else
            fromconnectmac1[j]=line;
        }
        if(i==3)
        {
            if(dev[j]!="con")
            {
            y[j]=(line.toInt());
            }
            else
            fromconnectmac2[j]=line;
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
int parsanddrow::getx(int i)
{
    return x[i];
}
int parsanddrow::gety(int i)
{
    return y[i];
}
QString parsanddrow::getdev(int i)
{
    return dev[i];
}
QString parsanddrow::getmac(int i)
{
    return mac[i];
}
QString parsanddrow::getname(int i)
{
    return name[i];
}
QString parsanddrow::gatmacconnect1(int i)
{
    return fromconnectmac1[i];
}
QString parsanddrow::gatmacconnect2(int i)
{
    return fromconnectmac2[i];
}

void parsanddrow::deletemas()
{
    delete x;
    delete y;
    delete dev;
    delete name;
}
void parsanddrow::rewritedata(QString f,int pos ,qreal newx,qreal newy)
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
        for(int i=0;i<c;i++)
        {
            if(i!=pos || dev[i]=="con")
            {
        t<<dev[i];
        t<< "\n";
        if(dev[i]!="con")
        {
        t<<x[i];
        t<<"\n";
        t<<y[i];
        t<<"\n";
        }
        else
        {
            t<<fromconnectmac1[i];
            t<<"\n";
            t<<fromconnectmac2[i];
            t<<"\n";
        }
        t<<mac[i];
        t<<"\n";
        t<<name[i];
        t<<"\n";
            }
            else
            {
                if(dev[i]!="con")
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
        }

        file.close();
    }
}
void parsanddrow::startdel(QString f)//початок видалення
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
void parsanddrow::delate(QString f,int pos ) //видалення обладнання основна процедура
{
    QFile file(f);
    QTextStream t( &file );
    if ( !file.open(QIODevice::WriteOnly | QIODevice::Text) )
          {
          QMessageBox::warning(0,"Warning", "файл пошкоджено");
          }
    else
    {
        for(int i=0;i<c;i++)
        {
            if(i!=pos)
            {
        t<<dev[i];
        t<< "\n";
        if(dev[i]!="con")
        {
            t<<x[i];
            t<<"\n";
            t<<y[i];
        }
        if(dev[i]=="con")
        {
            t<<fromconnectmac1[i];
            t<<"\n";
            t<<fromconnectmac2[i];
        }
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
int parsanddrow::coutofdev(QString typeofdev)
{
    int devcount=0;
    for(int i=0;i<c;i++)
    {
        if (dev[i]==typeofdev)
        {
            devcount++;
        }
    }
    return devcount;
}
