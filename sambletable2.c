// //To write a C program for implementing symbol table.
// /* 1. start the program for performing insert, display, delete, search and modify option in symbol table
//    2. Define the structure of the symbol table.
//    3. Enter the choice for performing the operation in the symbol table.
//    4. If the entered choice is 1, search the symbol table for the symbol to inserted. if the symbol table is already
//       present, it displays "Duplicate symbol". Else, insert the symbol table and the corresponding address in the symbol
//       table.
//    5. If the entered choice is 2, the symbol present in the symbol table are displayed.
//    6. if the entered choice is 3, the symbol to be deleted is searched in the symbol table.
//    7. if it is not found in the symbol table it displays "Label not found". Else the symbol is deleted.
//    8. if the entered choice is 5, the symbol to be modified is searched in the symbol table. the label or address or both can be modified.
//    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define null 0

int size = 0;

void insert();
void del();
int search(char lab[]);
void modify();
void display();

struct symbtab {
    char label[10];
    int addr;
    struct symbtab *next;
};

struct symbtab *first = NULL, *last = NULL;

int main(void) {
    int op;
    int y;
    char la[10];

    do {
        printf("\nSymbol Table Implementation\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Modify\n");
        printf("6. End\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                insert();
                display();
                break;
            case 2:
                display();
                break;
            case 3:
                del();
                display();
                break;
            case 4:
                printf("Enter the label to be searched: ");
                scanf("%s", la);
                y = search(la);
                if (y == 1) {
                    printf("The label is already in the symbol table\n");
                } else {
                    printf("The label is not found in the symbol table\n");
                }
                break;
            case 5:
                modify();
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (op != 6);

    return 0;
}

void insert() {
    char l[10];
    printf("Enter the label: ");
    scanf("%s", l);
    int n = search(l);

    if (n == 1) {
        printf("The label already exists. Duplicate can't be inserted.\n");
    } else {
        struct symbtab *p = (struct symbtab *)malloc(sizeof(struct symbtab));
        if (p == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        strcpy(p->label, l);
        printf("Enter the address: ");
        scanf("%d", &p->addr);
        p->next = NULL;

        if (size == 0) {
            first = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
        size++;
    }
}

void display() {
    struct symbtab *p = first;
    printf("Label\tAddress\n");
    while (p != NULL) {
        printf("%s\t%d\n", p->label, p->addr);
        p = p->next;
    }
}

int search(char lab[]) {
    struct symbtab *p = first;
    while (p != NULL) {
        if (strcmp(p->label, lab) == 0) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void modify() {
    char l[10], nl[10];
    int add, choice, s;
    struct symbtab *p = first;

    printf("What do you want to modify?\n");
    printf("1. Only the label\n");
    printf("2. Only the address of a particular label\n");
    printf("3. Both the label and address\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the old label: ");
            scanf("%s", l);
            printf("Enter the new label: ");
            scanf("%s", nl);
            s = search(l);
            if (s == 0) {
                printf("No such label\n");
            } else {
                while (p != NULL) {
                    if (strcmp(p->label, l) == 0) {
                        strcpy(p->label, nl);
                        break;
                    }
                    p = p->next;
                }
            }
            break;
        case 2:
            printf("Enter the label whose address is to be modified: ");
            scanf("%s", l);
            printf("Enter the new address: ");
            scanf("%d", &add);
            s = search(l);
            if (s == 0) {
                printf("No such label\n");
            } else {
                while (p != NULL) {
                    if (strcmp(p->label, l) == 0) {
                        p->addr = add;
                        break;
                    }
                    p = p->next;
                }
            }
            break;
        case 3:
            printf("Enter the old label: ");
            scanf("%s", l);
            printf("Enter the new label: ");
            scanf("%s", nl);
            printf("Enter the new address: ");
            scanf("%d", &add);
            s = search(l);
            if (s == 0) {
                printf("No such label\n");
            } else {
                while (p != NULL) {
                    if (strcmp(p->label, l) == 0) {
                        strcpy(p->label, nl);
                        p->addr = add;
                        break;
                    }
                    p = p->next;
                }
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

void del() {
    char l[10];
    printf("Enter the label to be deleted: ");
    scanf("%s", l);
    int a = search(l);

    if (a == 0) {
        printf("Label not found\n");
    } else {
        struct symbtab *p = first, *prev = NULL;

        if (strcmp(first->label, l) == 0) {
            first = first->next;
            free(p);
        } else {
            while (p != NULL && strcmp(p->label, l) != 0) {
                prev = p;
                p = p->next;
            }
            if (p == NULL) return;
            prev->next = p->next;
            if (p == last) {
                last = prev;
            }
            free(p);
        }
        size--;
    }
}
