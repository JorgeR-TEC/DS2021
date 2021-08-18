#include<iostream>
#include<vector>

using namespace std;

int factorialIterativo(int n){
	int respuesta=1;
	for(int i=1; i<=n; i++){
		respuesta*=i;
	}
	return respuesta;
}

int factorialRecursivo(int n){
	if(n==0){
		return 1;
	}else{
		return n*factorialRecursivo(n-1);
	}
}

int factorialColaAux(int n, int res){
	if(n==0){
		return res;
	}else{
		return factorialColaAux(n-1, res*n);
	}
}

int factorialCola(int n){
	return factorialColaAux(n, 1);
}




int main(){
	cout<<factorialCola(5)<<endl;
	/*vector<int> v;
	cout<<"tam: "<<v.size()<<endl;
	v.push_back(5);
	v.push_back(3);
	cout<<"tam: "<<v.size()<<endl;
	cout<<"valor en 0: "<<v[0]<<endl;*/
	return 0;
}

