#include <stdio.h>

struct Employee {//Child class
    char empID[20];
    float salary;
    char empName[50];
};

struct Organization {//Parent class
    char orgName[50];
    int orgID;
    struct Employee emp[2];
};

int main() {
    struct Organization org[2];
    int i, j;

    //--------Input loop for Org-------------
    for(i = 0; i < 2; i++) {
        printf("=== Enter Details for Organization %d ===\n", i + 1);
        printf("Enter Organization Name: ");
        scanf(" %[^\n]", org[i].orgName);
        printf("Enter Organization ID: ");
        scanf("%d", &org[i].orgID);

        //--------Input loop for emp-------------
        for(j = 0; j < 2; j++) {
            printf("\n  -- Enter Details for Employee %d of %s --\n", j + 1, org[i].orgName);
            printf("  Enter Employee Name: ");
            scanf(" %[^\n]", org[i].emp[j].empName);
            printf("  Enter Employee ID: ");
            scanf(" %[^\n]", org[i].emp[j].empID);
            printf("  Enter Salary: ");
            scanf("%f", &org[i].emp[j].salary);
        }
        printf("\n");
    }

    //--------Output Loop------------
    for(i = 0; i < 2; i++) {
        printf("\nOrganization Name: %s (ID: %d)\n", org[i].orgName, org[i].orgID);

        for(j = 0; j < 2; j++) {
            printf("  Employee %d Name : %s\n", j + 1, org[i].emp[j].empName);
            printf("  Employee %d ID   : %s\n", j + 1, org[i].emp[j].empID);
            printf("  Employee %d Salary : Rs.%.2f\n", j + 1, org[i].emp[j].salary);
            printf("\n");
        }
    }

    return 0;
}

