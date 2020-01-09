#include "utils.h"

bool isLowerEnglishLetter(char c)
{
    return c - 'a' >= 0 && c - 'a' <= 25;
}

bool isUpperEnglishLetter(char c)
{
    return c - 'A' >= 0 && c - 'A' <= 25;
}

char charToLowerCase(char c)
{
    if (isUpperEnglishLetter(c))
        return c + 'a' - 'A';
    else
        return c;
}