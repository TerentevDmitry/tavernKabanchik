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
        int endGame = 0;

        std::cout << "1. ����� ��-���� ��� �������?? (1.�� / 2.���)" << std::endl;
        std::cout << ">";
        std::cin >> endGame;
        //chooseEndOfGame
        if (endGame != static_cast<int> (chooseEndOfGame::yes) && endGame != static_cast<int> (chooseEndOfGame::no) /*&& endGame != static_cast<int> (chooseEndOfGame::dontKnow)*/)
        {
            do
            {
                std::cout << "�� ������� �������� ��������. �������� ������ ��������: ";
                std::cout << "> ";
                std::cin >> endGame;
            } while (!(endGame == static_cast<int> (chooseEndOfGame::yes) || endGame == static_cast<int> (chooseEndOfGame::no) /*|| endGame == static_cast<int> (chooseEndOfGame::dontKnow)*/));
        };

        if (endGame == static_cast<int> (chooseEndOfGame::no))
        {
            return true;
        }
        else if (endGame == static_cast<int> (chooseEndOfGame::yes))
        {
            return false;
        }
        //else if (endGame == static_cast<int> (chooseEndOfGame::dontKnow))
        //{
        //    std::cout << "� ���, �� ���� �������� ������? ����� ������, �� ����! " << std::endl;
        //    playSound("nado_fedya_nado.ogg");
        //    std::this_thread::sleep_for(std::chrono::seconds(4));

        //    
        //    return false;
        //}
        else
        {
            std::cout << "Errore in bool EndOfGame()" << std::endl;
            return false;
        }
    };

    
    
}

bool oneMoreTime()
{
    int moreTime = 0;

    std::cout << "1. ����� ��� �����? (1.�� / 2.��� / 3.�� ����)" << std::endl;
    std::cout << ">";
    std::cin >> moreTime;
    //chooseEndOfGame
    if (moreTime != static_cast<int> (chooseEndOfGame::yes) && moreTime != static_cast<int> (chooseEndOfGame::no) && moreTime != static_cast<int> (chooseEndOfGame::dontKnow))
    {
        do
        {
            std::cout << "�� ������� �������� ��������. �������� ������ ��������: ";
            std::cout << "> ";
            std::cin >> moreTime;
        } while (!(moreTime == static_cast<int> (chooseEndOfGame::yes) || moreTime == static_cast<int> (chooseEndOfGame::no) || moreTime == static_cast<int> (chooseEndOfGame::dontKnow)));
    };

    if (moreTime == static_cast<int> (chooseEndOfGame::no))
    {
        return true;
    }
    else if (moreTime == static_cast<int> (chooseEndOfGame::yes))
    {
        return false;
    }
    else if (moreTime == static_cast<int> (chooseEndOfGame::dontKnow))
    {
        std::cout << "� ���, �� ���� �������� ������? ����� ������, �� ����! " << std::endl;
        playSound("nado_fedya_nado.ogg");
        std::this_thread::sleep_for(std::chrono::seconds(4));


        return false;
    }
    else
    {
        std::cout << "Errore in bool EndOfGame()" << std::endl;
        return false;
    }
};
