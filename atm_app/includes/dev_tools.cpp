#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#include "dev_tools.h"

/*  Read dataMap in atm_app.cpp file
    * prints out the key and values in the map in this format
    * key : value_1 value_2
*/
void DevTools::readVectorMap(std::map<std::string, std::vector<std::string>> &argMap) {
    for (auto const& [key, value] : argMap) {
        std::cout << key << " : ";
        for (auto const& v : value) {
            std::cout << v << " ";
        }
        std::cout << "\n";
    }
}

/*  checkDevAcc function
    * checks if user is a admin(username starts with a_)
*/
bool DevTools::checkDevAcc(std::map<std::string, std::vector<std::string>> &argMap) {
    return false;
}

/*  alterLine function
    * finds 
*/
void DevTools::alterLine(std::string fileName, std::string findValue) {
    //Input file
    std::fstream file(fileName);
    //Output file
    std::ofstream outputFile("C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\tests\\outputData.txt");

    std::string line;

    while (std::getline(file, line)) {
        if (line.find(findValue) != std::string::npos) { continue; }
        outputFile << line << "\n";
    }

}