#include "PersonMedTel.h"
#include "Person.h"

std::string nummer; 



std::string PersonMedTel::getNummer()
{
	return nummer;
}

void PersonMedTel::Print (){
	std::cout << Person::GetName() << ", Telefon: " << nummer << "\n" << Person::GetAddress() << std::endl;

}
