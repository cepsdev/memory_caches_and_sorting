#include "base.hpp"
template <typename T1>
void insertion_sort(T1& v){
	for(ssize_t i = 1; i < v.size(); ++i){
		auto elem_to_insert = v[i];
		auto j = i - 1;
		for(;j >= 0 && get_key(v[j]) > get_key(elem_to_insert); --j){
			v[j + 1] = v[j];
        }
		v[j + 1] = elem_to_insert;
	}
}
