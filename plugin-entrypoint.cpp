
#include <stdlib.h>
#include <iostream>
#include <ctype.h>
#include <chrono>
#include <sstream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <unordered_map>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <future>
#include <netinet/sctp.h> 

#include "ceps_ast.hh"
#include "core/include/state_machine_simulation_core.hpp"

namespace cepsplugin{
    static Ism4ceps_plugin_interface* plugin_master = nullptr;
    static const std::string version_info = "INSERT_NAME_HERE v0.1";
    static constexpr bool print_debug_info{true};
    ceps::ast::node_t insertion_sort(ceps::ast::node_callparameters_t params);
}



template <typename T> T get_key(T v) {return v;}
int get_key(int* v) {return *v;}

template <typename T>
void insertion_sort(T& v){
	for(ssize_t i = 1; i < (ssize_t)v.size(); ++i){
		auto elem_to_insert = v[i];
		auto j = i - 1;
		for(;j >= 0 && get_key(v[j]) > get_key(elem_to_insert); --j)
			v[j + 1] = v[j];
		v[j + 1] = elem_to_insert;
	}
}



ceps::ast::node_t cepsplugin::insertion_sort(ceps::ast::node_callparameters_t params){
    using namespace std;
    using namespace ceps::ast;
    using namespace ceps::interpreter;
    auto data = get_first_child(params);    
    if (!is<Ast_node_kind::structdef>(data)) return nullptr;
    auto& ceps_struct = *as_struct_ptr(data);
    cout << ceps_struct << '\n';


    vector<int> v1 = {5,4,3,2,1};
    ::insertion_sort(v1);
    for( auto e: v1)
        cout << e << ' ';
    cout << '\n';

    auto one = 1;
    auto four = 4;
    auto five = 5;
    auto two = 2;
    auto three = 3;

    vector<int*> v2 = {&five,&four,&three,&two,&one};
    ::insertion_sort(v2);

    auto result = mk_struct("result");
    return result;
}

extern "C" void init_plugin(IUserdefined_function_registry* smc)
{
  cepsplugin::plugin_master = smc->get_plugin_interface();
  cepsplugin::plugin_master->reg_ceps_phase0plugin("insertion_sort",cepsplugin::insertion_sort);
}					
				