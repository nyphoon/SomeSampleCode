// http://en.cppreference.com/w/cpp/language/operators

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct Sum {
    int sum;
    Sum() : sum(0) { cout<<"construct sum"<<endl;}
    void operator()(int n) { sum += n; }
    
    void show(){ cout<<sum<<endl; }
};

int main()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(3);
	
	Sum s = std::for_each(v.begin(), v.end(), Sum());
	
	s.show();
	return 0;
}