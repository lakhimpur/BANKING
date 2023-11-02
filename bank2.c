#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accountNumber;
    char name[50];
    double balance;
    int accountType;  // 1 for Savings, 2 for Current
};

// Function to create a new account
struct Account createAccount(int accountNumber, char name[], double balance, int accountType) {
    struct Account account;
    account.accountNumber = accountNumber;
    strcpy(account.name, name);
    account.balance = balance;
    account.accountType = accountType;
    return account;
}

// Function to display account details
void displayAccount(struct Account account) {
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
    if (account.accountType == 1) {
        printf("Account Type: Savings\n");
    } else {
        printf("Account Type: Current\n");
    }
}

// Function to deposit money into an account
void deposit(struct Account *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited $%.2f successfully.\n", amount);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

// Function to withdraw money from an account
void withdraw(struct Account *account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrawn $%.2f successfully.\n", amount);
    } else {
        printf("Invalid withdrawal amount or insufficient balance.\n");
    }
}

int main() {
    struct Account accounts[10];
    int numAccounts = 0;

    int choice;
    do {
        printf("\nBanking Management System\n");
        printf("1. Create Savings Account\n");
        printf("2. Create Current Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Display Account Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int accountNumber;
                char name[50];
                double balance;
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Initial Balance: $");
                scanf("%lf", &balance);
                if (balance < 0) {
                    printf("Initial balance cannot be negative.\n");
                    break;
                }
                accounts[numAccounts] = createAccount(accountNumber, name, balance, 1);  // 1 for Savings
                numAccounts++;
                printf("Savings Account created successfully.\n");
                break;
            }
            case 2: {
                int accountNumber;
                char name[50];
                double balance;
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Initial Balance: $");
                scanf("%lf", &balance);
                if (balance < 1000) {
                    printf("Initial balance for Current Account must be at least $1000.\n");
                    break;
                }
                accounts[numAccounts] = createAccount(accountNumber, name, balance, 2);  // 2 for Current
                numAccounts++;
                printf("Current Account created successfully.\n");
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Deposit Amount: $");
                scanf("%lf", &amount);
                int found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        deposit(&accounts[i], amount);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                printf("Enter Withdrawal Amount: $");
                scanf("%lf", &amount);
                int found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        withdraw(&accounts[i], amount);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            }
            case 5: {
                int accountNumber;
                printf("Enter Account Number: ");
                scanf("%d", &accountNumber);
                int found = 0;
                for (int i = 0; i < numAccounts; i++) {
                    if (accounts[i].accountNumber == accountNumber) {
                        displayAccount(accounts[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Account not found.\n");
                }
                break;
            }
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
