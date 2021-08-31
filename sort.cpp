#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Sorter{
	public:
	virtual void Sort(vector<T> &data)=0;
	
	void Imprimir(vector<T> &data){
		for(int i=0; i<data.size(); i++){
			cout<<data[i]<<",";
		}
		cout<<endl;
	}
	
	void Intercambiar(vector<T> &data, int posI, int posJ){
		T temp=data[posI];
		data[posI]=data[posJ];
		data[posJ]=temp;
	}
};

template <class T>
class LuckySort: public Sorter<T>{
	public:
	void Sort(vector<T> &data){
		this->Intercambiar(data, 0, data.size()-1);
	}
};


template <class T>
class SelectionSort: public Sorter<T>{
	public:
	void Sort(vector<T> &data){
		for(int i=0; i<data.size()-1; i++){
			int minimo=i;
			for(int j=i+1; j<data.size(); j++){
				if(data[j]<data[minimo]){
					minimo=j;
				}
			}
			this->Intercambiar(data, i, minimo);
		}
	}
};

template <class T>
class BubbleSort: public Sorter<T>{
	public:
	void Sort(vector<T> &data){
		for(int i=0; i<data.size(); i++){
			for(int j=1; j<data.size()-i; j++){
				if(data[j-1]>data[j]){
					this->Intercambiar(data, j-1, j);
				}
			}
		}
	}
};

template <class T>
class InsertionSort: public Sorter<T>{
	public:
	void Sort(vector<T> &data){
		for(int i=1; i<data.size(); i++){
			for(int j=i; j>0; j--){
				if(data[j-1]>data[j]){
					this->Intercambiar(data, j-1, j);
				}else{
					break;
				}
			}
		}
	}
};


int main(){
	vector<int> a={7,5,3,4,1};
	InsertionSort<int> s;
	s.Imprimir(a);
	s.Sort(a);
	s.Imprimir(a);
	return 0;
}