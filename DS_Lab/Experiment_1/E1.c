#include <stdio.h>

int main()
{
    int main_arr[7] = {5,7,10,6,3,1,11};
    int a = 6;
    int i = 0;
    int j = 0;
    int temp;
    int bubble_arr[7];
    int insercation_arr[7];
    int selection_arr[7];
    
    
    //------Q.1 Part-1 liner search-------
    printf("\n------Q.1 Part-1 liner search-------");
    for(i = 0; i < 7; i++){
        if (a == main_arr[i]){
            printf("\n%d found at %d's place", a, i+1);
            break;
        }
        else
            printf("\n%d's place Checked not found", i+1);
    };


    //---------Q.2 Bubble Sort.-----------
    for(i = 0; i < 7; i++){
        bubble_arr[i] = main_arr[i];
    };

    for(i = 0; i < 7; i++){
        for(j = 0; j < 6 ; j++){
                if (bubble_arr[j]>bubble_arr[j+1]){
                    temp = bubble_arr[j];
                    bubble_arr[j] = bubble_arr[j+1];
                    bubble_arr[j+1] = temp;
                };

        };
    };
    printf("\n---------Q.2 Bubble Sort.-----------");
    for(i = 0; i < 7; i++){
        printf("\n%d",bubble_arr[i]);
    };


    //---------Q.2 Insercation Sort-----------
    for(i = 0; i < 7; i++){
        insercation_arr[i] = main_arr[i];
    };

    for(i = 1; i < 7; i++){
        int key = insercation_arr[i];
        j=i-1;
        while(j>=0 && insercation_arr[j]>key){
            insercation_arr[j+1]=insercation_arr[j];
            j=j-1;
        };
        insercation_arr[j+1]=key;
    };

    printf("\n---------Q.2 Insercation Sort-----------");
    for(i = 0; i < 7; i++){
        printf("\n%d",insercation_arr[i]);
    };


    //---------Q.2 Selection Sort-----------
    for(i = 0; i < 7; i++){
        selection_arr[i] = main_arr[i];
    };

    int temparr[7];
    int min_idx;

    for (i = 0; i < 6; i++) {
         min_idx = i;

        for (j = i + 1; j < 7; j++) {
            if (selection_arr[j] < selection_arr[min_idx]) {
                min_idx = j;
            };
        };

        temp = selection_arr[min_idx];
        selection_arr[min_idx] = selection_arr[i];
        selection_arr[i] = temp;
    };

    printf("\n---------Q.2 Selection Sort-----------");
    for(i = 0; i < 7; i++){
        printf("\n%d",selection_arr[i]);
    };


    //----------Q.1 Part-2 Binary Search----------
    int st = 0, end = 6;
    int z = 0;
    printf("\n----------Q.1 Part-2 Binary Search----------");

    while (st <= end){
        int mid = (st + end) / 2;
        if(selection_arr[mid] == a){
            printf("\n%d found at %d's place", a, mid+1);
            z=1;
            break;
        }
            
        else if(selection_arr[mid] > a){
            end = mid-1;
        }

        else if(selection_arr[mid] < a){
            st = mid+1;
        }
    }

    if(z == 0) {
        printf("\n%d not found", a);
    }



    //---------Q3 Max and Min-----------
    printf("\n---------Q3 Max and Min-----------");
    printf("\nMin:%d", selection_arr[0]);
    printf("\nMax:%d", selection_arr[6]);
    printf("\nSecond Min:%d", selection_arr[1]);
    printf("\nSecond Max:%d", selection_arr[5]);

}