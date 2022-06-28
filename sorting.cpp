#include <vector>
#include <iostream>

using namespace std;

void insertion_sort(vector<int> & v){
	for(ssize_t i = 1; i < v.size(); ++i){
		auto key = v[i];
		auto j = i - 1;
		for(;j >= 0 && v[j] > key; --j)
			v[j + 1] = v[j];
		v[j + 1] = key;
	}
}

int main(){
    vector<int> v1 = {5,4,3,2,1};
    insertion_sort(v1);
    for( auto e: v1)
        cout << e << ' ';
    cout << '\n';
}