#include <regex>
#include "RegexUtil.h"

bool RegexUtil::isCd(const std::string& line) {
    return std::regex_search(line, std::regex(R"(\$\s[cd]+\s[a-zAZ]+)"));
}

bool RegexUtil::isCdBack(const std::string& line) {
    return std::regex_search(line, std::regex(R"(cd\s\.\.+)"));
}

bool RegexUtil::isFile(const std::string& line) {
    return std::regex_search(line, std::regex(R"([0-9]+\s[a-zA-Z])"));
}

bool RegexUtil::isDir(const std::string &line)
{
    return std::regex_search(line, std::regex(R"(dir\s[a-zA-Z]+)"));
}
