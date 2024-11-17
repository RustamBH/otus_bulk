#include "CmdHandler.h"

class ConsoleOut : public CmdHandler
{
public:
    ConsoleOut() {};
    void CommandLog(const std::string& str) override { std::cout << str; };
};