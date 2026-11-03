#include <stdio.h>
#include <string.h>

int main(void)
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];
    char copyName[100];
    char searchName[100];

    /* 1. Accept all four fields */
    printf("Enter supplier name: ");
    fgets(supplierName, sizeof(supplierName), stdin);
    supplierName[strcspn(supplierName, "\n")] = '\0';

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);
    town[strcspn(town, "\n")] = '\0';

    /* 2. Display the information */
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\nEmail: %s\nPhone: %s\nTown : %s\n",
           supplierName, email, phone, town);

    /* 3. Length of the supplier name */
    printf("Supplier name length: %zu\n", strlen(supplierName));

    /* 4. Copy the supplier name */
    strcpy(copyName, supplierName);
    printf("Copied name: %s\n", copyName);

    /* 5 & 6. Search and display a message */
    printf("\nEnter supplier name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(supplierName, searchName) == 0)
        printf("Supplier found.\n");
    else
        printf("Supplier not found.\n");

    return 0;
}