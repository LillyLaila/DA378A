#include "Person.h"
#include "PersonReg.h"
#include <iostream>
#include <algorithm>
#include <random>

void sortera2a() {
    std::cout << "\n-------Uppgift 2a):------------ " << std::endl;

    PersonReg* reg = new PersonReg(20);

    //För att det inte ska krångla till sig så skapar man en person objekt direkt och SEN efteråt använder 
	//man dess adress. 
    Person person1("AA", "A-Gatan");
    Person person2("AA", "B-Gatan");
    Person person3("AA", "C-Gatan");
    Person person4("AA", "D-Gatan");
    Person person5("AA", "E-Gatan");
    Person person6("AA", "F-Gatan");

    reg->LäggTill(&person1);
    reg->LäggTill(&person2);
    reg->LäggTill(&person3);
    reg->LäggTill(&person4);
    reg->LäggTill(&person5);
    reg->LäggTill(&person6);

    // random_shuffle fungerar inte
	// skapa en random-generator och sen använda shuffle.
    std::cout << "-------Shuffled register: ------" << std::endl;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(reg->begin(), reg->end(), g);
    reg->PrintRegister();

    // Sortera och sen printa ut. 
    std::sort(reg->begin(), reg->end());
    std::cout << "\n---------Sorterad register:------ " << std::endl;
    reg->PrintRegister();

    delete reg;
    std::cout << std::endl;
}

void sortera2b() {
	   std::cout << "\n-------Uppgift 2b):------------ " << std::endl;
    PersonReg* reg = new PersonReg(20);

//För att det inte ska krångla till sig så skapar man en person objekt direkt och SEN efteråt använder 
	//man dess adress. 
    Person person1("AA", "A-Gatan");
    Person person2("AA", "B-Gatan");
    Person person3("AA", "C-Gatan");
    Person person4("AA", "D-Gatan");
    Person person5("AA", "E-Gatan");
    Person person6("AA", "F-Gatan");

    reg->LäggTill(&person1);
    reg->LäggTill(&person2);
    reg->LäggTill(&person3);
    reg->LäggTill(&person4);
    reg->LäggTill(&person5);
    reg->LäggTill(&person6);

    // random_shuffle fungerar inte
	// skapa en random-generator och sen använda shuffle.
    std::cout << "-------Shuffled register: ------" << std::endl;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(reg->begin(), reg->end(), g);
    reg->PrintRegister();

    // Sortera och sen printa ut. 
    std::sort(reg->begin(), reg->end());
    std::cout << "\n---------Sorterad register:------ " << std::endl;
    reg->PrintRegister();

    delete reg;
    std::cout << std::endl;
}