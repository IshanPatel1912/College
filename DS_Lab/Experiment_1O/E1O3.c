#include <stdio.h>
#include <string.h>

// 1. Search product function
void searchproduct(int product_id[], char product_name[][50], int product_qty[]) {
    int target = 0;
    printf("\nEnter the product ID which you want to find: ");
    scanf("%d", &target);
    for (int i = 0; i < 10; i++) {
        if (product_id[i] == target) {
            printf("\nProduct found");
            printf("\nName: %s", product_name[i]);
            printf("\nQty.: %d\n", product_qty[i]);
            return;
        }
    }
    printf("\nProduct with ID %d not found.\n", target);
}

// 2. Identify max and min stock function
void findmaxmin(int product_id[], char product_name[][50], int product_qty[]) {
    int maxid = 0, minid = 0;
    for (int i = 1; i < 10; i++) {
        if (product_qty[i] > product_qty[maxid]) maxid = i;
        if (product_qty[i] < product_qty[minid]) minid = i;
    }
    printf("\n%d Item has Max Qty. Name: %s (Qty.: %d)", product_id[maxid], product_name[maxid], product_qty[maxid]);
    printf("\n%d Item has Min Qty. Name: %s (Qty.: %d)\n", product_id[minid], product_name[minid], product_qty[minid]);
}

// 3. Update stock function
void updatestock(int product_id[], char product_name[][50], int product_qty[]) {
    int id = 0;
    printf("\nEnter the Product ID which you want to update Qty.: ");
    scanf("%d", &id);
    for (int i = 0; i < 10; i++) {
        if (product_id[i] == id) {
            printf("Enter the new Qty of product %s (ID: %d): ", product_name[i], product_id[i]);
            scanf("%d", &product_qty[i]);
            printf("Stock updated successfully.\n");
            return;
        }
    }
    printf("\nProduct Not Found\n");
}

// 4. Sort and print function (Bubble Sort)
void printinorder(int product_id[], char product_name[][50], int product_qty[]) {
    int temp = 0;
    int flag = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (product_qty[j] > product_qty[j + 1]) {
                // Swap Qty
                temp = product_qty[j];
                product_qty[j] = product_qty[j + 1];
                product_qty[j + 1] = temp;

                // Swap ID
                flag = product_id[j];
                product_id[j] = product_id[j + 1];
                product_id[j + 1] = flag;

                // Swap Name
                char tempname[50];
                strcpy(tempname, product_name[j]);
                strcpy(product_name[j], product_name[j + 1]);
                strcpy(product_name[j + 1], tempname);
            }
        }
    }
    printf("\nSorted Products:\n");
    for (int i = 0; i < 10; i++) {
        printf("ID: %d | Name: %s | Stock: %d\n", product_id[i], product_name[i], product_qty[i]);
    }
}

// 5. Stock alert function
void stockalert(int product_id[], char product_name[][50], int product_qty[], int alert_qty) {
    printf("\nStock Alert (Items <= %d):\n", alert_qty);
    int itemsFound = 0;
    for (int i = 0; i < 10; i++) {
        if (product_qty[i] <= alert_qty) {
            printf("ID: %d | Name: %s | Stock: %d\n", product_id[i], product_name[i], product_qty[i]);
            itemsFound = 1;
        }
    }
    if (!itemsFound) {
        printf("No products are below the alert threshold.\n");
    }
}

int main() {
    int product_id[10];
    char product_name[10][50];
    int product_qty[10];
    int alert_qty;
    int choice;

    // Collect product entries
    for (int i = 0; i < 10; i++) {
        product_id[i] = 101 + i;
        printf("\nEnter the Detail for %d product", product_id[i]);
        printf("\nName: ");
        scanf(" %[^\n]", product_name[i]);
        printf("Qty.: ");
        scanf("%d", &product_qty[i]);
    }

    printf("\nEnter the threshold Qty.: ");
    scanf("%d", &alert_qty);

    // Interactive menu loop to drive operations
    do {
        printf("\n--- Retail System Menu ---\n");
        printf("1. Search Product\n");
        printf("2. Find Max/Min Stock\n");
        printf("3. Update Stock Quantity\n");
        printf("4. Display Sorted Products\n");
        printf("5. Check Stock Alert\n");
        printf("6. Exit\n");
        printf("Enter choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchproduct(product_id, product_name, product_qty);
                break;
            case 2:
                findmaxmin(product_id, product_name, product_qty);
                break;
            case 3:
                updatestock(product_id, product_name, product_qty);
                break;
            case 4:
                printinorder(product_id, product_name, product_qty);
                break;
            case 5:
                stockalert(product_id, product_name, product_qty, alert_qty);
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
