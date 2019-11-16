#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //Arco
    arco e_arco;
    e_arco.setModal(true);
    e_arco.exec();
}

void Dialog::on_pushButton_2_clicked()
{
    //Poligono
    poligono e_poligono;
    e_poligono.setModal(true);
    e_poligono.exec();
}

void Dialog::on_pushButton_3_clicked()
{
    //Cono
    cono e_cono;
    e_cono.setModal(true);
    e_cono.exec();
}

void Dialog::on_pushButton_4_clicked()
{
    //Cubo
    cubo e_cubo;
    e_cubo.setModal(true);
    e_cubo.exec();
}

void Dialog::on_pushButton_5_clicked()
{
    //Prisma Base Rect
    prismaRectangular e_prismaBaseRectangular;
    e_prismaBaseRectangular.setModal(true);
    e_prismaBaseRectangular.exec();
}

void Dialog::on_pushButton_6_clicked()
{
    //Prisma Base Triangular
    prismaTriangular e_prismaBaseTriangular;
    e_prismaBaseTriangular.setModal(true);
    e_prismaBaseTriangular.exec();
}

