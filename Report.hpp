#pragma once

#include <ostream>


class Report {
	public:

		int           num_areas;

		unsigned long gross_wages;
		unsigned long min_wages;
		unsigned long max_wages;
		float         stdev_wages;
		int           unique_wages;
		int           distinct_wages;

		unsigned      gross_emplvl;
		unsigned      max_emplvl;
		unsigned      min_emplvl;
		int           unique_emplvl;
		int           distinct_emplvl;

		unsigned      gross_estabs;
		unsigned      max_estabs;
		unsigned      min_estabs;
		int           unique_estabs;
		int           distinct_estabs;

		Report() {};
		~Report() { };

		friend std::ostream& operator<<(std::ostream& os, const Report& rpt);  
};
