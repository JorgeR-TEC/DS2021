#include <iostream>
#include <unordered_map>

using namespace std;

class Estudiante{
	public:
	string nombre;
	string matricula;
	
	Estudiante(){
		nombre="";
		matricula="";
	}
	
	Estudiante(string n, string m){
		nombre=n;
		matricula=m;
	}
	
	bool operator==(const Estudiante& otro) const{
		if(this->matricula==otro.matricula){
			return true;
		}
		return false;
	}
};

struct HashEstudiante{
	size_t operator()(const Estudiante& e) const{
		return hash<string>()(e.matricula);
	}

};

int main(){
	/*unordered_map<string, Estudiante> grupo;
	Estudiante a("juan", "12312");
	Estudiante b("laura", "1231111");
	grupo["juan"]=a;
	grupo["laura"]=b;
	cout<<grupo["juan"].matricula<<endl;*/
	unordered_map<Estudiante, int, HashEstudiante> calificaciones;
	//cout<<hash<string>()("hola")<<endl;
	Estudiante a("juan", "12312");
	Estudiante b("laura", "12312");
	calificaciones.insert({a,85});
	calificaciones.insert({b, 100});
	cout<<"la calificacion de "<<a.nombre<<" es "<<calificaciones[a]<<endl;
	/*if(a==a){
		cout<<"son iguales"<<endl;
	}*/
}	