#include "theGame.h"


void menuFirstSelection(int* menuSelection)
{
	//std::cout << "������� ������� ��������.�� ���������� �� ���� ����!" << std::endl;
	std::cout << "1. ������ ����" << std::endl;
	std::cout << "2. ���������� � ��������" << std::endl;
	std::cout << '>';
	std::cin >> *menuSelection;

	if (*menuSelection != 1 && *menuSelection != 2)
	{
		while (!std::cin.good() || !(*menuSelection == 1 || *menuSelection == 2))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� ������� �������� ��������. �������� ������ ��������: ";
			std::cout << "> ";
			std::cin >> *menuSelection;
		};
	};

	
}



//bool winGameOrNot(int numberOfSips, int tipeOfName)
//{
//	
//	
//	if (numberOfSips == tipeOfName)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//	
//};

bool theGame(int numberOfSips, int tipeOfName)
{
	std::cout << "� ������ ������ ���������� �������..." << std::endl;
	std::cout << "> ";
	std::cin >> numberOfSips;

	
		while (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� ����� �� ���������� �������, � �����-�� ����. ������� ����� �������: ";
			std::cout << "> ";
			std::cin >> numberOfSips;
		};



	if (numberOfSips == tipeOfName)
	{
		std::cout << "���, �� ������." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
	

};