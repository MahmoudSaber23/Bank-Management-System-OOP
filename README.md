# Bank Management System

A console-based **Bank Management System** developed in C++ to simulate common banking operations while applying Object-Oriented Programming, file handling, authentication, authorization, validation, and modular software design.

The project was built as a practical C++ application rather than a collection of isolated exercises. It manages bank clients, system users, transactions, currencies, and persistent records through a structured set of classes and modules.

## Overview

The system provides two main sides of the banking environment:

* **Bank Clients** — customers who have accounts and balances.
* **Bank Users** — system users/operators who are authorized to perform administrative and banking operations.

The application supports client management, user management, deposits, withdrawals, transfers, transaction logging, currency management, authentication, and permission-based access control.

All persistent data is handled through text files, so the application does not require an external database.

---

## Features

### Client Management

The system provides the main operations required to manage bank clients:

* Add a new client
* Update client information
* Delete a client
* Find a client
* List all clients
* Check whether an account exists
* Manage account numbers and PINs
* View account balances
* Calculate total balances

Client records are loaded from files when needed and saved back after modifications.

### Transactions

The system supports basic banking transactions:

* Deposit
* Withdraw
* Transfer
* View total balances
* View transaction information

Before performing operations, the system validates the relevant client and account information and checks the available balance where required.

### Money Transfer

The transfer module allows one client to transfer money to another client.

A transfer includes:

1. Validating the sender account.
2. Validating the receiver account.
3. Checking the sender's available balance.
4. Updating the sender balance.
5. Updating the receiver balance.
6. Recording the operation in the transfer log.

Transfer records contain information such as the date, sender, receiver, amount, and balances after the operation.

### User Management

Authorized bank users can manage other system users:

* Add users
* Update users
* Delete users
* Find users
* List users
* Manage permissions
* Authenticate users
* Record login activity

This separates the concept of a **bank client** from the **user operating the system**.

### Authentication & Authorization

The application includes a login system based on username and password.

Users can have different permissions depending on their role.

The permission system uses **bitwise flags**, allowing multiple permissions to be combined into a single value.

Examples of permissions include:

* List Clients
* Add Client
* Delete Client
* Update Client
* Find Client
* Perform Transactions
* Manage Users
* Login/Register

An administrator can be granted full access to the available operations.

### Currency Management

The application includes a separate currency module for managing currency information.

It provides:

* List currencies
* Find a currency
* Update currency rates
* Currency calculator

The currency functionality is kept separate from the main client and transaction modules.

### Logging

The system records important activities in dedicated log files, including:

* Login activity
* Money transfers

The logs include timestamps and relevant information about the operation.

This provides basic traceability of system activity.

---

# Project Structure

The project is organized into three main areas:

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

Contains the main entities and core functionality of the system.

Important classes include:

* `Person`
* `BankClient`
* `BankUser`
* `Currency`
* `InterfaceCommunication`

The `Person` class provides common information that can be shared by specialized entities such as clients and users.

### Lib

Contains reusable utility functionality used throughout the application.

Examples include:

* Date operations
* Period/date calculations
* String manipulation
* Input validation
* Utility functions
* Random data generation

Keeping these utilities separate reduces duplication and makes them reusable across different modules.

### Screens

Contains the console interface of the application.

The screens are separated by responsibility:

```text
Screens/
├── BankClient/
├── Currency/
├── Transactions/
└── UserScreen/
```

There are also general screens such as:

* Login
* Main menu
* Screen header

This keeps the user interface logic separated from the core entities.

---

# Object-Oriented Design

The project was designed around several core OOP concepts.

## Encapsulation

Each major entity manages its own data and exposes operations through class methods instead of allowing unrelated parts of the program to directly manipulate internal state.

## Inheritance

A base `Person` entity is used for shared personal information, with specialized classes built on top of it.

```text
Person
├── BankClient
└── BankUser
```

This avoids duplicating common information and behavior.

## Abstraction

Operations such as loading records, saving records, searching, updating, and deleting are handled by the relevant classes instead of being implemented repeatedly throughout the application.

## Function Overloading

The project uses function overloading where multiple versions of an operation are useful for different inputs or contexts.

## Static Members and Functions

Static functionality is used for operations that belong to the class or shared data rather than a particular object instance.

---

# File Handling

One of the main goals of the project is to practice persistent storage using C++ file handling.

Instead of using a database, the application stores records in text files.

The system performs operations such as:

* Read records from files
* Convert file records into C++ objects
* Store objects in vectors
* Add records
* Update records
* Delete records
* Convert objects back into file records
* Save updated data to files

