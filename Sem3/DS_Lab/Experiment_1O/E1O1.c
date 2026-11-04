#include <stdio.h>
#include <time.h>

void generateNumbers(int arr[]) {
    struct timespec ts;

    timespec_get(&ts, TIME_UTC);

    unsigned long seed = (unsigned long)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);

    for (int i = 0; i < 100; i++) {
        seed = seed * 1664525 + 1013904223;
        arr[i] = seed % 101;
    }
}

int main() {
    int arr[100];
    generateNumbers(arr);

    //Avrage Of Class
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        sum = sum + arr[i];
    }
    int avg = sum/100;
    printf("\nAvrage: %d", avg);

    //Count Below and above Avarage
    int above_avg = 0, below_avg = 0;
    for (int i = 0; i < 100; i++) {
        if(arr[i] > avg){
            above_avg ++;
        }
        else{
            below_avg ++;
        }
    }
    printf("\nAbove Avarage:%d",above_avg);
    printf("\nBelow Avarage:%d",below_avg);


    //Check specific marks
    int target = 43;
    for (int i = 0; i < 100; i++){
        if (arr[i] == target)
        {
            printf("\n%d is found at %d's place",target,i+1);
        }
    }

    //Frequency check of all marks
    int freq[101] = {0};
    for (int i = 0; i < 100; i++) {
        freq[arr[i]]++;
    }
    printf("\n\n--- Frequency of Marks ---");
    for (int i = 0; i <= 100; i++) {
        if (freq[i] > 0) {
            printf("\nMarks %d: %d time(s)", i, freq[i]);
        }
    }

    return 0;
}
