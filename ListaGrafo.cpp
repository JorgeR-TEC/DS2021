#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

template <class T>
class Nodo{
	public:
	T id;
	unordered_map<Nodo<T> *, int> siguientes;
	
	Nodo(T id){
		this->id=id;
	}
	
	void agregarArcoConPeso(Nodo<T> *sig, int peso){
		siguientes[sig]=peso;
	}
	
	void imprimirNodo(){
		cout<<this->id<<":";
		for(auto it=siguientes.begin(); it!=siguientes.end(); it++){
			cout<<it->first->id<<","<<it->second<<";";
		}
		cout<<endl;
	}
};

template <class T>
class Grafo{
	unordered_map<T,Nodo<T>*> nodos;
	
	public:
	
	void agregarNodo(T id){
		Nodo<T> *nuevo=new Nodo<T>(id);
		nodos[id]=nuevo;
	}
	
	void agregarArcoDirigidoConPeso(T fuente, T destino, int peso){
		if(nodos.find(fuente)!=nodos.end() && nodos.find(destino)!=nodos.end()){
			nodos[fuente]->agregarArcoConPeso(nodos[destino], peso);
		}
	}
	
	void agregarArcoNoDirigidoConPeso(T fuente, T destino, int peso){
		agregarArcoDirigidoConPeso(fuente, destino, peso);
		agregarArcoDirigidoConPeso(destino, fuente, peso);
	}
	
	void imprimir(){
		for(auto it:nodos){
			it.second->imprimirNodo();
		}
	}
	
};


int main(){
	Grafo<string> g;
	g.agregarNodo("CDMX");
	g.agregarNodo("Tijuana");
	g.agregarNodo("Guadalajara");
	g.agregarArcoNoDirigidoConPeso("CDMX", "Guadalajara", 5);
	g.agregarArcoNoDirigidoConPeso("Guadalajara", "Tijuana", 20);
	g.agregarArcoDirigidoConPeso("CDMX", "Tijuana", 50);
	g.imprimir();
	
	return 0;
}