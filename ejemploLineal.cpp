#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> v;
	v.push_back(5);
	v.push_back(10);
	v.push_back(15);
	v[2]=11;
	/*for(int i=0; i<v.size(); i++){
		cout<<v[i]<<",";
	}*/
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
}