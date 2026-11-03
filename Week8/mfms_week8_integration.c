#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUPPLIERS 5

/* ---------- Supplier storage (file-scope) ---------- */
char supNames[MAX_SUPPLIERS][100];
char supEmails[MAX_SUPPLIERS][100];
char supPhones[MAX_SUPPLIERS][30];
char supTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* ---------- Prototypes ---------- */
void displayMenu();
void readLine(const char *prompt, char *buf, int size);
float readFloat(const char *prompt);
int readInt(void);

float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

void salaryOption();
void vatOption();
void budgetOption();
void employeeSearchOption();
void supplierManagement();

void addSupplier();
void displaySupplier();
void searchSupplier();

/* ---------- main ---------- */
int main(void)
{
    int choice;

    do
    {
        displayMenu();
        choice = readInt();

        switch (choice)
        {
            case 1: salaryOption();         break;
            case 2: vatOption();            break;
            case 3: budgetOption();         break;
            case 4: employeeSearchOption(); break;
            case 5: supplierManagement();   break;
            case 6: printf("Goodbye.\n");   break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

/* ---------- Menu and input helpers ---------- */
void displayMenu()
{
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void readLine(const char *prompt, char *buf, int size)
{
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

float readFloat(const char *prompt)
{
    char line[50];
    float value = 0;
    readLine(prompt, line, sizeof(line));
    sscanf(line, "%f", &value);
    return value;
}

int readInt(void)
{
    char line[50];
    int value = 0;
    if (fgets(line, sizeof(line), stdin) != NULL)
    {
        if (sscanf(line, "%d", &value) != 1)
            value = 0;
    }
    return value;
}

/* ---------- Financial functions ---------- */
float calculateVAT(float amount)
{
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
            return i;
    }
    return -1;
}

/* ---------- Menu option handlers ---------- */
void salaryOption()
{
    float basic = readFloat("Basic salary: ");
    float housing = readFloat("Housing allowance: ");
    float transport = readFloat("Transport allowance: ");
    printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
}

void vatOption()
{
    float amount = readFloat("Enter amount: ");
    printf("VAT: %.2f\n", calculateVAT(amount));
}

void budgetOption()
{
    float revenue = readFloat("Enter revenue: ");
    float expenses = readFloat("Enter expenses: ");
    float balance = calculateBudget(revenue, expenses);

    printf("Budget balance: %.2f\n", balance);
    if (balance > 0)      printf("SURPLUS\n");
    else if (balance < 0) printf("DEFICIT\n");
    else                  printf("BALANCED\n");
}

void employeeSearchOption()
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = sizeof(employeeIDs) / sizeof(employeeIDs[0]);
    int id, position;

    printf("Enter employee ID: ");
    id = readInt();

    position = searchEmployee(id, employeeIDs, size);
    if (position != -1)
        printf("Employee found at position %d.\n", position);
    else
        printf("Employee not found.\n");
}

/* ---------- Supplier module ---------- */
void supplierManagement()
{
    int choice;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");
        choice = readInt();

        switch (choice)
        {
            case 1: addSupplier();     break;
            case 2: displaySupplier(); break;
            case 3: searchSupplier();  break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);
}

void addSupplier()
{
    char temp[100];

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    readLine("Enter supplier name: ", temp, sizeof(temp));
    strcpy(supNames[supplierCount], temp);

    readLine("Enter email: ", supEmails[supplierCount], sizeof(supEmails[0]));
    readLine("Enter phone: ", supPhones[supplierCount], sizeof(supPhones[0]));
    readLine("Enter town: ", supTowns[supplierCount], sizeof(supTowns[0]));

    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    char description[250];

    if (supplierCount == 0)
    {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("\n--- SUPPLIER DETAILS ---\n");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("Supplier %d\n", i + 1);
        printf("Name : %s (length %zu)\n", supNames[i], strlen(supNames[i]));
        printf("Email: %s\n", supEmails[i]);
        printf("Phone: %s\n", supPhones[i]);
        printf("Town : %s\n", supTowns[i]);

        strcpy(description, supNames[i]);
        strcat(description, " operates in ");
        strcat(description, supTowns[i]);
        strcat(description, ".");
        printf("%s\n\n", description);
    }
}

void searchSupplier()
{
    char searchName[100];

    readLine("Enter supplier name to search: ", searchName, sizeof(searchName));

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(supNames[i], searchName) == 0)
        {
            printf("Supplier found.\n");
            printf("Name : %s\nEmail: %s\nPhone: %s\nTown : %s\n",
                   supNames[i], supEmails[i], supPhones[i], supTowns[i]);
            return;
        }
    }
    printf("Supplier not found.\n");
}