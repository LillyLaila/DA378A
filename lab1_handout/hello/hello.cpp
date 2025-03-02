#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    std::cout << "Hello World!";

    if (argc > 1) {
        std::cout << " Nice to see you, ";

        // den loopar igenom alla inparametrar och skriver ut dem
        for (int i = 1; i < argc; ++i) {
            std::cout << argv[i];

            // lägger till space mellan varje argument
            if (i < argc - 1) {
                std::cout << " ";
            }
        }

        std::cout << "!";
    }

    std::cout << std::endl;
    return 0;
}
