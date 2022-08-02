#pragma once
#include "ceps_ast.hh"
template <typename T> T get_key(T v) {return v;}
int get_key(int* v);
int get_key(ceps::ast::node_t v);