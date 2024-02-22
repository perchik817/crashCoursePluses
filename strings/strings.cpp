// строки в с++ - массив символов + пустой символ (нулевой байт в конце)
// пассивные строки, просто лежат в памяти
// нет проверки, вышел ли за пределы памяти и остальные данные в памяти просто перезаписываются
// 0'0 == 0 == 0x00 == '\0'

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <cstring>
#include <string>

int strLen(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len += 1;
    }
    return len;
}

int main()
{    
    const char* str1 = "asdfe";
    const char* str2 = "12345";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int totalLen = len1 + len2 + 1;

    char* newStr = new char[totalLen];
    //newstr = str1
    strcpy(newStr, str1);
    //newStr += str2
    strcat(newStr, str2);

    newStr[strlen(newStr) - 1] = 'a';
    std::cout << newStr << std::endl;


    const char* str = "12345678";
    int len = strLen(str);
    std::cout << len << std:: endl;


    std::string s1 = "Hello";
    std::string s2 = "hi";
    std::string s3 = s1 + s2 + "goodbye";

    std::cout << s1 << std::endl;
    std::cout << s3[4] << std::endl;
}
