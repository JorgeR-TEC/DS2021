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

template <class T>
class MergeSort: public Sorter<T>{
	public:
	void Sort(vector<T> &data){
		SortAux(data, 0, data.size()-1);
	}
	private:
	void SortAux(vector<T> &data, int lo, int hi){
		if(lo>=hi){
			return;
		}
		int mid=(lo+hi)/2;
		SortAux(data, lo, mid);//sort de la izquierda
		SortAux(data, mid+1, hi);//sort de la derecha
		Merge(data, lo, mid, hi);
	}
	
	void Merge(vector<T> &data, int lo, int mid, int hi){
		//Determinar el tamaño de la copia izquierda
		//int sizeI=mid-lo+1;
		//Determinar el tamaño de la copia derecha
		//int sizeD=hi-mid;
		//Hacer la copia izquierda
		vector<T> copiaI;
		for(int i=lo; i<=mid; i++){
			copiaI.push_back(data[i]);
		}
		//Hacer la copia derecha
		vector<T> copiaD;
		for(int i=mid+1; i<=hi; i++){
			copiaD.push_back(data[i]);
		}
		//Poner los indicadores de posicion Izquierda, Derecha y Global en su lugar
		int posI=0;
		int posD=0;
		int posG=lo;
		//Copiar en su lugar
		//mientras posI<sizeI y posD<sizeD
		while(posI<copiaI.size() && posD<copiaD.size()){
			if(copiaI[posI]<copiaD[posD]){
				data[posG]=copiaI[posI];
				posI++;
				posG++;
			}else{
				data[posG]=copiaD[posD];
				posD++;
				posG++;
			}
		}
			//revisar si el menor esta en copiaI o copiaD y poner en posicion Global
		//copiar elementos restantes
		while(posI<copiaI.size()){
			data[posG]=copiaI[posI];
			posI++;
			posG++;
		}
		while(posD<copiaD.size()){
			data[posG]=copiaD[posD];
			posD++;
			posG++;
		}
	}
	
	
};


template <class T>
class QuickSort: public Sorter<T>{
	public:
	void Sort(vector<T> &data){
		SortAux(data, 0, data.size()-1);
	}
	
	private:
	void SortAux(vector<T> &data, int lo, int hi){
		if(lo>=hi){
			return;
		}
		int posOrdenado=Partition(data, lo, hi);
		SortAux(data, lo, posOrdenado-1);
		SortAux(data, posOrdenado+1, hi);
	}
	
	int Partition(vector<T> &data, int lo, int hi){
		int p=lo;
		int i=lo+1;
		int j=hi;
		while (true){
			while(data[i]<=data[p] &&i<hi){
				i++;
			}
			while(data[j]>data[p]&&j>lo){
				j--;
			}
			if(i<j){
				this->Intercambiar(data, i,j);
			}else{
				this->Intercambiar(data, p, j);
				break;
			}
		}
		return j;
	}
};

int main(){
	vector<int> a={7,5,3,4,1,8};
	QuickSort<int> s;
	s.Imprimir(a);
	s.Sort(a);
	s.Imprimir(a);
	return 0;
}