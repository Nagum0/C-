#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>

#include "includes/dev_tools.h"

/* User struct */
struct User {   
    std::string name;
    std::string pin;
    std::string balance;
};

/* Variables */
std::map<std::string, std::vector<std::string>> dataMap;
User user;
DevTools dev; //DevTools class

/* Functions declarations */
void getUserData(std::map<std::string, std::vector<std::string>> &argMap); //Input user data to data map
void login(User &argUser); //login prompt
bool checkLogin(std::map<std::string, std::vector<std::string>> &argMap, User &argUser); //Check login 
void signUp(User &user); //Sign up function
std::string genPin(); //Generate 4 digit PIN function
void saveSignUpData(User &user); //Saves sign up data to userData.txt file
void showPersonalInfo(User user); //Shows personal info

/* Main function */
int main() {
    //Read file and get user data
    getUserData(dataMap);
    std::cout << "--------------ATM--------------" << "\n";

    /* Login */
    //Login prompt
    login(user);
    //Check login
    if (checkLogin(dataMap, user)) {
        std::cout << "Logged in successfully!" << "\n";
    }
    else {
		std::string tempCmd;

        std::cout << "Incorrect username or password!" << "\n";
		std::cout << "Type `exit` or `sign_up` to continue: ";
		std::getline(std::cin >> std::ws, tempCmd);

		if (tempCmd == "exit") {
            std::cout << "-------------------------------" << "\n";
			return 1;
		}
		else if (tempCmd == "sign_up") {
			signUp(user);
		}
    }

    //Command variable
    std::string cmd;

    /* Mainloop */
    do {
        std::cout << "$ ";
        std::getline(std::cin >> std::ws, cmd);

        if (cmd == "!!" || cmd == "exit") { break; }
        //User tools
        else if (cmd == "info" || cmd == "person" || cmd == "user") { showPersonalInfo(user); continue; }
        //Developer tools
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
        if (user.pin == (*itr).second[0]) {
            user.balance = (*itr).second[1]; //Assign user.balance value
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

/*  signUp function
    * takes input for user.name
    * generates 4 digit pin for user.pin using the `genPin` function
    * takes input for user.balance
*/
void signUp(User &user) {
    std::cout << "Username: ";
    std::getline(std::cin >> std::ws, user.name);

    std::cout << "Generating PIN..." << "\n";
    user.pin = genPin();
    //Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "New PIN: " << user.pin << "\n";

    std::cout << "Account balance: ";
    std::cin >> std::ws >> user.balance;

    //Confirmation
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Your account info: " << user.name << " " << user.pin << "\n";
    std::cout << "Confirm (Y/N): ";
    std::string confirm;
    std::cin >> std::ws >> confirm;

    if (confirm == "Y" || confirm == "yes" || confirm == "Yes" || confirm == "YES") {
        saveSignUpData(user);
        std::cout << "Account registered!" << "\n";
    }
    else {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Retry..." << "\n";
        signUp(user);
    }
}

/*  genPin function 
    * generates 4 digit string PIN for user
*/
std::string genPin() {
    //PIN
    std::string PIN;

    //Seeding the random number generator
    std::srand(std::time(nullptr));

    //Gen random number between 0 and 9999
    int randNum = std::rand() % 10000;

    //Turning randNum into string and adding 0-s to its end until it is 4 digits long
    PIN = std::to_string(randNum);
    while (PIN.length() < 4) {
        PIN = "0" + PIN;
    } 

    return PIN;
}

/*  saveSignUpData function
    * opens userData.txt file
    * writes user.name user.pin and user.balance in this order to the end of the file
*/
void saveSignUpData(User &user) {
    std::string fileName = "C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\atm_app\\userData.txt";
    
    //Opening file in append mode
    std::ofstream file(fileName, std::ios_base::app);

    if (!file.is_open()) {
        std::cerr << "An error occured..." << "\n";
    }

    file << user.name << " " << user.pin << " " << user.balance << "\n";

    file.close();
}

/*  showPersonalInfo
    * prints personal user info to the screen if entered PIN = user.pin
*/
void showPersonalInfo(User user) {
    std::string tempPin;

    std::cout << "\n" << "Enter PIN: ";
    std::cin >> std::ws >> tempPin;

    if (tempPin == user.pin) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Name: " << user.name << " PIN: " << user.pin << " Balance: " << user.balance << "$" << "\n" << "\n";
    }
    else {
        std::cerr << "Incorrect PIN!" << "\n" << "\n";
    }
}