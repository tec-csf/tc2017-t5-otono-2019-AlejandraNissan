#include "poligono.h"
#include "ui_poligono.h"
#include <QPainter>
#include <math.h>
#include <QMessageBox>
void drawPoligono(int lados, int radio, QPainter &painter);
poligono::poligono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::poligono)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

poligono::~poligono()
{
    delete ui;
}

void poligono::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pincel(Qt::blue);
    pincel.setWidth(2);
    painter.setPen(pincel);
    if (draw){
        QString nS = ui->boxLados->toPlainText();
        QString radioS = ui->boxRadio->toPlainText();
        if(!nS.isEmpty() && !radioS.isEmpty()) {
            lados = nS.toInt();
            radio = radioS.toInt();
            for(int i=0; i<qVecTrans.size(); ++i){
                painter.setTransform(qVecTrans[i],true);
                drawPoligono(lados, radio ,painter);
            }
        }else {
            QMessageBox msgBox;
            msgBox.setText("Favor de especificar el numero de lados y radio");
            msgBox.exec();
        }
    }
}

void poligono::drawPoligono(int lados, int radio,QPainter &painter){
      double angulo = (double)360.0/(double)lados,  v = 3.141592 / 180, centX = 0.0, centY = 0.0;
      int xInicial,yInicial,xFinal,yFinal;
      angulo *= v;
      for(int a=1; a<=lados; a++) {
        xInicial = centX + (radio * cos(angulo*a));
        yInicial = centY + (radio * sin(angulo*a));

        xFinal = centX + (radio * cos(angulo*(a+1)));
        yFinal = centY + (radio * sin(angulo*(a+1)));

        painter.drawLine(xInicial, yInicial, xFinal, yFinal);
      }
}

void poligono::on_pushButton_clicked()
{
    qVecTrans.clear();
    QString n = ui->boxLados->toPlainText();
    QString r = ui->boxRadio->toPlainText();
     if(!n.isEmpty() && !r.isEmpty()) {

       QTransform centro;
       centro.translate(centroX,centroY);
       qVecTrans.push_back(centro);
       draw = !draw;
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de especificar numero de lados y radio");
       msgBox.exec();
     }
     update();
}

//Traslación
void poligono::on_pushButton_2_clicked()
{
    QString xTrasladar = ui->boxXinicio->toPlainText();
    QString yTrasladar = ui->boxYinicio->toPlainText();
     if(!xTrasladar.isEmpty() && !yTrasladar.isEmpty()) {
       int x = xTrasladar.toInt();
       int y = yTrasladar.toInt();
       QTransform t;
       t.translate(x, y);
       qVecTrans.push_back(t);
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de determinar las coordenadas de la traslacion");
       msgBox.exec();
     }
     update();
}

//Zoom In
void poligono::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    qVecTrans.push_back(zoomIn);
    update();

}

//Zoom Out
void poligono::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    qVecTrans.push_back(zoomOut);
    update();

}


//Reflexion Vertical
void poligono::on_pushButton_7_clicked()
{
    QTransform reflexionVertical;
    reflexionVertical.scale(1,-1);
    qVecTrans.push_back(reflexionVertical);
    update();

}

//Reflexion Horizontal
void poligono::on_pushButton_6_clicked()
{
    QTransform reflexionHorizontal;
    reflexionHorizontal.scale(-1,1);
    qVecTrans.push_back(reflexionHorizontal);
    update();

}

//Rotar
void poligono::on_pushButton_3_clicked()
{
    QString rot = ui->boxGrados->toPlainText();
      if(!rot.isEmpty()) {
        int rotar = rot.toInt();
        QTransform r;
        r.rotate(rotar);
        qVecTrans.push_back(r);
      } else {
        QMessageBox msgBox;
        msgBox.setText("Favor de determinar el angulo");
        msgBox.exec();
      }
    update();
}
