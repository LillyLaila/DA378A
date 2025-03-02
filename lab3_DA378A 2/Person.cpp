#include <iostream>
#include "Person.h"
#include <string>
#include <iostream>

std::string name;
std::string address;
//Konstruktor
Person::Person(std::string name, std::string address) {
  this->name = name;
this->address = address;

}
//Destruktor
Person::~Person() {

}
//get-metod för namn
std::string Person::GetName () 
{
	return name;
}
//get-metod för address
std::string Person::GetAddress () 
{
	return address; 
}
//Print för en personobjekt
void Person::Print() {
    std::cout << "Namn:" << name << "\n" << "Address: "<< address << std::endl;
}