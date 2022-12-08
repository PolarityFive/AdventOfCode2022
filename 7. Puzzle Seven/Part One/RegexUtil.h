#ifndef UNTITLED_REGEXUTIL_H
#define UNTITLED_REGEXUTIL_H

#include <string>

class RegexUtil
{
public:
    static bool isCd(const std::string& line);
    static bool isFile(const std::string& line);
    static bool isDir(const std::string& line);
    static bool isCdBack(const std::string &line);
};


#endif
