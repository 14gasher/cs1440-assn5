#pragma once

#include <string>

#include "Employment.hpp"

/* implement these functions */
Employment* build_empl_list(std::string filename);

void print_every_empl(Employment *emp);

int list_length(Employment *emp);

void append_lists(Employment* list1, Employment* list2);

void cleanup_list(Employment* list);
