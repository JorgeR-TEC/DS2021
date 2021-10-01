#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo *next;
	Nodo *prev;
	
	Nodo(T val){
		value=val;
		next=NULL;
		prev=NULL;
	}
};


template <class T>
class DoubleLinkedList{
	public:
	Nodo<T> *head;
	Nodo<T> *tail;
	
	DoubleLinkedList(){
		head=NULL;
		tail=NULL;
	}
	
	void append(Nodo<T> *nuevo){
		if(head==NULL){
			head=nuevo;
			tail=head;
			return;
		}
		nuevo->prev=tail;
		tail->next=nuevo;
		tail=nuevo;
		
	}
	
	void append(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		append(nuevo);
	}
	
	void imprimir(){
		Nodo<T> *temp=head;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	void insert(int pos, Nodo<T> *nuevo){
		if(head==NULL){
				append(nuevo);
				return;
		}
		if (pos==0){
			nuevo->next=head;
			head->prev=nuevo;
			head=nuevo;
			return;
		}
		int p=0;
		Nodo<T> *it=head;
		while(it->next!=NULL && p<pos){
			it=it->next;
			p++;
		}
		if(p==pos){
			it->prev->next=nuevo;
			nuevo->prev=it->prev;
			it->prev=nuevo;
			nuevo->next=it;
		}
		if((p+1)==pos){
			append(nuevo);
		}
		
	}
	
	void imprimirReversa(){
		Nodo<T> *temp=tail;
		while(temp!=NULL){
			cout<<temp->value<<",";
			temp=temp->prev;
		}
		cout<<endl;
	}
	
	
	void insert(int pos, T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		insert(pos, nuevo);
	}
	
	void remover(T value){
		Nodo<T> *it=head;
		while(it!=NULL && it->value!=value){
			it=it->next;
		}
		if(it!=NULL){
			if(it->prev!=NULL){
				it->prev->next=it->next;
			}else{
				head=it->next;
			}
			if(it->next!=NULL){
				it->next->prev=it->prev;
			}else{
				tail=it->prev;
			}
			delete it;
		}
	}
	
};

int main(){
	DoubleLinkedList<int> dll;
	dll.append(5);
	dll.append(7);
	dll.append(29);
	dll.imprimir();
	dll.insert(0, 3);
	dll.imprimir();
	dll.insert(2, 6);
	dll.imprimir();
	dll.insert(5, 30);
	dll.imprimir();
	dll.imprimirReversa();
	dll.remover(7);
	dll.imprimir();
	dll.remover(3);
	dll.imprimir();
	dll.remover(30);
	dll.imprimir();
	dll.append(41);
	dll.imprimir();
	
	

}