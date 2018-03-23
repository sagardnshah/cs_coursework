USE pretty;
#1
SELECT customer_name, customer_add, customer_city, customer_state, customer_zip
FROM customers;
#2
SELECT customer_name, customer_phone
FROM customers
WHERE customer_state = 'GA';
#3
SELECT customer_name, customer_zip
FROM customers
WHERE customer_state = 'NC' or customer_state = 'SC';
#4
SELECT title, artist, order_date, ship_date
FROM items, orders, orderline
WHERE orderline.item_id = items.item_id
AND orderline.order_id = orders.order_id;
#5
SELECT *
FROM items
ORDER BY unit_price ASC;
#6
SELECT *
FROM items
WHERE unit_price>100.00;
#7
SELECT *
FROM items
WHERE on_hand>300;
#8
SELECT title, unit_price, unit_price*2 AS retail_price
FROM items;
#9
SELECT customer_name, customer_phone
FROM customers
WHERE customer_id IN (SELECT customer_id 
					  FROM orders
                      WHERE order_date>='2014-01-01');
#10

#11
SELECT title
FROM items
WHERE unit_price BETWEEN 40.00 AND 100.00;
#12

#13

#14
SELECT customer_state, count(customer_state)
FROM customers
GROUP BY customer_state;