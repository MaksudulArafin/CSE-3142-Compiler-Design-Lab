/*Build a lexical analyzer implementing the following regular expressions:
Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)
Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
Invalid Input or Undefined = Otherwise*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int classifyToken(char *);
int isFloatVariable(char *);
int isFloatNumber(char *);
int isDoubleNumber(char *);

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
    if (isFloatVariable(str))
    {
        printf("%s is Float Variable.\n", str);
    }

    else if (isFloatNumber(str))
    {
        printf("%s is Float Number.\n", str);
    }

    else if (isDoubleNumber(str))
    {
        printf("%s is Double Number.\n", str);
    }

    else
    {
        printf("%s is Invalid Input or Undefined.\n", str);
    }
}

// Float variable = (a-hA-Ho-zO-Z)(a-zA-Z0-9)*
int isFloatVariable(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'h' ||
        str[0] >= 'A' && str[0] <= 'H' ||
        str[0] >= 'o' && str[0] <= 'z' ||
        str[0] >= 'O' && str[0] <= 'Z')
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

// Float Number = 0.(0-9)(0-9)|(1-9)(0-9)*.(0-9)(0-9)

int isFloatNumber(char *str)
{
    int length = strlen(str);
    if (length == 4 && str[0] == '0' && str[1] == '.' && isdigit(str[2]) && isdigit(str[3]))
    {
        return 1;
    }

    if (str[0] >= '1' && str[0] <= '9')
    {
        int j = 1;
        while (isdigit(str[j]))
        {
            j++;
        }

        if (str[j] == '.' && isdigit(str[j + 1]) && isdigit(str[j + 2]) && str[j + 3] == '\0')
        {
            return 1;
        }
    }

    return 0;
}

// Double Number = 0.(0 - 9)(0 - 9)(0 - 9) + | (1 - 9)(0 - 9) *.(0 - 9)(0 - 9)(0 - 9) +
int isDoubleNumber(char *str)
{
    int length = strlen(str);
    if (length >= 5 && str[0] == '0' && str[1] == '.' && isdigit(str[2]) && isdigit(str[3]))
    {
        for (int i = 4; str[i] != '\0'; i++)
        {
            if (!isdigit(str[i]))
            {
                return 0;
            }
        }
        return 1;
    }

    if (str[0] >= '1' && str[0] <= '9')
    {
        int j = 1;
        while (isdigit(str[j]))
        {
            j++;
        }

        if (str[j] == '.' && isdigit(str[j + 1]) && isdigit(str[j + 2]) && isdigit(str[j + 3]))
        {
            for (int k = j + 4; k < length; k++)
            {
                if (!isdigit(str[k]))
                    return 0;
            }
            return 1;
        }
    }
    return 0;
}