#include "chatWithBarman.h"


void chatWithBarman(int* menuSelection)
{
    

    std::cout << "В нашей таверне Вы можете не только приятно провести время за свои деньги, но и немного выпить за счёт заведения!" << std::endl;
    std::cout << "Я вижу Вас насквозь - у Вас в кармане пусто, но наш бешеный кабанчик благосклонен к специалистам по выпивке!" << std::endl;
    std::cout << "Чтобы немного выпить за счёт заведения, ";
    std::cout << "Вы должны с завязанными глазами угадать количество глотков выпивки, которую я накапаю в стакан." << std::endl;
    std::cout << "Не бойся! Буду наливать не больше десяти глотков." << std::endl;
    std::cout << "Если не угадаешь - получишь такую оплеуху от меня, что звездочки будут плясать джигу на твоём лбу!" << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "А ещё разрешите представить - это наша красавица, Светлана! Первая леди нашего заведения.";
    std::cout << "Она будет тебя подбадривать всю игру! " << std::endl;
    //playSound("privetikr.ogg");
    //std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "1. Отодвинуться" << std::endl;
    std::cout << '>';
    
    std::cin >> *menuSelection;

    if (*menuSelection != static_cast <int> (MenuSelection::moveAwayFromBarman))
    {
        while (!std::cin.good() || !(*menuSelection == static_cast <int> (MenuSelection::moveAwayFromBarman)))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Вы выбрали неверное действие. Выберите верное действие: ";
            std::cout << "> ";
            std::cin >> *menuSelection;
        };
    };
};