#ifndef PARSANDDROW_H
#define PARSANDDROW_H
#include "mainwindow.h"
#include "mainwindow.h"
#include <QFile>"
#include "QString"
#include "QTextStream"
#include <QMessageBox>
#include <QMainWindow>
class parsanddrow
{
    QFile filer;
    MainWindow *window= new MainWindow;
public:
    parsanddrow();
    void setcord(QFile file)
    {
        if ( !file.open(QIODevice::ReadOnly) )
              {
                    QMessageBox::warning(0,"Warning", "файл пошкоджено");
               }
        else
        {
            QTextStream t( &file );
            qreal x;
            qreal y;
            QString h=" ";
            QString line;
            QString l;
            QString le;
            QString lei;
            int j=0;
            int tt=0;
            int u=0;
            bool viras=false;
            bool virasx=false;
                    while ( !t.atEnd() )
                    {
                      line = t.readLine();
                      for(int i=1;line[i]!='\n';i++)
                      {
                          if(line[i]!=h[0] && viras!=true)
                          {
                              l[j]=line[i];
                              j++;
                              if(line[i]==h[0])
                                  viras=true;
                          }
                          if(line[i]!=h[0] && virasx!=true && viras==true)
                          {
                              le[tt]=line[i];
                              tt++;
                              x=(le.toInt());
                              if(line[i]==h[0])
                                  virasx==true;
                          }
                          if(line[i]!=h[0] && virasx==true && viras==true)
                          {
                              lei[u]=line[i];
                              u++;
                              y=(lei.toInt());
                          }

                      }
                    }
                    file.close();
        }

   }

};

#endif // PARSANDDROW_H
