#include <ostream>
#include "Interpreter.h"
#include <string>
#include <regex>

/*
 * Konstruktor
 */
Interpreter::Interpreter(std::ostream &out_stream)
{
    outstream = &out_stream;
    position = 0;
}
/*
 * Denna funktion ska parse och utföra alla actions i koden, som att lagra variabler, set configurations
 * och printa ut till out-stream.
 * Innan evaluate så ska koden bli "tokenized" (broken down to a sequence of strings representing code elements.
 * Start by splitting down the code into lines and then into tokens using whitespace as a separator))
 * Raw code line "value = 10 + y"
 * Tokenized code line "value", "=", "10", "+", ","
 */
void Interpreter::evaluate(const std::vector<std::string> &tokens)
{
    this->tokens = tokens;
    position = 0;
    parseStmt();
}
/*
 * Returnerar nuvarande token.
 */
std::string Interpreter::peek()
{
    return peek(0);
}
/*
 * Denna funktionen kollar ett antal steg framåt i vektorn utan att flytta nuvarande positionen.
 * Behövs för att avgöra vilken typ av statement du kommer parsa härnäst
 * om positionen överskrider slutet av token-vektorn så returneras: ETX - end of text
 */
std::string Interpreter::peek(int steps)
{
    if (position + steps >= tokens.size())
        return ETX;
    
    return tokens[position + steps];
}
/*
 * Denna funktion tar bort gamla tokens  efter de har bearbetats
 */
void Interpreter::consume(const std::string &token)
{
    std::string next_token = peek();
    if (next_token == ETX)
        throw std::runtime_error("Consumed past last token\n");
    if (next_token != token)
        throw std::runtime_error("Could not consume token " + token + "\n");

    ++position;
}

// Parsing metoder för olika statements
/* STMT = ConfigStmt | AssgStmt | PrintStmt
 */
void Interpreter::parseStmt()
{
    std::string next_token = peek();
    std::regex variabel("[a-zA-z][a-zA-z0-9]*"); // Variabel:= [a-zA-z][a-zA-z0-9]*   //regex- ger regulära uttryck

    if (next_token == "config")
    { // ConfigStmt = "config" ["dec" | "hex" | "bin"]
        consume("config");
        parseConfigStmt();
    }
    else if (std::regex_match(next_token, variabel) && peek(1) == "=")
    { // AssgStmt = Variable "=" MathExp
        // consume("="); Ta inte bort denna, kan behövas senare.
        parseAssgStmt();
    }
    else if (next_token == "print")
    { // PrintStmt = "print" MathExp
        consume("print");
        parsePrintStmt();
    }
    else
    {
        error("Token invalid: " + tokens[position]); // skriver ut om tokens position är ogiltigt
    }
}
/*
 * Sätter en konfigueration ?
 * ConfigStmt = "config" ["dec" | "hex" | "bin"]
 */
void Interpreter::parseConfigStmt()
{
    std::string next_token = peek();

    if (next_token == "dec")
    {
        consume("dec");
        print = "dec";
        *outstream << "Print är i decimal tal:  \n";
        *outstream << std::dec;
    }
    else if (next_token == "hex")
    {
        consume("hex");
        print = "hex";
        *outstream << "Print är i hexdecimala tal:  \n";
        *outstream << std::hex;
    }
    else if (next_token == "bin")
    {
        consume("bin");
        print = "bin";
        *outstream << "Print är i binära tal: \n";
    }
    else
    {
        error("Token invalid: " + tokens[position]); // skriver ut om tokens position är ogiltigt
    }
}

/*
 * Printa utskrift (resultatet) i output.
 * PrintStmt = "print" MathExp
 *
 */
void Interpreter::parsePrintStmt()
{
    // parse matematiska uttrycket
    int value = parseMathExp();
    if (print == "dec")
    {
        *outstream << std::dec << value << "\n";
    }
    else if (print == "hex")
    {
        *outstream << std::hex << "0x" << value << "\n";
    }
    else if (print == "bin")
    {
        *outstream << std::bitset<16>(value).to_string() << "\n";
    }
    else
    {
        error("Error i printStmt, finns ingen bas att printa ut");
    }
}

/*
 * Denna funktionen tilldelar resultatet av ett uttryck till en variabel
 * AssgStmt = Variable "=" MathExp
 */
void Interpreter::parseAssgStmt()
{
    std::string variabelNamn = peek(); // första token ska vara "variabel"
    if (peek() != variabelNamn)
    {
        error("Token måste ha giltig variabel: ");
    }
    consume(variabelNamn);

    if (peek() != "=") // andra token ska vara  "="
    {
        error("Token måste följa med en variabel och en = tecken.: ");
    }
    consume("=");

    int value = parseMathExp();
    variabelMap[variabelNamn] = value; // variabelnamn och value lagras i en key-value hash-table.
}

// MathExp = SumExp
int Interpreter::parseMathExp()
{
    return parseSumExp();
}

// SumExp = ProductExp ("+" ProductExp | "-" ProductExp)*
int Interpreter::parseSumExp()
{
    int sum = parseProductExp();
    std::string next_token = peek(); // kolla nästa token
    while (1)
    {
        if (next_token == "+")
        {
            consume("+");
            int value = parseProductExp();
            sum = sum + value;
        }
        else if (next_token == "-")
        {
            consume("-");
            int value = parseProductExp();
            sum = sum - value;
        }
        else
            break;

        next_token = peek();
    }

    return sum;
}
// ProductExp = PrimaryExp ("*" PrimaryExp | "/" PrimaryExp)*
int Interpreter::parseProductExp()
{
    int product = parsePrimaryExp();
    std::string next_token = peek(); // kolla nästa token
    while (1)
    {
        if (next_token == "*")
        {
            consume("*");
            int value = parsePrimaryExp();
            product = product * value;
        }
        else if (next_token == "/")
        {
            consume("/");
            int value = parsePrimaryExp();
            product = product / value;
        }
        else
            break;

        next_token = peek();
    }

    return product;
}
// Primary = Int | Variable | "()" MathExp ")"
int Interpreter::parsePrimaryExp()
{
    std::string next_token = peek(); // kolla nästa token
    std::regex nummer("-?[0-9]+"); //Int = -?[0-9]+
    std::regex variabel("[a-zA-z][a-zA-z0-9]*"); //Variable = [a-zA-z][a-zA-z0-9]*

    if (next_token == "(")
	{
		consume("(");
		int value = parseMathExp();
		consume(")");

		return value;
	}
    	else if (std::regex_match(next_token, variabel)) //det finns en variabel 
	{
		if (variabelMap.find(next_token) != variabelMap.end())
		{
			consume(next_token);
			return variabelMap.at(next_token);
		}
		else
		{
            error("Variebel är inte giltig, eller definierad. ");
		}

	}
	else if (std::regex_match(next_token, nummer)) //det finns en int
	{
		consume(next_token);
		return stoi(next_token); //stoi konverterar string till int
	}
	else 
	{
            error("Det du angav är ogiltigt, eller odefinierat. ");
	}
    return 0;
}

// hanterar errors
void Interpreter::error(const std::string &message)
{
    throw std::runtime_error("Error: " + message);
}

