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

int login(){
    char username[20];
    char pin[5];
    int attempts = 0;

    while (attempts < 3) {
        printf("Enter username: ");
        scanf("%s", username);
        
        printf("Enter 4-digit PIN: ");
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

int main() {
    printf("ATM Simulator\n");
    int loginResult = login();
    return 0;
}
