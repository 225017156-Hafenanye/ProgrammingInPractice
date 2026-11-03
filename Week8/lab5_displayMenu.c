#include <stdio.h>

void displayMenu();

int main(void)
{
    int choice;

    displayMenu();
    scanf("%d", &choice);
    printf("You chose option %d\n", choice);

    return 0;
}

void displayMenu()
{
    printf("\n==================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}