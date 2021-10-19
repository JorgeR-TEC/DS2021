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
class BST{
	public:
	Nodo<T> *root;
	
	BST(){
		root=NULL;
	}
	

	void insert(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(root==NULL){
			root=nuevo;
		}else{
			insertAux(nuevo, root);
		}
	}
	
	void insertAux(Nodo<T> *nuevo, Nodo<T> *it){
		if(it==NULL||nuevo->value==it->value){
			return;
		}
		if(nuevo->value>it->value){
			if(it->der==NULL){
				it->der=nuevo;
				return;
			}else{
				insertAux(nuevo, it->der);
			}
		}else{
			if(it->izq==NULL){
				it->izq=nuevo;
			}else{
				insertAux(nuevo, it->izq);
			}
		}
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
};


int main(){
	BST<int> b;
	b.insert(710);
	b.insert(689);
	b.insert(2000);
	b.insert(143);
	b.insert(702);
	b.insert(1040);
	b.insert(2099);
	b.insert(3300);
	b.insert(70);
	b.printInorder();
	return 0;
}