#include "Lista.h"
#include<iostream>
template <class elemento>
Lista<elemento>::Lista(){
	this->primero = NULL;
	this->ultimo = NULL;
	this->longitud = 0;
}


template <class elemento>
Lista<elemento>::Lista(const Lista<elemento> &lista){
	this->longitud =lista.longitud;
	this->primero = NULL;
	this->ultimo = NULL;
	this->copiar(lista);
}


template <class elemento>
bool Lista<elemento>::esVacia(){
	bool res;
	if(this->longitud < 1  ){
		res = true;
	}else{
		res = false;
	}
	return res;
}


template <class elemento>
bool Lista<elemento>::esta(elemento e){
	bool res = false;
	Nodo<elemento> *actual;
	actual = this->primero;
	if(e == actual->getInfo()){
		res = true;
	}else{
		while((actual != NULL) && !res){
			if(e == actual->getInfo()){
				res = true;
			}else{
				actual = actual->getSiguiente();
			}
		}	
	}
	return res;
}


template <class elemento>
elemento Lista<elemento>::consultar(int pos){
	elemento res;
	int cont = 1;
	Nodo<elemento> *actual;
	actual = this->primero;
	if( pos == 1){
		res = actual->getInfo();
	}else{
		cont = 2;
		actual = actual->getSiguiente();
		while(cont <pos){
			actual = actual->getSiguiente();
			cont++;	
		}
		if(cont == pos){
			res = actual->getInfo();
		}
		
	}
	return res;
}


template <class elemento>
void Lista<elemento>::insertar(elemento e,int pos){
	int cont = 1;
	Nodo<elemento> *anterior,*actual = new Nodo<elemento>(e),*siguiente;
	anterior = this->primero;
	if(pos == 1){
		if(this->longitud < 1){
			this->primero = actual;
			this->ultimo = actual;
		}else{
			actual->setSiguiente(anterior);
			this->primero = actual;
		}
	}else{
		cont = 2;
		siguiente = anterior->getSiguiente();
		while(cont <pos){
			anterior = siguiente;
			siguiente = siguiente->getSiguiente();
			cont++;	
		}
		if(cont == pos){
			actual->setSiguiente(siguiente);
			anterior->setSiguiente(actual);
		}
		if(actual->getSiguiente() == NULL){
				this->ultimo = actual;
		}
		
	}
	this->longitud++;
}


template <class elemento>
void Lista<elemento>::eliminar(int pos){
	int cont = 1;
	Nodo<elemento> *anterior,*actual,*siguiente;
	anterior = this->primero;
	if( pos == 1){
		this->primero = anterior->getSiguiente();
		delete anterior;
	}else{
		cont = 2;
		actual = anterior;
		siguiente = anterior->getSiguiente();
		while(cont < pos){
			anterior = siguiente;
			siguiente = siguiente->getSiguiente();
			cont++;	
		}
		if(cont == pos){
			actual = anterior->getSiguiente();
			anterior->setSiguiente(siguiente);
			delete actual;
		}
	}
	if(siguiente == NULL){
			this->ultimo = anterior;
	}
	this->longitud--;
}


/*
template <class elemento>
void Lista<elemento>::eliminarElemento(elemento e){
	int cont = 1;
	Nodo<elemento> *anterior,*actual,*siguiente;
	anterior = this->primero;
	if( anterior->getInfo() == e){
		this->primero = anterior->getSiguiente();
		delete anterior;
	}else{
		cont = 2;
		actual = anterior;
		siguiente = anterior->getSiguiente();
		while(cont < pos){
			anterior = siguiente;
			siguiente = siguiente->getSiguiente();
			cont++;	
		}
		if(cont == pos){
			actual = anterior->getSiguiente();
			anterior->setSiguiente(siguiente);
			delete actual;
		}
	}
	if(siguiente == NULL){
				this->ultimo = anterior;
		}
	this->longitud--;
}*/


template <class elemento>
void Lista<elemento>::modificar(elemento e,int pos){
	int cont = 1;
	Nodo<elemento> *anterior,*siguiente;
	anterior = this->primero;
	if(pos == 1){
		anterior->setInfo(e);
	}else{
		cont = 2;
		siguiente = anterior->getSiguiente();
		while(cont <pos){
			anterior = siguiente;
			siguiente = siguiente->getSiguiente();
			cont++;	
		}
		if(cont == pos){
			anterior->setInfo(e);
		}
	}
}


