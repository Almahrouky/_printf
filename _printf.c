#include "main.h"
/**
 * intToString - converts integer to string
 * @num: the number to convert
 * @str: the result string
 * Return: void
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

/***
 * _printf - the new printf function
 * @text: the string passed to the function
 * @...: variadic function
 * Return: 0 on success
 */
int _printf(const char *text, ...){
    va_list ptr;
    va_start(ptr, text);

    while(*text){
        if(*text == '%'){
            ++text;
            if(*text == '%'){
                _putchar('%');
                ++text;
                continue;
            }

            switch (*text){
                case 'c':{
                    char ch = (char)va_arg(ptr, int);
                    _putchar(ch);
                    break;
                }

                case 's':{
                    char *str = va_arg(ptr, char*);
                    while(*str) _putchar(*str++);
                    break;
                }

                case 'd':{
                    int num = va_arg(ptr, int);
                    char str[12];
                    intToString(num, str);
                    int size = strlen(str);
                    for(int i = 0; i < size; ++i){
                        _putchar(str[i]);
                    }
                    break;
                }
                
                case 'i':{
                    int num = va_arg(ptr, int);
                    char str[12];
                    intToString(num, str);
                    int size = strlen(str);
                    for(int i = 0; i < size; ++i){
                        _putchar(str[i]);
                    }
                    break;
                }
                
                case('u'):{

                    break;
                }
                
                case('f'):{

                    break;
                }

                case('x'):{

                    break;
                }

                case('X'):{

                    break;
                }

                case('p'):{

                }
            }
        }else{
            _putchar(*text);
        }
        ++text;
    }
        

    va_end(ptr);

    return 0;
}