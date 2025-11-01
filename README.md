# 🔒 Password Check

**Password Check** is a simple yet powerful console application written in **C** that analyzes and rates the strength of a password.
It provides an interactive and colorful terminal interface with a stylish ASCII banner.

---

## ✨ Features

* **Password Strength Evaluation:**
  Analyzes the password based on:

  * Minimum length (8+ characters)
  * Uppercase and lowercase letters
  * Numbers
  * Special characters

* **Security Levels:**
  Rates the password as **Weak**, **Medium**, **Strong**, **Very Strong**, or **Perfect** using colored text.

* **Interactive Interface:**
  Includes a green ASCII banner and automatic screen clearing for a clean look.

* **Cross-Platform Compatibility:**
  Works on **Windows**, **Linux**, and **macOS** (auto-detects the system for screen clearing).

---

## ⬇️ Setup (Cloning the Repository)

If this project is hosted on GitHub, you can clone it using Git:

```bash
git clone https://github.com/CodeMarcsX/PasswordCheck.git
cd PasswordCheck
```

---

## 🛠️ How to Compile and Run

### Prerequisites

Make sure you have a **C compiler** installed, such as **GCC** or **Clang**.

### Compilation

1. Save the source code as `main.c`.
2. Open your terminal or command prompt.
3. Compile with:

```bash
gcc main.c -o main
```

### Execution

Run the program after compiling:

**On Linux/macOS:**

```bash
./main
```

**On Windows:**

```bash
.\main.exe
```

⚠️ If colors or characters appear broken on Windows, set UTF-8 mode first:

```bash
chcp 65001
```

---

## 🚀 Usage

1. The program starts with a banner and clears the screen.
2. You’ll be prompted to **enter a password**.
3. The system evaluates the password and shows its **security level** with colored output.

**Example:**

```
=========================================================
       ____                  ______/ /             __     
      / __ `___   __________/ ____/ /_  ___  ____ / /__   
     / /_/ / __ `/ ___/ ___/ /   / __ `/ _ `/ ___/ //_/   
    / ____/ /_/ (__  |__  ) /___/ / / /  __/ /__/ ,<      
   /_/    `__,_/____/____/`____/_/ /_/`___/ ___/_/|_|     
========================================================= 
                      PASSWORD CHECK                      
========================================================= 

Enter your password: P@ssw0rd123!

Password level is PERFECT
```
