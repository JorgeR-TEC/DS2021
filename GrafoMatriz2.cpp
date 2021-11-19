#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


template <class T>
class Graph{
	unordered_map<T,int> ids;
	vector<vector<int>> matriz;
	int cantidad;
	
	public:
	Graph(){
		cantidad=0;
	}
	
	void agregarNodo(T id){
		ids[id]=cantidad;
		vector<int> nuevaFila;
		for(int fila=0; fila<cantidad; fila++){
			matriz[fila].push_back(0);
			nuevaFila.push_back(0);
		}
		nuevaFila.push_back(0);
		matriz.push_back(nuevaFila);
		cantidad++;
	}
	
	void agregarArcoDirigidoConPeso(T fuente, T destino, int peso){
		if(ids.find(fuente)!=ids.end() && ids.find(destino)!=ids.end()){
			matriz[ids[fuente]][ids[destino]]=peso;
		}
		//ids.find(fuente)->second
		//ids[fuente]	
	}
	
	void agregarArcoConPeso(T fuente, T destino, int peso){
		agregarArcoDirigidoConPeso(fuente,destino,peso);
		agregarArcoDirigidoConPeso(destino,fuente,peso);
	}
	
	void imprimir(){
		for(auto nodo: ids){
			cout<<nodo.first<<":"<<nodo.second<<endl;
		}
		for(int col=0; col<cantidad; col++){
			for(int filas=0; filas<cantidad; filas++){
				cout<<matriz[col][filas]<<",";
			}
			cout<<endl;
		}
	}
	
	
	
	
};

int main(){
	Graph<string> g;
	g.agregarNodo("CDMX");
	g.agregarNodo("Tijuana");
	g.agregarNodo("Guadalajara");
	g.agregarArcoConPeso("CDMX", "Guadalajara", 5);
	g.agregarArcoConPeso("Guadalajara", "Tijuana", 20);
	g.agregarArcoConPeso("CDMX", "Tijuana", 50);
	g.imprimir();
	
	/*unordered_map<string, int> c;
	c["cdmx"]=0;
	pair<string,int> p("tijuana", 1);
	c.insert(p);
	c.insert({"guadalajara", 2});
	cout<<c["cdmx"]<<endl;*/
	
}