#include <iostream>
#include <string>

using namespace std;

string ch[100] = {"Cardiff Express", "Belfast Express", "Derby Express",
                   "Chester Express", "Newport Express", "Truro Express"};

int busNo;
int seatNo;
int pasSeatno[16];
string pasName[16];
bool seats[16] = {false, false, false, false, false, false, false, false,
                  false, false, false, false, false, false, false, false};

void userLogin();
void Bus();
void booking();
void displaySeats();
bool isSeatBooked(int seatNumber);
void displayBookedTickets();
void cancel();

int main() {
    userLogin();
    int n;

    do {
        cout << "\n\n\n";
        cout << "==================== WELCOME TO BUS RESERVATION SYSTEM =================\n\n\n";
        cout << "\t[0]=> View Bus List\n";
        cout << "\n";
        cout << "\t[1]=> Book Tickets\n";
        cout << "\n";
        cout << "\t[2]=> Booking Status\n";
        cout << "\n";
        cout << "\t[3]=> Cancel\n";
        cout << "\n";
        cout << "\t[4]=> Exit\n\n";
        cout << "===================================================================\n\n";
        cout << "\t\tEnter Your Choice: ";
        cin >> n;

        switch (n) {
            case 0:
                cout << "\n\n\n";
                cout << "======================= BUS RESERVATION SYSTEM ========================\n\n\n";
                for (int i = 0; i < 5; ++i) {
                    cout << "[" << i + 1 << "]  =>  " << ch[i] << "\n";
                    cout << "\n";
                }
                break;
            case 1:
                booking();
                break;
            case 2:
                displayBookedTickets();
                break;
            case 3:
                cancel();
                break;
        }
        cin.ignore();
    } while (n != 4);

    cout << "\t-------------------------------------------------------------------\n";
    cout << "\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n";
    cout << "\t-------------------------------------------------------------------\n";

    cin.get();
    return 0;
}

void userLogin() {
    int ch, confirm, a;
    string userName, password, password1;
    string userName1;  // Move the declaration here

    cout << "\n\n*Welcome to the system*" << endl;
    cout << " \n\n1)To login\n2)New registration: " << endl;
    cout << "\nEnter your choice: ";
    cin >> ch;

    switch (ch) {
        case 1:
            cout << "\n*Welcome to User Login*\n" << endl;
            cout << "Enter Username: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> password;
            if (userName == "khushi" && password == "enter") {
                cout << "\n\n***successfully Logged In****";
                break;
            } else {
                cout << "Wrong username or password entered....";
                userLogin();
            }
            break;
        case 2:
            a = 1;
            while (a == 1) {
                cout << "\n\n" << endl;
                cout << "Please enter your username: " << endl;
                cin.ignore();
                getline(cin, userName);
                cout << "\n\n Username -  " << userName << "\nConfirm? \n\n[1] Yes\n[2] No" << endl;
                cin >> confirm;
                if (confirm == 1) {
                    cout << "\n\nPlease enter the password:" << endl;
                    cin >> password;
                    cout << "\nPlease re-enter your password:" << endl;
                    cin >> password1;
                    if (password == password1) {
                        cout << "\n\n-----------------------Your password is set----------------------" << endl;
                        cout << "\n\n*Please login*\n" << endl;
                        cout << "Enter Username: ";
                        cin >> userName1;
                        cout << "Enter Password: ";
                        cin >> password;
                        if (userName == userName1 && password == password1) {
                            cout << "\n\n***successfully Logged In****";
                            break;
                        } else {
                            cout << "Wrong username or password entered....";
                            userLogin();
                            break;
                        }

                    } else {
                        cout << "\n\nSorry invalid password please enter the same passwords" << endl;
                    }
                } else {
                    cout << "\n\nSorry invalid input, Please try again" << endl;
                    a = 1;
                    cin.clear();
                }
            }
            break;
        default:
            cout << "Invalid Input...";
            break;
    }
}

void Bus() 
{
   cout << "\n\n\n";
    cout << "====================== BUS RESERVATION SYSTEM ======================\n\n\n";
    cout << "[1]  =>  " << ch[0] << "\n";
    cout << "\n";
    cout << "[2]  =>  " << ch[1] << "\n";
    cout << "\n";
    cout << "[3]  =>  " << ch[2] << "\n";
    cout << "\n";
    cout << "[4]  =>  " << ch[3] << "\n";
    cout << "\n";
    cout << "[5]  =>  " << ch[4] << "\n";
}

void displaySeats() {
    int index = 0;
    cout << "\n\n**********" << endl;
    for (int i = 0; i < 4; ++n) {
        for (int j = 0; j < 4; ++j) {
            cout << index + 1 << ") " << (seats[index] ? "Booked" : "Empty") << "\t";
            ++index;
        }
        cout << "\n";
    }
    cout << "**********\n\n";
}

bool isSeatBooked(int seatNumber) { 
    return seats[seatNumber - 1];
}

void booking() {
    int index = 0, i, k;
 
    Bus();
    cout << "*******" << endl;
    cout << "\nEnter bus no: ";
    cin >> busNo;
    cout << "\nEnter No of seats you require: ";
    cin >> seatNo;

    if (seatNo > 16) {
        cout << "\n\n*Only 16 seats available. Please try again.*";
    } else {
        cout << "The total amount to be paid is: " << 200 * seatNo << endl;
        cout << "\n\n" << endl;

        displaySeats();

        for (int m = 0; m < seatNo; m++) {
            do {
                cout << "Enter seat number: ";
                cin >> pasSeatno[m];
                if (pasSeatno[m] < 1 || pasSeatno[m] > 16) {
                    cout << "Invalid seat number. Please choose a seat between 1 and 16.\n";
                } else if (isSeatBooked(pasSeatno[m])) {
                    cout << "This Seat is already Booked. Choose another seat.\n";
                } else {
                    cout << "Enter name: ";
                    cin >> pasName[m];
                    seats[pasSeatno[m] - 1] = true;
                    break;
                }
            } while (true);
        }

        for (i = 0; i < seatNo; i++)
            cout << "\tSeat " << pasSeatno[i] << " booked successfully for passenger " << pasName[i] << endl;

        cout << "Thank you for booking tickets" << endl;
    }
}

void displayBookedTickets() {
    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << index + 1 << ") " << (seats[index] ? "Booked" : "Empty") << "\t";
            ++index;
        }
        cout << "\n";
    }
}

void cancel() {
    int CN;
    cout << "**********" << endl;
    cout << "\n\nEnter the number of seats to cancel: ";
    cin >> CN;

    for (int i = 0; i < CN; ++i) {
        int cancelSeat;
        cout << "Enter the seat number to cancel: ";
        cin >> cancelSeat;

        if (cancelSeat > 0 && cancelSeat <= 16) {
            if (isSeatBooked(cancelSeat)) {
                seats[cancelSeat - 1] = false;
                cout << "Seat " << cancelSeat << " cancelled successfully.\n";
            } else {
                cout << "Seat " << cancelSeat << " is not booked.\n";
            }
        } else {
            cout << "Invalid seat number.\n";
        }
    }

    displaySeats();
}
