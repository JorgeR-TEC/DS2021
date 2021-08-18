#include <iostream>

using namespace std;

class Animal{
	public:
		string especie;
		int patas;
		bool alas;
		string sonido;
		
		void hacerSonido(){
			cout<<"El animal hace "<<sonido<<endl;
		}
};

class Perro: public Animal{
  public:
	string nombre;
	
	Perro(string n){
		nombre=n;
		especie="canino";
		patas=4;
		alas=false;
		sonido="guau";
	}
	
	void hacerSonido(){
		cout<<nombre<<" hace "<<sonido<<endl;
	}
};

class Gato: public Animal{
  public:
	string nombre;
	
	Gato(string n){
		nombre=n;
		especie="felino";
		patas=4;
		alas=false;
		sonido="miau";
	}
	
	void hacerSonido(){
		cout<<nombre<<" hace "<<sonido<<endl;
	}
};

template <class T>
class Veterinario{
	public:
		string nombre;
		
		Veterinario(string n){
			nombre=n;
		}
		
		void inyectar(T paciente){
			cout<<nombre<<" inyecta a "<<paciente.nombre<<endl;
			paciente.hacerSonido();
		}
};



void ejercicio2(){
	int cantidad=0;
	cout<<"Cuantos números quieres introducir: ";
	cin>>cantidad;
	int suma=0;
	int entradaNumero=0;
	for(int i=0; i<cantidad; i++){
		 cout<<"Que numero quieres agregar: ";
		 cin>>entradaNumero;
		 suma+=entradaNumero;
	}
	cout<<"La suma es "<<suma<<endl;
}


void ejercicio3(){
	string frase;
	string palabra;
	cout<<"Introduce una frase: ";
	getline(cin, frase);
	cout<<"Introduce una palabra: ";
	cin>>palabra;
	int contador=0;
	for(int i=0; i<frase.length(); i++){
		if(i+palabra.length()>frase.length()){
			break;
		}
		bool bandera=true;
		for(int j=0; j<palabra.length(); j++){
			if(frase[i+j]!=palabra[j]){
				bandera=false;
				break;
			}
		}
		if(bandera){
			contador++;
		}
	}
	cout<<"La palabra se encontro "<<contador<<" veces"<<endl;
}


void ejercicio3v2(){
	string frase;
	string palabra;
	cout<<"Introduce una frase: ";
	getline(cin, frase);
	cout<<"Introduce una palabra: ";
	cin>>palabra;
	int contador=0;
	int pos=frase.find(palabra);
	while(pos!=string::npos){
		contador++;
		pos=frase.find(palabra, pos+1);
	}
	cout<<"La palabra se encontro "<<contador<<" veces"<<endl;
}

int main(){
	/*string x;
	cout<<"Dame una frase: ";
	getline(cin, x);
	cout<<"La frase que me diste es "<<x<<endl;*/
	/*Perro fido("Fido");
	fido.hacerSonido();
	Gato garfield("Garfield");
	garfield.hacerSonido();
	Veterinario<Gato> ale("Alejandra");
	ale.inyectar(garfield);*/
	return 0;
}