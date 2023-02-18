// Таверна "Бешений кабанчик". Игра на угадывание количества глотков от бармена.
#include <iostream>
#include <string>
#include "sound1.h"
#include "PrintScreen.h"
#include <windows.h>
#include <thread> //для доступа к текущему потоку
#include <chrono> //для ожидания в секундах

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

    int menuSelection = 0;
    int numberOfSips = 0;
    
    
    
        std::cout << "Таверна бешеный кабанчик.Вы посмотрите на наше меню!" << std::endl;
        
        printMenu();
        std::cin >> menuSelection;
        std::cout << "Играет музыка..." << std::endl;
        //playSound("bar_long_friends.ogg", NULL, SND_SYNC);
        

        std::this_thread::sleep_for(std::chrono::seconds(5));
        

        switch (menuSelection)
        {
        case 1:
        {
            bool ggg = false;
            int count = 0;

            do
            {
                if (count != 0)
                {
                    std::cout << "Таверна бешеный кабанчик.Вы посмотрите на наше меню!" << std::endl;
                    printMenu();
                    std::cin >> menuSelection;
                }

                std::cout << "Игра началась..." << std::endl;
                std::cout << "Играет музыка..." << std::endl;
                
                playSound("bar_long_friends.ogg");

                //ожидание для того чтобы звук успел отыграть
                std::this_thread::sleep_for(std::chrono::seconds(5));

                std::cout << "Сколько глотков я налил?" << std::endl;
                std::cout << '>';
                std::cin >> numberOfSips;

                if (numberOfSips == 1)
                {
                    std::cout << "Угадал..." << std::endl;
                }
                else 
                { 
                    std::cout << "НЕ Угадал..." << std::endl;
                }

                count++;
                bool ggg = endOfGame();




            } while (!ggg);

            break;
        }

        case 2:
        {
            std::cout << "В нашей таверне Вы можете не только приятно провести время за свои деньги, но и немного выпить за счёт заведения!" << std::endl;
            std::cout << "Я вижу Вас насквозь - у Вас в кармане пусто, но наш бешеный кабанчик благосклонен к специалистам по выпивке!" << std::endl;
            std::cout << "Чтобы немного выпить за счёт заведения, ";
            std::cout << "Вы должны с завязанными глазами угадать количество глотков выпивки, которую я накапаю в стакан." << std::endl;
            std::cout << "Не бойся! Буду наливать не больше десяти глотков." << std::endl;
            std::cout << "На то чтобы угадать количество глотков у Вас будет только три секунды." << std::endl;
            std::cout << "Если не угадаешь, или истекут три секунды - получишь такую оплеуху от меня, что звездочки будут плясать джигу на твоём лбу!" << std::endl;

            std::cout << "1. Отодвинуться" << std::endl;
            std::cout << '>';
            



            break;

        }

        default:
            break;
        }

  
  





 //В нашей таверне вы можете не только приятно провести время за свои деньги, 
 // но и немного выпить за счёт заведения! Я вижу вас насквозь - у вас в кармане пусто, 
 // но наш бешеный кабанчик благосклонен к специалистам по выпивке! 
 // Теперь  Сначала вы с завязанными глазами должны узнать, сколько грамм я накапаю в стакан. 
 // Потом у вас будет только три секунды, чтобы сделать нужное количество глотков. 
 // Не бойся! Не больше десяти. Если не угадаешь, то получишь такую оплеуху от меня, что звездочки будут плясать джигу на твоём лбу! "
 //    
//

}