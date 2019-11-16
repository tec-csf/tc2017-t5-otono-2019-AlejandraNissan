#include "arco.h"
#include "ui_arco.h"
#include <QPainter>
#include <QMessageBox>
#include <math.h>

arco::arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arco)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

arco::~arco()
{
    delete ui;
}

void arco::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    if (draw){
        for(int i=0; i<qVecTrans.size(); ++i){
            painter.setTransform(qVecTrans[i],true);
            drawArco(painter);
        }
    }
}

void arco::drawArco(QPainter &painter){
    //painter.drawPoint();
    painter.drawArc(0, 0, 50, 50, 0, 270);
}


void arco::on_pushButton_clicked()
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
void arco::on_pushButton_2_clicked()
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
void arco::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    qVecTrans.push_back(zoomIn);
    update();

}

//Zoom Out
void arco::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    qVecTrans.push_back(zoomOut);
    update();

}

//Reflexion Vertical
void arco::on_pushButton_7_clicked()
{
    QTransform reflexionVertical;
    reflexionVertical.scale(1,-1);
    qVecTrans.push_back(reflexionVertical);
    update();

}

//Reflexion Horizontal
void arco::on_pushButton_6_clicked()
{
    QTransform reflexionHorizontal;
    reflexionHorizontal.scale(-1,1);
    qVecTrans.push_back(reflexionHorizontal);
    update();

}

//Rotar
void arco::on_pushButton_3_clicked()
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
