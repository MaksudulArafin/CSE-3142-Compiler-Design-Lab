/*1. Write a C program that read the following string:
“ Md. Tareq Zaman, Part-3, 2011”
a) Count number of words, letters, digits and other characters.
b) Separates letters, digits and others characters.*/

#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>

int main(){

    FILE *fp;
    char ch,nch;
    int cw,cl,cd,coc; 
    bool whitespace = true;
    cw=cl=cd=coc=0;

    fp = fopen("input.txt","r");\
    if(fp == NULL){
        printf("Error in opening file.\n");
        return 0;
    }

    while((ch = getc(fp)) != EOF){
        // find words
        if(whitespace && !isspace(ch)){
            cw++;
            whitespace = false;
        }
        else if(!whitespace && isspace(ch)){
            whitespace = true;
        }



        if(isalpha(ch) != 0){  // find alphabets
            cl++;
        }
        else if(isdigit(ch) != 0){ // find digits
            cd++;
        }
        else {  // other characters
            coc++;
        }
    }

    printf("Letter : %d\n",cl);
    printf("Digit : %d\n",cd);
    printf("Other Characters : %d\n",coc);
    printf("Words : %d\n",cw);
    fclose(fp);

    return 0;
}