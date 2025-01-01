#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>

int _printf(const char *text, ...);
int _putchar(char c);
void intToString(int num, char *res);
void uIntToString(unsigned int num, char *str);
int stringToInt(char *str);
bool isDigit(char c);
void llToString(long long num, char *str);
void llToHex(long long num, char* str);
void ullToHex(uintptr_t num, char* str);

#endif