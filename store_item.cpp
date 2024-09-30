#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

class stockItem {
    private:
        int itemCode; // Fixed spelling from itenCode to itemCode
        int itemQuantity; // Data member
        char itemDescription[20]; // Fixed spelling from itemDiscription to itemDescription
        float itemPrice; // Fixed spelling from itemPrise to itemPrice

    public:
        void readData() {
            cout << "-------Enter particulars of stock Item---------- " << endl;
            cout << "Enter Item Code: ";
            cin >> itemCode;

            cout << "Enter Item Description: ";
            cin >> ws; // Consume any leading whitespace
            cin.getline(itemDescription, 20); // Safely read a full line into the char array

            cout << "Enter Item Quantity: ";
            cin >> itemQuantity;

            cout << "Enter Item Unit Price: ";
            cin >> itemPrice;
        }

        void display() {
            cout << "----------Particulars of a stock Item are-------------" << endl;
            cout << "Item Code: " << itemCode << endl;
            cout << "Item Description: " << itemDescription << endl;
            cout << "Item Quantity: " << itemQuantity << endl;
            cout << "Item Unit Price: " << itemPrice << endl;
        }

        void saveToFile(ofstream& outFile) {
            outFile << itemCode << " "
                    << itemDescription << " "
                    << itemQuantity << " "
                    << itemPrice << endl;
        }
};

int main() {
    // Open the output file
    ofstream outfile("stock_Item.txt", ios::app); // Append mode
    // if (!outfile) {
    //     cerr << "Error opening file!" << endl;
    //     return 1; // Return with error code
    // }
    char continueInput;
do{
    stockItem item; // Create an instance of stockItem
    item.readData(); // Call the readData method
    item.display(); // Call the display method

    // Save the item details to the file
    item.saveToFile(outfile); // Pass the ofstream to saveToFile method

    cout<<"----------do you want to store another item if yes then press small y: ";
    cin>>continueInput;
}while(continueInput == 'y');
    outfile.close(); // Close the file
    cout << "Data saved to stock_Item.txt" << endl;



    return 0;
    
}
