#ifndef Lista_h
#define Lista_h
#include "Nodo.h"
#include<iostream>
template <class elemento>
class Lista{
	private:
		int longitud;	
		Nodo<elemento> *primero;
		Nodo<elemento> *ultimo;
	public:
		Lista();//listo
		Lista(const Lista<elemento> &lista);//falla se borra la lista a copiar
		void copiar(const Lista<elemento> &lista);//listo
		bool esVacia();//listo
		bool esta(elemento e);//listo
		elemento consultar(int pos);//listo
		void insertarPrimero(elemento e);//listo
		void insertarUltimo(elemento e);//listo
		void insertar(elemento e,int pos);//listo
		void eliminar(int pos);//listo
		void eliminarElemento(elemento e);//falta
		void modificar(elemento e, int pos);//listo
		void invertir();//listo
		void mergeSort();//listo
		Nodo<elemento>* merge(Lista<elemento>& mitad1, Lista<elemento>& mitad2);
		void burbuja();
		Nodo<elemento>* particion(Nodo<elemento>* inicio, Nodo<elemento>* fin);
		void quickSortAux(Nodo<elemento>* inicio, Nodo<elemento>* fin);
		void quickSort();
		void vaciar();//listo
		void concatenar(const Lista<elemento> &lista1,const Lista<elemento> &lista2,Lista<elemento> *result);
		//getters 
		int getLongitud();//listo
		Nodo<elemento>* getPrimero();//listo
		Nodo<elemento>* getUltimo();//listo
		~Lista();
		// Operadores
		Lista<elemento>& operator =(const Lista<elemento> &lista);
		//Lista<elemento>& operator &(const Lista<elemento> &lista);
		
};
#endif
