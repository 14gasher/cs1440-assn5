#pragma once

#include <vector>
#include "Employment.hpp"

/* implement these functions */
unsigned long total_annual_wages(Employment *emp);

unsigned long min_annual_wages(Employment *emp);

unsigned long max_annual_wages(Employment *emp);

float stdev_annual_wages(Employment *emp);

unsigned int unique_wages(Employment *emp);

unsigned int distinct_wages(Employment *emp);

std::vector< std::vector<unsigned long> > generateHistogram(Employment *emp);

