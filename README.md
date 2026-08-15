# 🏦 Bank Management System — C++

A feature-rich **console-based Bank Management System** developed in **C++** with a strong focus on **Object-Oriented Programming, file-based persistence, access control, transaction processing, and modular software design**.

This project simulates the core operations of a banking environment, including client management, employee/user management, financial transactions, money transfers, currency management, authentication, authorization, and transaction logging.

> **Project Type:** Console Application
> **Language:** C++
> **Paradigm:** Object-Oriented Programming
> **Persistence:** File Handling / Text-Based Storage
> **Development Environment:** Visual Studio

---

## 📌 Overview

The system is designed as a complete banking management application rather than a simple CRUD project.

It provides separate modules for:

* 👤 Bank User Management
* 👥 Client Management
* 💰 Deposits & Withdrawals
* 🔄 Money Transfers
* 📊 Balance Management
* 💱 Currency Management
* 🔐 Authentication & Authorization
* 📝 Login & Transaction Logging
* 📅 Date and time utilities
* ✅ Input validation
* 🧰 Reusable utility functions

The application uses a modular structure that separates the **core business entities**, **reusable libraries**, and **user-interface screens**.

---

# ✨ Main Features

## 👥 Client Management

The system provides complete client management functionality:

* Add new clients
* Update existing client information
* Delete clients
* Search for clients
* Display all clients
* Check account existence
* Manage account numbers
* Manage PIN codes
* Track account balances
* Calculate total balances

Client data is persisted using file handling, allowing information to remain available between application runs.

---

## 💰 Banking Transactions

The system supports essential banking operations:

### Deposit

Allows authorized users to deposit money into a client account.

### Withdraw

Allows money to be withdrawn while preventing withdrawals that exceed the available balance.

### Transfer

Supports transferring money between two bank accounts while:

* Validating the sender's balance
* Updating both accounts
* Recording the transaction
* Storing sender and receiver balances after the transfer
* Recording the user responsible for the operation

---

## 🔄 Transfer Logging

Transfers are not simply executed and forgotten.

Each transfer can be recorded with information such as:

* Date and time
* Sender account number
* Receiver account number
* Transfer amount
* Sender balance after transfer
* Receiver balance after transfer
* User who performed the transaction

This provides a basic transaction-auditing mechanism.

---

## 🔐 Authentication & Authorization

The system includes a user authentication system based on:

* Username
* Password
* User permissions
* Login/register records

Users can be assigned different permissions depending on their responsibilities.

### Permission-Based Access Control

The project uses a permission system based on **bit flags**, allowing multiple permissions to be combined efficiently.

Examples include:

* List Clients
* Add New Client
* Delete Client
* Update Client
* Find Client
* Transactions
* Manage Users
* Login/Register

An administrator-level permission can grant full access to the system.

---

## 👤 Bank User Management

Authorized users can:

* Add new users
* Update users
* Delete users
* Search for users
* List all users
* Manage permissions
* Authenticate users
* Record login activity

This creates a clear separation between **bank clients** and **system users/operators**.

---

# 💱 Currency Management

The system includes a dedicated currency module for managing currency information.

Features include:

* List currencies
* Find currencies
* Update currency rates
* Currency calculator
* Currency-related operations through dedicated screens

This makes the system more than a basic account-management application by introducing an additional financial-management module.

---

# 🏗️ Project Architecture

