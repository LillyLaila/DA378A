#ifndef PERSONMEDTEL_H
#define PERSONMEDTEL_H
#include "Person.h"
#include <iostream>


class PersonMedTel : public Person {
    private:
         std::string nummer;
    public:
        PersonMedTel() : Person(), nummer("Okänt nummer"){}
        PersonMedTel(std::string name, std::string nummer, std::string address) : Person(name, address), nummer(nummer) {}

        std::string getNummer();

         void Print();
};


#endif