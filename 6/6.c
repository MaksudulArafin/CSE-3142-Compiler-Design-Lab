/*6.  Build a lexical analyzer implementing the following regular expressions:
Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)*
Binary Number = 0(0|1)(0|1)*
Invalid Input or Undefined = Otherwise */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int classifyToken(char *);
int isCharacterVariable(char *);
int isBinaryVariable(char *);
int isBinaryNumber(char *);

int main()
{

    char *str;

    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Error in opening file.\n");
    }

    while (fscanf(fp, "%s", str) != EOF)
    {
        classifyToken(str);
    }
    fclose(fp);

    return 0;
}

int classifyToken(char *str)
{
    if (isCharacterVariable(str))
    {
        printf("%s is Character Variable.\n", str);
    }
    else if (isBinaryVariable(str))
    {
        printf("%s is Binary Variable.\n", str);
    }
    else if (isBinaryNumber(str))
    {
        printf("%s is Binary Number.\n", str);
    }
    else
    {
        printf("%s is Invalid Input or Undefined.\n", str);
    }
}

// Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)*
int isCharacterVariable(char *str)
{
    if (str[0] == 'c' && str[1] == 'h' && str[2] == '_')
    {
        if (isalnum(str[3]))
        {

            for (int i = 4; str[i] != '\0'; i++)
            {
                if (!isalnum(str[i]))
                {
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

// Binary variable = bn_(a-zA-Z0-9)(a-zA-Z0-9)*
int isBinaryVariable(char *str)
{

    if (str[0] == 'b' && str[1] == 'n' && str[2] == '_')
    {
        if (isalnum(str[3]))
        {

            for (int i = 4; str[i] != '\0'; i++)
            {
                if (!isalnum(str[i]))
                {
                    return 0;
                }
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

// Binary Number = 0(0|1)(0|1)*
int isBinaryNumber(char *str)
{
    if (str[0] == '0' && (str[1] == '0' || str[1] == '1'))
    {
        for (int i = 2; str[i] != '\0'; i++)
        {
            if (!(str[i] == '0' || str[i] == '1'))
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}