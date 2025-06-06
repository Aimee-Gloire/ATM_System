# ATM System in C

This is an ATM system in C that allows multiple predefined users to log in and perform basic banking operations such as checking balance, depositing, withdrawing, and viewing transaction history. The system simulates a real ATM interface and demonstrates how arrays and strings can be used to manage user accounts and operations.

## Features

- User login with a 3-attempt limit
- Check account balance
- Deposit money
- Withdraw money
- View last 5 transactions
- Logout functionality
- Input validation and basic error handling
- Modular code using functions, arrays, and strings and user interaction through a text-based menu system

## Getting Started

You need a C compiler like `gcc` to compile and run this project.

### Compiling and running

```bash
gcc atm.c -o atm

./atm
```

### Sample Run

```
Welcome to the ATM!
Enter your username: user1
Enter your password: pass1

Login successful!

----- ATM Menu -----
1. Check Balance
2. Deposit
3. Withdraw
4. View Transaction History
5. Logout
Choose an option: 2
Enter amount to deposit: 500
Deposit successful!

Choose an option: 1
Your current balance is: 500.00

Choose an option: 5
You have been logged out.
```

### Design Notes

- The program is modularized using functions to ensure separation of concerns and cleaner code. Each functionality — login, balance check, deposit, withdrawal, transaction logging — is handled by a dedicated function.

- Arrays are used to simulate user data (username, password, balance) and transaction history.

- Each user has a 2D array of strings to store up to 5 recent transaction logs.

- The system tracks the logged-in user using a simple index (currentUser) to associate actions with the correct data set.

- The main function serves only as a loop controller and relies on helper functions for specific operations, enhancing clarity and maintainability.
