#include <iomanip>

#include "Report.hpp"

const int width = 36;

template<typename T>
void printLine(std::ostream& os, std::string label, T item) {
	os << std::left << std::setw(width) << label << item << std::endl;
}

template<typename T>
void printLine(std::ostream& os, std::string label, char prefix, T item) {
	os << std::left << std::setw(width) << label << prefix << item << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Report& rpt) {
	os  << "[============]\n"
		   "[Final Report]\n"
		   "[============]\n\n"
		   "Statistics over all industries in 2016:\n"
		   "=======================================\n"
		<< std::setprecision(12);

	printLine(os, "Count of FIPS areas in report", rpt.num_areas);

	printLine(os, "Gross annual wages", '$', rpt.gross_wages);
	printLine(os, "Minimum annual wage", '$', rpt.min_wages);
	printLine(os, "Maximum annual wage", '$', rpt.max_wages);
	printLine(os, "Population STDDEV of Annual Wages", '$', rpt.stdev_wages);
	os << std::endl;

	printLine(os, "Gross annual employment level", rpt.gross_emplvl);
	printLine(os, "Maximum annual employment level", rpt.max_emplvl);
	printLine(os, "Minimum annual employment level", rpt.min_emplvl);
	os << std::endl;

	printLine(os, "Gross number of establishments", rpt.gross_estabs);
	printLine(os, "Maximum number of establishments", rpt.max_estabs);
	printLine(os, "Minimum number of establishments", rpt.min_estabs);
	os << std::endl;

	return os;  
}
