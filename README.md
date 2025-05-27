Expense Tracker

Overview

The Expense Tracker is a console-based C++ application designed to help users manage their personal finances by tracking expenses. It uses SQLite3 for persistent storage and provides functionalities to add, view, filter, update, and delete expense records. The application features a simple menu-driven interface for ease of use.

Features





Add Expense: Record a new expense with amount, category, description, and timestamp.



View All Expenses: Display all stored expense records.



Filter by ID: Retrieve and display a specific expense record by its ID.



Delete Expense: Remove an expense record by its ID.



Update Expense: Modify the amount, category, or description of an existing expense by its ID.



Persistent Storage: Uses SQLite3 to store expense data in a local database (new_financial.db).



Automatic Date Tracking: Automatically captures the current date and time for each expense.

Prerequisites

To build and run the Expense Tracker, ensure you have the following installed:





C++ Compiler: A C++ compiler that supports C++11 or later (e.g., g++).



SQLite3: SQLite library for database operations.





On Ubuntu/Debian: sudo apt-get install libsqlite3-dev



On macOS: brew install sqlite



On Windows: Download SQLite DLL and development files from the SQLite website.



CMake (optional): For easier build configuration.

Installation





Clone the Repository (if applicable):

git clone <repository-url>
cd expense-tracker



Ensure SQLite3 is Installed:





Verify SQLite3 installation by running:

sqlite3 --version



If not installed, follow the platform-specific instructions above.



Compile the Code:





Use a C++ compiler to build the application. For example, with g++:

g++ -o expense_tracker main.cpp -lsqlite3



Ensure the -lsqlite3 flag is included to link the SQLite3 library.



Run the Application:

./expense_tracker

Usage





Launch the Application: Run the compiled executable to start the menu-driven interface:

./expense_tracker



Menu Options: Upon starting, the application displays a menu with the following options:





1. Add Expense: Prompts for amount, category, and description, then saves the record with the current timestamp.



2. View All: Displays all expense records in the database.



3. Filter By Category: Prompts for an ID and displays the corresponding expense record.



4. Delete Expense: Prompts for an ID and deletes the specified expense record.



5. Update: Prompts for an ID, field to update (Amount, Category, or Description), and the new value.



6. Exit: Closes the application.



Example Interaction:

Welcome to expense tracker

1. Add Expense
2. View All
3. Filter By Category
4. Delete Expense
5. Update
6. Exit
1
What is the amount you want to insert?
50
What is the category?
Food
What is the description?
Lunch

This adds a new expense record to the database.

Database Structure

The application creates a SQLite database file named new_financial.db with a single table, finance, structured as follows:





ID: Integer, Primary Key, Auto-incremented



Amount: Integer, Not Null



Category: Text, Not Null



Description: Text, Not Null



Date: Text, Not Null (stores timestamp)

Code Structure

The project consists of two main classes:





Money: Handles core expense management functionalities, including database operations.





Date(): Generates the current timestamp.



addMoney(): Adds a new expense to the database.



viewAll(): Retrieves and displays all expense records.



Filter(): Retrieves a specific expense by ID.



deleteExpense(): Deletes an expense by ID.



Updating(): Updates a specified field of an expense by ID.



Menu: Inherits from Money and provides a menu-driven interface for user interaction.





menu(): Displays the menu and processes user input.

The main() function creates a Menu object and starts the application.

Known Issues





Input Handling: The application uses cin for input, which may not handle invalid inputs robustly (e.g., non-integer input for amount or ID).



Error Handling: Limited error handling for SQLite operations; errors are not fully propagated to the user.



Filter by Category: The current Filter() function filters by ID, not category, despite the menu label.



String Input: Multi-word inputs for category or description may not be handled correctly due to cin limitations.

Planned Improvements





Enhance input validation for robust user input handling.



Fix the Filter() function to support filtering by category instead of ID.



Add support for multi-word inputs using getline() for category and description.



Improve error handling for SQLite operations with user-friendly messages.



Add summary statistics (e.g., total expenses by category).



Implement a configuration file for customizable database names or settings.

Contributing

Contributions are welcome! To contribute:





Fork the repository.



Create a new branch for your feature or bug fix.



Submit a pull request with a clear description of changes.

License

This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments





Built using SQLite3 for lightweight database management.



Inspired by personal finance management needs.
