#include <iostream>

using namespace std;

class Ejemplo{
	public:
	int *a;
	string b;
	
	Ejemplo(){
		a=new int[10];
		b="";
	}
	
	Ejemplo(int v, string v2){
		a=new int[v];
		b=v2;
	}
	
	~Ejemplo(){
		delete[] a;
		//cout<<"Destructor ejecutado"<<endl;
	}

};

void f(){
	Ejemplo a;
	Ejemplo b();
	Ejemplo c(10, "hola");
	Ejemplo *d=new Ejemplo(10, "hola");
	cout<<(*d).b<<endl;
	cout<<d->b<<endl;
	delete d;

}

int main(){
	f();
	
	/*int arreglo[100000]={10,20,30,40};
	arreglo[10000]
	*(arreglo+10000)
	int *b=arreglo;
	cout<<*++b<<endl;
	cout<<*b<<endl;*/
}