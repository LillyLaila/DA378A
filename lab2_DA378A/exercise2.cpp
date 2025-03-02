#include <iostream>
#include <string>


void substitute_str(std::string& iostring, const std::string& before, const std::string& after) {
    size_t position = 0;

    // while-loop: man söker efter första sträng i (before) från iostring med hjälp av find-metoden
    while ((position = iostring.find(before, position)) != std::string::npos) { 
        // när första sträng hittas så ersätts den med (after) med hjälp av replace-metoden
        iostring.replace(position, before.length(), after);

        // Gå över till nästa ord  och fortsätt med while-loop tils de finns inga strängar kvar.
        position += after.length();
    }
    
}

int main()
{

    std::string iostring = "Hej på dej";
    std::string before = "ej";
    std::string after = "ig"; 

    std::cout << "Före : " << iostring << std::endl;
    substitute_str(iostring, before, after);
    std::cout << "Efter: " << iostring << std::endl;

    return 0;

}