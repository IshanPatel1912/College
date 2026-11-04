#include <stdio.h>
#include <string.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

struct Student {
    int id;
    char name[50];
    float score;
};

int main() {
    printHeader();

    struct Student s1;
    struct Student *ptr = &s1;

    printf("--- Enter Student Details ---\n");
    printf("Enter Student ID    : ");
    if (scanf("%d", &ptr->id) != 1) return 1;

    printf("Enter Student Name  : ");
    scanf(" %[^\n]", ptr->name);

    printf("Enter Student Score : ");
    if (scanf("%f", &ptr->score) != 1) return 1;

    printf("\n============================================================\n");
    printf("      STUDENT DETAILS ACCESSED VIA STRUCTURE POINTER        \n");
    printf("============================================================\n");
    printf("  Structure Address  : %p\n", (void *)ptr);
    printf("  Student ID (->id)  : %d\n", ptr->id);
    printf("  Student Name       : %s\n", ptr->name);
    printf("  Student Score      : %.2f\n", ptr->score);
    printf("============================================================\n");

    return 0;
}
