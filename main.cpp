#include "CmdParser.h"
using namespace std;


int main (int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "No Argument" << std::endl;
        return -1;
    }

    int nBlock = atoi(argv[1]);
    if (nBlock == 0)
    {
        std::cerr << "Invalid block size" << std::endl;
        return -1;
    }

    FileWriter file_log;
    ConsoleOut console_log;
    CmdParser parser(nBlock, &file_log, &console_log);    

    string name_cmd;
    while (true) {
        cin >> name_cmd;
        if (name_cmd == "EOF") {
            parser.PrintCommands();
            break;
        }
        parser.AddCommand(name_cmd);
    }

    return 0;
}
