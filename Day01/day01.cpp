#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>


int main(){
     int input = 0;
    std::vector<int> lhs;
    std::vector<int> rhs;

    std::ifstream inputFile("day01input.txt");
    

    while(inputFile >> input){
        lhs.push_back(input);
        inputFile >> input;
        rhs.push_back(input);
    }

    std::sort(lhs.begin(), lhs.end());
    std::sort(rhs.begin(), rhs.end());

    int distance = 0;
    for (int i = 0 ; i < lhs.size() ; i++){
        distance = distance + abs(rhs.at(i) - lhs.at(i)); 
    }

    std::cout <<"distance: " <<  distance << std:: endl;

    // Similarity Score
    unsigned long sim_score = 0;
    std::unordered_map<int, int> sim_map;

    for (int value : rhs){
        sim_map[value]++;
    }

    for (auto value : lhs){
        // std::cout <<"value: " << value <<  "sim map s_value:" << sim_map[value] << std::endl;
        sim_score = sim_score + (value * sim_map[value]);
    }

    std::cout << "Simularity Score: " << sim_score << std::endl;

    return 0;
    
}