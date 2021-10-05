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
class Queue{
	public:
	Nodo<T> *front;
	Nodo<T> *back;
	
	Queue(){
		front=NULL;
		back=front;
	}
	
	void Enqueue(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(back==NULL){
			back=nuevo;
			front=back;
		}else{
			back->next=nuevo;
			nuevo->prev=back;
			back=nuevo;
		}
	}
	
	T Dequeue(){
		if(back==NULL){
			return NULL;
		}else if(front==back){
			T value=front->value;
			delete front;
			front=NULL;
			back=NULL;
			return value;
		}else{
			Nodo<T>* temp=front;
			front=temp->next;
			front->prev=NULL;
			T value=temp->value;
			delete temp;
			return value;
		}
	}
	
	void imprimir(){
		Nodo<T> *it=front;
		while(it!=NULL){
			cout<<it->value<<",";
			it=it->next;
		}
		cout<<endl;
	}
};

int main(){
	Queue<int> q;
	q.Enqueue(5);
	q.Enqueue(10);
	q.Enqueue(20);
	q.imprimir();
	cout<<"Sacado: "<<q.Dequeue()<<endl;
	q.imprimir();
	return 0;
}
