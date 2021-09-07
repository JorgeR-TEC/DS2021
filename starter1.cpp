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
int main(){
	cargarDatos("/mnt/c/dr/reto/datosEquipo0.csv");
	data[0].imprimirRecord();
}