#include <stdio.h>
#include <string.h>

char str[1000], tr[1000];
char gr[][10] = {"E+E", "E-E", "E*E", "E/E", "(E)", "a", "b", "c"};

void replac(int pos, char st[]) {
    int i;
    for (i = 0; st[i]; i++) {
        tr[pos + i] = st[i];
    }
    tr[pos + i] = '\0';
}

int main() {
    int i, j, ln, op;
    
    // Take input as a string
    scanf("%s", str);

    // Initialize tr with "E"
    strcpy(tr, "E");
    
    // Length of the input string
    ln = strlen(str);
    
    // Print initial "E"
    printf("E\n");
    
    i=j=0;
    while(i < ln) {
        if (i + 1 < ln) {
            // Determine operation based on the operator
            if (str[i + 1] == '+') op = 0;
            else if (str[i + 1] == '-') op = 1;
            else if (str[i + 1] == '*') op = 2;
            else op = 3;
            
            // Replace part of tr with the corresponding grammar rule
            replac(j, gr[op]);
            
            // Print the current result
            printf("%s\n", tr);
        }
        
        // Set the character in tr
        tr[j] = str[i];
        
        // Print the current result
        printf("%s\n", tr);
        
        // Increment j and i accordingly
        j += 2;
        i += 2;
    }

    return 0;
}
