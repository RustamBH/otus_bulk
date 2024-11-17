#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <chrono>


class CmdHandler
{
public:    
    virtual ~CmdHandler() = default;
    virtual void CommandLog(const std::string&) = 0;
};