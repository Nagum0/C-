#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "includes/dev_tools.h"

/* User struct */
struct User {   
    std::string name;
    std::string pin;
    int balance;
};

/* Variables */
std::map<std::string, std::vector<std::string>> dataMap;
User user;
DevTools dev; //DevTools class

/* Functions declarations */
void getUserData(std::map<std::string, std::vector<std::string>> &argMap); //Input user data to data map
void login(User &argUser); //login prompt
bool checkLogin(std::map<std::string, std::vector<std::string>> &argMap, User &argUser);

/* Main function */
int main() {
    //Read file and get user data
    getUserData(dataMap);

    //Main input/output loop
    std::cout << "--------------ATM--------------" << "\n";

    //Login prompt
    login(user);
    //Check login
    if (checkLogin(dataMap, user)) {
        std::cout << "Logged in successfully!" << "\n";
    }
    else {
        std::cout << "Incorrect username or password!" << "\n";
    }

    //Command variable
    std::string cmd;
    do {
        std::cout << "$ ";
        std::getline(std::cin >> std::ws, cmd);

        if (cmd == "!!" || cmd == "exit") { break; }
        else if (cmd == "dev_show_all_users" || cmd == "d_s_a_u") { dev.readVectorMap(dataMap); continue; }
        else { std::cout << "Command not recognized" << "\n"; continue; }

    } while (cmd != "!!");

    std::cout << "-------------------------------" << "\n";
    return 0;
}

/* Functions */

/*  getUserData function
    * reads all the data from userData file and inputs into a map<string, vector<string>>
*/
void getUserData(std::map<std::string, std::vector<std::string>> &argMap) {
    std::string fileName = "C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\atm_app\\userData.txt";
    std::ifstream file(fileName);

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string key;
            iss >> key;
            std::string value;

            while (iss >> value) {
                argMap[key].push_back(value);
            }
        }
    }

    file.close();
}

/*  login prompt function 
    * prompts login inputs
    * name, PIN
    * runs checkLogin function at the end
*/
void login(User &argUser) {
    std::cout << "Username: ";
    std::getline(std::cin >> std::ws, argUser.name);

    std::cout << "PIN: ";
    std::getline(std::cin >> std::ws, argUser.pin);
}

/*  checkLogin function 
    * goes into dataMap
    * checks if user.name is a key
        * if not returns false
    * then checks if user.pin is the first element inside the value vector for the given key(user.name)
        * if not returns false
    * prints logged in 
*/
bool checkLogin(std::map<std::string, std::vector<std::string>> &argMap, User &argUser) {
    auto itr = argMap.find(user.name);

    if (itr != argMap.end()) {
        std::cout << (*itr).second[0] << "\n";

        if (user.pin == (*itr).second[0]) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        std::cout << "Incorrect username" << "\n";
        return false;
    }
}