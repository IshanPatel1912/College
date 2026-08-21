import os

FILE_NAME = "student.txt"

if not os.path.exists(FILE_NAME):
    open(FILE_NAME,"w").close()

def read_records():
    students = []
    with open(FILE_NAME,"r") as file:
        for line in file:
            line=line.strip()
            if line:
                roll, name, age, department = line.split(",")
                students.append([roll, name, age, department]) 
    return students

def write_records(students):
    with open(FILE_NAME,"w") as file:
        for student in students:
            file.write(",".join(student) + "\n")

def add_student():
    roll = input("Enter the Roll No.")

    students = read_records()
    for student in students:
        if student[0] == roll:
            print("Roll No. already exists!")
            return
    name = input("Enter the Name: ")
    age = input("Enter the Age: ")
    department = input("Enter the Department: ")

    with open(FILE_NAME,"a") as file:
        file.write(f"{roll},{name},{age},{department}\n")

    print("Student record added successfully.") 

def view_all_records():
    students = read_records()

    if not students:
        print("No Record Found")
        return

    print("\n{:<15}{:<20}{:<10}{:<20}".format(
            "Roll Number", "Name", "Age", "Department"))
    print("-" * 65)

    for student in students:
            print("{:<15}{:<20}{:<10}{:<20}".format(
                student[0], student[1], student[2], student[3]))

def search_record():
    roll = input("Enter the Roll No.:")

    students = read_records()

    for student in students:
        if student[0] == roll:
            print("\nRecord Found")
            print("Roll Number :", student[0])
            print("Name        :", student[1])
            print("Age         :", student[2])
            print("Department  :", student[3])
            return

    print("Record Not Found")

def update_record():
    roll = input("Enter the Roll No. to update: ")

    students = read_records()
    found = False 

    for student in students:
        if student[0] == roll:
            print("Enter new details:")
            student[1] = input("Name: ")
            student[2] = input("Age: ")
            student[3] = input("Department: ")
            found = True
            break
    if found:
        write_records(students)
        print("Record Updated Successfully")
    else:
        print("Record Not Found")

def delete_record():
    roll=input("Enter the Roll You want to delete:i de ")

    students=read_records()
    updated_students = []

    found = False

    for student in students:
        if student[0] == roll:
            found = True
        else:
            updated_students.append(student)
    
        if found:
            write_records(updated_students)
            print("Record deleted successfully.")
        else:
            print("Record not found.")

def menu():
    while True:
        print("\n----- STUDENT RECORD MANAGEMENT SYSTEM -----")
        print("1. Add a Student Record")
        print("2. View All Records")
        print("3. Search a Record by Roll Number")
        print("4. Update a Record")
        print("5. Delete a Record")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            add_student()
        
        elif choice == "2":
            view_all_records()
        
        elif choice == "3":
            search_record()
        
        elif choice == "4":
            update_record()
        
        elif choice == "5":
            delete_record()
        
        elif choice == "6":
            print("Program terminated.")
            break
        
        else:
            print("Invalid choice! Please try again.")
menu()