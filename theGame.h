#pragma once
#include <iostream>
#include <string>
#include <thread> //для доступа к текущему потоку
#include <chrono> //для ожидания в секундах

bool theGame(int numberOfSips, int tipeOfName);

void menuFirstSelection(int* menuSelection);