#include <vector>
#include <iostream>

using namespace std;

template <typename T> T get_key(T v) {return v;}
int get_key(int* v) {return *v;}

template <typename T>
void insertion_sort(T& v){
	for(ssize_t i = 1; i < v.size(); ++i){
		auto elem_to_insert = v[i];
		auto j = i - 1;
		for(;j >= 0 && get_key(v[j]) > get_key(elem_to_insert); --j)
			v[j + 1] = v[j];
		v[j + 1] = elem_to_insert;
	}
}

int main(){
    vector<int> v1 = {5,4,3,2,1};
    insertion_sort(v1);
    for( auto e: v1)
        cout << e << ' ';
    cout << '\n';

    auto one = 1;
    auto four = 4;
    auto five = 5;
    auto two = 2;
    auto three = 3;

    vector<int*> v2 = {&five,&four,&three,&two,&one};
    insertion_sort(v2);
    for( auto e: v2)
        cout << *e << ' ';
    cout << '\n';
}