# C++ Programming Library System Project

## Project Overview

This project involves creating a simple console-based library system. The system allows an admin to manage books and users, enabling operations such as adding books, searching for books, borrowing, and returning books. 

## Features

### Books Operations

1. **Adding a Book**:
   - Each book has an ID, name, and quantity.
   - Example: `101, CppHowToProgram, 7` (7 copies of the book with ID 101).

2. **Searching for a Book**:
   - Search by book name prefix.
   - Example: 
     - Query: `Cpp` ⇒ Results: `CppHowToProgram, CppForDummies, CppForAdvancedLevels`
     - Query: `Java` ⇒ Results: None (if no books with "Java" in the name).

3. **Listing Books**:
   - List all books, sortable by either ID or name.
   - Example:
     - By Name: `ArabicLiterature, Math1, Math2`
     - By ID: `Math2 (1011), Math1 (1111), ArabicLiterature (5041)`

4. **Listing Users Who Borrowed a Book**:
   - Input: Book Name
   - Output: List of user names who borrowed the book.
   - Example: For book `Math1`, output could be `Mostafa, John, Mark, Ali`.

### User Operations

1. **Adding a User**:
   - Each user has an ID and name.
   - Optionally, additional info like email and address can be added.

2. **Borrowing a Book**:
   - Admin enters user name and book name.
   - If the book's quantity is > 0, mark the book as borrowed by the user and decrease the quantity by 1.
   - If no copies are available, notify the admin.

3. **Returning a Book**:
   - Mark the book as returned by the user and increase the quantity by 1.

4. **Additional User Operations**:
   - List system users, sortable by name or ID.
   - List borrowed books of a specific user.

## System Workflow

1. **Menu**:
   - Display all possible choices to the admin.
   - Admin selects a choice, performs the operation, and returns to the main menu.

## Getting Started

### Prerequisites

- C++ compiler
- Basic knowledge of C++ programming
### Acknowledgments

- Inspired by classic library systems.
- Special thanks to Mostafa S. Ibrahim for project guidance and inspiration.
  
---

Feel free to contribute to this project by forking the repository and submitting pull requests. For any issues or suggestions, please open an issue in the GitHub repository.
