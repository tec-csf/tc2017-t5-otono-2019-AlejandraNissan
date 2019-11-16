#include "cubo.h"
#include "ui_cubo.h"
#include <QPainter>
#include <QMessageBox>
#include <math.h>

cubo::cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cubo)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

cubo::~cubo()
{
    delete ui;
}

void cubo::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    if (draw){
        for(int i=0; i<qVecTrans.size(); ++i){
            painter.setTransform(qVecTrans[i],true);
            drawCubo(painter);
        }
    }
}

void cubo::drawCubo(QPainter &painter){
        painter.drawLine(-40, 40, 40, 40);
        painter.drawLine(-40, 40, -40, -40);
        painter.drawLine(40, 40, 40, -40);
        painter.drawLine(-40, -40, 40, -40);
        painter.drawLine(0, 0, 80, 0);
        painter.drawLine(0, 0, 0, -80);
        painter.drawLine(80, 0, 80, -80);
        painter.drawLine(0, -80, 80, -80);
        painter.drawLine(-40, 40, 0, 0);
        painter.drawLine(40, 40, 80, 0);
        painter.drawLine(-40, -40, 0, -80);
        painter.drawLine(40, -40, 80, -80);
}


void cubo::on_pushButton_clicked()
{
    //Dibujar
    qVecTrans.clear();
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
    draw = !draw;
    update();
}

void cubo::on_pushButton_2_clicked()
{
    //Trasladar
    QString x = ui->boxXinicio->toPlainText();
    QString y = ui->boxYinicio->toPlainText();
     if(!x.isEmpty() && !y.isEmpty()) {
       int xS = x.toInt();
       int yS = y.toInt();
       QTransform t;
       t.translate(xS, yS);
       qVecTrans.push_back(t);
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de elegir traslacion");
       msgBox.exec();
     }
     update();
}

void cubo::on_pushButton_4_clicked()
{
    //Zoom In
    QTransform zIn;
    zIn.scale(2,2);
    qVecTrans.push_back(zIn);
    update();
}

void cubo::on_pushButton_5_clicked()
{
    //Zoom Out
    QTransform zOut;
    zOut.scale(0.5,0.5);
    qVecTrans.push_back(zOut);
    update();
}

void cubo::on_pushButton_7_clicked()
{
    //Refl Vertical
    QTransform rv;
    rv.scale(1,-1);
    qVecTrans.push_back(rv);
    update();
}

void cubo::on_pushButton_6_clicked()
{
    //Refl Horizontal
    QTransform rh;
    rh.scale(-1,1);
    qVecTrans.push_back(rh);
    update();
}

void cubo::on_pushButton_3_clicked()
{
    //Rotar
    QString r = ui->boxGrados->toPlainText();
      if(!r.isEmpty()) {
        int rS = r.toInt();
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
