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

int MCD(int m, int n){
	int r=m%n;
	if(r==0){
		return n;
	}else{
		return MCD(n, r);
	}
}

int sumaVectorIterativo(vector<int> A){
	int resultado=0;
	for(int i=0; i<A.size(); i++){
		resultado+=A[i];
	}
	return resultado;
}


int sumaVectorRecursivo(vector<int> A, int resultado, int posicion){
	if(posicion==A.size()){
		return resultado;
	}else{
		return sumaVectorRecursivo(A, resultado+A[posicion], posicion+1);
	}
}

int sumaMatrix(vector<vector<int>> M){
	int resultado=0;
	for(int fila=0; fila<M.size(); fila++){
		/*for(int columna=0; columna<M[fila].size(); columna++){
			resultado+=M[fila][columna];
		}*/
		resultado+=sumaVectorIterativo(M[fila]);
	}
	return resultado;
}

int sumaMatrixRecursiva(vector<vector<int>> m, int resultado, int fila){
	if(fila==m.size()){
		return resultado;
	}else{
		return sumaMatrixRecursiva(m, resultado+sumaVectorRecursivo(m[fila],0,0), fila+1);
	}
}


int main(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	vector<vector<int>> m;
	m.push_back(a);
	m.push_back(a);
	m.push_back(a);
	cout<<sumaMatrixRecursiva(m, 0, 0)<<endl;
	//cout<<factorialCola(5)<<endl;
	/*vector<int> v;
	cout<<"tam: "<<v.size()<<endl;
	v.push_back(5);
	v.push_back(3);
	cout<<"tam: "<<v.size()<<endl;
	cout<<"valor en 0: "<<v[0]<<endl;*/
	return 0;
}

