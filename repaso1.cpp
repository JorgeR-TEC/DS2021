#include <iostream>

using namespace std;


class Ejemplo1{
  private:
    int b;
  public:
	int a;
	void printEjemplo(){
		cout<<"hola desde el ejemplo"<<endl;
	}
};

class Ejemplo2: public Ejemplo1{
	public:
		int c;
	Ejemplo2(){
		c=5;
	}
	
	Ejemplo2(int var){
		c=var;
	}
};

template <class T>
class EjemploGenerics{
 public:
	T valor;
	
	EjemploGenerics(){
		
	}
	
	EjemploGenerics(T val){
		valor=val;
	}
	
	void printValor(){
		cout<<valor<<endl;
	}
	
	void sumarValores(T val1, T val2){
		cout<<val1+val2<<endl;
	}
};

template <class T>
class EjemploGenericsHijo : public EjemploGenerics<T>{
	public:
		A valorHijo;
	EjemploGenericsHijo(A val){
		valorHijo=val;
	}
};


int main(){
	int a=0;
	float b=0.0;
	double c=0.0;
	char d='a';
	bool e=true;
	string g="hola";
	cout<<g<<endl;
	Ejemplo2 h;
	h.printEjemplo();
	EjemploGenerics<int> i(5);
	i.printValor();
	i.sumarValores(5,3);
	EjemploGenerics<string> j("hola");
	j.printValor();
	j.sumarValores("hola", " mundo");
	EjemploGenericsHijo<int> k(5);
	return 0;
}