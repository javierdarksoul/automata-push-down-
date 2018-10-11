#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>
using namespace std;

//estructura de la lista enlazada
typedef struct nodo{
    string estado;
    string simbolo;
    string simPila;
    string estSiguiente;
    string agregarpila;
    struct nodo *next;
}nodo;

//estructura del registro
typedef struct reg{

    string estadoActual;
    string simbolo_leer;
}reg;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void crear();
    void agregar();
    void lectura();
    ~MainWindow();

     string estado,simbolo,simPila,estSiguiente,agregarpila,palabra,ini,final;
     nodo *lista;
     stack <string> mystack;
     reg registro;
     int vacio_final,bol,cont;


private slots:
    void on_pushButton_clicked();
    void on_radioButton_2_clicked(bool checked);
    void on_radioButton_clicked();
    void on_botonA_clicked();
    void on_pushButton_3_clicked();
    void on_botonB_clicked();
    //void on_radioButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
