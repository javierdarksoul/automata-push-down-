#ifndef LISTA_H
#define LISTA_H
#include "mainwindow.h"

//funcion que asigna espacio de memoria a los nodos de la lista enlazada
nodo* crear_nodo(){
    nodo* q=new nodo();
    return q;
}

//funcion que permite añadir una transicion a la lista enlazada
void agregarlist(nodo** p,string a,string b,string c,string d,string e){

    nodo* q= crear_nodo();
    q->estado=a;
    q->simbolo=b;
    q->simPila=c;
    q->estSiguiente=d;
    q->agregarpila=e;
    if((*p)==NULL){
        (*p)=q;
        (*p)->next=NULL;
    }
    else{
        q->next=(*p);
        (*p)=q;
    }
}


//funcion que vacia el stack
void vaciar_stack(stack <string> *mystack){
    while(!(*mystack).empty()){
        (*mystack).pop();
    }
}

//funcion que se encarga de actualizar el registro del APD, leyendo un simbolo
int actualizar_estado(nodo *lista, stack <string> *mystack,reg *registro){
    while(lista!=NULL){
        if((*registro).estadoActual==lista->estado && (*registro).simbolo_leer==lista->simbolo && (*mystack).top()==lista->simPila){
            (*registro).estadoActual=lista->estSiguiente;
            if(lista->agregarpila=="e"){
                if(!(*mystack).empty()){

                    (*mystack).pop();
                }
            }
            else if(lista->agregarpila.length()==1){
                return 0;

            }
            else{
                string bb;
                for(int x=(lista->agregarpila.length())-2;x>=0;x--){
                    bb=lista->agregarpila[x];
                    (*mystack).push(bb);
                }
            }
            return 0;
        }
        lista=lista->next;
    }
    return 1;

}
#endif // JJ_H
