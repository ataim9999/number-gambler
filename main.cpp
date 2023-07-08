//=======================================================================
//
//
//              github.com/ataim9999/number-gambler
//
//  ██████   █████  ███    ███ ██████  ██      ███████ ██████  
// ██       ██   ██ ████  ████ ██   ██ ██      ██      ██   ██ 
// ██   ███ ███████ ██ ████ ██ ██████  ██      █████   ██████  
// ██    ██ ██   ██ ██  ██  ██ ██   ██ ██      ██      ██   ██ 
//  ██████  ██   ██ ██      ██ ██████  ███████ ███████ ██   ██ 
//
// This project is made by ataim9999
// I made this to practice C++
// This is not a real gamble game, it is just a number guesser
//
//
//=======================================================================


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <limits>

std::string name = "number gambler";
std::string separator = " ~ ";
std::string version = "1.0.0";

void sleep(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    system("cls");

    double num;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomNumber = (std::rand() % 10) + 1;

    std::cout << "===================================================" << std::endl;
    std::cout << name << separator << version << std::endl;
    std::cout << "===================================================" << std::endl;

    std::cout << "Generating a random number..." << std::endl;
    sleep(1500);

    int chances = 5;
    bool correctGuess = false;

    while (chances > 0 && !correctGuess) {
        std::cout << "Guess a number (chances left: " << chances << "): ";
        std::cin >> num;

        if (num == randomNumber) {
            std::cout << "Correct! The number was: " << randomNumber << std::endl;
            correctGuess = true;
        } else {
            std::cout << "Incorrect guess!" << std::endl;
            chances--;
        }
    }

    if (!correctGuess) {
        std::cout << "Out of chances. The number was: " << randomNumber << std::endl;
    }

    std::cout << "Press enter to exit: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