A custom delimiter is used to store multiple fields in a single record.

Example:

```text
Field1#//#Field2#//#Field3#//#Field4
```

This approach provides simple persistent storage while keeping the project focused on C++ and file handling.

---

# Data Flow

A typical operation follows this general flow:

```text
Text File
   ↓
Read Record
   ↓
Parse Fields
   ↓
Create C++ Object
   ↓
Perform Operation
   ↓
Update Object
   ↓
Save Updated Record
   ↓
Text File
```

For example, when updating a client:

```text
Client File
    ↓
Load Clients
    ↓
Find Client
    ↓
Modify Client Data
    ↓
Save Clients
```

This pattern is reused throughout different parts of the application.

---

# Main Data Model

The main entities can be represented conceptually as:

```text
Person
│
├── BankClient
│   ├── Account Number
│   ├── PIN
│   └── Balance
│
└── BankUser
    ├── Username
    ├── Password
    └── Permissions
```

The system also manages:

```text
Currency
Transactions
Transfer Logs
Login Records
```

---

# Validation

Input validation is handled through reusable validation functionality.

The application validates different types of input, including:

* Numeric values
* Required values
* Account numbers
* Usernames
* Passwords
* Transaction amounts
* Client/user existence
* Balance-related operations

This helps prevent invalid input from reaching the core operations.

---

# Security Considerations

This project is an educational C++ application and is **not intended to represent a production banking system**.

Authentication and password storage are implemented for learning purposes using the project's own reversible text transformation.

For a real banking or production application, this approach would need to be replaced with technologies such as:

* Strong password hashing
* Secure credential storage
* Database transactions
* Encryption
* Secure communication
* Proper session management
* Auditing and monitoring
* Stronger authorization controls

The purpose here is to demonstrate the underlying programming and software design concepts rather than production-grade financial security.

---

# Technologies

| Technology           | Usage                         |
| -------------------- | ----------------------------- |
| C++                  | Main programming language     |
| OOP                  | Application and entity design |
| STL                  | Data structures and utilities |
| `vector`             | In-memory record collections  |
| `string`             | Text and record manipulation  |
| File Streams         | Persistent storage            |
| Inheritance          | Shared entity design          |
| Encapsulation        | Data and behavior management  |
| Function Overloading | Flexible operations           |
| Bitwise Flags        | User permissions              |
| Visual Studio        | Development environment       |

---

# Running the Project

## Requirements

* Windows
* Visual Studio
* C++ development tools

## Steps

1. Clone or download the repository.
2. Open the project/solution in Visual Studio.
3. Make sure the project is configured for a C++ standard supported by the source code.
4. Build the project.
5. Run the application.

The application uses text files for persistent data, so the required data files should be available in the expected working directory.

---

# Example System Flow

A typical session can follow this flow:

```text
Start Application
       ↓
Login / Register
       ↓
Authentication
       ↓
Permission Check
       ↓
Main Menu
       ↓
┌─────────────────────────────┐
│ Client Management           │
│ User Management             │
│ Transactions                │
│ Currency Management         │
│ Login / Register            │
└─────────────────────────────┘
       ↓
Perform Operation
       ↓
Validate Input
       ↓
Update Data
       ↓
Save Changes
       ↓
Log Important Operations
```

---

# Why I Built This Project

The main purpose of this project was to apply C++ concepts to a larger, practical system.

Instead of implementing OOP concepts through small independent examples, the project combines them into one application where different components have to work together.

The project helped me practice:

* Designing classes around real-world entities
* Using inheritance and encapsulation
* Managing collections of objects
* Working with files as persistent storage
* Designing CRUD operations
* Building authentication and authorization
* Implementing permission systems
* Handling financial transactions
* Creating reusable utilities
* Organizing a multi-module C++ project
* Thinking about separation of responsibilities

---

# Future Improvements

Possible next steps for the project include:

* Replace text-file storage with a relational database
* Introduce a repository/data-access layer
* Improve the authentication and password-storage mechanism
* Add unit testing
* Improve exception handling
* Add automated tests
* Separate business logic from the console UI even further
* Add a graphical or web interface
* Expose the banking operations through a backend API

---

# Project Status

The project is an ongoing C++ learning and development project.

The current version focuses on:

**OOP → File Handling → Validation → Authentication → Authorization → Transactions → Modular Design**

The architecture can be extended as the project evolves.

---

## Author

**Mahmoud Saber**

C++ / Backend Development Learner

---

## Repository

[View the source code on GitHub](https://github.com/MahmoudSaber23/Bank-Management-System-OOP)
