#include "PersonReg.h"
#include <iostream>
#include "Person.h"
#include <string>



Person* personer;
int nurvarandeStorlek;
//Konstruktor som tar max antal personer (maxStorlek)
PersonReg::PersonReg(int  maxStorlek) {
    this-> maxStorlek = 10;
    this->nurvarandeStorlek = 0;

    personer = new Person[maxStorlek];

}
//Destruktor: körs när man gör delete på personregistret 
PersonReg::~PersonReg(){
    delete[] personer;
}
/* 
* Lägger till en personobjekt, tar en pekare till en personobjekt som parameter, kopieras sedan in på rätt plats i arrayen. 
* returnerar true om det gick att lägga till
*/
bool PersonReg::LäggTill(const Person* person) {
    if(nurvarandeStorlek >= maxStorlek) { //kontrollera om det finns plats i arrayen
        return false;
    }
    personer[nurvarandeStorlek++] = *person;  //kopiera innehåll från *person till platsen i arrayen som är tom (nuvarandestorlek++)
    return true;


}

bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress){
    // Kontrollera om registret är fullt
    if (nurvarandeStorlek >= maxStorlek) {
        std::cerr << "Kunde inte lägga till: registret är fullt." << std::endl;
        return false;
    }

    // Lägg till en ny person i registret
    personer[nurvarandeStorlek] = Person(namn, adress);
    nurvarandeStorlek++;

    return true;
}

//Tar bort en person från arrayen, 
/*
* Kollar först om personen finns med i listan genom att jämföra namn och efternamn, om personen
* Inte finns med så får man ett felmeddelande, 
* Annars tas personen bort och antalet personer i arrayen minskas.
*OBS!! tar nt bort från txt.filen utan bara arrayen
*/
void PersonReg::TaBortEntry(Person* ptr){ // pekare ptr till personen som ska bort
 int indexToDelete = -1; //index till den som ska bort

    for (int i = 0; i < nurvarandeStorlek; ++i) { //gå genom registret
        if (personer[i].GetName() == ptr->GetName() &&
            personer[i].GetAddress() == ptr->GetAddress()) {
            indexToDelete = i; //matchning hittas, index sparas på personen 
            break;
        }
    }
//här flyttas alla ett steg bakåt i arrayen där personen togs bort för att fylla tomrummet
    if (indexToDelete != -1) { //kolla om personen hittas
        for (int k = indexToDelete; k < nurvarandeStorlek - 1; ++k) { 
            personer[k] = personer[k + 1];
        }
        nurvarandeStorlek--;
    } else {
        std::cout << "Personen du namngav finns inte i registret!" << std::endl;
    }

}
/*
* Söker upp en person med namn
*/
Person* PersonReg::SökNamn(const std::string& namn) const  { //konstant referens till string som representerar namnet man ska söka efter    
    // iterera genom alla personer objekt mha en pekare
   for (Person* ptr = personer; ptr != personer + nurvarandeStorlek; ++ptr) {
	if ((ptr->GetName()).compare(namn) == 0)
		{
			return ptr;
		}
    }
    return nullptr;
    }

//Printar ut hela registret 
void PersonReg::PrintRegister()const {
   
	for (Person* ptr = personer; ptr != personer + nurvarandeStorlek; ++ptr) 
	{
		ptr->Print();
	}

    
}
//Tömmer personerna i arrayen
void PersonReg::Töm(){
        nurvarandeStorlek = 0; 

}
/*
*Fritextsökning - Sökfunktion som kollar om personen har de namnet och adressen 
* Param 1 - tar en sträng
* Param 2  - en pekare till den senaste träffen 
* Ska limma starta om sökningen från början av registret.
*/
Person* PersonReg::SökFritt(const std::string& sökEfter, Person *startOnNext) const 
{
    // Starta vid nästa element efter startOnNext eller börja från början
    Person* start = startOnNext ? startOnNext + 1 : personer;

    // Iterera över registren men håll dig inom de nuvarande storleken gränserna
    for (Person* ptr = start; ptr != personer + nurvarandeStorlek; ++ptr) {
        // Kolla  efter namn eller adress matchning, (-1 betyder att den inte har hittat )
       	if ((ptr->GetName()).find(sökEfter, 0) != -1 || (ptr->GetAddress()).find(sökEfter, 0) != -1){
			return ptr; // Returnera pekaren till denna person
        }
    }

    // Om ingen träff finns returnera nullptr 
    return nullptr;
}



