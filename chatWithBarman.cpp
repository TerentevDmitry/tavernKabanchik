#include "chatWithBarman.h"


void chatWithBarman(int* menuSelection)
{
    

    std::cout << "� ����� ������� �� ������ �� ������ ������� �������� ����� �� ���� ������, �� � ������� ������ �� ���� ���������!" << std::endl;
    std::cout << "� ���� ��� �������� - � ��� � ������� �����, �� ��� ������� �������� ������������ � ������������ �� �������!" << std::endl;
    std::cout << "����� ������� ������ �� ���� ���������, ";
    std::cout << "�� ������ � ����������� ������� ������� ���������� ������� �������, ������� � ������� � ������." << std::endl;
    std::cout << "�� �����! ���� �������� �� ������ ������ �������." << std::endl;
    std::cout << "�� �� ����� ������� ���������� ������� � ��� ����� ������ ��� �������." << std::endl;
    std::cout << "���� �� ��������, ��� ������� ��� ������� - �������� ����� ������� �� ����, ��� ��������� ����� ������� ����� �� ���� ���!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "1. ������������" << std::endl;
    std::cout << '>';
    
    std::cin >> *menuSelection;

    if (*menuSelection != static_cast <int> (MenuSelection::moveAwayFromBarman))
    {
        while (!std::cin.good() || !(*menuSelection == static_cast <int> (MenuSelection::moveAwayFromBarman)))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "�� ������� �������� ��������. �������� ������ ��������: ";
            std::cout << "> ";
            std::cin >> *menuSelection;
        };
    };
};