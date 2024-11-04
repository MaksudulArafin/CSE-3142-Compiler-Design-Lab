/*Write a program which converts a word of C++ program to its equivalent token.
RESULT:
Input: 646.45
Output: Float
Input: do
Output: Keyword
Input: 554
Output: Integer
Input: abc
Output: Identifier
Input: +
Output: Arithmetic Operator */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(const char *);
int isInteger(const char *);
int isFloat(const char *);
int isArithmeticOperator(const char *);
int isIdentifier(const char *);

int main()
{
    const char *str;

    FILE *fp;
    fp = fopen("input.txt", "r");

    while (fscanf(fp, "%s", str) != EOF)
    {

        if (isKeyword(str))
        {
            printf("%s is a Keyword.\n", str);
        }
        else if (isInteger(str))
        {
            printf("%s is a Integer.\n", str);
        }
        else if (isFloat(str))
        {
            printf("%s is a Float.\n", str);
        }
        else if (isArithmeticOperator(str))
        {
            printf("%s is a ArithmeticOperator.\n", str);
        }
        else if (isIdentifier(str))
        {
            printf("%s is a identifier.\n", str);
        }
        else
        {
            printf("%s is Undefined.\n", str);
        }
    }

    return 0;
}

int isKeyword(const char *str)
{
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"};

    int numkeyword = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numkeyword; i++)
    {
        if (strcmp(keywords[i], str) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isInteger(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int isFloat(const char *str)
{
    int flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            flag++;
        }
        else if (!isdigit(str[i]))
        {
            return 0;
        }
    }

    return (flag == 1);
}

int isArithmeticOperator(const char *str)
{
    return (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 ||
            strcmp(str, "/") == 0 || strcmp(str, "%") == 0);
}

int isIdentifier(const char *str)
{
    if (isalpha(str[0]) || str[0] == '_' || str[0] == '$')
    {
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (!isalnum(str[i]) && str[i] != '_')
            {
                return 0;
            }
        }
    }

    return 1;
}