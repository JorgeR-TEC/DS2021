#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	/*vector<int> v;
	v.push_back(5);
	v.push_back(10);
	v.push_back(15);
	v[2]=11;
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<",";
	}
	v.push_back(10);
	v.push_back(15);
	cout<<"Size: "<<v.size()<<" cap:"<<v.capacity()<<endl;
	cout<<endl;
	for(auto it=v.begin(); it<v.end(); it++){
		cout<<*it<<",";
	}
	for(int i: v){
		cout<<i<<",";
	}
	cout<<endl;*/
	list<int> l;
	l.push_back(5);
	l.push_back(6);
	l.push_back(10);
	auto it=l.begin();
	for(it=l.begin(); it!=l.end(); it++){
		//cout<<*it<<",";
		if((*it)==5){
			break;
		}
	}
	l.erase(it);
	//cout<<endl;
	l.sort();
	for(int i: l){
		cout<<i<<",";
	}
	cout<<endl;
}