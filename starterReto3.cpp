#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

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

vector<Record> data;
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
		data.push_back(r);
		valores.clear();
	}
}

class ConexionesComputadora{
	public:
	string ip;
	vector<string> conexionesSalida;
	
	ConexionesComputadora(){
		this->ip="";
	}
	
	ConexionesComputadora(string ip){
		this->ip=ip;
	}
	
	void agregarSaliente(string ipDestino){
		conexionesSalida.push_back(ipDestino);
	}
	
	void imprimir(){
		cout<<ip<<":";
		for(string ipDestino: conexionesSalida){
			cout<<ipDestino<<",";
		}
		cout<<endl;
	}
};

int main(){
	leerDatos("/mnt/c/dr/reto/datosEquipo14.csv");
	cout<<"Datos leidos"<<endl;
	unordered_map<string, ConexionesComputadora> cnx;
	for(Record r:data){
		if(cnx.find(r.ipFuente)==cnx.end()){
			ConexionesComputadora a(r.ipFuente);
			cnx[r.ipFuente]=a;
		}
		cnx[r.ipFuente].agregarSaliente(r.ipDestino);
	}
	for(auto c:cnx){
		c.second.imprimir();
	}
}