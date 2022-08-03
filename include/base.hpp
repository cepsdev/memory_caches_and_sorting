#pragma once
#include "ceps_ast.hh"
template <typename T> T get_vector_data(T v) {return v;}
int get_vector_data(int* v);
int get_vector_data(ceps::ast::node_t v);