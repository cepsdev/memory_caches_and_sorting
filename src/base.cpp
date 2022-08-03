#include "base.hpp"

int get_vector_data(int* v) {return *v;}

int get_vector_data(ceps::ast::node_t v) {
    using namespace ceps::ast;
    return value(as_int_ref(v));
}
