#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}

/*
 Instructivo:
 Para poder utilizar la aplicación se deben de bajar los archivos en el programa QT, presionar en el botón play para que se compile y se corra
 el programa.
Primeramente se abrirá una ventana con las distintas figuras con las que se cuentan, cada una lleva a otra pantalla que permite
 realizarle distintas funciones a la figura y poder verlo reflejado graficamente en pantalla.
 Para continuar con otra figura, favor de cerrar la ventana de la figura actual y presionar otra. Además, para comenzar un nuevo dibujo de la
 misma figura se vuelve a presionar dibujar y se borrará la figura actual para poder volver a comenzar.
*/


//https://doc.qt.io/archives/qt-5.5/qpainter.html
//https://www.youtube.com/watch?v=5JE5ek_oN_0
