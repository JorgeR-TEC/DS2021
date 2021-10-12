#include <iostream>
#include <unordered_map>


using namespace std;

int main(){
	unordered_map<string, int> d;
	pair<string, int> p("hola", 20);
	d.insert(p);
	d.insert({"adios", 5});
	d["gato"]=15;
	d["hola"]=10;
	d["perro"]=2;
	/*if(d.find("hola")!=d.end()){
		cout<<d["hola"]<<endl;
	}else{
		cout<<"no se encontro esa llave"<<endl;
	}*/
	//leyendo de un pars
		//cout<<p.first<<"-"<<p.second<<endl;
	//iterador
	/*cout<<"usando iterador"<<endl;
	for(auto it=d.begin(); it!=d.end(); it++){
		cout<<it->first<<","<<it->second<<endl;
	}
	cout<<"usando for tipo python"<<endl;
	//iterador tipo python
	*/for(auto par:d){
		cout<<par.first<<","<<par.second<<endl;
	}
	
}