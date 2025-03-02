#include <iostream>

int main( ) {
    std::int32_t sum = 0;
    std::int32_t number;


    std::cout << "Ange tal (avsluta med Ctrl-D):" << "\n";

    //en while-loop, adderar alla numbers till sum. avslutas när användare matar in control+D
    while (std::cin >> number) {
        std::cout << "Read number: " << number << "\n";  // printar varje nummer 

        sum = sum + number;
    }
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
    
}
