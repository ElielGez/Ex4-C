#include "utils.h"

// void initStringToSearch()
// {
//     char c;
//     int line = 0;
//     int charCount = 0;
//     while (scanf("%c", &c) != EOF)
//     {
//         if (c == '\n')
//         {
//             //enter , new line
//             str[line++][charCount] = c;
//             charCount = 0;
//         }
//         else
//         {
//             str[line][charCount++] = c;
//         }
//     }
// }

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