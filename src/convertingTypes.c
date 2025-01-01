#include "main.h"

/**
 * intToString - converts integer to string
 * @num: the number to convert
 * @str: the resulting string
 */
void intToString(int num, char *str){
    if(num < 0){
        num *= -1;
        int ind = 0;
        while(num){
            str[ind++] = (num % 10) + '0';
            num /= 10;
        }
        str[ind++] = '-';
        str[ind] = '\0';
        
        // reversing the string
        int start = 0, end = ind - 1;
        while(start < end){
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            ++start;
            --end;
        }
    }else if(num == 0){
        str[0] = '0';
        str[1] = '\0';
    }else{
        int ind = 0;
        while(num){
            str[ind++] = (num % 10) + '0';
            num /= 10;
        }
        str[ind] = '\0';
        // reversing the string
        int start = 0, end = ind - 1;
        while(start < end){
            char tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
            ++start;
            --end;
        }
    }
}

/**
 * uIntToString - converts unsigned integer to string
 * @num: the number to convert
 * @str: the resulting string
 */
void uIntToString(unsigned int num, char *str){
    int ind = 0;
    while(num){
        str[ind++] = (num % 10) + '0';
        num /= 10;
    }
    str[ind] = '\0';
    // reversing the string
    int start = 0, end = ind - 1;
    while(start < end){
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        ++start;
        --end;
    }
}

/**
 * llToString - converts long long integer to string
 * @num: the number to convert
 * @str: the resulting string
 */
void llToString(long long num, char *str){
    int ind = 0;
    while(num){
        str[ind++] = (num % 10) + '0';
        num /= 10;
    }
    str[ind] = '\0';
    // reversing the string
    int start = 0, end = ind - 1;
    while(start < end){
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        ++start;
        --end;
    }
}

/**
 * stringToInt - converts string to int
 * @str: the string to convert
 * Return: int
 */
int stringToInt(char *str){
    int res = 0;
    int base = pow(10, strlen(str) - 1);
    while(*str){
        res += base * (*str - '0');
        base /= 10;
        ++str;
    }
    return res;
}

/**
 * isDigit - check if the character is a digit or not
 * @c: character to check
 * Return: true if it is a digit, false otherwise
 */
bool isDigit(char c){
    if(c >= '0' && c <= '9') return true;
    else return false;
}

/**
 * llToHex - a function to convert long long to hexadecimal (lower cases)
 * @num: number to convert
 * @str: the resulting string
 */
void llToHex(long long num, char* str){
    int ind = 0;
    while(num){
        int rem = num % 16;
        num /= 16;
        if(rem < 10) str[ind++] = rem + '0';
        else str[ind++] = rem - 10 + 'a';
    }
    str[ind] = '\0';

    // reversing the string
    int left = 0, right = ind - 1;
    while(left < right){
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left;
        --right;
    }
}

/**
 * ullToHex - a function to convert unsigned long long to hexadecimal (upper cases)
 * @num: number to convert
 * @str: the resulting string
 */
void ullToHex(uintptr_t num, char* str){
    int ind = 0;
    while(num){
        int rem = num % 16;
        num /= 16;
        if(rem < 10) str[ind++] = rem + '0';
        else str[ind++] = rem - 10 + 'a';
    }
    str[ind] = '\0';

    // reversing the string
    int left = 0, right = ind - 1;
    while(left < right){
        char tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        ++left;
        --right;
    }
}