#include <iostream>
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