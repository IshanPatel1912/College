#include <stdio.h>

void printHeader() {
    printf("===================================================\n");
    printf("  Name   : Ishan Patel                             \n");
    printf("  Roll No: 25BCP113                                \n");
    printf("===================================================\n\n");
}

struct Employee {
    char empID[20];
    float salary;
    char empName[50];
};

struct Organization {
    char orgName[50];
    int orgID;
    struct Employee emp[2];
};

int main() {
    printHeader();

    struct Organization org[2];
    int i, j;

    //-------- Input loop for Org -------------
    for(i = 0; i < 2; i++) {
        printf("============================================================\n");
        printf("  Enter Details for Organization %d\n", i + 1);
        printf("============================================================\n");
        printf("Enter Organization Name : ");
        scanf(" %[^\n]", org[i].orgName);
        printf("Enter Organization ID   : ");
        scanf("%d", &org[i].orgID);

        //-------- Input loop for emp -------------
        for(j = 0; j < 2; j++) {
            printf("\n  -- Enter Details for Employee %d of %s --\n", j + 1, org[i].orgName);
            printf("  Enter Employee Name   : ");
            scanf(" %[^\n]", org[i].emp[j].empName);
            printf("  Enter Employee ID     : ");
            scanf(" %[^\n]", org[i].emp[j].empID);
            printf("  Enter Monthly Salary  : ");
            scanf("%f", &org[i].emp[j].salary);
        }
        printf("\n");
    }

    //-------- Output Loop ------------
    printf("\n============================================================\n");
    printf("              ORGANIZATION & EMPLOYEE RECORDS               \n");
    printf("============================================================\n");
    for(i = 0; i < 2; i++) {
        printf("\nOrganization %d: %s (ID: %d)\n", i + 1, org[i].orgName, org[i].orgID);
        printf("------------------------------------------------------------\n");

        for(j = 0; j < 2; j++) {
            printf("  Employee %d:\n", j + 1);
            printf("    Name   : %s\n", org[i].emp[j].empName);
            printf("    ID     : %s\n", org[i].emp[j].empID);
            printf("    Salary : Rs. %.2f\n", org[i].emp[j].salary);
        }
        printf("------------------------------------------------------------\n");
    }

    return 0;
}
