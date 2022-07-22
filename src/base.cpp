#include "base.hpp"

int get_key(int* v) {return *v;}

int get_key(ceps::ast::node_t v) {
    using namespace ceps::ast;
    return value(as_int_ref(v));
}
