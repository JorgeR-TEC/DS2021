#include <iostream>
#include <list>

using namespace std;

template <class K, class V>
class Pair{
	public:
	K key;
	V value;
	
	Pair(K k, V v){
		key=k;
		value=v;
	}
};

template <class K, class V>
class Dict{
	public:
	list<Pair<K,V>> *data;
	int size;
	
	Dict(){
		size=100;
		data=new list<Pair<K,V>>[size];
	}
	
	Dict(int s){
		size=s;
		data=new list<Pair<K,V>>[size];
	}
	
	void insertar(K k, V v, int hash(K,int)){
		int pos=hash(k, size);
		for(Pair<K,V> par:data[pos]){
			if(par.key==k){
				return;
			}
		}
		Pair<K,V> p(k, v);
		data[pos].push_back(p);	
	}
	
	bool find(K k, V v, int hash(K,int)){
		int pos=hash(k, size);
		for(Pair<K,V> par:data[pos]){
			if(par.key==k){
				return true;
			}
		}
		return false;
	}
	
	void imprimir(){
		for(int i=0; i<size; i++){
			if(!data[i].empty()){
				cout<<i<<":";
				for(Pair<K,V> par:data[i]){
					cout<<par.key<<"-"<<par.value<<",";
				}
				cout<<endl;
			}
		}
	}
};

int hashString(string s, int size){
	return s.length()%size;
}
	
int main(){
	Dict<string, int> d;
	d.insertar("hola", 5, hashString);
	d.insertar("hola", 20, hashString);
	d.imprimir();

}