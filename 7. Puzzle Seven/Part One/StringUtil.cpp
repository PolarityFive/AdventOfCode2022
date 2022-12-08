#include "StringUtil.h"
#include <sstream>

std::string StringUtil::getDirName(const std::string& line)
{
    std::string ignored, dirName;
    std::stringstream ss(line);
    ss >> ignored >> dirName;
    return dirName;
}

std::string StringUtil::getDirNameForCd(const std::string& line)
{
    std::string ignored, dirName;
    std::stringstream ss(line);
    ss >> ignored >> ignored >> dirName;
    return dirName;
}

uintptr_t StringUtil::getFileSize(const std::string& line)
{
    int fileSize;
    std::stringstream ss(line);
    ss >> fileSize;

    return fileSize;
}
