#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Record{
	public:
	string nombreFuente;
	int puertoFuente;
	
	Record(string nF, string pF){
		this->nombreFuente=nF;
		if(pF=="-"){
			this->puertoFuente=0;
		}else{
			this->puertoFuente=stoi(pF);
		}
		
	}
	
	void imprimirRecord(){
		cout<<nombreFuente<<":"<<puertoFuente<<endl;
	}
};

vector<Record> data;
void cargarDatos(string path){
	ifstream in;
	in.open(path);
	string line, parte;
	vector<string> partes;
	while(getline(in, line)){
		if(line.find("\r")!=line.npos){
				line=line.substr(0, line.size()-1);
		}
		istringstream inString(line);
		while(getline(inString, parte, ',')){
			partes.push_back(parte);
		}
		Record r(partes[4], partes[3]);
		data.push_back(r);
		partes.clear();
	}
	in.close();
}

int compararRecordNombreFuente(Record r, string nF){
	if(r.nombreFuente<nF){
		return -1;
	}else if (r.nombreFuente==nF){
		return 0;
	}else{
		return 1;
	}
}

int compararDosRecordsNombreFuente(Record r1, Record r2){
	if(r1.nombreFuente<r2.nombreFuente){
		return -1;
	}else if (r1.nombreFuente==r2.nombreFuente){
		return 0;
	}else{
		return 1;
	}
}

template <class T, class B>
int busquedaSecuencial(vector<T> a, B buscado, int comparador(T a, B b)){
	for(int i=0; i<a.size(); i++){
		if(comparador(a[i],buscado)==0){
			return i;
		}
	}
	return -1;
}


template <class T>
class Sorter{
	public:
	virtual void Sort(vector<T> &data, int comparador(T a, T b))=0;
	
	void Imprimir(vector<T> &data){
		for(int i=0; i<data.size(); i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
	
	void Intercambiar(vector<T> &data, int posI, int posJ){
		T temp=data[posI];
		data[posI]=data[posJ];
		data[posJ]=temp;
	}
};


template <class T>
class SelectionSort: public Sorter<T>{
	public:
	void Sort(vector<T> &data, int comparador(T a, T b)){
		for(int i=0; i<data.size()-1; i++){
			int minimo=i;
			for(int j=i+1; j<data.size(); j++){
				if(comparador(data[j],data[minimo])==-1){
					minimo=j;
				}
			}
			this->Intercambiar(data, i, minimo);
		}
	}
};

int main(){
	cargarDatos("/mnt/c/dr/reto/datosEquipo0.csv");
	
	int pos=busquedaSecuencial<Record, string>(data, "samuel.reto.com", compararRecordNombreFuente);
	cout<<"samuel.reto.com se encuentra en la posicion: "<<pos<<endl;
	SelectionSort<Record> s;
	s.Sort(data, compararDosRecordsNombreFuente);
	for(int i=0; i<100; i++){
		data[i].imprimirRecord();
	}
}