# 💸 Expense Tracker (C++ + SQLite)

A lightweight Command Line Interface (CLI) based expense management system developed in C++ with SQLite integration.

---

## 🚀 Project Motivation

As a continuation of my learning journey into Object-Oriented Programming and systems-level thinking, this project was created to reinforce:
- Practical application of **encapsulation**, **inheritance**, and class design in C++.
- Integration with a real **database (SQLite)** to make the project more scalable and modular.
- Habit formation by working on consistent, purposeful summer projects to make coding feel natural, not forced.

---

## 🛠 Features

- ✅ Add new expense entries with date, amount, category, and description.
- 📋 View all stored expenses.
- 🔍 Filter expenses by ID.
- ❌ Delete specific entries.
- ✏️ Update expense details by field (amount/category/description).

---

## ⚙️ Tech Stack

- **C++17**: Core language.
- **SQLite3**: Lightweight embedded database.
- **Standard Library**: Used for date/time, string manipulation, and input/output handling.

---

## 📁 File Structure

ExpenseTracker/
├── ExpenseTracker.cpp # Main program source code
├── financial.db # SQLite database (auto-created)
└── README.md # Project documentation


---

## 🧪 Example Usage

**1. Menu on Launch**

Welcome to expense tracker

Add Expense
View All
Filter By Category
Delete Expense
Update

**2. Sample Output When Viewing Data**

ID: 1 Amount: 500 Category: Food Description: Lunch DATE: Sat May 25 21:30:15 2025


---

## 📦 How to Run

Make sure you have SQLite3 installed and linked properly.

**Compile:**

```bash
g++ ExpenseTracker.cpp -lsqlite3 -o tracker
Run:

./tracker
💡 What I Learned

Importance of planning and documenting code to avoid burnout in long projects.
How real database integrations (SQLite in this case) differ from file-based systems.
Better understanding of sqlite3_exec, callbacks, and building robust, modular functions.
🤝 Contributing

This project is for personal learning. Suggestions and ideas are welcome! Feel free to fork it or use it as a reference.

🔗 Connect With Me

Check out more of my work on LinkedIn or GitHub.


---

Let me know if you'd like me to generate a `README.md` file you can directly upload, or if you need help customizing any part!
