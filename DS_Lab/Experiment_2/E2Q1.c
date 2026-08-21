#include<stdio.h>
#include<string.h>

struct student{
    char name[50];
    int rollnum;
    char add[100];
};

void main(){
    struct student s1;
    strcpy(s1.name, "Ishan Patel");
    s1.rollnum=113;
    strcpy(s1.add,"Sec 2C, Gan");

    printf("The name is: %s", s1.name);
    printf("\nThe Roll No.: %d", s1.rollnum);
    printf("\nThe Add: %s", s1.add);
}