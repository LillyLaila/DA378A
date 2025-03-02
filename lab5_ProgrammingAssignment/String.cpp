#include "String.h"
#include <cstring>
#include <iostream>
#include <cassert>



// Konstruktor - null värden 
String::String() :str(nullptr), kapacitet(0), storlek(0)
{
    
}
// Copy-konstruktor - kopierar ett till String-objekt. Är till för att förhindra delad minneshantering mellan objekt.Varje String har sitt eget dynamiska minne. 
String::String(const String &rhs) : str(nullptr), kapacitet(rhs.kapacitet), storlek(rhs.storlek)
{
    str = new char[kapacitet]; //Nytt minne allokeras på heap, lika stort som kapaciteten.

    std::copy(rhs.str, rhs.str + storlek, str); //Kopierar innehåller i rhs.str (startadress) till nya minnesblocket str. (rhs.str + storlek) - slutet av datamängd som ska kopierar.
}

// Den här metoden skapar en String från en C-string. cstr avslutas med \0
String::String(const char *cstr) 
{
    storlek = std::strlen(cstr); //Storlek på C-string
    kapacitet = storlek; //Tilldela samma värde
    std::cout << "Kapacitet för C-string: " << kapacitet << std::endl;
    
    str = new char[kapacitet];
    std::copy(cstr,cstr + storlek, str); //kopierar c-string

  
}
// Copy assignment - Tilldelningsoperator, skapar en djup kopia av rhs.  
String& String::operator=(const String &rhs)
{
    if (&rhs != this) //Kontrollera så att objektet inte har raderats och kopierats till sig själv.g
	{
		if (str)  
			delete[] str; //frigöra gammalt minne 

		storlek = rhs.size();
		kapacitet = rhs.capacity();
		str = new char[kapacitet]; //nytt minne allokeras med ny kapacitet 
        std::copy(rhs.str,rhs.str + storlek, str); //kopierar c-string

		
	}
	return *this; //referens till *this, vänstra String-objekt  så att man kan göra tilldelningar a=b, b=c etc
}
//Destruktorn - frigör allokerat minne. 
String::~String()
{    
    delete[] str; 
}
//Den här metoden kontrollerar så att storleken inte överskrider kapacitet
void String::Invariant() const
{
    assert(size() <= capacity());
}

// Indexerar utan range check, För anrop av normala String, Ger tillgång till normala tecken.
char& String::operator[](size_t i)
{
    return str[i];
}
// Indexerar utan range check, För anrop av const String. 
const char& String::operator[](size_t i) const
{
    return str[i];
}
// Hur många tecken i strängen
size_t String::size() const
{
    return storlek;
}
// Returnerar Max kapacitet som kan lagras i strängen.
size_t String::capacity() const
{
    return kapacitet;
}
// Lägger till ett tecken sist
void String::push_back(char c) {
        if (storlek  >= kapacitet) {//Om sträng överskrider kapacitet
        kapacitet = (kapacitet == 0) ? 1 : 2 * kapacitet; //bestäm hur mkt kapacitet som behövs läggas till. Om kapacitet == 0 (sträng är ny ,elr inget värde har tilldelats) ställs den till 1. Annars fördubblas kapaciteten.
        reallocate(kapacitet);

    }
    str[storlek++] = c;  // lägg till tecknet och samtidigt öka storleken.
}

// Utöka kapaciteten
void String::reallocate(size_t new_cap) {
    char* newStr = new char[new_cap];
    std::copy(str, str + storlek, newStr); //kopiera befintligt innehåll.

    delete[] str;
    str = newStr;
}
// Out-of-class definition, Jämför två string-objekt för att se om de har samma storlek &innehåll.
 bool operator==(const String &lhs, const String &rhs) {
    	if (lhs.size() == rhs.size()) //kontrollera om de har samma storlek. 
	{
		for (size_t i = 0; i < lhs.size(); i++) //lhs.size == rhs.size,  
		{
			if (lhs[i] != rhs[i]) //Kollar om det finns tecken som inte matchar 
			{
				return false; //om det hittas några tecken som inte matchar. 
			}
		}
		return true; //Om alla tecken matchar, lhs och rhs  är equal
	}
	return false;
 }
// Out-of-class definition - Returnerar true om två String-objekt inte är lika
 bool operator!=(const String &lhs, const String &rhs) {
    	return ! (lhs == rhs);

 }
// För testning, Ger en pekare till arrayen som innehåller strängen, ej avslutad med \0
const char* String::data() const {
    return str;
}
// friend- out of class definition, Skriver ut strängens innehåll till output-stream
 std::ostream &operator<<(std::ostream &out, const String &rhs)
{
    for (size_t i = 0; i < rhs.storlek; ++i)
        out << rhs.str[i];
    return out;
}
