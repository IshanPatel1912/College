CREATE IF NOT EXISTS DATABASE e6_db;
USE e6_db;

CREATE TABLE Supplier (
    scode INT PRIMARY KEY,
    sname VARCHAR(50),
    scity VARCHAR(50),
    turnover INT
);

CREATE TABLE Part (
    pcode INT PRIMARY KEY,
    weigh INT,
    color VARCHAR(20),
    cost INT,
    sellingprice INT
);

CREATE TABLE Supplier_Part (
    scode INT,
    pcode INT,
    qty INT,
    PRIMARY KEY (scode, pcode),
    FOREIGN KEY (scode) REFERENCES Supplier(scode),
    FOREIGN KEY (pcode) REFERENCES Part(pcode)
);

INSERT INTO Supplier VALUES (1, 'Acme Corp', 'Bombay', 50);
INSERT INTO Supplier VALUES (2, 'Global Supplies', 'Delhi', NULL);
INSERT INTO Supplier VALUES (3, 'TechParts Inc', 'Bombay', 75);
INSERT INTO Supplier VALUES (4, 'Reliable Co', 'Madras', NULL);
INSERT INTO Supplier VALUES (5, 'Sunrise Traders', 'Bombay', 50);
INSERT INTO Supplier VALUES (6, 'Apex Systems', 'Pune', 120);

INSERT INTO Part VALUES (3, 28, 'Green', 30, 45); 
INSERT INTO Part VALUES (4, 50, 'Red', 40, 60);
INSERT INTO Part VALUES (5, 32, 'Yellow', 15, 25);
INSERT INTO Part VALUES (6, 25, 'Black', 20, 35);
INSERT INTO Part VALUES (1, 30, 'Red', 20, 25);
INSERT INTO Part VALUES (2, 40, 'Blue', 35, 50);

INSERT INTO Supplier_Part VALUES (2, 1, 30);
INSERT INTO Supplier_Part VALUES (3, 1, 15);
INSERT INTO Supplier_Part VALUES (3, 2, 25);
INSERT INTO Supplier_Part VALUES (3, 3, 50);
INSERT INTO Supplier_Part VALUES (5, 4, 10);
INSERT INTO Supplier_Part VALUES (6, 5, 200);
INSERT INTO Supplier_Part VALUES (6, 6, 75);
INSERT INTO Supplier_Part VALUES (1, 1, 100);
INSERT INTO Supplier_Part VALUES (1, 2, 150);

-- Q1.
SELECT scode, pcode 
FROM Supplier_Part 
ORDER BY scode ASC;

--Q2.
SELECT * 
FROM Supplier 
WHERE scity = 'Bombay' AND turnover = 50;

--Q3.
SELECT COUNT(*) 
FROM Supplier;

--Q4.
SELECT pcode 
FROM Part 
WHERE weigh BETWEEN 25 AND 35;

--Q5.
SELECT scode 
FROM Supplier 
WHERE turnover IS NULL;

--Q6.
SELECT pcode 
FROM Part 
WHERE cost IN (20, 30, 40);

--Q7.
SELECT SUM(qty) 
FROM Supplier_Part 
WHERE pcode = 2;

--Q8.
SELECT s.sname 
FROM Supplier s 
JOIN Supplier_Part sp ON s.scode = sp.scode 
WHERE sp.pcode = 2;

--Q9.
SELECT pcode 
FROM Part 
WHERE cost > (SELECT AVG(cost) FROM Part);

--Q10.
SELECT scode, turnover 
FROM Supplier 
ORDER BY turnover DESC;

--QE1.
SELECT pcode, SUM(qty) AS total_quantity 
FROM Supplier_Part 
GROUP BY pcode;

--QE2.
SELECT pcode 
FROM Supplier_Part 
GROUP BY pcode 
HAVING SUM(qty) > 20;

--QE3.
SELECT sname 
FROM Supplier 
WHERE scode NOT IN (SELECT scode FROM Supplier_Part);

--QE4.
SELECT s.sname 
FROM Supplier s
JOIN Supplier_Part sp ON s.scode = sp.scode
WHERE sp.pcode IN (1, 2)
GROUP BY s.scode, s.sname
HAVING COUNT(DISTINCT sp.pcode) = 2;