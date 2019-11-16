#include "cono.h"
#include "ui_cono.h"
#include <QPainter>
#include <QMessageBox>
#include <math.h>

cono::cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cono)
{
    ui->setupUi(this);
    centroX = width()/2;
    centroY = height()/2;
    QTransform centro;
    centro.translate(centroX,centroY);
    qVecTrans.push_back(centro);
}

cono::~cono()
{
    delete ui;
}


void cono::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pincel(Qt::blue);
    pincel.setWidth(2);
    painter.setPen(pincel);
    if (draw){
        QString height = ui->boxAltura->toPlainText();
        if(!height.isEmpty()) {
            altura = height.toInt();
            for(int i=0; i<qVecTrans.size(); ++i){
                painter.setTransform(qVecTrans[i],true);
                drawCono(painter,altura);
            }
        }else {
            QMessageBox msgBox;
            msgBox.setText("Favor de determinar la altura del cono");
            msgBox.exec();
        }
    }
}

void cono::drawCono(QPainter &painter, int altura){
    painter.drawEllipse(-50,-25,100,50);
    painter.drawLine(0,altura,50,0);
    painter.drawLine(0,altura,-50,0);
}

void cono::on_pushButton_clicked()
{
    qVecTrans.clear();
    QString height = ui->boxAltura->toPlainText();
     if(!height.isEmpty()) {
       QTransform centro;
       centro.translate(centroX,centroY);
       qVecTrans.push_back(centro);
       draw = !draw;
     } else {
       QMessageBox msgBox;
       msgBox.setText("Favor de determinar la altura");
       msgBox.exec();
     }
     update();
}

//Traslación
void cono::on_pushButton_2_clicked()
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
void cono::on_pushButton_4_clicked()
{
    QTransform zoomIn;
    zoomIn.scale(2,2);
    qVecTrans.push_back(zoomIn);
    update();

}

//Zoom Out
void cono::on_pushButton_5_clicked()
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    qVecTrans.push_back(zoomOut);
    update();

}

//Reflexion Vertical
void cono::on_pushButton_7_clicked()
{
    QTransform reflexionVertical;
    reflexionVertical.scale(1,-1);
    qVecTrans.push_back(reflexionVertical);
    update();

}

//Reflexion Horizontal
void cono::on_pushButton_6_clicked()
{
    QTransform reflexionHorizontal;
    reflexionHorizontal.scale(-1,1);
    qVecTrans.push_back(reflexionHorizontal);
    update();

}

//Rotar
void cono::on_pushButton_3_clicked()
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
