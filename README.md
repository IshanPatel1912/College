<div align="center">

# 🎓 College — Lab Work & Assignments

**My complete collection of code, outputs and lab documents from college: Python basics, and the Semester 3 labs for Data Structures (C), Database Management Systems (SQL) and Java.**

![C](https://img.shields.io/badge/C-Data%20Structures-A8B9CC?logo=c&logoColor=black)
![Java](https://img.shields.io/badge/Java-OOP-ED8B00?logo=openjdk&logoColor=white)
![SQL](https://img.shields.io/badge/SQL-DBMS-4479A1?logo=mysql&logoColor=white)
![Python](https://img.shields.io/badge/Python-Basics-3776AB?logo=python&logoColor=white)
![University](https://img.shields.io/badge/PDEU-CSE-0b6e4f)

[Overview](#-overview) • [Repository Map](#-repository-map) • [Python](#-python) • [Data Structures](#-data-structures-lab-c) • [DBMS](#-dbms-lab-sql) • [Java](#-java-lab) • [How to Run](#-how-to-run) • [Related Projects](#-related-projects)

</div>

---

## 📋 Overview

This repository is the home of everything I wrote and submitted for my college coursework. Each lab folder keeps the **source code**, the **screenshots of the output** and the **lab manual / final lab file** together, so any experiment can be found, run and checked in one place.

| Subject | Language | Contents |
|---|---|---|
| 🐍 **Python** | Python | 24 beginner programs |
| 🧱 **Data Structures Lab** | C | 10 experiments + 2 additional assignments, with output screenshots |
| 🗄️ **DBMS Lab** | SQL, Python | 10 experiments, question papers and the final lab file |
| ☕ **Java Lab** | Java | Labs 0 to 7 on OOP, exceptions, threads and 3 mini systems |

---

## 🗺️ Repository Map

```
College/
├── Python/                      # 24 beginner programs (1.py ... 22.py, A1.py, A2.py)
└── Sem3/
    ├── DS_Lab/                  # C programs, per-experiment output screenshots, lab file PDF
    │   ├── Experiment_1 ... Experiment_10/
    │   ├── Experiment_1O/ , Experiment_2O/     # additional assignments
    │   ├── DS_Lab_Manual.docx
    │   └── 25BCP113_Lab_File.pdf               # final submitted lab file
    ├── DBMS_Lab/                # SQL scripts E2 ... E10, Python file-handling program E1
    │   ├── Question/            # Lab question sheets (PDF / DOCX / images)
    │   ├── DBMS_Lab_Manual.docx
    │   └── Final file.pdf       # final submitted lab file
    └── JAVA_Lab/                # Lab 0 ... Lab 7 + three mini systems
        ├── Lab 0/ ... Lab 7/    # code, output screenshots and code PDFs
        ├── BankSystem.java
        ├── Bookingsystem.java
        └── UniversitySystem.java
```

---

## 🐍 Python

24 small programs that build core programming skills: taking user input, arithmetic, currency and discount calculations, swapping two values, and computing totals and averages of marks.

| Folder | Programs |
|---|---|
| [`Python/`](./Python) | `1.py` to `22.py`, plus assignment programs `A1.py` and `A2.py` |

---

## 🧱 Data Structures Lab (C)

Path: [`Sem3/DS_Lab`](./Sem3/DS_Lab). Every experiment folder has the `.c` files and an `Output/` folder with a screenshot of each run. Every program prints a header with the student's details before running.

| Experiment | Topic | What it covers |
|:-:|---|---|
| **1** | Searching and sorting | Linear search, binary search, bubble sort, insertion sort, selection sort |
| **2** | Structures | Student records with structures, and nested structures (organizations and their employees) |
| **3** | Pointers | Pointer to an array, accessing structure members through a structure pointer, swapping with pointers and printing addresses |
| **4** | Linked lists | Create and display, insert at front / after a node / at end, delete from beginning / end / middle, circular list, and a doubly linked list with insertions and deletions |
| **5** | Stacks | Array stack and linked-list stack, push / pop / peek, sorting a stack with recursion |
| **6** | Stack applications | Infix to postfix conversion (precedence and associativity), postfix expression evaluation, and other expression problems using a stack |
| **7** | Queues | Array queue, linked queue, priority queue, double-ended queue, enqueue / dequeue / front / rear |
| **8** | Binary search trees | Insert, find minimum, delete, in-order / pre-order / post-order traversals, building a BST from a given sequence |
| **9** | Graphs | BFS, DFS, directed and undirected graphs, Kruskal's minimum spanning tree, complexity analysis |
| **10** | Hashing | Direct-index hashing with a 2D table for O(1) search, and a hash table with a hash function |
| **1O** | Additional assignment 1 | Generating numbers, 30-day temperature (hottest and coldest day), product stock management with stock alerts |
| **2O** | Additional assignment 2 | Hospital patient records: duplicate-ID checks, admitted patients by department, oldest patient, total admitted |

📄 Documents: [Lab manual](./Sem3/DS_Lab/DS_Lab_Manual.docx) • [Final lab file (PDF)](./Sem3/DS_Lab/25BCP113_Lab_File.pdf) • [Course syllabus (PDF)](<./Sem3/DS_Lab/24CS203P - Data Structures.pdf>)

---

## 🗄️ DBMS Lab (SQL)

Path: [`Sem3/DBMS_Lab`](./Sem3/DBMS_Lab)

| Experiment | File | Topic |
|:-:|---|---|
| **1** | [`E1.py`](./Sem3/DBMS_Lab/E1.py) | Student record manager in Python using file handling (`student.txt`): add, view and search records |
| **2** | [`E2.sql`](./Sem3/DBMS_Lab/E2.sql) | Creating and filling tables: `CLIENT_MASTER`, `PRODUCT_MASTER`, `SALESMAN_MASTER` |
| **3** | [`E3.sql`](./Sem3/DBMS_Lab/E3.sql) | `SELECT` with `WHERE`, `UPDATE`, `DELETE` and `ALTER TABLE` (add / modify columns) |
| **5** | [`E5.sql`](./Sem3/DBMS_Lab/E5.sql) | Library schema (`AUTHOR`, `BOOK`, `AUTHOR_LIST`) with `ALTER TABLE`, `GRANT` and `REVOKE` |
| **6** | [`E6.sql`](./Sem3/DBMS_Lab/E6.sql) | Supplier-parts database with `GROUP BY` and `HAVING` |
| **7** | [`E7.sql`](./Sem3/DBMS_Lab/E7.sql) | `EMP` / `DEPT` tables with aggregate queries |
| **8** | [`E8.sql`](./Sem3/DBMS_Lab/E8.sql) | Subqueries (for example `NOT IN`) and grouping |
| **9** | [`E9.sql`](./Sem3/DBMS_Lab/E9.sql) | Joins: self-join and left join on `EMP` |
| **10** | [`E10.sql`](./Sem3/DBMS_Lab/E10.sql) | Stored functions and procedures (`annual_salary`, `get_emp_by_dept`, `increase_salary`) and triggers that validate and audit salary changes |

> Experiment 4 (`E4.sql`) is currently an empty file.

📄 Documents: [Lab manual](./Sem3/DBMS_Lab/DBMS_Lab_Manual.docx) • [Final lab file (PDF)](<./Sem3/DBMS_Lab/Final file.pdf>) • [Question sheets](./Sem3/DBMS_Lab/Question)

---

## ☕ Java Lab

Path: [`Sem3/JAVA_Lab`](./Sem3/JAVA_Lab). Each lab folder has the `.java` files, output screenshots and a PDF of the code.

| Lab | Topic |
|:-:|---|
| **0** | Java basics with `Scanner` input, including a student class (10 programs) |
| **1** | Arrays and basic classes: average temperature and days above it, area of a rectangle and a square |
| **2** | Classes and inheritance (a `Vehicle` class) |
| **3** | Inheritance and abstraction: an `Emp` / `Faculty` / `Adminstaff` hierarchy and an abstract `BankAccount` with savings and premium accounts |
| **4** | Interfaces and polymorphism: a `Payment` interface with `UPIPayment`, `CreditCardPayment` and `NetBankingPayment` |
| **5** | Exception handling: `try` / `catch`, `throws` and a custom `BankExc` exception; plus an audio merge program using `javax.sound` |
| **7** | Multithreading with `Thread` |

### Mini systems

| File | Description |
|---|---|
| [`BankSystem.java`](./Sem3/JAVA_Lab/BankSystem.java) | Console banking system with customers and accounts |
| [`Bookingsystem.java`](./Sem3/JAVA_Lab/Bookingsystem.java) | Hotel booking system |
| [`UniversitySystem.java`](./Sem3/JAVA_Lab/UniversitySystem.java) | University student management |

---

## ▶️ How to Run

**C programs**
```bash
gcc E4Q2.c -o e4q2
./e4q2
```

**Java programs**
```bash
javac L3q1.java
java L
```
*(In several labs the main class is named `L`. Check the class that contains `main` in each file.)*

**Python programs**
```bash
python 1.py
```

**SQL scripts** — run them in MySQL, MariaDB or any SQL client:
```bash
mysql -u root -p < E2.sql
```
Some scripts assume tables from earlier experiments or a classic `EMP` / `DEPT` sample database.

---

## 🔗 Related Projects

Mini projects I built while learning these subjects:

| Project | Built with |
|---|---|
| [FinWise](https://github.com/IshanPatel1912/FinWise) | Java + MySQL — personal finance manager |
| [DineFlow](https://github.com/IshanPatel1912/DineFlow) | Java + MySQL — restaurant management |
| [SmartPark](https://github.com/IshanPatel1912/SmartPark) | Java + MySQL — parking management |
| [Blacksite](https://github.com/IshanPatel1912/Blacksite) | React + Node + SQL — DBMS group project |

---

## ⚠️ Academic Note

This repository is a record of my own coursework, kept for reference and revision. If you are a student, use it to learn and compare approaches, and write your own solutions for your submissions.

---

## 👤 Author

**Ishan Patel** — Undergraduate student (CSE), Pandit Deendayal Energy University (PDEU)

[![GitHub](https://img.shields.io/badge/GitHub-IshanPatel1912-181717?logo=github)](https://github.com/IshanPatel1912)

---

<div align="center">

**Learning by building, one lab at a time**

[🔝 Back to top](#-college--lab-work--assignments)

</div>
