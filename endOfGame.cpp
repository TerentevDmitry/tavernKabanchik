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
            playSound("nado_fedya_nado.ogg");
            std::this_thread::sleep_for(std::chrono::seconds(3));

            
            return false;
        }
        else
        {
            std::cout << "Errore in bool EndOfGame()" << std::endl;

        }
    };
    
}
