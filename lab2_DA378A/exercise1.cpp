#include <iostream>
#include <cmath> // För sqrt()


void countPrimeNumber(int n) {
    //steg 1 skapa en lista över alla tal, 2 till n  (c-array av int)
    int* listPrimeNumber = new int[n + 1];
    // Initiera arrayen med talen från 2 till n
    for (int i = 2; i <= n; ++i) {
        listPrimeNumber[i] = i;
    }

    // steg 3 och 4: Stryk ut tal som inte är primtal
    for (int p = 2; p <= std::sqrt(n); ++p) {
        if (listPrimeNumber[p] != 0) { // Om p är ett primtal, stryk ut alla dess multiplar
            for (int multiple = p * p; multiple <= n; multiple += p) {
                listPrimeNumber[multiple] = 0; // Stryk ut
            }
        }
    }

    // steg 6 skriv ut alla tal som fortfarande är markerade som primtal
    std::cout << "Primtal mindre än " << n << " är:\n";
    for (int i = 2; i <= n; ++i) {
        if (listPrimeNumber[i] != 0) {
            std::cout << listPrimeNumber[i] << " ";
        }
    }
    std::cout << std::endl;

}



int main()
{
    int n;

    std::cout << "Ange ett tal för uppräkning av primtal: " << "\n";
    std::cin >> n;

    if(n >= 2) {
        std::cout << "Ditt primtal är: " << n << "\n";
        countPrimeNumber(n);
    } else {
        std::cout << "Testa igen, primtal högre än 2 : " << "\n";

    }

    return 0;

}

