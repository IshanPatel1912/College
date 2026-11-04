#include <stdio.h>
#include <string.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

struct student {
    char name[50];
    int rollnum;
    char add[100];
};

int main() {
    printHeader();

    int i = 0;
    struct student s[5];

    //------- Taking The data -------
    printf("--- Enter Details for 5 Students ---\n");
    for(i = 0; i < 5; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("  Enter Name    : ");
        scanf(" %[^\n]", s[i].name);

        printf("  Enter Roll No.: ");
        scanf("%d", &s[i].rollnum);

        printf("  Enter Address : ");
        scanf(" %[^\n]", s[i].add);
    }

    //------- Displaying The Data -------
    printf("\n============================================================\n");
    printf("                 STUDENT RECORDS DISPLAY                    \n");
    printf("============================================================\n");
    for(i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name    : %s\n", s[i].name);
        printf("  Roll No : %d\n", s[i].rollnum);
        printf("  Address : %s\n", s[i].add);
        printf("------------------------------------------------------------\n");
    }

    return 0;
}
