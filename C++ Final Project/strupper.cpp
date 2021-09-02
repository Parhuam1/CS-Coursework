
// Implement functions 
#define _CRT_SECURE_NO_WARNINGS
#include <cctype>

// lower case chars to upper case chars                       
void strUpper(char* str)
{
	while (*str != 0)
	{
		*str = toupper(*str);
		str++;
	}
}