#include "CmdParser.h"


void CmdParser::PrintCommands()
{
    if (arrayCmd.size() == 0) {
        return;
    }
    CommandLog("bulk: ");

    for (auto it = arrayCmd.cbegin(); it != arrayCmd.cend(); ++it) {
        CommandLog(*it);
        if (it != --arrayCmd.cend()) {
            CommandLog(", ");
        }
    }
    CommandLog("\n");
    arrayCmd.clear();
}

void CmdParser::AddCommand(const std::string& cmd)
{
    if (cmd == "{") {
        if (nestedBlocks == 0) {
            PrintCommands();
            arrayCmd.clear();
        }
        nestedBlocks++;
        return;
    }
    else if (cmd == "}") {
        nestedBlocks--;
        if (nestedBlocks == 0) {
            PrintCommands();
        }
        return;
    }
    else if (cmd == "}" && nestedBlocks == 0) {
        CommandLog("Invalid block \n");
        return;
    }

    arrayCmd.push_back(cmd);
    if ((arrayCmd.size() == nCmd_) && nestedBlocks == 0) {
        PrintCommands();
    }
}

void CmdParser::CommandLog(const std::string& str)
{    
    pOut_->CommandLog(str);
    pFile_->CommandLog(str);    
}
