#include "Cola.h"
#include<iostream>
template <class elemento>
Cola<elemento>::Cola(){
	this->ultimo = NULL;
	this->primero = NULL;
	this->longitud = 0;
}


template <class elemento>
Cola<elemento>::Cola(const Cola<elemento> &cola){
	this->ultimo = cola.ultimo;
	this->primero = cola.primero;
	this->longitud = cola.longitud;
}

template <class elemento>
void Cola<elemento>::copia(const Cola<elemento> &cola){
	 Nodo<elemento> *temp,*aux,*info;
    if (cola.longitud != 0) {
        temp = cola.ultimo;
        // Copiar el primer nodo
        info = new Nodo<elemento>(temp->getInfo());
        this->ultimo = info;
        aux = this->ultimo;
        temp = temp->getSiguiente();

        // Copiar los nodos restantes
        while (temp != NULL) {
			info = new Nodo<elemento>(temp->getInfo());
            aux->setSiguiente(info);
            aux = aux->getSiguiente();
            temp = temp->getSiguiente();
        }
        this->longitud = cola.longitud;
    }	
}


template <class elemento>
void Cola<elemento>::encolar(elemento e) {
   Nodo<elemento> *info,*actual;
	info = new Nodo<elemento>(e);
	if(this->longitud < 1){
		this->primero = info;
		this->ultimo = info;
	}else{
		actual = this->ultimo;
		actual->setSiguiente(info);
		this->ultimo = info;
	}

	this->longitud++;
}

template <class elemento>
void Cola<elemento>::desencolar() {
    Nodo<elemento>* temp = this->primero;
    if (this->longitud == 1) {
        this->primero = NULL;
    }else{
		this->primero = this->primero->getSiguiente();
		
	}
    delete temp;
    this->longitud--;
}


template <class elemento>
elemento Cola<elemento>::frente(){
	return (this->primero->getInfo());
}


template <class elemento>
bool Cola<elemento>::esVacia(){
	bool res = false;
	if(this->longitud < 1){
		res = true;
	}
	return res;
}
