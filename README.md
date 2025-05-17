# Canteen-Management-and-Billing-System-

# 🧾 SR University Canteen Billing System

A terminal-based C project simulating a real-world canteen billing system for SR University. This project offers a clean menu interface, cart operations, and bill generation with time and barcode — ideal for beginners learning C structures, loops, and modular design.

---

## 🚀 Features

- ✅ **Show Menu** with categorized items (Non-Veg, Veg, Drinks)
- ➕ **Add multiple items** to cart with quantity
- 🔄 **Change quantity** of items already added
- ❌ **Delete items** from cart
- 🧾 **Final Bill Generation**:
  - Student ID & Customer Name
  - Date & Time
  - Item-wise price breakdown
  - Amount received from customer
  - **Random barcode** (visualized in ASCII)
- 📦 Uses C **structs** for menu and cart
- 📋 Structured and easy-to-understand code

---

## 🖥️ Tech Stack

- Language: **C**
- Libraries: `stdio.h`, `stdlib.h`, `string.h`, `time.h`

---

## 🧑‍💻 Sample Run
Enter Student ID Number: 342324
Enter Customer Name: John

Select Option:
	1.	Show Menu
	2.	Add Items to Cart
	3.	Change Quantity of Item in Cart
	4.	Delete Item from Cart
	5.	View Bill and Exit
Enter choice: 2
Enter Item ID to add (0 to stop): 3
Enter Quantity: 2
Item added successfully.
…
===== SR University Canteen =====

Student ID: 342324
Customer Name: anurag
Date & Time: 17-05-2025 13:45:29

ID    Item Name                      Qty   Price   Total

3     Chicken Curry with Rice        2     ₹100    ₹200
14    Pepsi                          1     ₹50     ₹50


                             Grand Total: ₹250



