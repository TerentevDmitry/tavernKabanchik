#pragma once


enum class MenuSelection
{
    startTheGame = 1, chatWithBarman,
    moveAwayFromBarman = 1
};

enum class chooseEndOfGame
{
    yes = 1, no, dontKnow
};

enum class numberOfSipsSelection
{
    oneSip = 1, twoSip, threeSip, fiveSip = 5, tenSip = 10,
    losing = 99
};

void playSound(std::string sound_file_name);