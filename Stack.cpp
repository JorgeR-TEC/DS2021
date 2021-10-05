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
class Stack{
	public:
	Nodo<T> *top;
	
	Stack(){
		top=NULL;
	}
	
	void push(T value){
		Nodo<T> *nuevo=new Nodo<T>(value);
		if(top==NULL){
			top=nuevo;
		}else{
			top->next=nuevo;
			nuevo->prev=top;
			top=nuevo;
		}
	}
	
	T pop(){
		if(top==NULL){
			return NULL;
		}
		T val=top->value;
		Nodo<T> *temp=top;
		top=top->prev;
		if(top!=NULL){
			top->next=NULL;
		}
		delete temp;
		return val;
	}
	
	void imprimir(){
		Nodo<T> *it=top;
		while(it!=NULL){
			cout<<it->value<<",";
			it=it->prev;
		}
		cout<<endl;
	}
};

int main(){
	Stack<int> s;
	s.push(5);
	s.push(20);
	s.push(10);
	s.imprimir();
	cout<<"sacado: "<<s.pop()<<endl;
	s.imprimir();
	return 0;
}