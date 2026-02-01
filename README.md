Smart Banking System (C++)

A console-based Smart Banking System implemented in C++, designed to demonstrate core Object-Oriented Programming (OOP) principles such as encapsulation, inheritance, and polymorphism.

 Features

Account creation with unique account numbers

Deposit and withdrawal operations

Savings Account with:

Minimum balance enforcement

Interest calculation

Current Account with:

Overdraft facility

Runtime polymorphism using base class pointers

Clean separation of responsibilities using OOP

++OOP CONCEPTS DEMONSTRATED

Encapsulation – Private data members with controlled access

Inheritance – SavingsAccount and CurrentAccount derived from Account

Polymorphism – Virtual functions called via base class pointer

Method Overriding – Specialized withdraw() behavior per account type

Abstraction – Common interface via base class

🗂️ Project Structure
SmartBankingSystem/
│
├── SmartBankingSystem.cpp
├── .gitignore
└── README.md

⚙️ Build & Run Instructions
Requirements

C++ compiler (GCC / MinGW / g++)

Windows, Linux, or macOS

Compile
g++ SmartBankingSystem.cpp -o SmartBankingSystem

Run
./SmartBankingSystem


(On Windows PowerShell)

.\SmartBankingSystem

🧪 Sample Usage

Create a Savings Account

Deposit money

Add interest

Attempt withdrawals with minimum balance rules

Create a Current Account

Withdraw using overdraft limit

Display account information polymorphically

-- Future Improvements

Add transaction history

Store multiple accounts using STL containers

Convert base class to an abstract class

Add file handling for persistent storage

Implement a menu-driven interface

👤 Author

Mark Nambuva
Computer Science Student | Network & Software Engineering Enthusiast

📜 License

This project is for learning and educational purposes.
