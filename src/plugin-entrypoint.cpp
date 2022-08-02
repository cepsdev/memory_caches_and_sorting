
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

#include "sort_algorithms.hpp"

namespace cepsplugin{
    static Ism4ceps_plugin_interface* plugin_master = nullptr;
    static const std::string version_info = "INSERT_NAME_HERE v0.1";
    static constexpr bool print_debug_info{true};
    ceps::ast::node_t insertion_sort(ceps::ast::node_callparameters_t params);
}




///////////////////////////////
///////////////////////////////
///////////////////////////////

using namespace std;
using namespace ceps::ast;

struct logger{
    vector<node_t> v;
    vector<node_t>& log;
    logger(vector<node_t> v, vector<node_t>& log) : v{v},log{log} { }
    size_t size() const {return v.size();}
    
    node_t& operator[] (size_t i) {
        log.push_back(ceps::interpreter::mk_int_node(i));
        return v[i]; 
    } 
};

ceps::ast::node_t cepsplugin::insertion_sort(ceps::ast::node_callparameters_t params){
    using namespace std;
    using namespace ceps::ast;
    using namespace ceps::interpreter;
    auto data = get_first_child(params);    
    if (!is<Ast_node_kind::structdef>(data)) return nullptr;
    auto& ceps_struct = *as_struct_ptr(data);
    auto v1 = children(ceps_struct);

    vector<node_t> mem_access;    
    auto input = logger{v1,mem_access};
    
    ::insertion_sort(input);

    auto result = mk_struct("result",
                            {mk_struct("output", input.v),
                            mk_struct("mem_access", mem_access)  });
    return result;
}

extern "C" void init_plugin(IUserdefined_function_registry* smc)
{
  cepsplugin::plugin_master = smc->get_plugin_interface();
  cepsplugin::plugin_master->reg_ceps_phase0plugin("insertion_sort",cepsplugin::insertion_sort);
}					
				