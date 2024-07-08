// Write a C program to implement a symbol table.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int i = 0, j = 0, x = 0, n, flag = 0;
    void *p, *add[15];
    char srch, b[15], d[15], c;

    printf("Enter expression terminated by $: ");
    fgets(b, sizeof(b), stdin);
    n = strlen(b);
    if (b[n - 1] == '\n') {
        b[n - 1] = '\0'; // Remove the newline character
        n--; // Decrement the length to exclude the newline character
    }

    printf("Given expression is: %s\n", b);

    printf("Symbol table:\n");
    printf("Symbol\tAddress\t\t\tType\n");
    while (j <= n) {
        c = b[j];
        if (isalpha(c)) { // Check if the character is an identifier (alphabetic character)
            // Allocate memory for the identifier
            p = malloc(1);  // Allocate 1 byte for demonstration purposes
            if (p == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return 1;
            }
            add[x] = p;
            d[x] = c;
            printf("%c\t%p\tidentifier\n", c, p);
            x++;
        }
        j++;
    }

    printf("Enter the symbol to be searched: ");
    srch = getchar(); // Read the search character
    getchar(); // Consume the newline character after entering the search symbol

    for (i = 0; i < x; i++) {
        if (srch == d[i]) {
            printf("Symbol found in table:\n");
            printf("%c\t%p\n", srch, add[i]);
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("Symbol not found in table\n");
    }

    // Free allocated memory
    for (i = 0; i < x; i++) {
        free(add[i]);
    }

    return 0;
}

