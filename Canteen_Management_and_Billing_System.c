#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITEMS 50
#define MAX_NAME_LEN 50
#define MAX_MENU_ITEMS 20

// Menu Item Structure
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int price;
} MenuItem;

// Cart Item Structure
typedef struct {
    int itemID;
    int quantity;
} CartItem;

// Menu
MenuItem menu[MAX_MENU_ITEMS] = {
    {1,  "Chicken Biryani", 120},
    {2,  "Egg Biryani", 80},
    {3,  "Chicken Curry with Rice", 100},
    {4,  "Chicken Fry Piece (1 leg or breast)", 70},
    {5,  "Egg Curry with Chapati / Rice", 60},
    {6,  "Fish Curry with Rice", 120},
    {7,  "South Indian Veg Thali", 70},
    {8,  "Chapati with Veg Curry", 40},
    {9,  "Vegetable Biryani with Raita", 60},
    {10, "Curd Rice", 40},
    {11, "Lemon Rice / Tomato Rice", 35},
    {12, "Thums Up", 50},
    {13, "Coca-Cola", 50},
    {14, "Pepsi", 50},
    {15, "Sprite", 50},
    {16, "7UP", 50},
    {17, "Fanta", 50},
    {18, "Limca", 50},
    {19, "Mountain Dew", 50}
};

CartItem cart[MAX_ITEMS];
int cartCount = 0;

char studentID[20];
char customerName[50];

void showMenu() {
    printf("\n----- MENU -----\n\n");
    printf("*** Non-Veg Items ***\n");
    for (int i = 0; i < 6; i++)
        printf("%2d. %-35s ₹%d\n", menu[i].id, menu[i].name, menu[i].price);

    printf("\n*** Veg Items ***\n");
    for (int i = 6; i < 11; i++)
        printf("%2d. %-35s ₹%d\n", menu[i].id, menu[i].name, menu[i].price);

    printf("\n*** Drinks Items ***\n");
    for (int i = 11; i < 19; i++)
        printf("%2d. %-35s ₹%d\n", menu[i].id, menu[i].name, menu[i].price);
}

void addItem() {
    int itemID, quantity;
    while (1) {
        printf("Enter Item ID to add (0 to stop): ");
        scanf("%d", &itemID);
        if (itemID == 0) break;

        if (itemID < 1 || itemID > MAX_MENU_ITEMS) {
            printf("Invalid Item ID.\n");
            continue;
        }

        printf("Enter Quantity: ");
        scanf("%d", &quantity);

        int found = 0;
        for (int i = 0; i < cartCount; i++) {
            if (cart[i].itemID == itemID) {
                cart[i].quantity += quantity;
                found = 1;
                break;
            }
        }

        if (!found) {
            cart[cartCount].itemID = itemID;
            cart[cartCount].quantity = quantity;
            cartCount++;
        }

        printf("Item added successfully.\n");
    }
    printf("Stopped adding items.\n");
}

void changeQuantity() {
    int itemID;
    printf("Enter Item ID to change quantity: ");
    scanf("%d", &itemID);
    int found = 0;
    for (int i = 0; i < cartCount; i++) {
        if (cart[i].itemID == itemID) {
            printf("Enter new quantity: ");
            scanf("%d", &cart[i].quantity);
            found = 1;
            printf("Quantity updated.\n");
            break;
        }
    }
    if (!found) {
        printf("Item not found in cart.\n");
    }
}

void deleteItem() {
    int itemID;
    printf("Enter Item ID to delete: ");
    scanf("%d", &itemID);
    int found = 0;
    for (int i = 0; i < cartCount; i++) {
        if (cart[i].itemID == itemID) {
            for (int j = i; j < cartCount - 1; j++)
                cart[j] = cart[j + 1];
            cartCount--;
            found = 1;
            printf("Item deleted.\n");
            break;
        }
    }
    if (!found)
        printf("Item not found in cart.\n");
}

void viewBill() {
    printf("\n===== SR University Canteen =====\n\n");
    printf("Student ID: %s\n", studentID);
    printf("Customer Name: %s\n", customerName);

    time_t t;
    time(&t);
    struct tm *tm_info = localtime(&t);
    char date_time[30];
    strftime(date_time, 30, "%d-%m-%Y %H:%M:%S", tm_info);
    printf("Date & Time: %s\n\n", date_time);

    printf("ID    Item Name                      Qty   Price   Total  \n");
    printf("-------------------------------------------------------------\n");
    int grandTotal = 0;
    for (int i = 0; i < cartCount; i++) {
        int id = cart[i].itemID;
        int qty = cart[i].quantity;
        int price = menu[id - 1].price;
        printf("%-5d %-30s %-5d ₹%-6d ₹%-6d\n", id, menu[id - 1].name, qty, price, qty * price);
        grandTotal += qty * price;
    }
    printf("-------------------------------------------------------------\n");
    printf("                                      Grand Total: ₹%d\n", grandTotal);

    int amountReceived;
    printf("Amount Received: ₹");
    scanf("%d", &amountReceived);

    printf("\nBarcode: ");
    srand(time(NULL));
    for (int i = 0; i < 12; i++) {
        printf("%d", rand() % 10);
    }
    printf("\n------------------\n");
}

int main() {
    int choice;

    printf("Enter Student ID Number: ");
    scanf("%s", studentID);
    printf("Enter Customer Name: ");
    scanf("%s", customerName);

    while (1) {
        printf("\nSelect Option:\n");
        printf("1. Show Menu\n");
        printf("2. Add Items to Cart\n");
        printf("3. Change Quantity of Item in Cart\n");
        printf("4. Delete Item from Cart\n");
        printf("5. View Bill and Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: showMenu(); break;
            case 2: addItem(); break;
            case 3: changeQuantity(); break;
            case 4: deleteItem(); break;
            case 5: viewBill(); return 0;
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
