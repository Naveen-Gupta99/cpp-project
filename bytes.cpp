#include <iostream>
#include <vector>
using namespace std;

void convertToBinary(int decimal) {
    vector<int> binary;  // Vector to store binary digits

    // Edge case for decimal 0
    if(decimal == 0) {
        cout << "The binary equivalent is: 0" << endl;
        return;
    }

    // Loop to divide the decimal number by 2 and store remainders
    while(decimal > 0) {
        binary.push_back(decimal % 2);  // Store remainder (binary digit)
        decimal = decimal / 2;          // Update decimal by dividing by 2
    }

    // Print the binary number in reverse order
    cout << "The binary equivalent is: ";
    for(int i = binary.size() - 1; i >= 0; i--) {
        cout << binary[i];
    }
    cout << endl;
}

int main() {
    int decimal;

    // Input the decimal number from the user
    cout << "Enter a decimal number: ";
    cin >> decimal;

    // Call the function to convert and display the binary equivalent
    convertToBinary(decimal);

    return 0;
}
