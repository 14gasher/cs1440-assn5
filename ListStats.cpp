#include "ListStats.hpp"
#include "List.hpp"

// TODO: implement this function - clear
unsigned long total_annual_wages(Employment *emp) {
    auto l = list_length(emp);
    auto c = emp;
    unsigned wages = 0;
    for(int i = 0; i < l; i++){
        wages += c->total_annual_wages;
        c = c->next;
    }
    return wages;
}



// TODO: implement this function - clear
unsigned long min_annual_wages(Employment *emp) {
    auto l = list_length(emp);
    auto c = emp;
    unsigned wages = c->total_annual_wages;
    for(int i = 0; i < l; i++){
        if(c->total_annual_wages < wages){
            wages = c->total_annual_wages;
        }
        
        c = c->next;
    }
    return wages;
}



/* TODO: implement this function
unsigned long max_annual_wages(Employment *emp) {
}
*/


/* TODO: implement this function
float stdev_annual_wages(Employment *emp) {
}
*/


/* TODO: implement this function
int unique_annual_wages(Employment *emp) {
}
*/


/* TODO: implement this function
int distinct_annual_wages(Employment *emp) {
}
*/
