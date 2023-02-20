#pragma once
#include <iostream>
#include "mainTavern.h"
#include <string>
#include <thread> //для доступа к текущему потоку
#include <chrono> //для ожидания в секундах


void chatWithBarman(int* menuSelection);
