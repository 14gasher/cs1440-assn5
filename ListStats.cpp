#include "ListStats.hpp"
#include "List.hpp"
#include "math.h"

#include <iostream>


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

// Unique Count
unsigned int unique_wages(Employment *emp){
    auto vec = generateHistogram(emp);
    int uniqueCount = 0;
    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i][1] == 1){
            uniqueCount++;
        }
    }
    
    return uniqueCount;
}


// Distinct Wages
unsigned int distinct_wages(Employment *emp){
    return generateHistogram(emp).size();
}



std::vector< std::vector<unsigned long> > generateHistogram(Employment *emp){
    std::vector<std::vector<unsigned long>> vec = {};

    auto count = list_length(emp);
    auto current = emp;
    
    for(int i = 0; i < count; i++){
        
        auto currentWage = current->total_annual_wages;
        bool found = false;
        
        for(unsigned int j = 0; j < vec.size(); j++){
            if(vec[j][0] == currentWage){
                found = true;
                vec[j][1]++;
            }
        }
        
        if(!found){
            std::vector<unsigned long> newNumber = {currentWage, 1};
            vec.push_back(newNumber);
        }
        
        current = current->next;
    }
    
    return vec;
}