#include "List.hpp"
#include <fstream>
#include <iostream>


// TODO: implement this function - Check
Employment* build_empl_list(std::string filename) {
    Employment* head;
    Employment* current;
    std::ifstream file(filename);
    if(!file){
        return nullptr;
    } else {
        std::string ignoreMe;
        file >> ignoreMe >> ignoreMe >> ignoreMe >> ignoreMe;
        std::string area_fips;
        unsigned long annual_avg_estabs, annual_avg_emplvl, total_annual_wages;
        
        // Initialize first part
        file >> area_fips >> annual_avg_estabs >> annual_avg_emplvl >> total_annual_wages;
        current = new Employment(area_fips, annual_avg_estabs, annual_avg_emplvl, total_annual_wages);
        
        // Save the head of the list
        head = current;
        
        while(file >> area_fips >> annual_avg_estabs >> annual_avg_emplvl >> total_annual_wages){
            current->next = new Employment(area_fips, annual_avg_estabs, annual_avg_emplvl, total_annual_wages);
            current = current->next;
            
        }
        current = nullptr;
        return head;
    }
    
}



// TODO: implement this function - Clear
void print_every_empl(Employment *emp) {
    while(emp != nullptr){
        std::cout << *emp << std::endl;
        emp = emp->next;
    }
}



// TODO: implement this function
int list_length(Employment *emp) {
    int count = 0;
    while(emp != nullptr){
        count++;
        emp = emp->next;
    }
    return count;
}



// TODO: implement this function
void append_lists(Employment* head, Employment* tail) {
    auto cool = head;
    while(cool->next != nullptr){
        cool = cool->next;
    }
    cool->next = tail;
    tail = nullptr;
}

void cleanup_list(Employment* list){
    auto cool = list->next;
    auto prev = list;
    while(cool != NULL){
        delete prev;
        prev = cool;
        cool = cool->next;
    }
    delete prev;
    
}

