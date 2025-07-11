#include <stdio.h>
#include <string.h>

#define Users 3
#define Max_transactions 5

char usernames[Users][20] = {"alice", "bob", "charlie"};
char pins[Users][5] = {"1234", "5678", "0000"};
int balances[Users] = {1000, 1500, 2000};
char transactions[Users][Max_transactions][50];
int transactionCounts[Users] = {0};

int currentUser = -1;

int login() {
  char username[20];
  char pin[5];
  int attempts = 0;

  while (attempts < 3) {
    printf("WELCOME TO THE ATM\n");
    printf("Please log in to continue.\n");
    printf("Enter username: \n");
    scanf("%s", username);

    printf("Enter 4-digit PIN: \n");
    scanf("%s", pin);

    for (int i = 0; i < Users; i++) {
      if (strcmp(username, usernames[i]) == 0 && strcmp(pin, pins[i]) == 0) {
        currentUser = i;
        printf("Login successful!\n");
        return 1;
      }
    }
    printf("Invalid username or PIN. Please try again.\n");
    attempts++;
  }
  printf("Too many failed attempts. Exiting...\n");
  return 0;
}

void checkBalance() {
  if (currentUser == -1) {
    printf("Please log in first.\n");
    return;
  }
  printf("Current balance: $%d\n", balances[currentUser]);
}

void deposit() {
  if (currentUser == -1) {
    printf("Please log in first.\n");
    return;
  }
  int amount;
  printf("Enter amount to deposit: \n");
  scanf("%d", &amount);
  if (amount <= 0) {
    printf("Please deposit more than $0.\n");
    return;
  }
  balances[currentUser] += amount;
  if (transactionCounts[currentUser] < Max_transactions) {
    sprintf(transactions[currentUser][transactionCounts[currentUser]],
            "Deposited $%d", amount);
    transactionCounts[currentUser]++;
  } else {
    printf("Transaction log is full. This transaction will not be recorded.\n");
  }

  printf("Deposit successful. New balance: $%d\n", balances[currentUser]);
}

void withdraw() {
  if (currentUser == -1) {
    printf("Please log in first.\n");
    return;
  }
  int amount;
  printf("Enter amount to withdraw: \n");
  scanf("%d", &amount);
  if (amount <= 0) {
    printf("Please withdraw more than $0.\n");
    return;
  }
  if (amount > balances[currentUser]) {
    printf("Insufficient funds. Current balance: $%d\n", balances[currentUser]);
    return;
  }
  balances[currentUser] -= amount;
  if (transactionCounts[currentUser] < Max_transactions) {
    sprintf(transactions[currentUser][transactionCounts[currentUser]],
            "Withdrew $%d", amount);
    transactionCounts[currentUser]++;
  } else {
    printf("Transaction log is full. This transaction will not be recorded.\n");
  }

  printf("Withdrawal successful. New balance: $%d\n", balances[currentUser]);
}

void viewTransactions() {
  if (currentUser == -1) {
    printf("Please log in first.\n");
    return;
  }
  printf("Transaction history:\n");
  for (int i = 0; i < transactionCounts[currentUser]; i++) {
    printf("%s\n", transactions[currentUser][i]);
  }
  if (transactionCounts[currentUser] == 0) {
    printf("No transactions found.\n");
  }
}

void showMenu() {
  int choice;
  while (1) {
    printf("\n===== ATM Menu =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Transactions\n");
    printf("5. Logout\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        checkBalance();
        break;
      case 2:
        deposit();
        break;
      case 3:
        withdraw();
        break;
      case 4:
        viewTransactions();
        break;
      case 5:
        printf("Logging out...\n");
        return;  // exit menu and return to main
      default:
        printf("Invalid choice. Please select between 1–5.\n");
    }
  }
}

int main() {
  printf("ATM Simulator\n");

 if (login()) {
    showMenu();
  }

  return 0;
}
