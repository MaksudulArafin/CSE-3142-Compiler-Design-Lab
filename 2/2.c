/* Write a program that read the following string:
“ Munmun is the student of Computer Science & Engineering”.
a) Count how many vowels and Consonants are there?
b) Find out which vowels and consonants are existed in the above string?
c) Divide the given string into two separate strings, where one string only contains
 the words started with vowel, and another contains the words started with
 consonant.*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#define VSIZE 10
#define CSIZE 42

int findVowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main()
{
    FILE *fp;

    char ch, str[10000], vowelCh[VSIZE], consonantCh[CSIZE], vowelStr[10000] = "", consonantStr[10000] = "";

    int i, j, v = 0, c = 0, cv = 0, cc = 0, flag;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error in opening file.\n");
        return 0;
    }

    while (fgets(str, sizeof(str), fp) != NULL)
    {

        for (i = 0; str[i] != '\0'; i++)
        {
            ch = str[i];
            if (isalpha(ch) != 0)
            {
                if (findVowel(ch))
                {
                    v++; // counting Vowels

                    flag = 0;
                    for (j = 0; j < VSIZE; j++)
                    {
                        if (ch == vowelCh[j])
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        vowelCh[cv] = ch;
                        cv++;
                    }
                }
                else
                {
                    c++; // counting Consonants

                    flag = 0;
                    for (j = 0; j < CSIZE; j++)
                    {
                        if (ch == consonantCh[j])
                        {
                            flag = 1;
                            break;
                        }
                    }

                    if (flag == 0)
                    {
                        consonantCh[cc] = ch;
                        cc++;
                    }
                }
            }
        }

        // seperate the string
        char *word = strtok(str, " ");

        while (word != NULL)
        {
            if (findVowel(word[0]))
            {
                strcat(vowelStr, word);
                strcat(vowelStr, " ");
            }
            else
            {
                strcat(consonantStr, word);
                strcat(consonantStr, " ");
            }
            word = strtok(NULL, " "); // Passing NULL as the first argument tells strtok to
            // continue tokenizing the same initial string from the previous call
        }

        // Remove the trailing space
        vowelStr[strlen(vowelStr) - 1] = '\0';
        consonantStr[strlen(consonantStr) - 1] = '\0';
    }

    printf("Number of Vowels : %d\nNumber of Consonants : %d\n", v, c);

    printf("Existing vowels in string : ");
    for (j = 0; j < cv; j++)
    {
        printf("%c ", vowelCh[j]);
    }
    putchar('\n');

    printf("Existing consonants in string : ");
    for (j = 0; j < cc; j++)
    {
        printf("%c ", consonantCh[j]);
    }
    putchar('\n');

    printf("Words statrs with Vowel = %s\n", vowelStr);
    printf("Words statrs with Consonant = %s", consonantStr);

    fclose(fp);

    return 0;
}