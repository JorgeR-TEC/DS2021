#include <iostream>

using namespace std;

template <class T>

class Vector{
	public:
	T *data;
	int size;
	int capacity;
	
	Vector(){
		capacity=10;
		size=0;
		data= new T[capacity]();
	}
	
	Vector(int c){
		capacity=c;
		size=0;
		data= new T[capacity]();
	}
	
	void increaseSize(){
		int newCapacity=capacity*2;
		T *nuevo=new T[newCapacity]();
		for(int i=0; i<size; i++){
			nuevo[i]=data[i];
		}
		delete[] data;
		data=nuevo;
		capacity=newCapacity;
		
	}
	
	void append(T value){
		if(size>=capacity){
			this->increaseSize();
		}
		data[size]=value;
		size++;
	}
	
	T leer(int pos){
		if(pos<size){
			return data[pos];
		}else{
			return NULL;
		}
	}
	
	void modificar(int pos, T value){
		if(pos<size){
			data[pos]=value;
		}
	}
	
	void insertar(int pos, T value){
		if(pos>size){
			return;
		}
		if(size>=capacity){
			this->increaseSize();
		}
		for(int i=size-1; i>=pos; i--){
			data[i+1]=data[i];
		}
		data[pos]=value;
		size++;
	}
	
	void remover(T value){
		for(int i=0; i<size; i++){
			if(data[i]==value){
				for(int j=i; j<size-1; j++){
					data[j]=data[j+1];
				}
				break;
			}
		}
		size--;		
	}
	
	void Imprimir(){
		for(int i=0; i<size; i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
	 
	~Vector(){
		delete[] data;
	}
};


int main(){
	Vector<int> v(1);
	cout<<"cap: "<<v.capacity<<" size: "<<v.size<<endl;
	v.append(5);
	cout<<"Vector: ";
	v.Imprimir();
	cout<<"cap: "<<v.capacity<<" size: "<<v.size<<endl;
	cout<<"Vector: ";
	v.append(15);
	v.append(30);
	v.insertar(1, 3);
	v.Imprimir();
	
	return 0;
}