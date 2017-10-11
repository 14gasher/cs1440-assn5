#include <iostream>

#include "List.hpp"
#include "ListStats.hpp"
#include "Report.hpp"



int main(void) {
	// Read in all employment lists
	auto list = build_empl_list("data/01.txt");
	std::cout << "LIST LENGTH BEFORE: " << list_length(list) << std::endl;
	auto list2 = build_empl_list("data/02.txt");
	append_lists(list, list2);
	print_every_empl(list);
	std::cout << "LIST LENGTH AFTER: " << list_length(list) << std::endl;

	// Append them into one list

	// Compute the statistics

	// Fill out the report
	Report rpt;

	rpt.num_areas      = 1;

	rpt.gross_wages    = 2;
	rpt.min_wages      = 3;
	rpt.max_wages      = 4;
	rpt.stdev_wages    = 5;
	rpt.unique_wages   = 6;
	rpt.distinct_wages = 7;

	rpt.gross_emplvl   = 8;
	rpt.max_emplvl     = 9;
	rpt.min_emplvl     = 10;

	rpt.gross_estabs   = 11;
	rpt.max_estabs     = 12;
	rpt.min_estabs     = 13;

	// Print the report
	std::cout << rpt;
}
