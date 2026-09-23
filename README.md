# 🏦 Bank Management System

A console-based **Bank Management System** built with **C++**, designed to demonstrate practical **Object-Oriented Programming (OOP)** concepts, file handling, authentication, authorization, input validation, and transaction management.

The system simulates a banking environment where users can manage clients, accounts, transactions, currencies, and system users through a structured console interface.

---

## ✨ Features

### 👤 Client Management

The system provides complete client management functionality:

* Add new clients
* List all clients
* Find clients
* Update client information
* Delete clients
* Manage account numbers
* Manage PIN codes
* View account balances
* Calculate total balances

### 💰 Banking Transactions

The system supports the main account operations:

* Deposit
* Withdraw
* Transfer
* View transaction information
* View total balances

Transfers include validation for both accounts and the sender's available balance before updating the accounts.

### 🔄 Transfer Logging

Each transfer can be recorded in a dedicated log file containing information such as:

* Date and time
* Sender account
* Receiver account
* Transfer amount
* Balances after the transaction
* User who performed the operation

### 👨‍💼 User Management

The system includes a dedicated management system for bank employees and system users:

* Add users
* List users
* Find users
* Update users
* Delete users
* Manage user permissions

### 🔐 Authentication & Authorization

The application provides a login/register system based on:

* Username
* Password
* User permissions

Permissions are implemented using **bit flags**, allowing multiple permissions to be combined and checked efficiently.

Available permissions include:

* List Clients
* Add Client
* Delete Client
* Update Client
* Find Client
* Transactions
* Manage Users
* Login/Register

### 💱 Currency Management

The system includes a dedicated currency module:

* List currencies
* Find currencies
* View currency information
* Update currency rates
* Currency calculator

### 📝 Activity Logging

Important system activities are stored in text files, including:

* Login/Register activity
* Transfer operations

---

# 🏗️ Project Structure

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

# 🧩 Project Modules

## Core

The `Core` directory contains the main entities and business-related classes.

* `Person` — common personal information.
* `BankClient` — client information, accounts, balances, and client operations.
* `BankUser` — system users, authentication, and permissions.
* `Currency` — currency information and currency operations.
* `InterfaceCommunication` — shared interface functionality.

## Lib

The `Lib` directory contains reusable utility components used throughout the application.

* `Date` — date-related operations.
* `Period` — date period operations.
* `String` — string manipulation utilities.
* `InputValidate` — input validation.
* `Util` — general-purpose utility functions.

## Screens

The `Screens` directory contains the console interface.

The screens are organized by responsibility:

* `BankClient`
* `Currency`
* `Transactions`
* `UserScreen`

This separation keeps the interface organized and makes the project easier to maintain and extend.

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

# 💾 File Handling

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

The general data flow is:

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

This allows application data to remain available after the program is closed and started again.

---

# 🔍 Validation

User input is validated before performing important operations.

Examples include:

* Account validation
* User validation
* Numeric input validation
* Transaction amount validation
* Balance validation
* Client existence checks
* User existence checks

Reusable validation functionality is located in:

```text
Lib/InputValidate.h
```

---

# 🛠️ Technologies & Concepts

The project was built using:

* **C++**
* **Object-Oriented Programming**
* **File Handling**
* **Authentication & Authorization**
* **Bit Flags**
* **Input Validation**
* **Transaction Management**
* **Logging**
* **Modular Design**

---

# 🚀 How to Run

### Requirements

* Visual Studio
* C++ development environment

### Steps

1. Clone or download the repository.
2. Open the project in **Visual Studio**.
3. Build the project.
4. Run the application.

The application uses the files inside `src/Files/` for persistent data.

---

# 🎯 Project Goal

The main goal of this project is to apply **C++ OOP concepts** in a practical application while also gaining experience with:

* Designing classes and relationships
* Separating responsibilities
* Working with files
* Managing application data
* Implementing authentication and permissions
* Validating user input
* Handling financial transactions
* Organizing a multi-module C++ project

---

## 👨‍💻 Author

**Mahmoud Saber**

GitHub: [MahmoudSaber23](https://github.com/MahmoudSaber23)

---

The project brings together:

**C++ OOP + File Handling + Authentication + Authorization + Validation + Transactions + Logging + Modular Design**
