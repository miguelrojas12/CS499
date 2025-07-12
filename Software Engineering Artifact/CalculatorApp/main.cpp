/*
 * Calculator.cpp
 *
 *  Date: 01/19/2025
 *  Author: Miguel Rojas Saavedra
 */

#include <iostream>

using namespace std;

int main() // Changed return type from 'void' to 'int' as the main function should return an integer.
{
    char statement[100];
    int op1, op2;
    char operation;
    char answer = 'Y'; // Changed double quotes to single quotes for character and added a semicolon.

    while (answer == 'Y' || answer == 'y') // Adjusted condition to check for both 'Y' and 'y'.
    {
        cout << "Enter expression" << endl;
        cin >> op1 >> operation >> op2; // Corrected the input order to match typical expression format (op1 operator op2).

        if (operation == '+') // Removed unnecessary semicolon.
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // Fixed operator usage and stream insertion.

        else if (operation == '-') // Removed unnecessary semicolon and changed to 'else if' for clarity.
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // Fixed operator usage and stream insertion.

        else if (operation == '*') // Corrected the operator to '*' for multiplication.
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // Fixed operator usage and added missing semicolon.

        else if (operation == '/') // Corrected the operator to '/' for division.
            cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // Fixed operator usage.

        cout << "Do you wish to evaluate another expression? (Y/N)" << endl;
        cin >> answer; // Captures the user's response to continue or terminate.
    }

    cout << "Program Finished." << endl; // Display termination message when the loop exits.

    return 0; // Ensure the 'main' function returns an int.
}
