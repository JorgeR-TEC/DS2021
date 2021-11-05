#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	bool visitado;
	Nodo<T> *izq;
	Nodo<T> *der;
	
	Nodo(){
		value=NULL;
		visitado=false;
		izq=NULL;
		der=NULL;
	}
	
	Nodo(T val){
		value=val;
		visitado=false;
		izq=NULL;
		der=NULL;
	}
};

template <class T>
class AVL{
	public:
	Nodo<T> *root;
	
	AVL(){
		root=NULL;
	}
	
	int altura(Nodo<T> *it){
		if(it==NULL){
			return -1;
		}
		int altDer=altura(it->der);
		int altIzq=altura(it->izq);
		int altura=altIzq>altDer? altIzq+1:altDer+1;
		return altura;
		/*if(altIzq>altDer){
			altura=altIzq+1;
		}else{
			altura=altDer+1;
		}*/
	}
	
	
	int calcularFE(Nodo<T> *it){
		return altura(it->der)-altura(it->izq);
	}
	
	Nodo<T> *rotacionDerecha(Nodo<T> *X){
		Nodo<T> *Y=X->izq;
		X->izq=Y->der;
		Y->der=X;
		return Y;
	}
	
	Nodo<T> *rotacionIzquierda(Nodo<T> *X){
		Nodo<T> *Y=X->der;
		X->der=Y->izq;
		Y->izq=X;
		return Y;
	}
	
	Nodo<T> *balanceo(Nodo<T> *X){
		int FEX=calcularFE(X);
		if(FEX>1){//desbalance a la derecha
			if(calcularFE(X->der)<0){//pivote desbalanceado hacia la izquierda
				X->der=rotacionDerecha(X->der);
			}	
			X=rotacionIzquierda(X);
		}else if(FEX<-1){//desbalance a la izquierda
			if(calcularFE(X->izq)>0){//pivote desbalanceado hacia la derecha
				X->izq=rotacionIzquierda(X->izq);
			}
			X=rotacionDerecha(X);
		}
		return X;
	}

	void insert(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(root==NULL){
			root=nuevo;
		}else{
			root=insertAux(nuevo, root);
		}
	}
	
	Nodo<T> * insertAux(Nodo<T> *nuevo, Nodo<T> *it){
		if(it==NULL){
			return nuevo;
		}
		else if(nuevo->value>it->value){
			it->der=insertAux(nuevo, it->der);
		}else if(nuevo->value<it->value){
			it->izq=insertAux(nuevo, it->izq);
		}
		it=balanceo(it);
		return it;
	}
	
	void printInorder(){
		printInorderAux(root);
	}
	
	void printInorderAux(Nodo<T> *it){
		if(it==NULL){
			return;
		}
		printInorderAux(it->izq);
		cout<<it->value<<",";
		printInorderAux(it->der);
	}
	
	bool find(T value){
		if(root==NULL){
			return false;
		}else{
			return findAux(value, root);
		}
	}
	
	bool findAux(T value, Nodo<T> *it){
		if(it==NULL){
			return false;
		}
		if(value==it->value){
			return true;
		}else if(value>it->value){
			return findAux(value, it->der);
		}else if(value<it->value){
			return findAux(value, it->izq);
		}
	}
	
	Nodo<T> *findNodo(T value){
		if(root==NULL){
			return NULL;
		}else{
			return findNodoAux(value, root);
		}
	}
	
	Nodo<T> *findNodoAux(T value, Nodo<T> *it){
		if(it==NULL){
			return NULL;
		}
		if(value==it->value){
			return it;
		}else if(value>it->value){
			return findNodoAux(value, it->der);
		}else if(value<it->value){
			return findNodoAux(value, it->izq);
		}
	}
	
	void borrar(T value){
		if(root==NULL){
			return;
		}
		root=borrarAux(value, root);
	}
	
	Nodo<T> *borrarAux(T value, Nodo<T> *it){
		if(it==NULL){
			return NULL;
		}
		Nodo<T> *aRegresar=it;
		if(value>it->value){
			it->der=borrarAux(value,it->der);
		}else if(value<it->value){
			it->izq=borrarAux(value, it->izq);
		}else if(value==it->value){
			//aqui borramos
			if(it->izq==NULL && it->der==NULL){
				delete it;
				return NULL;
			}else if(it->izq==NULL && it->der!=NULL){
				aRegresar=it->der;
				delete it;
			}else if(it->izq!=NULL && it->der==NULL){
				aRegresar=it->izq;
				delete it;
			}else{
				Nodo<T> *antecesor=it->izq;
				while(antecesor->der!=NULL){
					antecesor=antecesor->der;
				}
				it->value=antecesor->value;
				it->izq=borrarAux(it->value, it->izq);
			}
			
		}
		aRegresar=balanceo(aRegresar);
		return aRegresar;
	}
	
};


int main(){
	AVL<int> b;
	b.insert(7);
	b.insert(15);
	b.insert(12);
	b.printInorder();
	cout<<endl;
	cout<<"El factor de equilibrio de la raiz es: "<<b.calcularFE(b.root)<<endl;
	return 0;
}