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
	
	unsigned long
	gross_emplvl = 0,
	max_emplvl = list->annual_avg_emplvl,
	min_emplvl = list->annual_avg_emplvl,
	gross_estabs = 0,
	max_estabs = list->annual_avg_estabs,
	min_estabs = list->annual_avg_estabs;
	
	auto current = list;
	auto length = list_length(list);
	for(int i = 0; i < length; i++){
		// Emplvl
		auto e = current->annual_avg_emplvl;
		gross_emplvl += e;
		if(e > max_emplvl){
			max_emplvl = e;
		} else if(e < min_emplvl) {
			min_emplvl = e;
		}
		
		// estabs
		e = current->annual_avg_estabs;
		gross_estabs += e;
		if(e > max_estabs){
			max_estabs = e;
		} else if (e < min_estabs){
			min_estabs = e;
		}
		
		// Get next 
		current = current->next;
		
	}
					

	// Fill out the report
	Report rpt;

	rpt.num_areas      = list_length(list);

	rpt.gross_wages    = total_annual_wages(list);
	rpt.min_wages      = min_annual_wages(list);
	rpt.max_wages      = max_annual_wages(list);
	rpt.stdev_wages    = stdev_annual_wages(list);
	rpt.unique_wages   = unique_wages(list);
	rpt.distinct_wages = distinct_wages(list);

	rpt.gross_emplvl   = gross_emplvl;
	rpt.max_emplvl     = max_emplvl;
	rpt.min_emplvl     = min_emplvl;

	rpt.gross_estabs   = gross_estabs;
	rpt.max_estabs     = max_estabs;
	rpt.min_estabs     = min_estabs;

	// Print the report
	std::cout << rpt;
	
}
