#pragma once
#ifndef CORE_H
#define CORE_H
#include <QString>
#include <string>
#include "List.h"

using namespace std;
class Core
{
public:
    void saveProject(string file);
    bool loadProject(string file);
    explicit Core();
    ~Core();
};

#endif // CORE_H
