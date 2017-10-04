# This message is brought to you by the number 01010101 01010011 01000001

Employment and wage data courtesy the US Federal Government Bureau of Labor and
Statistics

* https://www.bls.gov/cew/datatoc.htm
* https://data.bls.gov/cew/doc/titles/industry/industry_titles.htm
* https://data.bls.gov/cew/doc/titles/area/area_titles.htm
* https://data.bls.gov/cew/doc/titles/ownership/ownership_titles.htm
* https://data.bls.gov/cew/doc/layouts/csv_annual_layout.htm

## Linked Lists

This assignment is to implement a similar system to your previous homework
using linked-lists instead of arrays.

The Employment class is now a data structures suitable to be linked together
into a singly-linked list.

Instead of a database of hardcoded arrays, this iteration of the assignent
provides the same data in several text files under the data/ directory.

Implement the functions named in List.hpp. These functions will convert text
files (e.g.  data/01.txt, data/02.txt, etc.) into linked lists of Employment
objects, print the items in the lists, measure their length and join them
together into one list.

Next, write implementations for the functions named in ListStats.hpp which will
traverse your mega-list looking for minimum, maximum values, counting unique
and distinct elements, and computing the population standard deviation.

Finally, instantiate a Report object (newly-updated for this assignment) and
fill in all of its members with the outcome of your statistical functions.  You
are free to create any helper functions to assist you in traversing your lists
and filling out the Report object for final submission.
