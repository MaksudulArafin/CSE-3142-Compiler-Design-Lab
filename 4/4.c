/*Build a lexical analyzer implementing the following regular expressions:
Integer variable = (i-nI-N)(a-zA-Z0-9)*
ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise*/

/*isIntegerVariable: This function checks if a token matches the Integer Variable pattern.
It verifies that the first character is between i and n (or I to N).
The rest of the characters must be alphanumeric.

isShortIntNumber: This function checks if a token matches the ShortInt Number pattern.
the number must be between 1 and 4 digits, starting with a non-zero digit (1-9).

isLongIntNumber: This function checks if a token matches the LongInt Number pattern.
The number must be at least 5 digits and start with a non-zero digit (1-9).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int classifyToken(char *);
int isIntegerVariable(char *);
int isShortIntNumber(char *);
int isLongIntNumber(char *);

int main()
{

    char *str;
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening file.\n");
        return 0;
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
    if (isIntegerVariable(str))
    {
        printf("%s is Integer Variable.\n", str);
    }

    else if (isShortIntNumber(str))
    {
        printf("%s is ShortInt Number.\n", str);
    }

    else if (isLongIntNumber(str))
    {
        printf("%s is LongInt Number.\n", str);
    }

    else
    {
        printf("%s is Invalid Input or Undefined.\n", str);
    }
}

int isIntegerVariable(char *str)
{
    if (str[0] >= 'i' && str[0] <= 'n' || str[0] >= 'I' && str[0] <= 'N')
    {
        for (int i = 1; str[i] != '\0'; i++)
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

int isShortIntNumber(char *str)
{
    int length = strlen(str);

    if (length > 0 && length <= 4 && str[0] >= '1' && str[0] <= '9')
    {
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]))
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int isLongIntNumber(char *str)
{
    int length = strlen(str);
    if (length > 4 && str[0] >= '1' && str[0] <= '9')
    {
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]))
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}