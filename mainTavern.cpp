// Таверна "Бешений кабанчик". Игра на угадывание количества глотков от бармена.
#include <iostream>
#include <string>
#include <windows.h>
#include <thread> //для доступа к текущему потоку
#include <chrono> //для ожидания в секундах



#include "theGame.h"
#include "chatWithBarman.h"
#include "mainTavern.h"
#include "endOfGame.h"

//сначала vorbis только дефайны
#define STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"    

//теперь весь миниаудио, подтягивает дефайны ворбиса
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

//vorbis реализацию
#undef STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"   

static ma_engine snd_engine;

bool initSound()
{
    ma_result result = ma_engine_init(NULL, &snd_engine);
    if (result != MA_SUCCESS) {
        std::cout << "Failed init sound engine\n";
        return false;  // Failed to initialize the engine.
    }
    return true;
}

void playSound(std::string sound_file_name)
{
    ma_engine_play_sound(&snd_engine, sound_file_name.c_str(), NULL);
    
}


int main()
{
    setlocale(LC_ALL, "Russian"); //Корректное отображение Кириллицы
    system("chcp 1251");

    //Попытка инициализации звука
    if (!initSound())
    {
        return EXIT_FAILURE;
    }

    int menuSelection = 0; // ds,jh gj vty.
    int numberOfSips = 0; // количество глотков
    bool chooseChatWithBarman = false; //
    bool notFirstGame = false; //не первый проход по меню


    const int SoundsWineMassSize = 10; // музыка для игры
    // музыка для игры
    static const std::string SoundsWine[SoundsWineMassSize] = { "wine1.ogg", "wine1_2.ogg", "wine2.ogg", "wine2_2.ogg", "wine3.ogg" , "wine3_2.ogg", "wine5.ogg" , "wine5_2.ogg", "wine10.ogg" , "wine10_2.ogg" };
    
    const int SoundsBarNegMassSize = 6;
    // музыка для выбора проиграл игру
    static const std::string SoundsBarNeg[SoundsBarNegMassSize] = { "bar_neg_fight.ogg", "bar_neg_lucky.ogg", "bar_neg_oh1.ogg", "bar_neg_oh2.ogg", "bar_neg_respect.ogg" , "bar_neg_what_say.ogg" };
    
    const int SoundsBarOkMassSize = 9;
    // музыка для выбора продолжить игру
    static const std::string SoundsBarOk[SoundsBarOkMassSize] = { "bar_ok_launch.ogg", "bar_ok_one_more.ogg", "bar_ok_problem.ogg", "bar_ok_quality.ogg", "bar_ok_respect_me.ogg" , "bar_ok_want_beer.ogg", "bar_ok_want_drink.ogg" , "bar_ok_with_pleasure.ogg", "bar_ok_zasohnut.ogg" };

    const int SoundsBarLongMassSize = 7;
    // музыка для chatWithBarman
    static const std::string SoundsBarLong[SoundsBarLongMassSize] = { "bar_long_between.ogg", "bar_long_kiss.ogg", "bar_long_legs.ogg", "bar_long_life.ogg", "bar_long_mind3.ogg" , "bar_long_water.ogg", "bar_long_work.ogg" };

    srand(time(NULL)); //Итак, измените начальное значение для генератора случайных чисел (например, используйте текущее время в качестве начального условия для генератора случайных чисел).




    std::cout << "Таверна бешеный кабанчик.Вы посмотрите на наше меню!" << std::endl;
    for (int i = 1; i < 3; i++)
    {
        playSound("chok.ogg");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    };
    

    do
     {   
        if (!notFirstGame)
        {
            playSound(SoundsBarLong[rand() % SoundsBarLongMassSize]);
            std::this_thread::sleep_for(std::chrono::seconds(5));
        };

        chooseChatWithBarman = false;
        menuFirstSelection(&menuSelection);
    
        switch (menuSelection)
        {
        case static_cast <int> (MenuSelection::startTheGame):
        {
            std::cout << "Таверна бешеный кабанчик. Игра начинается!" << std::endl;
            playSound("ready_for_game.ogg");
            std::this_thread::sleep_for(std::chrono::seconds(2));
            
            std::cout << "Ну, готов угадывать количество глотков?" << std::endl;
            //std::cin.get();
            
            std::string nameOfSound = SoundsWine[rand() % SoundsWineMassSize];
            playSound(nameOfSound);

            
            
            

            int tipeOfName = 0;

            //игра
            if (nameOfSound == SoundsWine[0] || nameOfSound == SoundsWine[1])
            {
                tipeOfName = static_cast<int> (numberOfSipsSelection::oneSip);
                std::this_thread::sleep_for(std::chrono::seconds(1));

            }
            else if (nameOfSound == SoundsWine[2] || nameOfSound == SoundsWine[3])
            {
                tipeOfName = static_cast<int> (numberOfSipsSelection::twoSip);
                std::this_thread::sleep_for(std::chrono::seconds(2));
            }
            else if (nameOfSound == SoundsWine[4] || nameOfSound == SoundsWine[5])
            {
                tipeOfName = static_cast<int> (numberOfSipsSelection::threeSip);
                std::this_thread::sleep_for(std::chrono::seconds(3));
            }
            else if (nameOfSound == SoundsWine[6] || nameOfSound == SoundsWine[7])
            {
                tipeOfName = static_cast<int> (numberOfSipsSelection::fiveSip);
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else if (nameOfSound == SoundsWine[8] || nameOfSound == SoundsWine[9])
            {
                tipeOfName = static_cast<int> (numberOfSipsSelection::tenSip);
                std::this_thread::sleep_for(std::chrono::seconds(10));
            }
            else 
            {
                tipeOfName = static_cast<int> (numberOfSipsSelection::losing);
                std::cout << "Сделал какую-то дичь..." << std::endl;

                playSound(SoundsBarNeg[rand() % SoundsBarNegMassSize]);
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }

            if (theGame(numberOfSips, tipeOfName))
            {
                std::cout << "std::cout << Ого, ты угадал. << std::endl;" << std::endl;
                playSound("win_game.ogg");
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else
            {
                std::cout << "Ну ты и лошара!" << std::endl;
                playSound("kick.ogg");
                std::this_thread::sleep_for(std::chrono::seconds(3));
                playSound(SoundsBarNeg[rand() % SoundsBarNegMassSize]);
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }

            std::cout << "Таверна бешеный кабанчик. Игра закончилась!" << std::endl;
            break;
        }
        case static_cast <int> (MenuSelection::chatWithBarman):
        {
            playSound(SoundsBarLong[rand() % SoundsBarLongMassSize]);
            chatWithBarman(&menuSelection);
            std::cout << std::endl;
            chooseChatWithBarman = true;
            break;
        }
        default:
            break;
        };

        notFirstGame = true;


        //EndOfGame(chooseChatWithBarman);





     } while (!EndOfGame(chooseChatWithBarman));



     //EndOfGame();

     playSound("dopyuIbroshu.ogg");
     std::this_thread::sleep_for(std::chrono::seconds(13));


}