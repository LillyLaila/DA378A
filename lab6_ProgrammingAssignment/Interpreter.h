#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>

class Interpreter
{

private:
    std::vector<std::string> tokens = {"1", "&&", "1", "<", "2", "&&", "0", "||", "(", "1", "==", "1", ")"};
    int position = 0;
    std::ostream *outstream;
    const std::string ETX = "\u0003"; // end of text
    std::string peek(int steps);
    std::string peek();
    void consume(const std::string &token);

    std::map<std::string, int> variabelMap;

    std::string print;

    // Parse metoder för olika statements
    void parseStmt();
    void parseConfigStmt();
    void parsePrintStmt();
    void parseAssgStmt();

    // Parse metoder för olika matematiska uttrycfk
    int parseMathExp();
    int parseSumExp();
    int parseProductExp();
    int parsePrimaryExp();

    // Error hantering
    void error(const std::string &message);

public:
    // Konstruktor med en outputstream
    Interpreter(std::ostream &out_stream);

    // Evaluate tokens
    void evaluate(const std::vector<std::string> &tokens);
};

#endif // INTERPRETER_H
