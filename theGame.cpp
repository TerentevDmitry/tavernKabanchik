#include "theGame.h"


void menuFirstSelection(int* menuSelection)
{
	//std::cout << "Таверна бешеный кабанчик.Вы посмотрите на наше меню!" << std::endl;
	std::cout << "1. Начать игру" << std::endl;
	std::cout << "2. Побазарить с барменом" << std::endl;
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
	std::cout << "А теперь угадай количество глотков..." << std::endl;
	std::cout << "> ";
	std::cin >> numberOfSips;

	if (numberOfSips == tipeOfName)
	{
		std::cout << "Ого, ты угадал." << std::endl;
		return true;
	}
	else
	{
		return false;
	}
	

};