/*
Write a program to generate a syntax tree for the sentence  a+b*c with the following
grammar:
    E→E+E|E-E|E*E|E/E|a|b|c

    Output: E
            E*E
            E+E*E
            a+E*E
            a+b*E
            a+b*c
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int len, i;
    char s[100], str[100] = "E";

    //Read input string
    scanf("%s", s);
    len = strlen(s);

    printf("E\n");

    //Loop through the string from the second-last character to the beginning
    for (i = len - 2; i >= 0; i -= 2)
    {
        // Check if the character is an operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            // Prepend operator and 'E' to str
            char temp[100] = "E";
            strncat(temp, &s[i], 1);
            //char *strncat(char *dest, const char *src, size_t n)
            //Parameters : This method accepts the following parameters :

            //dest : the string where we want to append.
            //src : the string from which ‘n’ characters are going to append.
            //n : represents a maximum number of characters to be appended.size_t is an unsigned integral type.
            strcat(temp, str);
            //char *strcat(char *dest, const char *src);
            //dest: This is a pointer to the destination array, which should contain a C string, and should be large enough to contain the concatenated resulting string
            //src: This is the string to be appended. This should not overlap the destination.
            strcpy(str, temp);
            printf("%s\n", str);
        }
    }


    for (i = 0; i < len; i += 2)
    {
        str[i] = s[i];
        printf("%s\n", str);
    }

    return 0;
}
