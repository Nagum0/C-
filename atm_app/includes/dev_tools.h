#include <iostream>
#include <map>
#include <vector>

#ifndef DEVTOOLS_H
#define DEVTOOLS_H

class DevTools {
    public:
        void readVectorMap(std::map<std::string, std::vector<std::string>> &argMap);
};

#endif