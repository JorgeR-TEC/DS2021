#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){
	/*set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(15);
	s.insert(4);
	for(auto it=s.rbegin(); it!=s.rend(); it++){
		cout<<*it<<",";
	}
	
	if(s.find(5)!=s.end()){
		s.erase(s.find(5));
	}
	for(int elemento:s){
		cout<<elemento<<",";
	}
	cout<<endl;*/
	map<int,string>m;
	pair<int, string> p(5, "hola");
	m.insert(p);
	m.insert({10, "adios"});
	m[30]="perro";
	/*for(auto it=m.begin(); it!=m.end(); it++){
		cout<<(*it).first<<","<<it->second<<"|";
		if(it->second.find("rro")!=string::npos){
			cout<<"encontrado"<<endl;
		}
	}*/
	
	for(auto par:m){
		cout<<par.first<<","<<par.second<<"|";
	}
	cout<<endl;
	return 0;
}