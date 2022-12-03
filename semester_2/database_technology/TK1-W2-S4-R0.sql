-- Active: 1670090327899@@127.0.0.1@3306@hotel_tk_1

CREATE TABLE customers (
  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  name VARCHAR(255),
  gender ENUM("male", "female"),
  address TEXT,
  email VARCHAR(255),
  phone_number VARCHAR(32),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

CREATE TABLE room_types (
  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  name VARCHAR(255),
  facilities TEXT,
  price DECIMAL(38, 2),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);

CREATE TABLE rooms (
  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  room_type_id INT,
  -- status ENUM("available", "under maintenance") remove redundancy with orders and checkin_checkouts table
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  FOREIGN KEY(room_type_id) REFERENCES room_types(id)
);

CREATE TABLE orders (
  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  customer_id INT,
  room_id INT,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  FOREIGN KEY(customer_id) REFERENCES customers(id),
  FOREIGN KEY(room_id) REFERENCES rooms(id)
);

CREATE TABLE checkin_checkouts (
  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  order_id INT,
  checkin_at TIMESTAMP,
  checkout_at TIMESTAMP,
  FOREIGN KEY(order_id) REFERENCES orders(id)
  -- don't need timestamp, add this later if necessary
);

CREATE TABLE invoices (
  id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
  order_id INT,
  price DECIMAL(38, 2),
  status ENUM("paid", "unpaid"),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  FOREIGN KEY(order_id) REFERENCES orders(id)
);

INSERT INTO room_types (name, facilities, price) VALUES
('Standard Twin Bed', 'Minimalist, two single beds, flat-screen 32 inch TV', 290000),
('Standard Double Bed', 'Minimalist, one queen size bed, flat-screen 32 inch TV', 300000),
('Premium Twin Bed', 'Minimalist, two single beds, flat-screen 32 inch TV, breakfast', 340000),
('Premium Double Bed', 'Minimalist, one queen size bed, flat-screen 32 inch TV, breakfast', 350000),
('Luxury Twin Bed', 'Minimalist, two single beds, flat-screen 32 inch TV, breakfast, medium bathup', 390000),
('Luxury Double Bed', 'Minimalist, one queen size bed, flat-screen 32 inch TV, breakfast, medium bathup', 400000),
('Enterprise Twin Bed', 'Minimalist, two single beds, flat-screen 32 inch TV, breakfast, medium bathup, balcony', 440000),
('Enterprise Double Bed', 'Minimalist, one queen size bed, flat-screen 32 inch TV, breakfast, medium bathup, balcony', 450000),
('Enterprise Plus Twin Bed', 'Minimalist, two single beds, flat-screen 32 inch TV, breakfast, large bathup, balcony', 500000),
('Enterprise Plus Double Bed', 'Minimalist, one queen size bed, flat-screen 32 inch TV, breakfast, large bathup, balcony', 510000);


INSERT INTO rooms (room_type_id) VALUES
(1), (1), (2), (2), (3), (3), (4), (4), (5), (5),
(6), (6), (7), (7), (8), (8), (9), (9), (10), (10);

INSERT INTO customers (name, gender, address, email, phone_number) VALUES
("Albert Dragunov", "male", "St. Louis 23b", "albertdragunov@mail.com", "016274910"),
("Robin Kowalsky", "male", "St. Peterburg 87", "robinkowa@mail.com", "061527738112"),
("Mary Mile", "female", "13 Rood Road", "marymile@mail.com", "65301482"),
("Kellie Bright", "male", "33 E County Line Road, Olney Springs", "kellieb@mail.com", "19641534479"),
("Victor Lawrence", "male", "4296 Sapien Av.", "victorlawrence@mail.com", "13034616223"),
("Nicole Fields", "male", "319 B Elit. Rd.", "nocolefields@mail.com", "18425661532"),
("Cara Mccarthy", "female", "4296 Sapien Av.", "caramcc@mail.com", "2173535457"),
("Jasmine Stuart", "female", "Ap 236-522 Vestibulum Road", "jasminestu@mail.com", "13145381480"),
("Stewart Clark", "male", "Ap 593-9218 Ante Rd.", "stewartclark@mail.com", "15642580247"),
("Lois Chaney", "male", "5189 Et Road", "loischa@mail.com", "2832477323");

INSERT INTO orders (customer_id, room_id) VALUES
(1, 1), (1, 11),
(2, 2), (2, 12),
(3, 3), (3, 13),
(4, 4), (4, 14),
(5, 5), (5, 15),
(6, 6), (6, 16),
(7, 7), (7, 17),
(8, 8), (8, 18),
(9, 9), (9, 19),
(10, 10), (10, 20);

INSERT INTO checkin_checkouts (order_id,checkin_at,checkout_at) VALUES
(1, '2022-01-01 14:00:00', '2022-01-04 11:00:00'),
(2, '2022-01-25 14:00:00', '2022-01-27 11:00:00'),
(3, '2022-02-05 14:00:00', '2022-02-06 11:00:00'),
(4, '2022-03-10 14:00:00', '2022-03-11 11:00:00'),
(5, '2022-03-15 14:00:00', '2022-03-17 11:00:00'),
(6, '2022-05-01 14:00:00', '2022-05-07 11:00:00'),
(7, '2022-08-11 14:00:00', '2022-08-12 11:00:00'),
(8, '2022-08-14 14:00:00', '2022-08-20 11:00:00'),
(9, '2022-09-02 14:00:00', '2022-09-03 11:00:00'),
(10, '2022-09-15 14:00:00', '2022-09-17 11:00:00'),
(11, '2022-09-20 14:00:00', '2022-09-21 11:00:00'),
(12, '2022-09-25 14:00:00', '2022-09-27 11:00:00'),
(13, '2022-10-01 14:00:00', '2022-10-01 11:00:00'),
(14, '2022-10-05 14:00:00', '2022-10-07 11:00:00'),
(15, '2022-10-10 14:00:00', '2022-10-20 11:00:00'),
(16, '2022-10-25 14:00:00', '2022-10-28 11:00:00'),
(17, '2022-11-01 14:00:00', '2022-11-02 11:00:00'),
(18, '2022-11-03 14:00:00', '2022-11-05 11:00:00'),
(19, '2022-11-10 14:00:00', '2022-11-20 11:00:00'),
(20, '2022-11-25 14:00:00', '2022-11-27 11:00:00');

INSERT INTO invoices (order_id, price, status) VALUES
(1, 300000, "paid"),
(2, 600000, "paid"),
(3, 240000, "paid"),
(4, 400000, "paid"),
(5, 200000, "paid"),
(6, 400000, "paid"),
(7, 400000, "unpaid"),
(8, 800000, "paid"),
(9, 460000, "paid"),
(10, 100000, "unpaid"),
(11, 350000, "paid"),
(12, 400000, "paid"),
(13, 325000, "unpaid"),
(14, 625000, "paid"),
(15, 700000, "paid"),
(16, 250000, "paid"),
(17, 820000, "paid"),
(18, 540000, "unpaid"),
(19, 450000, "paid"),
(20, 1280000, "paid");


-- a.	Semua pelanggan yang menyewa kamar single
SELECT customers.*
FROM customers
JOIN orders
  ON customers.id = orders.customer_id
JOIN rooms
  ON orders.room_id = rooms.id
JOIN room_types
  ON rooms.room_type_id = room_types.id
WHERE room_types.name LIKE '%TWIN%';

-- b.	Jumlah pelanggan yang melakukan pemesanan lebih dari 3 hari
SELECT customers.*, customer_book_in_days.total_period
FROM customers
JOIN (
  SELECT orders.customer_id, SUM(DATEDIFF(checkout_at, checkin_at)) AS total_period
  FROM checkin_checkouts
  JOIN orders
    ON checkin_checkouts.order_id = orders.id
  GROUP BY orders.customer_id
) customer_book_in_days
  ON customers.id = customer_book_in_days.customer_id
WHERE customer_book_in_days.total_period > 3;

-- c.	Tanggal pemesanan pada bulan Januari 2022
SELECT customers.name, cico.checkin_at, orders.*
FROM customers
JOIN orders
  ON customers.id = orders.customer_id
JOIN checkin_checkouts cico
  ON orders.id = cico.order_id
WHERE YEAR(cico.checkin_at) = 2022
  AND MONTH(cico.checkin_at) = 1;

-- d.	Pelanggan yang mempunyai awalan nama huruf tertentu (sesuaikan dengan data yang digunakan oleh kelompok)
SELECT * FROM customers WHERE name LIKE 'R%';
