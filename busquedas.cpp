#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busquedaSecuencial(vector<int> a, int buscado){
	for(int i=0; i<a.size(); i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaMejorada1(vector<int> a, int buscado){
	for(int i=0; i<a.size(); i++){
		if(a[i]==buscado){
			return i;
		}else if(a[i]>buscado){
			return -1;
		}
	}
	return -1;
}


int busquedaMejorada2(vector<int> a, int buscado){
	int inicio=0;
	int salto=1000;
	while(inicio<a.size()){
		int fin=inicio+salto;
		if(fin>a.size()){
			fin=a.size();
		}
		if(a[fin-1]>=buscado){
			for(int i=inicio; i<fin; i++){
				if(a[i]==buscado){
					return i;
				}
			}
			return -1;
		}
		inicio=fin;
	}
	return -1;
}

int busquedaBinaria(vector<int> a, int buscado){
	int inicio=0;
	int fin=a.size()-1;
	while(inicio<=fin){
		int medio=(fin+inicio)/2;
		if(a[medio]==buscado){
			return medio;
		}else if(buscado>a[medio]){
			inicio=medio+1;
		}else{
			fin=medio-1;
		}
	}
	return -1;
}
int main(){
	vector<int> a;
	for(int i=0; i<1000000; i++){
		a.push_back(i);
	}
	int buscado=10000;
	auto antes=high_resolution_clock::now();
	int pos=busquedaSecuencial(a, buscado);
	//int pos=busquedaMejorada1(a, buscado);
	//int pos=busquedaBinaria(a, buscado);
	auto despues=high_resolution_clock::now();
	auto tiempo=duration_cast<microseconds>(despues-antes).count();
	cout<<"Se encontro el valor en la posicion: "<<pos<<" en un tiempo "<<tiempo<<endl;
	antes=high_resolution_clock::now();
	pos=busquedaBinaria(a, buscado);
	despues=high_resolution_clock::now();
	tiempo=duration_cast<microseconds>(despues-antes).count();
	cout<<"Se encontro el valor en la posicion: "<<pos<<" en un tiempo "<<tiempo<<endl;
	
	return 0;
}
