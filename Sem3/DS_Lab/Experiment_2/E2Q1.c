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

    struct student s1;
    strcpy(s1.name, "Ishan Patel");
    s1.rollnum = 113;
    strcpy(s1.add, "Sec 2C, Gan");

    printf("--- Student Details ---\n");
    printf("Name     : %s\n", s1.name);
    printf("Roll No. : %d\n", s1.rollnum);
    printf("Address  : %s\n", s1.add);

    return 0;
}
