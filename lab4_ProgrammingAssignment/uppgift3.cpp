#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Funktion för att kontrollera om ett tal är jämnt
bool Even(int i) {
    return i % 2 == 0;
}

// Funktion för att skapa och hantera vektorn
void hanteraVektor() {
    std::vector<int> vec; // Skapa en vector för att lagra heltal

    // Generera slumpmässiga tal och lägg till i vektorn
    std::srand(std::time(nullptr)); // slumpmässigt, baserat på tid okså.
    for (int i = 0; i < 15; i++) {
        vec.push_back(std::rand() % 100); // Lägg till slumpmässiga heltal mellan 0 och 99
    }

    // Skriv ut den osorterade vektorn
    std::cout << "Osorterad vektor: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Använd std::remove_if och std::erase för att ta bort alla jämna tal
    vec.erase(std::remove_if(vec.begin(), vec.end(), Even), vec.end());

    // Skriv ut vektorn efter att de jämna talen tagits bort
    std::cout << "Vektor efter att jämna tal tagits bort: ";
    for (int v : vec) { //loopa genom vector.
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    hanteraVektor(); // Kör funktionen för att skapa, skriva ut och modifiera vektorn
    return 0;
}
