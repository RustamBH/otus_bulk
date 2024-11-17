#include "CmdHandler.h"


class FileWriter : public CmdHandler
{
public:    
    FileWriter();
    void CommandLog(const std::string& str) override;
    void GetFileName();

private:
    bool bInit = false;
    std::ofstream FileLog;        
    std::string FileName;
};