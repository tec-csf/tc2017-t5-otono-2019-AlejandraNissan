#ifndef CONO_H
#define CONO_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
namespace Ui {
class cono;
}

class cono : public QDialog
{
    Q_OBJECT

public:
    explicit cono(QWidget *parent = 0);
    ~cono();
protected:
     void paintEvent(QPaintEvent *e);
     void drawCono(QPainter &painter, int altura);

private:
    Ui::cono *ui;
    bool draw = false;
    int altura;
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

#endif // CONO_H
