using namespace std;
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lista.h"
#include <string>

//funcion que asigna NULL a la lista
void MainWindow::crear(){
    lista=NULL;
}

//funcion que agrega una transicion a la lista a traves de la funcion agregarlist de la cabecera jj.h
void MainWindow::agregar(){
    agregarlist(&lista,estado,simbolo,simPila,estSiguiente,agregarpila);
}

//funcion que lee la palabra utilizando la funcion "actualizar_estado" de la cabecera jj.h ,
void MainWindow::lectura(){
    mystack.push("R");
    int largo;
    registro.estadoActual=ini;
    bol=0;
    cont=0;
    //se lee la palabra
    largo=palabra.length();

    //si no se encuentra la transicion, retorna un 1, se sale del while y rechaza automaticamente la palabra
    while(bol==0 && cont<largo){
        registro.simbolo_leer=palabra[cont];
        cont++;
        bol=actualizar_estado(lista,&mystack,&registro);
    }
    palabra.pop_back();
    string word="palabra '"+palabra+"' pertenece al lenguaje";
    string word2="palabra '"+palabra+"' NO pertenece al lenguaje";
    if(bol==1) ui->output->setText( QString::fromStdString(word2));
    else if(vacio_final==1 && final==registro.estadoActual) ui->output->setText( QString::fromStdString(word));
    else if(vacio_final==0 && mystack.empty()) ui->output->setText( QString::fromStdString(word));
    vaciar_stack(&mystack);
}

//constructor de la interfaz grafica
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->linF->setDisabled(true);
    ui->lineEdit->setDisabled(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}


//a continuacion se presentan eventos al presionar un botones


void MainWindow::on_pushButton_clicked()
{
    QString a= ui->estado->text();
    QString b= ui->simbolo->text();
    QString c= ui->simPila->text();
    QString d= ui->estSig->text();
    QString e= ui->addPila->text();
    QString pri="d("+a+","+b+","+c+")=("+d+","+e+")";
    estado=a.toStdString();
    simbolo=b.toStdString();
    simPila=c.toStdString();
    estSiguiente=d.toStdString();
    agregarpila=e.toStdString();
    ui->estado->setText("");
    ui->simbolo->setText("");
    ui->simPila->setText("");
    ui->estSig->setText("");
    ui->addPila->setText("");
    agregar();
    ui->textedit->appendPlainText(pri);
}


void MainWindow::on_radioButton_2_clicked(bool checked)
{
    ui->botonA->setEnabled(checked);
    ui->linF->setEnabled(checked);

}
void MainWindow::on_radioButton_clicked()
{
    ui->botonA->setEnabled(false);
    ui->linF->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    vacio_final=0;
}
void MainWindow::on_botonA_clicked()
{
    vacio_final=1;
    ui->in2->setText(ui->linF->text());
    ui->pushButton_3->setEnabled(true);
    ui->lineEdit->setEnabled(true);
    final=(ui->linF->text()).toStdString();
    ui->linF->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    QString b=ui->lineEdit->text();
    palabra=b.toStdString();
    palabra=palabra+"e";
    ui->lineEdit->setText("");
    lectura();
}

void MainWindow::on_botonB_clicked()
{
    ini=(ui->lineEdit_2->text()).toStdString();
    ui->in->setText(ui->lineEdit_2->text());
    ui->lineEdit_2->setText("");
}
