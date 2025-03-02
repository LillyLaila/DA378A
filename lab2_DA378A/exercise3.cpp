#include <iostream>
#include <cstring> 


char* substitute_cstr(const char* input, const char before, const char* after) 
{
    //storleken på resultatsträngen beforeInput och afterInput 
    size_t beforeInput = std::strlen(input);
    size_t afterInput = std::strlen(after);
    
   
    int counter = 0; //räknar hur många "before" det finns i input string. (before='e', input='Hej på dej')
    for (size_t i = 0; i < beforeInput; ++i) {
        if (input[i] == before) {
            counter++;
        }
    }
    
    // Räkna ut hur stor resultatsträngen behöver vara
    size_t lengthResult = beforeInput + counter * (afterInput - 1);
    
    // sparar resultatet
    char* result = new char[lengthResult + 1]; // +1 för att ta bort null
    
    size_t j = 0; // Index för resultatsträngen
    for (size_t i = 0; i < beforeInput; ++i) {
        if (input[i] == before) {
            // här ersätter man before med after. 
            std::strcpy(&result[j], after);
            j += afterInput;
        } else {
            // kopierar från input till result
            result[j] = input[i];
            j++;
        }
    }
    
    // denna används för att programmet ska veta var den ska sluta exekvera, slutet på strängen.
    result[j] = '\0';
    
    return result;
} 

int main() {
    const char* input = "Hej på dej";
    char before = 'e';
    const char* after = "EEEE";

    std::cout << "Före : " << input << std::endl;
    char* resultat = substitute_cstr(input, before, after);
    std::cout << "Efter: " << resultat << std::endl;

    delete[] resultat;
}