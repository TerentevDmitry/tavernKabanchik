#include "PrintScreen.h"


void printMenu()
{
	

	std::cout << "1. Начать игру" << std::endl;
	std::cout << "2. Побазарить с барменом" << std::endl;
	std::cout << '>';
	

	
}


bool endOfGame()
{
    std::string endGame;

    std::cout << "1. Попробовать еще раз? (да/нет/не знаю)" << std::endl;
    std::cout << ">";
    std::cin >> endGame;

    if (endGame != "да" && endGame != "нет" && endGame != "не знаю")
    {
        do
        {
            std::cout << "Вы выбрали неверное действие. Выберите верное действие: ";
            std::cout << "> ";
            std::cin >> endGame;
        } while (!(endGame == "да" || endGame == "нет" || endGame == "не знаю"));
    };

    if (endGame == "нет") { return true; }
    return false;
};