# Codebase Stay

A hotel management system for managing rooms and reservations.

## Set up and run

### 1. Install the required software

You need:
- MySQL Server 8.0 — stores the application’s data.
- MySQL Workbench — lets you create the database.
- Visual Studio with Desktop development with C++, C++/CLI support, v145 build tools, and the .NET Framework 4.7.2 targeting pack — builds and runs the application.

If these are already installed, continue below.

### 2. Download the project

On this GitHub page, click **Code → Download ZIP** and extract it.
You can also clone the repository using Git.

### 3. Create the database

1. Open MySQL Workbench and connect to your MySQL server.
2. Select **File → Open SQL Script**.
3. Open `schema.sql` inside the project's `database` folder.
4. Execute the entire script.

This creates the database and its empty tables.

**Run this only for initial setup. It deletes any existing records in the application’s tables.**

### 4. Enter your MySQL details

1. Open the `CODE BASE STAY` folder containing the `.vcxproj` file.
2. Copy and paste `database.config.example` into the same folder.
3. Rename the new copy to `database.config`.
4. Open it with Notepad.
5. Replace `YOUR_MYSQL_PASSWORD` with the password you use to connect in MySQL Workbench.
6. If your MySQL username is not `root`, change `User ID=root` too.
7. Save the file. Make sure it does not end with `.txt`.

Keep the original example file unchanged.

### 5. Run the application

1. Open `CODE BASE STAY.slnx` with Visual Studio.
2. Select **Debug** and **x64** at the top.
3. Select **Build → Build Solution**.
4. Press **F5** to run.

Keep MySQL Server running while using the application.

## Log in

- Username: `user`
- Password: `123`

These are application login details, separate from your MySQL username and password.

## Start using the system

Add a room first, then create a reservation for it.
Rooms and reservations are saved in MySQL and remain after closing the application.