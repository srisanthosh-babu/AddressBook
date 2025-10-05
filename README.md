## 📖 AddressBook (C Project)

The **AddressBook** project is a simple **C-based contact management system** that allows users to store, manage, and persist contact information. It implements a **CRUD (Create, Read, Update, Delete)** application with file handling, making it a great example of using **structures, arrays, and file operations in C programming**.

---

### ✨ Features

* **Add new contacts** – store name, phone number, and email.
* **Search contacts** – find a contact by name.
* **Edit contacts** – update existing contact details.
* **Delete contacts** – remove a contact from the address book.
* **List contacts** – display all saved contacts.
* **Persistent storage** – contacts are saved to a file and reloaded at startup.

---

### 🛠️ Technical Details

* Implemented in **C language**.
* Uses **structures (`struct`)** to represent contacts and address book.
* Stores data in an array with a maximum capacity (`MAX_CONTACTS`).
* Incorporates **file handling** (`fptr_contact`) to store and retrieve contacts from disk.
* Designed for **easy extension** with modular functions for each operation.

---

### 📂 Project Structure

* **`contact.h`** → Header file containing structure definitions and function prototypes.
* **`addressbook.c`** → Implementation of CRUD operations and file management.
* **`main.c`** → Entry point providing a menu-driven interface for user interaction.

---

### 🚀 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/AddressBook.git
   cd AddressBook
   ```
2. Compile the code:

   ```bash
   gcc main.c addressbook.c -o addressbook
   ```
3. Run the program:

   ```bash
   ./addressbook
   ```

---

### 🎯 Learning Objectives

* Understand **modular programming** in C.
* Practice **file I/O** for persistent data storage.
* Apply **CRUD operations** on structured data.
* Gain experience with **menu-driven applications**.

---

### 📌 Example Use Case

* Adding a new contact:

  ```
  Enter Name: John Doe
  Enter Phone: 1234567890
  Enter Email: john@example.com
  ```
* Searching for a contact:

  ```
  Enter Name to Search: John Doe
  Found: John Doe | 1234567890 | john@example.com
  ```

---

### 🔮 Future Enhancements

* Increase contact limit dynamically using linked lists.
* Support for importing/exporting CSV files.
* Add validation for phone numbers and emails.

---



