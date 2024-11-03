
/*7. Write a program to recognize C++
    i) Keyword    ii) Identifier    iii) Operator    iv) Constant */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int classifyToken(const char *);
int isKeyword(const char *);
int isConstant(const char *);
int isIdentifier(const char *);
int isOperator(const char *);

int main()
{
    const char *str;
    FILE *fp;
    fp = fopen("input.txt", "r");

    while (fscanf(fp, "%s", str) != EOF)
    {
        classifyToken(str);
    }

    return 0;
}

int classifyToken(const char *str)
{
    if (isKeyword(str))
    {
        printf("%s is a Keyword.\n", str);
    }
    else if (isConstant(str))
    {
        printf("%s is a Constant.\n", str);
    }
    else if (isOperator(str))
    {
        printf("%s is a Operator.\n", str);
    }
    else if (isIdentifier(str))
    {
        printf("%s is a identifier.\n", str);
    }
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

int isConstant(const char *str)
{
    int flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            if (str[i] == '.')
            {
                flag++;
            }
            else
            {
                return 0;
            }
        }
    }
    if (flag > 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
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

int isOperator(const char *str)
{
    const char *operators[] = {"()", "[]", "+", "-", "++", "--", "!", "~", "*", "&", "sizeof", "*", "/", "%", "<<",
                              ">>", "<", "<=", ">", ">=", "==", "!=", "&", "^", "|", "&&", "||", ",","="};

    int numOperator = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < numOperator; i++)
    {
        if (strcmp(operators[i], str) == 0)
        {
            return 1;
        }
    }
    return 0;

}