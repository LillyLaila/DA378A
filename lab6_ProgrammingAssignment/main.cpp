#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Interpreter.h"

// Den här funktionen gör en rad tokenized till en vector av strings based on whitespace " "
std::vector<std::string> tokenize(const std::string& line) {
    std::istringstream stream(line);
    std::vector<std::string> tokens;
    std::string token;
    while (stream >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::ifstream inputFile("code.c@");
    std::ofstream outputFile("output.txt");

    
    
    if (!inputFile.is_open()) { //om den inte är öppen 
        std::cerr << "Failed to open input file.\n";
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Failed to open output file.\n";
        return 1;
    }

    Interpreter interpreter(outputFile); // Skapar en Interpreter med en output stream 
    std::string line;

    while (std::getline(inputFile, line)) { //sålänge det finns en rad att hämta 
        std::vector<std::string> tokens = tokenize(line);
        if (!tokens.empty()) {
            try {
                interpreter.evaluate(tokens); // Processera varje rad av tokens 
            } catch (const std::runtime_error& e) {
                std::cerr << "Error!!!! : " << e.what() << "\n";
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
