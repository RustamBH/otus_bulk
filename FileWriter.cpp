#include "FileWriter.h"


FileWriter::FileWriter()
{
    if (!bInit) {        
        bInit = true;
        GetFileName();
        FileLog.open(FileName, std::ios::out | std::ios::app);        
    }
}

void FileWriter::CommandLog(const std::string& str)
{
    FileLog << str;
}

void FileWriter::GetFileName()
{
    std::stringstream time;

    auto cur_time = std::chrono::system_clock::now();
    auto TimeStamp = std::chrono::system_clock::to_time_t(cur_time);    
    time << TimeStamp;
    FileName = "bulk" + time.str() + ".log";
}