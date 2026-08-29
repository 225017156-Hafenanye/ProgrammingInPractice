#include <stdio.h>

int main() {
    double revenue = 0.0;
    double expenses = 0.0;
    double balance = 0.0;

    printf("MUNICIPAL BUDGET CALCULATOR\n");
    printf("---------------------------\n");

    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    // Calculate balance
    balance = revenue - expenses;

    // Output formatted report to two decimal places
    printf("\n--- FINANCIAL SUMMARY ---\n");
    printf("Revenue : $%.2f\n", revenue);
    printf("Expenses: $%.2f\n", expenses);
    printf("Balance : $%.2f\n", balance);

    return 0;
}