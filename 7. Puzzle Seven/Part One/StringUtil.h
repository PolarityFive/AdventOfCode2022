#ifndef UNTITLED_STRINGUTIL_H
#define UNTITLED_STRINGUTIL_H

#include <iostream>

class StringUtil
{
public:
    static std::string getDirName(const std::string& line);
    static uintptr_t getFileSize(const std::string& line);
    static std::string getDirNameForCd(const std::string &line);
};

#endif //UNTITLED_STRINGUTIL_H
