#include "prismaRectangular.h"
#include "ui_prismaRectangular.h"
#include <QPainter>
#include <QMessageBox>

prismaRectangular::prismaRectangular(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prismaRectangular)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

prismaRectangular::~prismaRectangular()
{
    delete ui;
}


void prismaRectangular::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    if (draw){
        for(int i=0; i<qVecTrans.size(); ++i){
            painter.setTransform(qVecTrans[i],true);
            drawPrismaRectangular(painter);
        }
    }
}

void prismaRectangular::drawPrismaRectangular(QPainter &painter){
     painter.drawLine(0,100,60,0);
     painter.drawLine(60,0,160,0);
     painter.drawLine(60,-300,60,0);

     painter.drawLine(100,100,160,0);
     painter.drawLine(0,-200,60,-300);
     painter.drawLine(100,-200,160,-300);
     painter.drawLine(0,100,100,100);
     painter.drawLine(0,-200,100,-200);
     painter.drawLine(0,-200,0,100);
     painter.drawLine(100,-200,100,100);
     painter.drawLine(60,-300,160,-300);
     painter.drawLine(160,-300,160,0);

}
void prismaRectangular::on_pushButton_clicked()
{
    //Dibujar
    qVecTrans.clear();
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
    draw = !draw;
    update();
}

//Traslación
void prismaRectangular::on_pushButton_2_clicked()
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

void prismaRectangular::on_pushButton_4_clicked()
{
    //Zoom In
    QTransform zoomIn;
    zoomIn.scale(2,2);
    qVecTrans.push_back(zoomIn);
    update();
}

void prismaRectangular::on_pushButton_5_clicked()
{
    //Zoom Out
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    qVecTrans.push_back(zoomOut);
    update();
}

//Reflexion Vertical
void prismaRectangular::on_pushButton_7_clicked()
{
    QTransform reflexionVertical;
    reflexionVertical.scale(1,-1);
    qVecTrans.push_back(reflexionVertical);
    update();
}

//Reflexion Horizontal
void prismaRectangular::on_pushButton_6_clicked()
{
    QTransform reflexionHorizontal;
    reflexionHorizontal.scale(-1,1);
    qVecTrans.push_back(reflexionHorizontal);
    update();
}

//Rotacion
void prismaRectangular::on_pushButton_3_clicked()
{
    QString rot = ui->boxGrados->toPlainText();
      if(!rot.isEmpty()) {
        int rS = rot.toInt();
        QTransform r;
        r.rotate(rS);
        qVecTrans.push_back(r);
      } else {
        QMessageBox msgBox;
        msgBox.setText("Favor de elegir angulo");
        msgBox.exec();
      }
    update();
}
