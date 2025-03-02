#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif

#include "PersonReg.h"
#include "PersonMedTel.h"

#include <iostream>
#include <fstream>

using namespace std;

#if 1
#define PN(x) cout << x
#define DN(x) x
#define PD(x) cout << x
#else
#define PN(x)
#define DN(x)
#define PD(x) (x)
#endif

void Init(PersonReg &tr)
{
    tr.Töm();
    PD(tr.LäggTillTest("olle", "0703955123"));
    PD(tr.LäggTillTest("olle", "123"));
    PD(tr.LäggTillTest("kurtåke", "12345"));
    PD(tr.LäggTillTest("olle", "456"));
    PD(tr.LäggTillTest("sven", "456"));
    PD(tr.LäggTillTest("kurt", "95815"));
    PN(endl);
    PN(("fullt reg "));
    PN((endl));
    DN((tr.PrintRegister()));
}
#include <fstream>
bool ReadReg(PersonReg &reg, string fileName)
{
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            while (line.length() == 0 && getline(myfile, line))
                ;
            string name(line);
            string adress;
            getline(myfile, adress);
            Person p = Person(name, adress);
            reg.LäggTill(&p);
        }
        myfile.close();
        return true;
    }
    else
    {
        std::cout << "Unable to open file";
        return false;
    }
}
void Test1()
{
    PersonReg reg(10);
    ReadReg(reg, "PersonExempel.txt");
    reg.PrintRegister();
    cout << "\n\n";
    reg.Töm();
    reg.PrintRegister();
}
void Test2()
{
    PersonReg reg(10);
    Init(reg);
    string namn, address;
    Person *tep;
    tep = reg.SökNamn("olle");
    if (tep)
    {
        std::cout << tep->GetAddress() << endl;
        reg.TaBortEntry(tep);
    }
    else
        cout << "not found \n";
    tep = reg.SökNamn("olle");
    if (tep)
    {
        std::cout << tep->GetAddress() << endl;
        reg.TaBortEntry(tep);
    }
    else
        std::cout << "not found \n";
    tep = reg.SökNamn("olle");
    if (tep)
    {
        std::cout << tep->GetAddress() << endl;
        reg.TaBortEntry(tep);
    }
    else
        std::cout << "not found \n";
    tep = reg.SökNamn("olle");
    if (tep)
    {
        std::cout << tep->GetAddress() << endl;
        reg.TaBortEntry(tep);
    }
    else
        std::cout << "not found \n";
    tep = reg.SökNamn("olle");
    if (tep)
    {
        std::cout << tep->GetAddress() << endl;
        reg.TaBortEntry(tep);
    }
    else
        std::cout << "not found \n";
    reg.PrintRegister();
    reg.Töm();
    reg.PrintRegister();
}
void Test3()
{
    PersonReg reg(10);
    Init(reg);
    reg.PrintRegister();
    string namn, adress;
    Person *tep;
    tep = nullptr;
    while ((tep = reg.SökFritt("olle", tep)))
    {
        tep->Print();
        // cout << tep->adress << endl;
    }
    cout << "not found \n";
    cout << "blandade sökningar \n";
    Person *ptr1 = nullptr, *ptr2 = nullptr;
    bool first = true;
    while (first || ptr1 || ptr2)
    {
        if (ptr1 || first)
        {
            ptr1 = reg.SökFritt("olle", ptr1);
            if (ptr1)
                ptr1->Print();
        }
        if (ptr2 || first)
        {
            ptr2 = reg.SökFritt("581", ptr2);
            if (ptr2)
                ptr2->Print();
        }
        first = false;
    }
}

int main()
{
    // #ifndef _DEBUG
    //    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //  #endif
    // locale::global(locale("swedish"));

    //  PersonReg reg(5);
    // Init(reg);
    // Test1();
    // Test2();
    // Test3();
    // cin.get();

    /*
        // Sökfri-funktionen----------
        std::cout << "\n-------Sökfri-funktionen--------" << std::endl;

        std::string sökUpp = "olle";
        std::cout << "\nFörsta träffen: \"" << sökUpp << "\"\n------" << std::endl;
        Person *x1 = reg.SökFritt(sökUpp, nullptr);
        if (x1)
            x1->Print();
        std::cout << "\nAndra träffen: \"" << sökUpp << "\"\n---" << std::endl;
        Person *x2 = reg.SökFritt(sökUpp, x1);
        if (x2)
            x2->Print();
        std::cout << "\nTredje träffen: \"" << sökUpp << "\"\n---" << std::endl;
        Person *x3 = reg.SökFritt(sökUpp, x2); // x3 blir tredje träffen
        if (x3)
            x3->Print();
        std::cout << "\nAndra träffen (y2): \"" << sökUpp << "\"\n---" << std::endl;
        Person *y2 = reg.SökFritt(sökUpp, x1); // Kommer åter ge andra träffen
        if (y2)
            y2->Print();


    */
    // testa att lägga till en person i arrayen
    PersonReg *reg = new PersonReg(10); // max 10 platser i arrayen
    std::cout << "\n------Printar ut hela registret: -------" << std::endl;
    std::string fileName = "Person.txt";
    ReadReg(*reg, fileName);
    reg->PrintRegister();

    // lägger till person objekt till registret
    Person *nyPerson = new Person("Jonas Eiselt", "Diamantvägen 14R, 262 70 ÄNGELHOLM");
    reg->LäggTill(nyPerson);
    std::cout << "\n------Tillagd Jonas Eiselt i Registret: -------" << std::endl;
    reg->PrintRegister();

    // Tar bort en person från registret.
    Person p("Gustav Sandberg", "Hagag 77, 443 65 STENKULLEN");
    reg->TaBortEntry(&p);
    std::cout << "\n-------Borttagningen av Gustav Sandberg--------" << std::endl;
    reg->PrintRegister();

    // Sök upp en person i listan med namnet
    std::string sökUpp = "Jonas Eiselt";
    std::cout << "\n-----Personen du sökte upp existerar i listan: \"" << sökUpp << "\"\n-------" << std::endl;
    Person *resultat = reg->SökNamn(sökUpp);
    resultat->Print();

    std::cout << "\n------Printar ut person med telefonnummer------" << std::endl;
    Person *myPerson = new PersonMedTel("Lala Sossk", "07000-0003", "Malmö universitet");
    myPerson->Print();
}
