#include<stdio.h>

void main(){
    float temp[30];

    //Temp input
    for(int i = 0; i<30; i++){
        printf("\nEnter temp. of %d's Day:",i+1);
        scanf("%f",&temp[i]);
    }

    //Hottest and Coldest check
    int hottest_day = 0, coldest_day = 0;
    float hot_value=temp[0], cold_value=temp[0];
    for(int i = 0; i<30; i++){
        if(temp[i]>hot_value){
            hot_value=temp[i];
            hottest_day= i+1;
        }
        if(temp[i]<cold_value){
            cold_value=temp[i];
            coldest_day= i+1;
        }
    }
    printf("\nHottest Day %d value is %0.2f", hottest_day, hot_value);
    printf("\nColdest Day %d value is %0.2f", coldest_day, cold_value);

    //Finding Longest continuous streak of incresing temp
    int max_streak = 0;
    int current_streak = 0;
    int streak_end_day = 0;

    for(int i = 1; i < 30; i++) {
        if(temp[i] > temp[i-1]) {
            current_streak++;
            if(current_streak > max_streak) {
                max_streak = current_streak;
                streak_end_day = i + 1;
            }
        } else {
            current_streak = 0;
        }
    }

    int total_streak_days = max_streak > 0 ? max_streak + 1 : 0;
    int streak_start_day = streak_end_day - max_streak;

    if(total_streak_days > 0) {
        printf("\nLongest continuous increasing streak: %d days (From Day %d to Day %d)\n",
               total_streak_days, streak_start_day, streak_end_day);
    } else {
        printf("\nNo strictly increasing temperature streak found.\n");
    }

    //Sort ascending order
    int flag=0;
    for(int i = 0; i < 30; i++){
        for(int j = 0; j < 29 ; j++){
            if (temp[j]>temp[j+1]){
                flag = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = flag;
            }
        }
    }

    //Value Search from user using binary search
    float target;
    printf("\nEnter the value you want to find: ");
    scanf("%f", &target);

    int st = 0, end = 29;
    int found = 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (temp[mid] == target) {
            printf("\nFound value %0.2f at sorted index %d", target, mid);
            found = 1;
            break;
        }
        else if (temp[mid] > target) {
            end = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }

    if (!found) {
        printf("\nValue %0.2f not found in the records.", target);
    }

    //Check how many temp higher than avg
    float sum = 0;
    for(int i = 0; i<30; i++){
        sum = sum + temp[i];
    }

    float avg = sum/30;
    int count;
    for(int i = 0; i<30; i++){
        if (temp[i]>avg){
            count ++;
        }
    }

    printf("Total Day more than avg temp %d", count);
}
