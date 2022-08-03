#include "base.hpp"
template <typename T1>
void heapify(T1 &v, int n, int i)
{   
    int largest = i;  
    int l = 2 * i + 1;    
    int r = 2 * i + 2; 
    if (l < n && get_vector_data(v[l]) > get_vector_data(v[largest]))
        largest = l;
    if (r < n && get_vector_data(v[r]) > get_vector_data(v[largest]))
        largest = r;
    if (largest != i) {
        std::swap(v[i],v[largest]); 
        heapify(v, n, largest);
    }
}

template <typename T1>
void heapsort(T1& v, int n){
        for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
        for (int i = n - 1; i > 0; i--) { 
        std::swap(v[i],v[0]) ;
        heapify(v, i, 0);
          }
	}

