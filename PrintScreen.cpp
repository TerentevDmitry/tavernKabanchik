#include "PrintScreen.h"


void printMenu()
{
	

	std::cout << "1. ������ ����" << std::endl;
	std::cout << "2. ���������� � ��������" << std::endl;
	std::cout << '>';
	

	
}


bool endOfGame()
{
    std::string endGame;

    std::cout << "1. ����������� ��� ���? (��/���/�� ����)" << std::endl;
    std::cout << ">";
    std::cin >> endGame;

    if (endGame != "��" && endGame != "���" && endGame != "�� ����")
    {
        do
        {
            std::cout << "�� ������� �������� ��������. �������� ������ ��������: ";
            std::cout << "> ";
            std::cin >> endGame;
        } while (!(endGame == "��" || endGame == "���" || endGame == "�� ����"));
    };

    if (endGame == "���") { return true; }
    return false;
};