template <class elemento>
void Lista<elemento>::insertarPrimero(elemento e){
	Nodo<elemento> *info,*actual;
	info = new Nodo<elemento>(e);
	if(this->longitud < 1){
		this->primero = info;
		this->ultimo = info;
	}else{
		actual = this->primero;
		actual->setSiguiente(info);
		this->primero = info;
	}
	this->longitud++;
}	


template <class elemento>
void Lista<elemento>::insertarUltimo(elemento e){
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
void Lista<elemento>::vaciar(){
	Nodo<elemento>	*anterior,*actual;
	anterior = NULL;
	actual = this->primero;
	while(actual != NULL ){
		anterior = actual;
		actual = actual->getSiguiente();
		delete anterior;
	}
	this->longitud = 0;
}


template <class elemento>
void Lista<elemento>::invertir(){
	Nodo<elemento> *actual,*prev,*siguiente;
	actual = this->primero;
	this->ultimo = actual;
	while(actual != NULL){
		siguiente = actual->getSiguiente();
		actual->setSiguiente(prev);
		prev = actual;
		actual = siguiente;
	}
	this->primero = prev;
}
	//getters
template <class elemento>	
Nodo<elemento>*	Lista<elemento>::getPrimero(){
		return(this->primero);
}template <class elemento>	


Nodo<elemento>*	Lista<elemento>::getUltimo(){
		return(this->ultimo);
}

	
template <class elemento>	
int	Lista<elemento>::getLongitud(){
		int	res	=	0;
		res=this->longitud;
		return(res);
}

template <class elemento>
void Lista<elemento>::mergeSort() {
    if (this->primero == NULL || this->primero->getSiguiente() == NULL) {
        // La lista está vacía o tiene solo un elemento, no hay nada que ordenar
        return;
    }

    // Dividir la lista en dos mitades
    Nodo<elemento>* lento = this->primero;
    Nodo<elemento>* rapido = this->primero->getSiguiente();
    while (rapido != NULL && rapido->getSiguiente() != NULL) {
        lento = lento->getSiguiente();
        rapido = rapido->getSiguiente()->getSiguiente();
    }

    Nodo<elemento>* mitad = lento->getSiguiente();
    lento->setSiguiente(NULL); // Separar las dos mitades

    // Ordenar las dos mitades recursivamente
    Lista<elemento> primeraMitad;
    primeraMitad.primero = this->primero;
    primeraMitad.mergeSort();

    Lista<elemento> segundaMitad;
    segundaMitad.primero = mitad;
    segundaMitad.mergeSort();

    // Combinar las dos mitades ordenadas
    this->primero = merge(primeraMitad, segundaMitad);
    Nodo<elemento>* aux = this->primero;
    while (aux->getSiguiente() != NULL) {
        aux = aux->getSiguiente();
    }
    this->ultimo = aux;
}

template <class elemento>
Nodo<elemento>* Lista<elemento>::merge(Lista<elemento>& mitad1, Lista<elemento>& mitad2) {
    Nodo<elemento>* temp = NULL;
    Nodo<elemento>* curr = temp;
    Nodo<elemento>* result = NULL;

    // Combinar las dos mitades ordenadas en una sola lista ordenada
    while (mitad1.primero != NULL && mitad2.primero != NULL) {
        if (mitad1.primero->getInfo() < mitad2.primero->getInfo()) {
            if (temp == NULL) {
                temp = mitad1.primero;
                curr = temp;
                result = temp; // Almacenar el inicio de la lista ordenada
                mitad1.primero = mitad1.primero->getSiguiente();
            } else {
                curr->setSiguiente(mitad1.primero);
                curr = curr->getSiguiente();
                mitad1.primero = mitad1.primero->getSiguiente();
            }
        } else {
            if (temp == NULL) {
                temp = mitad2.primero;
                curr = temp;
                result = temp; // Almacenar el inicio de la lista ordenada
                mitad2.primero = mitad2.primero->getSiguiente();
            } else {
                curr->setSiguiente(mitad2.primero);
                curr = curr->getSiguiente();
                mitad2.primero = mitad2.primero->getSiguiente();
            }
        }
    }

    // Agregar los nodos restantes de la mitad no vacía
    if (mitad1.primero != NULL) {
        curr->setSiguiente(mitad1.primero);
        while (mitad1.primero != NULL) {
            curr = curr->getSiguiente();
            mitad1.primero = mitad1.primero->getSiguiente();
        }
    } else if (mitad2.primero != NULL) {
        curr->setSiguiente(mitad2.primero);
        while (mitad2.primero != NULL) {
            curr = curr->getSiguiente();
            mitad2.primero = mitad2.primero->getSiguiente();
        }
    }

    return result;
}

template <class elemento>
void Lista<elemento>::burbuja() {
    if (this->primero == NULL || this->primero->getSiguiente() == NULL) {
        // La lista está vacía o solo tiene un elemento, ya está ordenada
        return;
    }

    bool intercambiado;
    Nodo<elemento>* actual;
    Nodo<elemento>* siguiente = NULL;

    do {
        intercambiado = false;
        actual = this->primero;

        while (actual->getSiguiente() != siguiente) {
            if (actual->getInfo() > actual->getSiguiente()->getInfo()) {
                // Intercambiar los elementos
                elemento temp = actual->getInfo();
                actual->setInfo(actual->getSiguiente()->getInfo());
                actual->getSiguiente()->setInfo(temp);
                intercambiado = true;
            }
            actual = actual->getSiguiente();
        }
        siguiente = actual;
    } while (intercambiado);
}

template <class elemento>
void Lista<elemento>::quickSort() {
    // Llamada a la función auxiliar para realizar el Quick Sort
    quickSortAux(this->primero, this->ultimo);
}

template <class elemento>
void Lista<elemento>::quickSortAux(Nodo<elemento>* inicio, Nodo<elemento>* fin) {
    if (inicio != NULL && fin != NULL && inicio != fin) {
        Nodo<elemento>* pivote = particion(inicio, fin);
        quickSortAux(inicio, pivote);
        quickSortAux(pivote->getSiguiente(), fin);
    }
}

template <class elemento>
Nodo<elemento>* Lista<elemento>::particion(Nodo<elemento>* inicio, Nodo<elemento>* fin) {
    // Tomamos el último elemento como pivote
    elemento pivote = fin->getInfo();
    Nodo<elemento>* i = inicio->getAnterior(); // Inicializamos i al anterior de inicio
    for (Nodo<elemento>* j = inicio; j != fin; j = j->getSiguiente()) {
        if (j->getInfo() <= pivote) {
            i = (i == NULL) ? inicio : i->getSiguiente();
            // Intercambiamos i y j
            elemento temp = (i == NULL) ? this->primero->getInfo() : i->getInfo();
            if (i != NULL) i->setInfo(j->getInfo());
            j->setInfo(temp);
        }
    }
    // Movemos i al siguiente elemento
    i = (i == NULL) ? inicio : i->getSiguiente();

    // Intercambiamos i y fin
    elemento temp = (i == NULL) ? this->primero->getInfo() : i->getInfo();
    if (i != NULL) i->setInfo(fin->getInfo());
    fin->setInfo(temp);

    return i;
}




template <class elemento>
void Lista<elemento>::copiar(const Lista<elemento> &lista) {
    Nodo<elemento> *nuevoNodo, *actual;
    actual = lista.primero;
    this->vaciar(); 
    if (lista.longitud != 0) {
        this->primero = new Nodo<elemento>(actual->getInfo());
        this->ultimo = this->primero;
        actual = actual->getSiguiente();
        while (actual != NULL) {
            nuevoNodo = new Nodo<elemento>(actual->getInfo());
            this->ultimo->setSiguiente(nuevoNodo);
            this->ultimo = nuevoNodo;
            actual = actual->getSiguiente();
        }
    } else {
        this->primero = NULL;
        this->ultimo = NULL;
    }
    
    this->longitud = lista.longitud;
}


template <class elemento>
Lista<elemento>::~Lista(){
	this->vaciar();
}
//OPERADORES

template <class elemento>
Lista<elemento>& Lista<elemento>::operator=(const Lista<elemento> &lista) {
	if (this != &lista) { 
        while (!this->esVacia()) {
            this->vaciar();
        }
        this->copiar(lista);
    }
    return *this;
}
/*
template <class elemento>
void Lista<elemento>::concatenar(const Lista<elemento> &lista1,const Lista<elemento> *lista2,Lista<elemento> &result){ 
	while ((lista1.esVacia()) && (lista2.esVacia())) {
        if((lista1.consultar(1)) > (lista2.consulta(1))){
        	*result.insertarUltimo(lista1.consultar(1));
        	lista1.eliminar(1);
		}else{
			if((lista1.consultar(1)) == (lista2.consulta(1))){
				*result.insertarUltimo(lista1.consultar(1));
				lista2.eliminar(1);
				lista1.eliminar(1);
			}else{
				lista2.eliminar(1);
			}
		}
    }
	while(lista1.esVacia()){
		*result.insertarUltimo(lista1.consultar(1));
		lista1.eliminar(1);
	}
	while(lista2.esVacia()){
		*result.insertarUltimo(lista2.consultar(1));
		lista2.eliminar(1);
	}
}*/
