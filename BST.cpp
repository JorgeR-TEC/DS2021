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
				aRegresar=NULL;
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
		
		return aRegresar;
	}
	
	void hermano(T value){
		Nodo<T> *it=root;
		if(root==NULL || root->value==value){
			cout<<"No tiene hermano"<<endl;
			return;
		}
		while(true){
			if (it==NULL){
				cout<<"No se encontro"<<endl;
				return;
			}
			if(value<it->value){
				//checar si es su hijo
				if(it->izq!=NULL && it->izq->value==value){
					if(it->der!=NULL){
						cout<<"El hermano es "<<it->der->value<<endl;
						return;
					}
				}else{
					it=it->izq;
				}
			}else if(value>it->value){
				//checar si es su hijo
				if(it->der!=NULL && it->der->value==value){
					if(it->izq!=NULL){
						cout<<"El hermano es "<<it->izq->value<<endl;
						return;
					}
				}else{
					it=it->der;
				}
			}
			
		}
	}
	
};


int main(){
	BST<int> b;
	/*b.insert(710);
	b.insert(689);
	b.insert(2000);
	b.insert(143);
	b.insert(702);
	b.insert(1040);
	b.insert(2099);
	b.insert(3300);
	b.insert(70);*/
	b.insert(10);
	b.insert(15);
	b.insert(8);
	b.insert(7);
	b.insert(9);
	b.printInorder();
	cout<<endl;
	b.hermano(7);
	//cout<<b.find(1040)<<endl;
	//cout<<b.find(5)<<endl;
	//b.borrar(710);
	//b.printInorder();
	//cout<<endl;
	return 0;
}