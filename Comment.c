/*Write a C program to identify wheather a given line is a comment or not */

/* logic
1. Read the input string.
2. Check wheather the string is starting '/' and check next character is '/'or '*'
3. If condition satisfies print comment.
4. Else not a comment. */

#include <stdio.h>
#include <conio.h>
#include <string.h>

void main() {
    char comment[31];  // Allow space for null terminator
    int i, a = 0;
    printf("\nEnter a comment: ");
    fgets(comment, 31, stdin);  // Use fgets to safely read input

    comment[strcspn(comment, "\n")] = '\0';

    if (comment[0] == '/') {
        if (comment[1] == '/') {
            printf("\nIt is a comment");
        } else if (comment[1] == '*') {
            for (i = 2; i < 30; i++) {
                if (comment[i] == '*' && comment[i + 1] == '/') {
                    printf("\nIt is a comment");
                    a = 1;
                    break;
                }
            }
            if (a == 0) {
                printf("\nIt is not a comment");
            }
        } else {
            printf("\nIt is not a comment");
        }
    } else {
        printf("\nIt is not a comment");
    }

    getch();
}
