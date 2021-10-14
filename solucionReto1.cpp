#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
class Record{
	public:
	string fecha;
	string hora;
	string ipFuente;
	int puertoFuente;
	string nombreFuente;
	string ipDestino;
	int puertoDestino;
	string nombreDestino;
	
	Record(string f, string h, string iF, string pF, string nF, string iD, string pD, string nD){
		fecha=f;
		hora=h;
		ipFuente=iF;
		if(pF=="-"){
			puertoFuente=0;
		}else{
			
			try{
				puertoFuente=stoi(pF);
			}catch (const std::invalid_argument& ia){
				puertoFuente=0;
				cout<<"error"<<pD<<endl;
			}
		}
		nombreFuente=nF;
		ipDestino=iD;
		if(pD=="-"){
			puertoDestino=0;
		}else{
			try{
				puertoDestino=stoi(pD);
			}catch (const std::invalid_argument& ia){
				puertoDestino=0;
				cout<<"error"<<pD<<endl;
			}
		}
		nombreDestino=nD;
	}
	
	void imprimirRecord(){
		cout<<nombreFuente<<endl;
	}
};

vector<Record> conexiones;
void leerDatos(string path){
	ifstream fileIn;
	fileIn.open(path);
	string line, partes;
	vector<string> valores;
	while(getline(fileIn, line)){
		istringstream sIn(line);
		while(getline(sIn, partes, ',')){
			valores.push_back(partes);
		}
		if(valores[7].find('\r')!=valores[7].npos){
			valores[7]=valores[7].substr(0, valores[7].size()-1);
		}
		Record r(valores[0], valores[1], valores[2], valores[3], valores[4], valores[5], valores[6], valores[7]);
		conexiones.push_back(r);
		valores.clear();
	}
}




template <class T>
class Sort{
	public:
	virtual void sort(vector<T> &data, int comparador(T a, T b))=0;
	void intercambiar(vector<T> &data, int posI, int posJ){
		T temp=data[posI];
		data[posI]=data[posJ];
		data[posJ]=temp;
	}
	
