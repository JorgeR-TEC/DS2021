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