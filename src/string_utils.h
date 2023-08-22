#pragma once

#include <string>

// https://stackoverflow.com/a/42844629
// Note, that starting from c++20 std::string will finally provide starts_with and ends_with.
// Seems like there is a chance that by c++30 strings in c++ might finally become usable,
// if you aren't reading this from distant future, you can use these startsWith/endsWith with C++17:
// Checks whether `str' ends with `suffix'
static bool endsWith(const std::string& str, const std::string& suffix) {
    if (&suffix == &str) return true; // str and suffix are the same string
    if (suffix.length() > str.length()) return false;
    size_t delta = str.length() - suffix.length();
    for (size_t i = 0; i < suffix.length(); ++i) {
        if (suffix[i] != str[delta + i]) return false;
    }
    return true;
}

static bool startsWith(const std::string& str, const std::string& prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

static bool endsWith(const std::string& str, const char* suffix, unsigned suffixLen)
{
    return str.size() >= suffixLen && 0 == str.compare(str.size()-suffixLen, suffixLen, suffix, suffixLen);
}

static bool endsWith(const std::string& str, const char* suffix)
{
    return endsWith(str, suffix, std::string::traits_type::length(suffix));
}

static bool startsWith(const std::string& str, const char* prefix, unsigned prefixLen)
{
    return str.size() >= prefixLen && 0 == str.compare(0, prefixLen, prefix, prefixLen);
}

static bool startsWith(const std::string& str, const char* prefix)
{
    return startsWith(str, prefix, std::string::traits_type::length(prefix));
}
