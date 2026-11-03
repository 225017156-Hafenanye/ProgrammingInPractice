#include <stdio.h>
#include <string.h>

int main(void)
{
    char supplierName[100] = "";
    char email[100] = "";
    char phone[30] = "";
    char town[50] = "";
    char temp[100];
    char description[250];
    char line[20];
    int choice = 0;
    int hasSupplier = 0;

    do
    {
        printf("\n================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        fgets(line, sizeof(line), stdin);
        if (sscanf(line, "%d", &choice) != 1)
        {
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                printf("Enter supplier name: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';
                strcpy(supplierName, temp);

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = '\0';

                hasSupplier = 1;
                printf("Supplier added.\n");
                break;

            case 2:
                if (!hasSupplier)
                {
                    printf("No supplier has been added yet.\n");
                    break;
                }
                printf("\n--- SUPPLIER DETAILS ---\n");
                printf("Name : %s\n", supplierName);
                printf("Email: %s\n", email);
                printf("Phone: %s\n", phone);
                printf("Town : %s\n", town);

                strcpy(description, supplierName);
                strcat(description, " operates in ");
                strcat(description, town);
                strcat(description, ".");
                printf("%s\n", description);
                break;

            case 3:
                if (!hasSupplier)
                {
                    printf("No supplier has been added yet.\n");
                    break;
                }
                printf("Enter supplier name to search: ");
                fgets(temp, sizeof(temp), stdin);
                temp[strcspn(temp, "\n")] = '\0';

                if (strcmp(supplierName, temp) == 0)
                    printf("Supplier found.\n");
                else
                    printf("Supplier not found.\n");
                break;

            case 4:
                if (!hasSupplier)
                {
                    printf("No supplier has been added yet.\n");
                    break;
                }
                printf("Supplier name length: %zu\n", strlen(supplierName));
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}