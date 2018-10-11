#include <iostream>
#include <stdio.h>    
#include <stdlib.h>
#include <string>
#include <stack> 
using namespace std;
#include "lista.h"

int main(int argc, char const *argv[])
{
	//declaracion de variables
	nodo* lista=NULL;	
	reg registro;
	string estado,estSiguiente,eleccion_1,eleccion_2;
	int j=1,bol=0,cont=0;
	string simbolo,simPila,agregarpila,palabra;
	//se ingresan las transiciones
	cout<<"ingrese cantidad de transiciones"<<endl;
	cin>>j;
	for(int h=0;h<j;h++){
		cin>>estado>>simbolo>>simPila>>estSiguiente>>agregarpila;
		agregarlist(&lista,estado,simbolo,simPila,estSiguiente,agregarpila);
	}
	//estado inicial
	cout<<"ingrese estado inicial"<<endl;
	string aux;
	cin>>aux;
	stack <string> mystack;
	
	cout<<"ingrese un 0 si desea por stack vacio o un 1 si desea por estado final"<<endl;
	cin>>eleccion_1;
	if (eleccion_1=="1")
	{
		cout<<"ingrese estado final"<<endl;
		cin>>eleccion_2;
		
	}
	cout<<"cuantas palabras desea ingresar?"<<endl;
	int la;
	cin>>la;
	
	for (int i = 0; i < la; ++i)
	{
		registro.estadoActual=aux;
		mystack.push("R");
		cout<<"ingrese palabra a leer"<<endl;
		cin>>palabra;
		palabra+="e";
		bol=0;
		cont=0;
		//se lee la palabra
		while(bol==0 && cont<palabra.length()){
			registro.simbolo_leer=palabra[cont];
			cont++;
			bol=actualizar_estado(lista,&mystack,&registro);
		}
		if (bol==1)
		{
			cout<<"palabra no aceptada por el automata"<<endl<<endl;
		}

		else if (mystack.empty())
		{
			cout<<"palabra aceptada"<<endl<<endl;
		}
		else if (registro.estadoActual==eleccion_2) cout<<"palabra aceptada por estado final"<<endl<<endl;
		vaciar_stack(&mystack);
	}
	
	return 0;


}