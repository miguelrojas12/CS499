// 01/20/2025
// Project One: Chada Tech
// Miguel Rojas Saavedra.
// In this project, a simulation of a clock needs to be developed, which has to  be able to view a 12- and a 24-hour clock.

#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Here I will declare a function for the clocks' borders.
void printClockBorder() {
	//This for loop will be used for prints space padding
	for (int i = 0; i < 16; ++i) {
		cout << " ";
	}
	//This for loop will be for prints *'s for the 12-hour clock border
	for (int i = 0; i < 27; ++i) {
		cout << "*";
	}
	//This for loop will print space padding between clocks
	for (int i = 0; i < 5; ++i) {
		cout << " ";
	}
	//This for loop will print *'s for the 24-hour clock border
	for (int i = 0; i < 27; ++i) {
		cout << "*";
	}
	cout << endl;
}

//This is the function that outputs both clocks and converts the 24-hour clock to 12-hour AM/PM clock
void printClocks(int hours, int minutes, int seconds) {

    // These are the necessary attributes used for the 12-hour conversion
    int hourConv;
    int minConv;
    int secConv;
    string amPm = "AM";

    // Convert 24-Hour clock to 12-Hour AM/PM clock
    if (hours == 0) {
        hourConv = 12;
    }
    else if (hours == 12) {
        hourConv = hours;
        amPm = "PM";
    }
    else if (hours > 12) {
        hourConv = hours - 12;
        amPm = "PM";
    }
    else {
        hourConv = hours;
    }

    // Clock titles
    cout << "\t\t*\t" << "12-Hour Clock";
        cout << "\t  *";
    cout << "\t*" << "\t24-Hour Clock";
    cout << "\t  *" << endl;

    // 12-hour clock
    cout << "\t\t* \t ";
    cout << setw(2) << setfill('0') << hourConv << ":";
        cout << setw(2) << minutes << ":";
    cout << setw(2) << seconds;
    cout << " " << amPm;
    cout << "\t  *";

    // 24-hour clock
    cout << "\t*" << "\t   ";
    cout << setw(2) << setfill('0') << hours << ":";
        cout << setw(2) << minutes << ":";
    cout << setw(2) << seconds;
    cout << "\t  *" << endl;
}

// Function that takes in the initial time from the user
void inputInitialTime(int& setHour, int& setMinute, int& setSecond) {

    string inputString;
    string tempString;
        bool validTime = false;
        int firstColonPosition;
        int secondColonPosition;

        while (!validTime) {
            cout << "Enter time as HH:MM:SS in 24-hour format: ";
                getline(cin, inputString);


                firstColonPosition = inputString.find(':');
                secondColonPosition = inputString.find(':', firstColonPosition + 1);

                    // Attempt to assign and convert each clock section only if they were integers, otherwise ignore
                try
                {
                    setHour = stoi(inputString.substr(0, firstColonPosition));
                    setMinute = stoi(inputString.substr(firstColonPosition + 1, secondColonPosition));
                    setSecond = stoi(inputString.substr(secondColonPosition + 1, inputString.size() - 1));
                }
                catch (const std::exception&)
                {
                }

                if (inputString.size() != 8) {
                    cout << "Time is invalid" << endl;
                    !validTime;
                }
                else if (setHour < 0 || setHour > 23) {
                    cout << "Time is invalid" << endl;
                    !validTime;
                }
                else if (setMinute < 0 || setMinute > 59) {
                    cout << "Time is invalid" << endl;
                    !validTime;
                }
                else if (setSecond < 0 || setSecond > 59) {
                    cout << "Seconds are invalid" << endl;
                    !validTime;
                }
                else {
                    validTime = true;
                }
        }
}

// Main menu options function
void printMainMenu() {

    cout << endl;
    cout << "*********************************" << endl;
    cout << "* 1-Add One Hour\t\t*" << endl;
    cout << "* 2-Add One Minute\t\t*" << endl;
    cout << "* 3-Add One Second\t\t*" << endl;
    cout << "* 4-Exit\t\t\t*" << endl;
    cout << "*********************************" << endl;
    cout << endl;
}

// This function takes in and validates user inputs
void processUserInput(int& userChoice, int& setHour, int& setMinute, int& setSecond) {

    cout << "Select option (1-4): ";

    // Verify user input is not other than an integer 
    if (!(cin >> userChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            userChoice = 0;
    }

    // Utilize swich statement based on user's input
    switch (userChoice) {
    case 1:
        cout << "1 hour added" << endl;
        if (setHour < 23) { // Increments 1 hour until reaches 24
            ++setHour;
        }
        else {
            setHour = 00;   // Reset to 00 hour onces it reaches 24
        }
        break;
    case 2:
        cout << "1 minute added" << endl;
        if (setMinute < 59) { // Increments 1 minute until reaches 59
            ++setMinute;
        }
        else {
            setMinute = 00;   // Reset to 00 minute onces it reaches 59
        }
        break;
    case 3:
        if (setSecond < 59) { // Increments 1 second until reaches 59
            ++setSecond;
        }
        else {
            setSecond = 00;   // Reset to 00 second onces it reaches 59
        }
        break;
    case 4:
        cout << "Goodbye!" << endl;
        break;
    default:
        cout << "Invalid choice. Enter a number between 1-4..." << endl;
        cin.clear();
        break;
    }
}

int main() {
    // Declare global properties
    int userChoice = 0;
    int setHour = 0;
    int setMinute = 0;
    int setSecond = 0;

    // Ask user to enter the initial time
    inputInitialTime(setHour, setMinute, setSecond);
    // Enter program's while loop
    while (userChoice != 4) {

            printClockBorder();
            printClocks(setHour, setMinute, setSecond);
            printClockBorder();
            printMainMenu();
            processUserInput(userChoice, setHour, setMinute, setSecond);
    }

    return 0;
}