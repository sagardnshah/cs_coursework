#WARNING!
#DO NOT EXECUTE OR THE LAST COMMAND WILL DROP THE ORDERS TABLE

#1
CREATE VIEW Under_100 AS
SELECT orderline.item_id, title, artist, unit_price, SUM(order_qty)
FROM items, orderline
WHERE items.item_id = orderline.item_id
AND unit_price<100.00
GROUP BY orderline.item_id;

#2
CREATE VIEW Allen AS
SELECT customers.customer_id, customer_name, customer_phone, title, artist
FROM customers, orders, orderline, items
WHERE customers.customer_id=orders.customer_id
AND orders.order_id=orderline.order_id
AND items.item_id=orderline.item_id;

#3
#Instructions say to name the view as 'orders'
#But there is already a table named 'orders'
#That's why I called this view 'orders_view'
CREATE VIEW orders_view AS
SELECT orderline.item_id, title, artist, unit_price, SUM(order_qty)
FROM items, orderline, orders
WHERE items.item_id = orderline.item_id
AND orders.order_id = orderline.order_id
AND order_date BETWEEN '2014-01-01' AND '2014-02-28'
GROUP BY orderline.item_id;

#4
CREATE VIEW zip_27 AS
SELECT customer_name, customer_phone, title, artist, ship_date
FROM customers, orders, orderline, items
WHERE customers.customer_id=orders.customer_id
AND orders.order_id=orderline.order_id
AND items.item_id=orderline.item_id
AND customer_zip LIKE '27%';

#5A
CREATE INDEX customer_id
ON customers (customer_id);

#5B
CREATE INDEX name
ON customers (customer_name);

#5C
CREATE INDEX shipped
ON orders (customer_id, ship_date);

#6
DROP INDEX name ON customers;

#7
ALTER TABLE Items
ADD CHECK (unit_price>=35.00);

#8A
ALTER TABLE Orders
ADD FOREIGN KEY (customer_id) REFERENCES customers(customer_id);

#8B
ALTER TABLE ITEMS
ADD PRIMARY KEY(item_id);
ALTER TABLE orderline
ADD FOREIGN KEY (item_id) REFERENCES items(item_id);

#9
ALTER TABLE items
ADD type CHAR(1);

#10
SET SQL_SAFE_UPDATES=0;
UPDATE items
SET type = 'M'
WHERE items.title = "Skies Above";

#11
ALTER TABLE items
MODIFY artist VARCHAR (30);

#12
DROP TABLE orders;