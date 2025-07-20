# todo-cli-c

To-Do List CLI App in C

A simple command-line To-Do list manager written in C. This project allows you to add, view, mark as completed, and delete all tasks using basic commands. It uses file handling to store tasks persistently in a `task.txt` file.

---

## 📌 Features

- ✅ Add new tasks with auto-incremented task IDs
- 📄 View all existing tasks
- ✔️ Mark specific tasks as completed
- 🗑️ Delete all tasks in one go
- 💾 Persistent storage using a text file (`task.txt`)
- 🧠 Easy-to-read and beginner-friendly code with comments

---

## 🛠️ Commands

After running the program, you can use the following commands:

| Command              | Description                          |
|----------------------|--------------------------------------|
| `task add`           | Add a new task                       |
| `task view`          | Display all tasks                    |
| `task completed`     | Mark a specific task as completed    |
| `task delete all`    | Delete all saved tasks               |
| `exit`               | Exit the program                     |

---

## 📂 File Structure

- `main.c` – Main source code file
- `task.txt` – Auto-generated file that stores all the tasks

---

## 🧑‍💻 How It Works

### Adding a Task
- You type `task add`
- The program prompts you for the task content
- It appends the task to `task.txt` with an ID like `1. task : Buy milk`

### Viewing Tasks
- You type `task view`
- The program reads `task.txt` line by line and prints each task

### Marking a Task as Completed
- You type `task completed`
- Enter the task number (e.g., `2`)
- That specific task will be updated to include `[COMPLETED]`

### Deleting All Tasks
- You type `task delete all`
- The program opens `task.txt` in write mode, effectively clearing all data

---

## 🧑‍🎓 What You'll Learn

This is a great beginner C project if you're learning:

- File handling (`fopen`, `fgets`, `fputs`, `fprintf`)
- String functions (`fgets`, `strcspn`, `strcat`, `strcmp`, `sscanf`)
- Basic loops and conditionals
- Command-line input and handling
- Arrays and memory management fundamentals

---

## 🏁 Getting Started

### Compile the code:
```bash
gcc main.c -o todo
