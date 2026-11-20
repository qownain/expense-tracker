#include <stdio.h>

int main(void) {
    int choice;
    puts("Expense tracker");
    while (1) {
        printf("\n1. Add expense\n2. List expenses and total\n3. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            puts("Please enter a menu number.");
            return 1;
        }
        if (choice == 3) return 0;
        if (choice == 1) {
            char category[31];
            double amount;
            printf("Category (one word, up to 30 letters): ");
            if (scanf("%30s", category) != 1) return 1;
            printf("Amount: ");
            if (scanf("%lf", &amount) != 1 || !(amount > 0 && amount <= 1000000000)) {
                puts("Enter an amount greater than zero and at most 1000000000.");
                return 1;
            }
            FILE *file = fopen("expenses.txt", "a");
            if (file == NULL) {
                puts("Could not open expenses.txt for writing.");
                return 1;
            }
            int written = fprintf(file, "%s %.2f\n", category, amount);
            int closed = fclose(file);
            if (written < 0 || closed != 0) {
                puts("Could not save expense.");
                return 1;
            }
            puts("Saved.");
        } else if (choice == 2) {
            FILE *file = fopen("expenses.txt", "r");
            if (file == NULL) {
                puts("No expenses file available. Add an expense first.");
                continue;
            }
            char category[31];
            double amount, total = 0;
            while (fscanf(file, "%30s %lf", category, &amount) == 2) {
                printf("%-30s %.2f\n", category, amount);
                total += amount;
            }
            fclose(file);
            printf("Total: %.2f\n", total);
        } else {
            puts("Choose 1, 2 or 3.");
        }
    }
}
