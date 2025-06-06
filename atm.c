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


int main() {
    printf("ATM Simulator\n");
    return 0;
}
