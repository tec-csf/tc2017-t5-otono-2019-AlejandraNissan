#ifndef POLIGONO_H
#define POLIGONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
namespace Ui {
class poligono;
}

class poligono : public QDialog
{
    Q_OBJECT

public:
    explicit poligono(QWidget *parent = 0);
    ~poligono();

protected:
     void paintEvent(QPaintEvent *e);
     void drawPoligono(int lados, int rad,QPainter &painter);

private:
    Ui::poligono *ui;
    bool draw = false;
    int lados, radio;
    double centroX, centroY;
    QVector<QTransform> qVecTrans;

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();
};

#endif // POLIGONO_H
