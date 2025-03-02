#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

class Person
{ 
    private:
        std::string name;
        std::string address;

public:
/*
* Konstruktor
 */
    Person() : name("Inget namn"), address("Ingen adress"){}
Person(std::string  name, std::string  address);

   //Destruktor
virtual~Person();
//get-metod för namn
std::string GetName() ;
//get-metod för address
std::string GetAddress() ;
virtual void Print() ;
};
#endif