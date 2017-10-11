#include <iostream>
// REMOVE THIS!!!
#include <iomanip>

#include "List.hpp"
#include "ListStats.hpp"
#include "Report.hpp"



int main(void) {
	// Read in all employment lists
	auto list = build_empl_list("data/01.txt");
	for(int i = 2; i < 79; i++){
		std::string toAdd = "";
		if(i < 10){
			toAdd = "0" + std::to_string(i);
		} else {
			toAdd = std::to_string(i);
		}
		auto temp = build_empl_list("data/" + toAdd + ".txt");
		
		// Append them into one list
		append_lists(list, temp);
	}


	// Compute the statistics

	// Fill out the report
	Report rpt;

	rpt.num_areas      = list_length(list);

	rpt.gross_wages    = total_annual_wages(list);
	rpt.min_wages      = min_annual_wages(list);
	rpt.max_wages      = max_annual_wages(list);
	rpt.stdev_wages    = stdev_annual_wages(list);
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
