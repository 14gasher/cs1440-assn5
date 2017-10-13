# This message is brought to you by the number 01010101 01010011 01000001

Employment and wage data courtesy the US Federal Government Bureau of Labor and
Statistics

* https://www.bls.gov/cew/datatoc.htm
* https://data.bls.gov/cew/doc/titles/industry/industry_titles.htm
* https://data.bls.gov/cew/doc/titles/area/area_titles.htm
* https://data.bls.gov/cew/doc/titles/ownership/ownership_titles.htm
* https://data.bls.gov/cew/doc/layouts/csv_annual_layout.htm

# Important updates

* You should not modify the files in the data/ directory in order to make
  your program work properly. This includes renaming the files.  We will grade
  your work by using files with different contents than the working set you
  were provided. If your program requires that the input files be formatted in
  a particular way to ensure proper operation, your submission will not fare
  well upon grading.

* You are no longer required to compute counts of unique and distinct wages. If
  you have already impemented these functions you are eligible for some extra
  credit points. Please leave a note for the grader on your Canvas submission
  to let them know to look for the code. The rubric has been updated to reflect
  this change in requirements.

* I have added function prototypes to ListStats.hpp describing functions that
  you should implement, but which were left out of the initial version of this
  file. These functions correspond to statistics which have been required from
  the start, and some of you may have already written your own functions to
  make these computations. If you have already written these functions, you
  don't have to change them to match my suggested names or function signatures.
  I'm not particular about the names of the functions, but I do want you to
  write modular, well-named code.

* You are required to use my Report class (unmodified) for output. Just because
  it isn't listed on the rubric doesn't mean that this is optional.


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
