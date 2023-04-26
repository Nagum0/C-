#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main() {
    //Opens main file
    std::fstream inputFile("C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\tests\\testData.txt");
    //Creates new output file
    std::ofstream outputFile("C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\tests\\outputData.txt");

    std::string line;

    //The value I'm searching for
    std::string searchValue = "Astolfo";

    while (std::getline(inputFile, line)) {
        //If the line contains the value we skip it
        if (line.find(searchValue) != std::string::npos) {
            continue;
        }

        //Otherwise, write the line to the output file
        outputFile << line << "\n";
    }

    outputFile << "Astolfo 1111 3000$" << "\n"; 

    //Close files
    inputFile.close();
    outputFile.close();

    //Remove the origial file and rename the output file
    std::remove("C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\tests\\testData.txt");
    std::rename("C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\tests\\outputData.txt", "C:\\Users\\csabe\\OneDrive\\Documents\\01 C++\\tests\\testData.txt");
}