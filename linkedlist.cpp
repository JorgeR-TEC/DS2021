#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo *next;
	
	Nodo(T val){
		value=val;
		next=NULL;
	}
};

template <class T>
class LinkedList{
	public:
		Nodo<T> *root;
		
		LinkedList(){
			root=NULL;
		}
		
		void append(Nodo<T> *nuevo){
			if(root==NULL){
				root=nuevo;
			}else{
				Nodo<T> *it=root;
				while(it->next!=NULL){
					it=it->next;
				}
				it->next=nuevo;
			}
		}
		
		void append(T val){
			Nodo<T> *nuevo=new Nodo<T>(val);
			this->append(nuevo);
		}
		
		void imprimir(){
			Nodo<T> *it=root;
			while(it!=NULL){
				cout<<it->value<<",";
				it=it->next;
			}
			cout<<endl;
		}
		
		void accederElemento(int i){
			int actual=0;
			Nodo<T> *it=root;
			while(it!=NULL && actual<i){
				actual++;
				it=it->next;
			}
			if(actual==i){
				cout<<it->value<<endl;
			}else{
				cout<<"no existe esa posicion"<<endl;
			}
		}
		
		void modificarElemento(int i, T val){
			int actual=0;
			Nodo<T> *it=root;
			while(it!=NULL && actual<i){
				actual++;
				it=it->next;
			}
			if(actual==i){
				it->value=val;
			}else{
				cout<<"no existe esa posicion"<<endl;
			}
		}
		
		void insert(int pos, Nodo<T> *nuevo){
			if(root==NULL){
				return;
			}
			int actual=0;
			Nodo<T> *it=root;
			if(pos==0){
				nuevo->next=root;
				root=nuevo;
				return;
			}
			while(it!=NULL && actual<pos-1){
				it=it->next;
				actual++;
			}
			if(actual==pos-1){
				nuevo->next=it->next;
				it->next=nuevo;
			}
		}
		
		void insert(int pos, T val){
			Nodo<T> *nuevo=new Nodo<T>(val);
			this->insert(pos, nuevo);
		}
		
		void eliminar(T val){
			if(root==NULL){
				return;
			}
			if(root->value==val){
				Nodo<T> *temp=root;
				root=root->next;
				delete temp;
				return;
			}
			Nodo<T> *it=root;
			while(it->next!=NULL &&it->next->value!=val){
				it=it->next;
			}
			if(it->next!=NULL){
				Nodo<T> *temp=it->next;
				it->next=temp->next;
				delete temp;
			}
		}

};

int main(){
	LinkedList<int> ll;
	ll.append(5);
	ll.append(5);
	ll.append(6);
	ll.append(4);
	ll.append(11);
	ll.append(15);
	ll.imprimir();
	ll.eliminar(4);
	ll.imprimir();
	ll.eliminar(5);
	ll.imprimir();
	ll.eliminar(15);
	ll.imprimir();
	
	
	return 0;
}