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

        std::cout << "1. ����������� ��� ���? (��/���/�� ����)" << std::endl;
        std::cout << ">";
        std::getline(std::cin, endGame);
        std::getline(std::cin, endGame);

        if (endGame != "��" && endGame != "���" && endGame != "�� ����")
        {
            do
            {
                std::cout << "�� ������� �������� ��������. �������� ������ ��������: ";
                std::cout << "> ";
                std::getline(std::cin, endGame);
            } while (!(endGame == "��" || endGame == "���" || endGame == "�� ����"));
        };

        if (endGame == "���")
        {
            return true;
        }
        else if (endGame == "��")
        {
            return false;
        }
        else if (endGame == "�� ����")
        {
            std::cout << "� ���, �� ���� �������� ������? ����� ������, �� ����! " << std::endl;
            return false;
        }
        else
        {
            std::cout << "Errore in bool EndOfGame()" << std::endl;

        }
    };
    
}
