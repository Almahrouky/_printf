#include "main.h"

/***
 * _printf - the new printf function
 * @text: the string passed to the function
 * Return: 0 on success
 */
int _printf(const char *text, ...){
    va_list ptr;
    va_start(ptr, text);

    int total = 0;
    int textSZ = strlen(text);
    for(int ix = 0; ix < textSZ; ++ix){
        if(text[ix] == '%'){
            ++ix;
            if(text[ix] == '.'){
                char str[20];
                int ind = 0;
                ++ix;
                while(isDigit(text[ix])){
                    str[ind] = text[ix];
                    ++ix;
                    ++ind;
                }
                str[ind] = '\0';
                total = stringToInt(str);
                if(text[ix] == 's') goto ss;
                else if(text[ix] == 'f') goto ff;
            }
            else if(text[ix] == '%'){
                _putchar('%');
                ++ix;
            }
            else if(text[ix] == 'c'){
                char ch = (char)va_arg(ptr, int);
                _putchar(ch);
            }
            else if(text[ix] == 's'){
                ss: char *str = va_arg(ptr, char*);
                while(*str && total) {_putchar(*str++); --total;}
            }
            else if(text[ix] == 'd' || text[ix] == 'i'){
                int num = va_arg(ptr, int);
                char str[20];
                intToString(num, str);
                int size = strlen(str);
                for(int i = 0; i < size; ++i){
                    _putchar(str[i]);
                }
            }
            else if(text[ix] == 'u'){
                unsigned int num = va_arg(ptr, unsigned int);
                char str[20];
                uIntToString(num, str);
                int size = strlen(str);
                for(int i = 0; i < size; ++i){
                    _putchar(str[i]);
                }
            }
            else if(text[ix] == 'f'){
                ff: double num = va_arg(ptr, double);
                long long before = num;
                char str[20];
                llToString(before, str);
                int size = strlen(str);
                for(int i = 0; i < size; ++i){
                    _putchar(str[i]);
                }
                _putchar('.');
                while(total){
                    long long tmp = num;
                    if((double)tmp == num) break;
                    num *= 10;
                    tmp = num;
                    _putchar((tmp%10) + '0');
                    --total;
                }
                while(total){
                    _putchar('0');
                    --total;
                }
            }
            else if(text[ix] == 'x'){
                long long num = va_arg(ptr, long long);
                char str[20];
                llToHex(num, str);
                int size = strlen(str);
                for(int i = 0; i < size; ++i){
                    _putchar(str[i]);
                }
            }
            else if(text[ix] == 'p'){
                void *ptr2 = va_arg(ptr, void *);
                if(ptr2){
                    char str[20];
                    ullToHex((uintptr_t)ptr2, str);
                    _putchar('0');
                    _putchar('x');
                    int size = strlen(str);
                    for(int i = 0; i < size; ++i){
                        _putchar(str[i]);
                    }
                }else{
                    char *str = "(nil)";
                    while(*str) _putchar(*str++);
                }
            }
        }else{
            _putchar(text[ix]);
        }
    }
        
    va_end(ptr);

    return 0;
}