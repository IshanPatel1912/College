#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int rollnum;
    char add[100];
};

int main() {
    int i = 0;
    struct student s[5];

    //-------Taking The data-------
    printf("Enter the data of students:\n");
    for(i = 0; i < 5; i++) {
        printf("\nEnter the name of %d's Student : ", i + 1);
        scanf(" %[^\n]", s[i].name);

        printf("Enter Roll No. for %d's Student: ", i + 1);
        scanf("%d", &s[i].rollnum);

        printf("Enter Address for %d's Student: ", i + 1);
        scanf(" %[^\n]", s[i].add);
    }

    //Displaying The Data
    printf("\n--- Displaying Student Data ---\n");
    for(i = 0; i < 5; i++) {
        printf("\n%d's Student's Name: %s", i + 1, s[i].name);
        printf("\n%d's Student Roll No.: %d", i + 1, s[i].rollnum);
        printf("\n%d's Student Address: %s\n", i + 1, s[i].add);
    }

    return 0;
}
