#include <iostream>
#include <list>

using namespace std;
class Set{
	public:
	int size;
	list<int> *data;
	
	Set(){
		size=100;
		data=new list<int>[size];
	}
	
	Set(int s){
		size=s;
		data=new list<int>[size];
	}
	
	int hash(int value){
		return value%size;
	}
	
	void insert(int value){
		int pos=hash(value);
		for(int elemento :data[pos]){
			if(elemento==value){
				return;
			}
		}
		data[pos].push_back(value);
	}
	
	bool find(int value){
		 int pos=hash(value);
		 for(int elemento:data[pos]){
			if(elemento==value){
				return true;
			}
		 }
		 return false;
	}
	
	void imprimir(){
		for(int i=0; i<size; i++){
			if(!data[i].empty()){
				cout<<i<<": ";
				for(int elemento: data[i]){
					cout<<elemento<<", ";
				}
				cout<<endl;
			}
			
		}
	}
	
	void eliminar(int value){
		int pos=hash(value);
		for(auto it=data[pos].begin(); it!=data[pos].end(); it++){
			if(*it==value){
				data[pos].erase(it);
				return;
			}
		}
	}
};

int main(){
	Set s;
	s.insert(5);
	s.insert(10);
	s.insert(20);
	s.insert(5400);
	s.insert(11231230);
	s.insert(211134);
	cout<<s.find(5)<<endl;
	cout<<s.find(40)<<endl;
	s.imprimir();
	cout<<"borrando el 5"<<endl;
	s.eliminar(5);
	s.imprimir();
}