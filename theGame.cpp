#include "theGame.h"


void menuFirstSelection(int* menuSelection)
{
	//std::cout << "������� ������� ��������.�� ���������� �� ���� ����!" << std::endl;
	std::cout << "1. ������ ����" << std::endl;
	std::cout << "2. ���������� � ��������" << std::endl;
	std::cout << '>';

	std::cin >> *menuSelection;
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