#ifndef Cola_h
#define Cola_h
#include "Nodo.h"
template <class elemento>
class Cola{
	private:
		Nodo<elemento> *ultimo;
		Nodo<elemento> *primero;
		int longitud;
	public:
		Cola();
		Cola(const Cola<elemento> &cola);
		void copia(const Cola<elemento> &cola);
		void desencolar();
		void encolar(elemento e);
		elemento frente();
		bool esVacia();
		//void vaciar();
};
#endif 
