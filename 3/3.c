/*3. Write a program that abbreviates the following code:
CSE-3141 as Computer Science & Engineering, 3rd year, 1st semester, Compiler Design, Theory.*/

#include<stdio.h>
#include<string.h>

int main(){

    FILE *fp;
    char *tok,str[10000];
    
    fp = fopen("input.txt","r");
    if (fp == NULL)
    {
        printf("Error in opening file.\n");
        return 0;
    }

    while(fgets(str, sizeof(str), fp) != NULL){
        tok = strtok(str,"-");

        while(tok != NULL){
            if(strcmp(tok,"CSE") == 0){
                printf("Computer Science & Engineering,");
            }
            else if(strcmp(tok,"3141") == 0){
                printf(" 3rd year, 1st semester, Compiler Design, Theory.");
            }
            tok = strtok(NULL,"-");
        }


    }



    return 0;
}