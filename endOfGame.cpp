#include "endOfGame.h"
#include "mainTavern.h"

bool EndOfGame(bool chooseChatWithBarman)
{
    if (chooseChatWithBarman)
    {
        return false;
    }
    else
    {
        int endGame;

        std::cout << "1. Попробовать еще раз? (1.Да / 2.Нет / 3.Не знаю)" << std::endl;
        std::cout << ">";
        std::cin >> endGame;
        //chooseEndOfGame
        if (endGame != static_cast<int> (chooseEndOfGame::yes) && endGame != static_cast<int> (chooseEndOfGame::no) && endGame != static_cast<int> (chooseEndOfGame::dontKnow))
        {
            do
            {
                std::cout << "Вы выбрали неверное действие. Выберите верное действие: ";
                std::cout << "> ";
                std::cin >> endGame;
            } while (!(endGame == static_cast<int> (chooseEndOfGame::yes) || endGame == static_cast<int> (chooseEndOfGame::no) || endGame == static_cast<int> (chooseEndOfGame::dontKnow)));
        };

        if (endGame == static_cast<int> (chooseEndOfGame::no))
        {
            return true;
        }
        else if (endGame == static_cast<int> (chooseEndOfGame::yes))
        {
            return false;
        }
        else if (endGame == static_cast<int> (chooseEndOfGame::dontKnow))
        {
            std::cout << "И что, ты меня оставишь одного? Давай играть, не нуди! " << std::endl;
            playSound("nado_fedya_nado.ogg");
            std::this_thread::sleep_for(std::chrono::seconds(3));

            
            return false;
        }
        else
        {
            std::cout << "Errore in bool EndOfGame()" << std::endl;
            return false;
        }
    };

    
    
}
