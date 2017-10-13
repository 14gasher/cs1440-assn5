#include "ListStats.hpp"
#include "List.hpp"
#include "math.h"

// TODO: implement this function - clear
unsigned long total_annual_wages(Employment *emp) {
    auto l = list_length(emp);
    auto c = emp;
    unsigned long wages = 0;
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
    unsigned long wages = c->total_annual_wages;
    for(int i = 0; i < l; i++){
        if(c->total_annual_wages < wages){
            wages = c->total_annual_wages;
        }
        
        c = c->next;
    }
    return wages;
}



// TODO: implement this function
unsigned long max_annual_wages(Employment *emp) {
    auto l = list_length(emp);
    auto c = emp;
    unsigned long wages = c->total_annual_wages;
    for(int i = 0; i < l; i++){
        if(c->total_annual_wages > wages){
            wages = c->total_annual_wages;
        }
        
        c = c->next;
    }
    return wages;
}



// TODO: implement this function
float stdev_annual_wages(Employment *emp) {
    const int count = list_length(emp);
    const double mean = static_cast<double>(total_annual_wages(emp))/count;
    auto current = emp;
    double internalSum = 0.0;
    for(int i = 0; i < count; i++){
        internalSum += pow(current->total_annual_wages - mean, 2.0);
        current = current->next;
    }
    
    return static_cast<float>(pow(internalSum / count, 0.5));
}



/* TODO: implement this function
<<<<<<< HEAD
int unique_annual_wages(Employment *emp) {
    
=======
unsigned total_annual_emplvl(Employment *emp) {
>>>>>>> ad99328bf536220449b20ddbd3e15d3d2e6161d0
}
*/



/* TODO: implement this function
unsigned max_annual_emplvl(Employment *emp) {
}
*/


/* TODO: implement this function
unsigned min_annual_emplvl(Employment *emp) {
}
*/


/* TODO: implement this function
unsigned total_annual_estabs(Employment *emp) {
}
*/


/* TODO: implement this function
unsigned max_annual_estabs(Employment *emp) {
}
*/


/* TODO: implement this function
unsigned min_annual_estabs(Employment *emp) {
}
*/
