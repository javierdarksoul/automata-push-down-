#include "mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //Q_INIT_RESOURCE( graphlib );
    MainWindow w;

    //inicializa la lista enlazada
    w.crear();
    w.setWindowIcon( QIcon( ":/images/gato.png" ) );
    w.show();
    return a.exec();
}
