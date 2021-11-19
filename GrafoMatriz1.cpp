#include <iostream>
#include <unordered_map>
using namespace std;

template <class T>
class Graph{
	unordered_map<T,int> ids;
	int **matriz;
	//vector<vector<int>> matriz
	int cantidad=0;
	int maximo;
	
	public:
	Graph(int N){
		maximo=N;
		matriz= new int*[N];
		for(int col=0; col<N; col++){
			matriz[col]=new int[N];
			for(int filas=0; filas<N; filas++){
				matriz[col][filas]=0;
			}
		}
		
	}
	
	void agregarNodo(string id){
		ids[id]=cantidad;
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
	Graph<string> g(5);
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