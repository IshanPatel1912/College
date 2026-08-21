CREATE DATABASE IF NOT EXISTS library_lab;
USE library_lab;

CREATE TABLE AUTHOR (
    Author_ID VARCHAR(5) PRIMARY KEY,
    Lastname VARCHAR(15) NOT NULL,
    Firstname VARCHAR(15) NOT NULL,
    Email VARCHAR(40),
    City VARCHAR(15),
    Country VARCHAR(15)
);

CREATE TABLE BOOK (
    Book_ID VARCHAR(5) PRIMARY KEY,
    Book_Title VARCHAR(100) NOT NULL,
    Copies INT CHECK (Copies > 2),
    CONSTRAINT CHK_BookID CHECK (Book_ID LIKE 'B%')
);

CREATE TABLE AUTHOR_LIST (
    Author_ID VARCHAR(5),
    Book_ID VARCHAR(5),
    Role VARCHAR(15),
    PRIMARY KEY (Author_ID, Book_ID),
    FOREIGN KEY (Author_ID) REFERENCES AUTHOR(Author_ID),
    FOREIGN KEY (Book_ID) REFERENCES BOOK(Book_ID)
);

INSERT INTO AUTHOR (Author_ID, Lastname, Firstname, Email, City, Country) VALUES
('A0001', 'Smith', 'John', 'john@example.com', 'New York', 'USA'),
('A0002', 'Doe', 'Jane', 'jane@example.com', 'London', 'UK'),
('A0003', 'Patel', 'Raj', 'raj@example.com', 'Mumbai', 'India'),
('A0004', 'Wong', 'Lisa', 'lisa@example.com', 'Toronto', 'Canada');

INSERT INTO BOOK (Book_ID, Book_Title, Copies) VALUES
('B0001', 'Database Systems', 5),
('B0002', 'Learn SQL', 3),
('B0003', 'Data Science 101', 10),
('B0004', 'Advanced Computing', 4);

INSERT INTO AUTHOR_LIST (Author_ID, Book_ID, Role) VALUES
('A0001', 'B0001', 'Co-Author'),
('A0002', 'B0002', 'Author'),
('A0003', 'B0003', 'Author'),
('A0004', 'B0004', 'Editor');

ALTER TABLE AUTHOR_LIST ADD Publisher VARCHAR(30);

CREATE USER 'manager_user'@'localhost' IDENTIFIED BY 'manager123';
CREATE USER 'staff_user'@'localhost' IDENTIFIED BY 'staff123';

GRANT SELECT, INSERT, UPDATE ON AUTHOR TO 'manager_user'@'localhost';
GRANT SELECT ON BOOK TO 'staff_user'@'localhost';

REVOKE INSERT ON AUTHOR FROM 'manager_user'@'localhost';

FLUSH PRIVILEGES;