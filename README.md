# Bank Management System

A console-based **Bank Management System** built with **C++**, focusing on Object-Oriented Programming, file handling, authentication, authorization, input validation, and transaction management.

The project simulates the management of bank clients and system users, including account operations, deposits, withdrawals, transfers, currency management, and activity logging.

---

## Features

### Client Management

* Add new clients
* List all clients
* Find clients
* Update client information
* Delete clients
* Manage account numbers
* Manage PIN codes
* View account balances
* Calculate total balances

### Banking Transactions

The system supports the main account operations:

* Deposit
* Withdraw
* Transfer
* View transaction information
* View total balances

Transfers include validation for both accounts and the sender's available balance before updating the accounts.

### Transfer Logging

Transfers are stored in a dedicated log file containing information such as:

* Date and time
* Sender account
* Receiver account
* Transfer amount
* Balances after the transaction
* User who performed the operation

### User Management

The system has a separate management system for bank employees/system users:

* Add users
* List users
* Find users
* Update users
* Delete users
* Manage user permissions

### Authentication & Authorization

The application provides a login/register system using:

* Username
* Password
* User permissions

Permissions are implemented using **bit flags**, allowing multiple permissions to be combined efficiently.

Examples of available permissions include:

* List Clients
* Add Client
* Delete Client
* Update Client
* Find Client
* Transactions
* Manage Users
* Login/Register

### Currency Management

The system includes a dedicated currency module:

* List currencies
* Find currencies
* View currency information
* Update currency rates
* Currency calculator

### Activity Logging

The application stores important activities in text files, including:

* Login/Register activity
* Transfer operations

---

# Project Structure

```text
src/
│
├── Core/
│   ├── BankClient.h
│   ├── BankUser.h
│   ├── Currency.h
│   ├── InterfaceCommunication.h
│   └── Person.h
│
├── Lib/
│   ├── Date.h
│   ├── InputValidate.h
│   ├── Period.h
│   ├── String.h
│   └── Util.h
│
├── Screens/
│   │
│   ├── BankClient/
│   │   ├── AddNewClientScreen.h
│   │   ├── ClientsListScreen.h
│   │   ├── DeleteClientScreen.h
│   │   ├── FindClientScreen.h
│   │   └── UpdateClientScreen.h
│   │
│   ├── Currency/
│   │   ├── CurrenciesListScreen.h
│   │   ├── CurrencyCalculatorScreen.h
│   │   ├── CurrencyScreen.h
│   │   ├── FindCurrencyScreen.h
│   │   └── UpdateCurrencyRateScreen.h
│   │
│   ├── Transactions/
│   │   ├── DepositScreen.h
│   │   ├── TotalBalancesScreen.h
│   │   ├── TransactionsScreen.h
│   │   ├── TransferLogScreen.h
│   │   ├── TransferScreen.h
│   │   └── WithdrawScreen.h
│   │
│   └── UserScreen/
│       ├── AddNewUserScreen.h
│       ├── DeleteUserScreen.h
│       ├── FindUserScreen.h
│       ├── LoginRegisterScreen.h
│       ├── ManageUsersScreen.h
│       ├── UpdateUserScreen.h
│       └── UsersListScreen.h
│
├── Files/
│   ├── Clients.txt
│   ├── Currencies.txt
│   ├── LoginRegister.txt
│   ├── Transfer.txt
│   └── Users.txt
│
├── Global.h
└── Bank-Management-System.cpp
```

---

# Project Modules

## Core

The `Core` directory contains the main entities and business-related classes.

* `Person` — common personal information.
* `BankClient` — client information, accounts, balances, and client operations.
* `BankUser` — system users, authentication, and permissions.
* `Currency` — currency information and currency operations.
* `InterfaceCommunication` — shared interface functionality.

## Lib

The `Lib` directory contains reusable utilities used throughout the application.

* `Date` — date-related operations.
* `Period` — date period operations.
* `String` — string manipulation utilities.
* `InputValidate` — input validation.
* `Util` — general-purpose utility functions.

## Screens

The `Screens` directory contains the console interface.

The screens are separated by responsibility into:

* `BankClient`
* `Currency`
* `Transactions`
* `UserScreen`

This keeps the user interface organized instead of placing all screens in a single directory.

## Files

The `Files` directory contains the application's persistent data.

| File                | Purpose                       |
| ------------------- | ----------------------------- |
| `Clients.txt`       | Stores client records         |
| `Users.txt`         | Stores system user records    |
| `Currencies.txt`    | Stores currency information   |
| `Transfer.txt`      | Stores transfer records       |
| `LoginRegister.txt` | Stores login/register records |

---

# Object-Oriented Programming

The project applies several C++ OOP concepts in a practical application.

### Encapsulation

Classes manage their own data and expose operations through member functions.

### Inheritance

Common personal information is represented through the `Person` base class and specialized into:

```text
Person
├── BankClient
└── BankUser
```

### Abstraction

Operations such as loading, saving, searching, updating, and deleting records are handled inside the relevant classes.

### Function Overloading

Overloaded functions are used where the same operation needs to support different parameters or use cases.

### Static Members and Functions

Static functionality is used for operations that belong to a class rather than a specific object.

---

# File Handling

The project uses **text files for persistent storage instead of a database**.

The application can:

* Read records from files
* Parse stored records
* Convert records into C++ objects
* Store objects in collections
* Add new records
* Update existing records
* Delete records
* Convert objects back into records
* Save updated data to files

The general flow is:

```text
File
 ↓
Read Record
 ↓
Parse Data
 ↓
Create / Load Object
 ↓
Perform Operation
 ↓
Update Object
 ↓
Save Data
 ↓
File
```

This allows data to remain available after the application is closed and started again.

---

# Validation

User input is validated before performing important operations.

Examples include:

* Account validation
* User validation
* Numeric input validation
* Transaction amount validation
* Balance validation
* Client existence checks
* User existence checks

Reusable validation functionality is located in `Lib/InputValidate.h`.

---

# How to Run

### Requirements

* Visual Studio

### Steps

1. Clone or download the repository.
2. Open the project in Visual Studio.
3. Build the project.
4. Run the application.

The application uses the files inside `src/Files/` for persistent data.

---

The project brings together:

**C++ OOP + File Handling + Authentication + Authorization + Validation + Transactions + Logging + Modular Design**

---




