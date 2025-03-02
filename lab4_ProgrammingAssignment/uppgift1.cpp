#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>

// jämförfunktion. ser om x är större än y 
bool Greater(int x, int y) {
    return x > y;
}
// Sorteringsfunktion
void sorteraVector(int& heltal) {
    std::vector<int> vec;  // Skapar en vector med heltal.

    // gnererar slumpmässiga heltal och lägger till i vektorn.
    for (int i = 0; i < heltal; i++) { //heltal = 10
        vec.push_back(i);  //varje iteration används pushback för att lägga till värdet av i i slutet av vektorn.
    }

    // Skapar en slumpgenerator.
    std::random_device rd; 
    std::mt19937 g(rd()); // random- generator- ger random siffror

    // Blandar elementen i vektorn.
    std::shuffle(vec.begin(), vec.end(), g);
// Skriver ut den slumpade vektorn.
    std::cout << "Slumpad vektor: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Sorterar vektorn.
    std::sort(vec.begin(), vec.end());

    // Skriver ut den sorterade vektorn.
    std::cout << "Sorterad vektor: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void sorteraInt(int storlek){
    int array[storlek]; //skapa en array med storlek
    std::srand(std::time(nullptr)); // Används för att generera olika slumpmässiga tal varje gång programmet körs
    for(int i = 0; i < storlek; i++) {
        array[i] = std::rand() % 100;
    }
// Skriver ut osorterad array
    std::cout << "Slumpad array: ";
    for (int i = 0; i < storlek; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    // Sorterar arrayen med std::sort
    std::sort(array, array + storlek);

    // Skriver ut sorterad array
    std::cout << "Sorterad array: ";
    for (int i = 0; i < storlek; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void sorteraVectorSjunkande(int heltal) {
    std::vector<int> vec;  // Skapar en vector med heltal.

    // Genererar slumpmässiga heltal och lägger till i vektorn.
    for (int i = 0; i < heltal; i++) { //heltal = 10
        vec.push_back(i);  //varje iteration används pushback för att lägga till värdet av i i slutet av vektorn.
    }

    // Skapar en slumpgenerator.
    std::random_device rd; 
    std::mt19937 g(rd()); // slumpgenerator istället för random_shuffle (den fungerar inte)

    // Blandar elementen i vektorn.
    std::shuffle(vec.begin(), vec.end(), g);
// Skriver ut den slumpade vektorn.
    std::cout << "Slumpad vektor: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Sorterar vektorn i sjunkande ordning med std::sort (rbegin och rend)
    std::sort(vec.rbegin(), vec.rend());

    // Skriver ut den sorterade vektorn i sjunkande ordning.
    std::cout << "Sorterad vektor i sjunkande ordning: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void sorteraIntSjunkande(int storlek)
{   int array[storlek]; //skapa en array med storlek
    std::srand(std::time(nullptr)); // Används för att generera olika slumpmässiga tal varje gång programmet körs
    for(int i = 0; i < storlek; i++) {
        array[i] = std::rand() % 100;
    }
// Skriver ut osorterad array
    std::cout << "Slumpad array: ";
    for (int i = 0; i < storlek; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

// Sorterar arrayen i sjunkande ordning med std::sort och Greater-funktionen
    std::sort(array, array + storlek, Greater);

    // Skriver ut sorterad array
    std::cout << "Sorterad array i sjunkande ordning: ";
    for (int i = 0; i < storlek; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}



void uppgift1a() {
    int heltal = 10;
    std::cout << "uppgift 1a). svar: " << std::endl;
    sorteraVector(heltal);
}

void uppgift1b() {
    int storlek = 10;
    std::cout << "uppgift 1b). svar: " << std::endl;
    sorteraInt(storlek);
}

void uppgift1c() {
int heltal = 10;
std::cout << "uppgift 1c). svar: " << std::endl;
sorteraVectorSjunkande(heltal);

}
void uppgift1d() {
int storlek = 10;
std::cout << "uppgift 1d). svar: " << std::endl;
sorteraIntSjunkande(storlek);
}

int main() {
    uppgift1a();
    std::cout << std::endl;
    uppgift1b();
    std::cout << std::endl;
    uppgift1c();
    std::cout << std::endl;
    uppgift1d();

    return 0;
}