	void imprimir(vector<T> data){
		for(int i=0; i<data.size(); i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
};


template <class T>
class MergeSort: public Sort<T>{
	
	public:
	void sort(vector<T> &data, int comparador(T a, T b)){
		sortAux(data, 0, data.size()-1, comparador);
	}
	private:
	void sortAux(vector<T> &data, int lo, int hi, int comparador(T a, T b)){
		if(lo>=hi){
			return;
		}
		int mid=(lo+hi)/2;
		sortAux(data, lo, mid, comparador);
		sortAux(data, mid+1, hi, comparador);
		merge(data, lo, mid, hi, comparador);
	}
	
	
	
	void merge(vector<T> &data, int low, int mid, int hi, int comparador(T a, T b)){
	int sizeA=mid-low+1;
	int sizeB=hi-mid;
	vector<T> copiaA;
	vector<T> copiaB;
	
	for(int i=0; i<sizeA; i++){
		copiaA.push_back(data[low+i]);
	}
	
	for(int i=0; i<sizeB; i++){
		copiaB.push_back(data[mid+i+1]);
	}
	
	int indexA=0;
	int indexB=0;
	int indexData=low;
	while(indexA<sizeA&&indexB<sizeB){
		//if(copiaA[indexA]<copiaB[indexB]){
		if(comparador(copiaA[indexA],copiaB[indexB])<0){
			data[indexData]=copiaA[indexA];
			indexA++;
		}else{
			data[indexData]=copiaB[indexB];
			indexB++;
		}
		indexData++;
	}
	
	while(indexA<sizeA){
		data[indexData]=copiaA[indexA];
		indexA++;
		indexData++;
	}
	
	while(indexB<sizeB){
		data[indexData]=copiaB[indexB];
		indexB++;
		indexData++;
	}
}
	
};

int cSortNombreFuente(Record a, Record b){
	if(a.nombreFuente<b.nombreFuente){
		return -1;
	}else if (a.nombreFuente==b.nombreFuente){
		return 0;
	}else{
		return 1;
	}
}

int cSortNombreDestino(Record a, Record b){
	if(a.nombreDestino<b.nombreDestino){
		return -1;
	}else if (a.nombreDestino==b.nombreDestino){
		return 0;
	}else{
		return 1;
	}
}

int cSortPuertoDestino(Record a, Record b){
	if(a.puertoDestino<b.puertoDestino){
		return -1;
	}else if (a.puertoDestino==b.puertoDestino){
		return 0;
	}else{
		return 1;
	}
}

int cSearchNombreFuente(Record a, string b){
	if(a.nombreFuente<b){
		return -1;
	}else if (a.nombreFuente==b){
		return 0;
	}else{
		return 1;
	}
}


int cSearchNombreDestino(Record a, string b){
	if(a.nombreDestino<b){
		return -1;
	}else if (a.nombreDestino==b){
		return 0;
	}else{
		return 1;
	}
}

int cSearchPuertoDestino(Record a, int b){
	if(a.puertoDestino<b){
		return -1;
	}else if (a.puertoDestino==b){
		return 0;
	}else{
		return 1;
	}
}

template <class T, class M>
int busquedaBinaria2(vector<T> a, M buscado, int comparador(T a, M b)){
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0){
			return medio;
		}else if(comparador(a[medio], buscado)<0){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}

template <class T>
int busquedaBinaria(vector<T> a, T buscado, int comparador(T a, T b)){
	int inicio=0;
	int fin=a.size()-1;
	while(fin>=inicio){
		int medio=(inicio+fin)/2;
		if(comparador(a[medio],buscado)==0){
			return medio;
		}else if(comparador(buscado,a[medio])>0){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}

string isPrivate(string ip){
	if(ip=="-"){
		return "-1";
	}
	istringstream sIn(ip);
	string partes="";
	getline(sIn, partes, '.');
	int primerOcteto=stoi(partes);
	if(primerOcteto!=172 & primerOcteto==10 & primerOcteto==192){
		return "-1";
	}
	getline(sIn, partes, '.');
	int segundoOcteto=stoi(partes);
	if((segundoOcteto==172 && (segundoOcteto<16 || segundoOcteto>32)) || (segundoOcteto==192 && segundoOcteto!=168)){
		return "-1";
	}
	getline(sIn, partes, '.');
	string ipPrivada=to_string(primerOcteto)+"."+to_string(segundoOcteto)+"."+partes+".0";
	return ipPrivada;
}

int main(){
	leerDatos("/mnt/c/dr/reto/datosEquipo14.csv");
	cout<<"Datos leidos"<<endl;
	//primera pregunta
	cout<<"Cantidad de datos: "<<conexiones.size()<<endl;
	//segunda pregunta
	int cantidadSegundoDia=0;
	string fecha=conexiones[0].fecha;
	int i=0;
	while(conexiones[i].fecha==fecha){
		i++;
	}
	fecha=conexiones[i].fecha;
	while(conexiones[i].fecha==fecha){
		i++;
		cantidadSegundoDia++;
	}
	cout<<"Datos en segundo día: "<<cantidadSegundoDia<<endl;
	//cuarta pregunta
	string ipPrivada=isPrivate(conexiones[0].ipFuente);
	i=1;
	while(ipPrivada=="-1"){
		ipPrivada=isPrivate(conexiones[i].ipFuente);
		i++;
	}
	cout<<"La dirección de la red es: "<<ipPrivada<<endl;
	
	//tercera pregunta
	MergeSort<Record> s;
	s.sort(conexiones, cSortNombreFuente);
	string nombres[8]={"jeffrey", "betty", "katherine", "scott", "benjamin", "samuel", "raymond", "server"};
	int pos=-1;
	string buscar="";
	for(i=0; i<8; i++){
		buscar=nombres[i]+".reto.com";
		pos=busquedaBinaria2(conexiones, buscar, cSearchNombreFuente);
		if(pos!=-1){
			cout<<nombres[i]<<" encontrado"<<endl;
		}
	}
	//quinta pregunta
	s.sort(conexiones, cSortNombreDestino);
	buscar="server.reto.com";
	pos=busquedaBinaria2(conexiones, buscar, cSearchNombreDestino);
	if(pos!=-1){
		cout<<"server encontrado como destino"<<endl;
	}
	//sexta pregunta
	string correos[5]={"gmail.com", "outlook.com", "protonmail.com", "freemailserver.com", };
	for(i=0; i<5; i++){
		buscar=correos[i];
		pos=busquedaBinaria2(conexiones, buscar, cSearchNombreDestino);
		if(pos!=-1){
			cout<<correos[i]<<" es el servidor de correo"<<endl;
			break;
		}
	}
	s.sort(conexiones, cSortPuertoDestino);
	cout<<"Puertos encontrados: ";
	for(int i=1; i<=1000; i++){
		pos=busquedaBinaria2(conexiones, i, cSearchPuertoDestino);
		
		if(pos!=-1){
			cout<<i<<", ";
		}
	}
	cout<<endl;
	/*
	s.sort(conexiones, compararPorNombreDestino);
	cout<<"Datos ordenados"<<endl;
	Record r("", "", "", "google.com");
	string a="google.com";
	int pos=busquedaBinaria2(conexiones, a, compararPorNombreDestino2);
	if(pos!=-1){
		cout<<"encontrado"<<endl;
	}*
	/*for (int i=0; i<conexiones.size(); i++){
		conexiones[i].imprimirRecord();
	}*/
	return 0;
}