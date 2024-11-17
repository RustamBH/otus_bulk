#pragma once

#include "CmdHandler.h"
#include "FileWriter.h"
#include "ConsoleOut.h"


class CmdParser : public CmdHandler
{
public:
    CmdParser() {};
    CmdParser (int nCmd, FileWriter* pFile = nullptr, ConsoleOut* pOut = nullptr) : nCmd_(nCmd), pFile_(pFile), pOut_(pOut){};
    void CommandLog(const std::string& str) override;
    void PrintCommands();
    void AddCommand(const std::string& cmd);    
   
private:
    size_t nCmd_;
    int nestedBlocks = 0;    
    std::vector<std::string> arrayCmd; 
    FileWriter* pFile_;
    ConsoleOut* pOut_;
};
