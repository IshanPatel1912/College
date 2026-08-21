--EXPERIMENT 2
CREATE DATABASE IF NOT EXISTS E2_db;
USE E2_db;

CREATE TABLE CLIENT_MASTER(
    clientno VARCHAR(6) PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    address1 VARCHAR(30),
    address2 VARCHAR(30),
    city VARCHAR(15) NOT NULL, 
    pincode INT NOT NULL,
    state VARCHAR(15) NOT NULL,
    baldue DECIMAL(10,2) DEFAULT 0.00
);

CREATE TABLE PRODUCT_MASTER(
    productno VARCHAR(6) PRIMARY KEY,
    description VARCHAR(15),
    profitpercent DECIMAL(4,2) NOT NULL,
    unit_measure VARCHAR(10) NOT NULL,
    qtyonhand INT DEFAULT 0,
    reorderl_vl INT DEFAULT 0,
    sellprice DECIMAL(8,2) NOT NULL,
    costprice DECIMAL(8,2) NOT NULL
);

CREATE TABLE SALESMAN_MASTER(
    salesmanno VARCHAR(6) PRIMARY KEY,
    salesmanname VARCHAR(20) NOT NULL,
    address1 VARCHAR(30),
    address2 VARCHAR(30),
    city VARCHAR(20) NOT NULL,
    pincode INT NOT NULL,
    state VARCHAR(20) NOT NULL,
    salamt REAL, 
    tgttoget DECIMAL NOT NULL,
    ytdsales DOUBLE(6,2) DEFAULT 0.00,
    remarks VARCHAR(60)
);

INSERT INTO CLIENT_MASTER
VALUES
('C00001','Ivan bayross',NULL,NULL,'Mumbai',400054,'Maharashtra',15000),
('C00002','Mamta muzumdar',NULL,NULL,'Madras',780001,'Tamil Nadu',0),
('C00003','Chhaya bankar',NULL,NULL,'Mumbai',400057,'Maharashtra',5000),
('C00004','Ashwini joshi',NULL,NULL,'Bangalore',560001,'Karnataka',0),
('C00005','Hansel colaco',NULL,NULL,'Mumbai',400060,'Maharashtra',2000),
('C00006','Deepak sharma',NULL,NULL,'Mangalore',560050,'Karnataka',0);

INSERT INTO PRODUCT_MASTER
VALUES
('P00001','T-Shirt',5,'Piece',200,50,350,250),
('P0345','Shirts',6,'Piece',150,50,500,350),
('P06734','Cotton jeans',5,'Piece',100,20,600,450),
('P07865','Jeans',5,'Piece',100,20,750,500),
('P07868','Trousers',2,'Piece',150,50,850,550),
('P07885','Pull Overs',2.5,'Piece',80,30,700,450),
('P07965','Denim jeans',4,'Piece',100,40,350,250),
('P07975','Lycra tops',5,'Piece',70,30,300,175),
('P08865','Skirts',5,'Piece',75,30,450,300);

INSERT INTO SALESMAN_MASTER
VALUES
('S00001','Aman','A/14','Worli','Mumbai',400002,'Maharashtra',3000,100,50,'Good'),
('S00002','Omkar','65','Nariman','Mumbai',400001,'Maharashtra',3000,200,100,'Good'),
('S00003','Raj','P-7','Bandra','Mumbai',400032,'Maharashtra',3000,200,100,'Good'),
('S00004','Ashish','A/5','Juhu','Mumbai',400044,'Maharashtra',3500,200,150,'Good');