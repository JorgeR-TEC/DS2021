#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
	unordered_set<string> s;
	/*hash<int> hs;
	hash<string> hst;
	hash<int *> hptr;
	int a=1241242;
	string b="holamundo";
	int *c=&a;
	cout<<hs(a)<<endl;
	cout<<hst(b)<<endl;
	cout<<hptr(c)<<endl;*/
	s.insert("hola");
	s.insert("gato");
	s.insert("perro");
	/*for(auto it=s.begin(); it!=s.end(); it++){
		cout<<*it<<endl;
	}*/
	for(string elemento:s){
		cout<<elemento<<endl;
	}
	if(s.find("perro")==s.end()){
		cout<<"no se encuentra la palabra perro"<<endl;
	}
	if(s.find("leon")==s.end()){
		cout<<"no se encuentra la palabra leon"<<endl;
	}
	
	
	
	
}