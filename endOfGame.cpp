#include "endOfGame.h"

bool EndOfGame(bool chooseChatWithBarman)
{
    if (chooseChatWithBarman)
    {
        return false;
    }
    else
    {


        std::string endGame;

        std::cout << "1. Попробовать еще раз? (да/нет/не знаю)" << std::endl;
        std::cout << ">";
        std::getline(std::cin, endGame);
        std::getline(std::cin, endGame);

        if (endGame != "да" && endGame != "нет" && endGame != "не знаю")
        {
            do
            {
                std::cout << "Вы выбрали неверное действие. Выберите верное действие: ";
                std::cout << "> ";
                std::getline(std::cin, endGame);
            } while (!(endGame == "да" || endGame == "нет" || endGame == "не знаю"));
        };

        if (endGame == "нет")
        {
            return true;
        }
        else if (endGame == "да")
        {
            return false;
        }
        else if (endGame == "не знаю")
        {
            std::cout << "И что, ты меня оставишь одного? Давай играть, не нуди! " << std::endl;
            return false;
        }
        else
        {
            std::cout << "Errore in bool EndOfGame()" << std::endl;

        }
    };
    
}
