#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

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
	cout<<endl;
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
	cout<<l.front()<<endl;
	cout<<l.back()<<endl;
	
	stack<int> s;
	s.push(5);
	s.push(6);
	s.push(7);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();*/
	queue<int> q;
	q.push(5);
	q.push(6);
	q.push(7);
	cout<<"adelante: "<<q.front()<<endl;
	cout<<"atras: "<<q.back()<<endl;
	q.pop();
	cout<<"adelante: "<<q.front()<<endl;
	cout<<"atras: "<<q.back()<<endl;
	q.pop();
	cout<<"adelante: "<<q.front()<<endl;
	cout<<"atras: "<<q.back()<<endl;
	
}