# Student-Management-System

The Student Management System is an application that offers functionalities/services required in an academic setting involving student activities. This project is developed using C-language on a Linux-based environment and provides features for registering, searching, updating, and deleting student records for a specific academic club.

# Table of Contents

1. Context
2. Problem Overview
3. Project Features
4. Directory Structure

# Context

In an academic institute, students can participate in various activities organized by different clubs. This project focuses on managing student records for one such club. The application allows administrators, managers, and members to interact with the system through a command-line interface. It uses a file-based database to store records and a main-memory linked list to keep track of recently accessed data efficiently.

# Problem Overview

The Student Management System aims to provide the following services:

1. Registration: Adding student records to the database.
2. Search: Retrieving student records based on student ID.
3. Update: Modifying student records, especially for hostel room updates.
4. Delete: Removing student records from the database.

The system supports three types of users: administrators, managers, and members. The application listens to requests from users or other programs, which may involve the operations mentioned above.

# Project Features

1. File-based database for storing student records.
2. Main-memory linked list to keep track of recently accessed data.
3. Command-line interface for user interaction.
4. Support for registration, search, update, and delete operations.
5. Differentiate between administrator, manager, and member roles.
