#ifndef ARCO_H
#define ARCO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QPainter>

namespace Ui {
class arco;
}

class arco : public QDialog
{
    Q_OBJECT

public:
    explicit arco(QWidget *parent = 0);
    ~arco();
protected:
     void paintEvent(QPaintEvent *e);
     void drawArco(QPainter &painter);

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();

private:
    Ui::arco *ui;
    bool draw = false;
    double centroX, centroY;
    QVector<QTransform> qVecTrans;
};

#endif // ARCO_H
