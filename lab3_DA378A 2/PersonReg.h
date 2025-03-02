#ifndef PERSONREG_H
#define PERSONREG_H
#include "Person.h"
#include <string>


class PersonReg
{
private:
    Person *personer;
    int maxStorlek;
    int nurvarandeStorlek;

public:
    /*
     * Konstruktor
     */
    PersonReg(int maxStorlek);
    ~PersonReg();
    bool LäggTill(const Person* person) ;
    bool LäggTillTest(const std::string& namn, const std::string& adress);
    void TaBortEntry(Person *ptr);
    Person* SökNamn(const std::string& namn) const;   
    void PrintRegister() const;
    void Töm();
    Person* SökFritt(const std::string& sökEfter, Person *startOnNext) const;

};
#endif