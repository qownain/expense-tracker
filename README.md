# Expense tracker in C

A small menu-based program to add expenses and list their total. Entries are stored in `expenses.txt` in the folder where you run the program, so they remain available after closing it.

## Run

```sh
gcc -std=c11 -Wall -Wextra main.c -o expenses
./expenses
```

On Windows PowerShell, compile with `-o expenses.exe` and run `./expenses.exe`.

Choose 1 to add an expense, 2 to list saved entries and their total, or 3 to exit. For example, adding `food` with amount `50` and `travel` with amount `20` produces a total of `70.00`.

## Limits

- Category names must be one word with at most 30 characters. Longer names are unsupported.
- Amounts must be greater than zero and at most 1,000,000,000.
- Invalid numeric input ends the program; restart it to try again.
- Amounts are saved to two decimal places. This uses floating-point arithmetic and is a practice project, not accounting software.
- Keep the saved file in the format written by the program. Listing stops if it encounters a malformed entry.

## Concepts

Loops, menu choices, strings, file input/output, and totals.

## Possible next change

Add dates and show totals for each category.
