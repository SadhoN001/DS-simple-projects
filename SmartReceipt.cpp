#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Node class representing an item in the linked list
class Node {
public:
    string item;
    double price;
    int quantity;
    Node* next;

    Node(string itm, double prc, int qty) : item(itm), price(prc), quantity(qty), next(nullptr) {}
};

// LinkedList class to manage the list of items
class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(string item, double price, int quantity) {
        Node* newNode = new Node(item, price, quantity);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    double calculateTotal() {
        double total = 0.0;
        Node* temp = head;
        while (temp != nullptr) {
            total += temp->price * temp->quantity;
            temp = temp->next;
        }
        return total;
    }

    void displayItems() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << setw(20) << left << temp->item
                 << setw(10) << right << temp->price
                 << setw(10) << right << temp->quantity
                 << setw(10) << right << temp->price * temp->quantity
                 << endl;
            temp = temp->next;
        }
    }
};

int main() {
    string customerName;
    string customerTokenID;
    string customerMobile;
    int totalItems;

    cout << "Enter customer name: ";
    getline(cin, customerName);
    cout << "Enter customer token ID: ";
    getline(cin, customerTokenID);
    cout << "Enter customer mobile number: ";
    getline(cin, customerMobile);

    cout << "Enter total number of items: ";
    cin >> totalItems;

    LinkedList itemList;

    for (int i = 0; i < totalItems; i++) {
        cout<<endl;// i need to space here
        string itemName;
        double itemPrice;
        int itemQuantity;
        cout << "Enter item " << i + 1 << " name: ";
        cin >> itemName;
        cout << "Enter item " << i + 1 << " price: ";
        cin >> itemPrice;
        cout << "Enter item " << i + 1 << " quantity: ";
        cin >> itemQuantity;
        itemList.append(itemName, itemPrice, itemQuantity);
    }

    double totalPrice = itemList.calculateTotal();

    cout << "\n------------------------------- RECEIPT -------------------------------" << endl;
    cout << "Customer Name      : " << customerName << endl;
    cout << "Customer Token ID  : " << customerTokenID << endl;
    cout << "Customer Mobile    : " << customerMobile << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout << setw(20) << left << "Item"
         << setw(10) << right << "Price"
         << setw(10) << right << "Quantity"
         << setw(10) << right << "Total" << endl;
    cout << "-----------------------------------------------------------------------" << endl;
    itemList.displayItems();
    cout << "-----------------------------------------------------------------------" << endl;
    cout << setw(40) << right << "Total Price: " << totalPrice << " .BDT" <<endl;
    cout << "-----------------------------------------------------------------------" << endl;
    cout<< "\n                              Thank You"<<endl;
    cout << "-----------------------------------------------------------------------" << endl;

    return 0;
}