The source code is organized into separate modules:

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
│   ├── BankClient/
│   ├── Currency/
│   ├── Transactions/
│   └── UserScreen/
│
├── Global.h
└── Bank-Management-System.cpp
```

### Core

Contains the main business entities and domain logic:

* `Person`
* `BankClient`
* `BankUser`
* `Currency`
* `InterfaceCommunication`

### Lib

Contains reusable functionality such as:

* Date manipulation
* String processing
* Input validation
* Utility functions
* Random data generation
* Text conversion
* Basic reversible text transformation

### Screens

Contains the application's console interface and separates the user interaction into dedicated modules for:

* Clients
* Users
* Currency
* Transactions
* Login
* Main navigation

---

# 🧠 Object-Oriented Programming

The project applies several important OOP concepts in a practical system.

### Encapsulation

Sensitive and internal object data is kept inside classes and exposed through controlled methods.

### Inheritance

The system uses inheritance between the base `Person` entity and specialized entities such as:

```text
Person
├── BankClient
└── BankUser
```

### Abstraction

Complex operations such as loading, saving, searching, updating, and deleting records are encapsulated inside the relevant classes.

### Polymorphism / Overloading

The project uses function overloading in several areas to provide different ways of performing similar operations.

### Static Operations

Static methods are used for operations that work with collections of records or provide utility functionality without requiring a specific object instance.

---

# 💾 File Handling & Persistence

Instead of relying on an external database, the application uses **text files as persistent storage**.

The system performs operations such as:

* Reading records from files
* Converting file records into C++ objects
* Converting objects back into file records
* Adding new records
* Updating records
* Deleting records
* Loading records into vectors
* Saving updated collections back to files

A custom delimiter is used to serialize multiple fields into a single text record.

Example concept:

```text
Field1#//#Field2#//#Field3#//#Field4
```

This provides a lightweight persistence layer without requiring a database server.

---

# 📝 Logging

The system maintains records for important activities such as:

* Login activity
* Money transfers

Log records include timestamps and relevant operation data, providing basic traceability of system operations.

---

# 🛠️ Technologies & Concepts

### Programming

* C++
* Object-Oriented Programming
* STL
* `vector`
* `string`
* File Streams
* Static Members
* Enumerations
* Structs
* Function Overloading
* Inheritance
* Encapsulation

### System Design

* Modular organization
* Separation of concerns
* Entity-based design
* Permission-based authorization
* File-based persistence
* Record serialization/deserialization
* Transaction logging
* Input validation

---

# 📂 Data Model

The application manages several categories of information:

```text
Person
│
├── BankClient
│   ├── Account Number
│   ├── PIN Code
│   └── Account Balance
│
└── BankUser
    ├── Username
    ├── Password
    └── Permissions
```

Additional data is maintained for:

```text
Currencies
Transactions
Transfer Logs
Login Records
```

---

# 🔒 Security Note

The project includes a basic reversible text transformation for stored passwords.

This is implemented as part of the educational design of the project and **should not be considered production-grade password security**.

A production banking application should use modern password hashing, secure credential management, encrypted communication, database transactions, and additional security controls.

---

# 🚀 What I Learned From This Project

Building this project provided practical experience with:

* Designing a multi-module C++ application
* Applying OOP concepts to a real-world domain
* Designing reusable classes
* Managing persistent data without a database
* Converting between objects and file records
* Implementing CRUD operations
* Building authentication and authorization logic
* Working with permission bit flags
* Implementing financial transactions
* Maintaining transaction logs
* Organizing a growing codebase
* Building reusable utility libraries
* Handling user input and validation

---

# 🔮 Possible Future Improvements

The project can be extended with:

* Database integration such as SQL
* Repository pattern
* Service layer
* Strong password hashing
* Improved exception handling
* Unit testing
* Automated testing
* REST API / backend version
* GUI or web interface
* Advanced reporting
* More detailed transaction auditing
* Multi-currency account support
* Role-based access control improvements
* Configuration management

---

# 🎯 Project Goal

The goal of this project was to move beyond isolated C++ exercises and build a **complete, modular software system** that combines object-oriented programming, persistent storage, authentication, authorization, financial operations, logging, and reusable utilities into one cohesive application.

---

## 👨‍💻 Author

**Mahmoud Saber**

C++ Developer | Object-Oriented Programming | Backend Development

---

## ⭐ If you find this project useful

Feel free to explore the source code, suggest improvements, or use the project as a reference for learning C++ Object-Oriented Programming and file-based application design.

---

### 📌 Repository

[Bank Management System — C++ OOP](https://github.com/MahmoudSaber23/Bank-Management-System-OOP)
