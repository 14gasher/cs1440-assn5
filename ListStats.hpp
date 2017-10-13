#pragma once

#include "Employment.hpp"

/* implement these functions */
unsigned long total_annual_wages(Employment *emp);

unsigned long min_annual_wages(Employment *emp);

unsigned long max_annual_wages(Employment *emp);

float stdev_annual_wages(Employment *emp);

unsigned total_annual_emplvl(Employment *emp);

unsigned max_annual_emplvl(Employment *emp);

unsigned min_annual_emplvl(Employment *emp);

unsigned total_annual_estabs(Employment *emp);

unsigned max_annual_estabs(Employment *emp);

unsigned min_annual_estabs(Employment *emp);
