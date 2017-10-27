#include <iostream>

#include "List.hpp"
#include "ListStats.hpp"
#include "Report.hpp"
#include "ListSort.hpp"

int dEmp(Employment *emp){
	auto current = emp;
	auto currentVal = emp->annual_avg_emplvl;
	int count = 1;
	while(current != nullptr){
		if(currentVal != current->annual_avg_emplvl){
			currentVal = current->annual_avg_emplvl;
			count++;
		}
		current = current->next;
	}
	return count;
}
int uEmp(Employment *emp){
	auto current = emp->next;
	auto currentVal = emp->annual_avg_emplvl;
	int count = 1;
	bool notFound = true;
	while(current != nullptr){
		if(currentVal != current->annual_avg_emplvl){
			if(notFound){
				count++;
			}
			currentVal = current->annual_avg_emplvl;
			notFound = true;
			
		} else {
			notFound = false;

		}
		current = current->next;
	}
	return count;
}
int dWages(Employment *emp){
	auto current = emp;
	auto currentVal = emp->total_annual_wages;
	int count = 1;
	while(current != nullptr){
		if(currentVal != current->total_annual_wages){
			currentVal = current->total_annual_wages;
			count++;
		}
		current = current->next;
	}
	return count;
}
int uWages(Employment *emp){
	auto current = emp->next;
	auto currentVal = emp->total_annual_wages;
	int count = 1;
	bool notFound = true;
	while(current != nullptr){
		if(currentVal != current->total_annual_wages){
			if(notFound){
				count++;
			}
			currentVal = current->total_annual_wages;
			notFound = true;
			
		} else {
			notFound = false;

		}
		current = current->next;
	}
	return count;
}
int dEstabs(Employment *emp){
	auto current = emp;
	auto currentVal = emp->annual_avg_estabs;
	int count = 1;
	while(current != nullptr){
		if(currentVal != current->annual_avg_estabs){
			currentVal = current->annual_avg_estabs;
			count++;
		}
		current = current->next;
	}
	return count;
}
int uEstabs(Employment *emp){
	auto current = emp->next;
	auto currentVal = emp->annual_avg_estabs;
	int count = 1;
	bool notFound = true;
	while(current != nullptr){
		if(currentVal != current->annual_avg_estabs){
			if(notFound){
				count++;
			}
			currentVal = current->annual_avg_estabs;
			notFound = true;
			
		} else {
			notFound = false;

		}
		current = current->next;
	}
	return count;
}






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
	
	
	
	/* New Stats */
	
	list = listsort_employment_by_total_annual_wages(list);
	auto uniqueWages = uWages(list);
	auto distinctWages = dWages(list);
	
	list = listsort_employment_by_annual_avg_emplvl(list);
	auto uniqueEmp = uEmp(list);
	auto distinctEmp = dEmp(list);
	
	list = listsort_employment_by_annual_avg_estabs(list);
	auto uniqueEstabs = uEstabs(list);
	auto distinctEstabs = dEstabs(list);
	
	

	

					

	// Fill out the report
	Report rpt;

	rpt.num_areas      = list_length(list);

	rpt.gross_wages    = total_annual_wages(list);
	rpt.min_wages      = min_annual_wages(list);
	rpt.max_wages      = max_annual_wages(list);
	rpt.stdev_wages    = stdev_annual_wages(list);
	rpt.unique_wages   = uniqueWages;
	rpt.distinct_wages = distinctWages;

	rpt.gross_emplvl   = gross_emplvl;
	rpt.max_emplvl     = max_emplvl;
	rpt.min_emplvl     = min_emplvl;
	rpt.unique_emplvl  = uniqueEmp;
	rpt.distinct_emplvl= distinctEmp;

	rpt.gross_estabs   = gross_estabs;
	rpt.max_estabs     = max_estabs;
	rpt.min_estabs     = min_estabs;
	rpt.unique_estabs  = uniqueEstabs;
	rpt.distinct_estabs= distinctEstabs;
	// Print the report
	std::cout << rpt;
	
	


	
}
