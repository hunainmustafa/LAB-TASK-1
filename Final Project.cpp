#include <iostream>
#include <string>
using namespace std;

class Flight
{
public:
    string departure;
    string arrival;
    string date;
    string time;
    int economyPrice;
    int standardPrice;
    int businessPrice;
    string flightClass;
    int price;
    string checkInTime;

    Flight(string dep, string arr, string dt, string tm)
        : departure(dep), arrival(arr), date(dt), time(tm), flightClass(""), price(0)
    {
        setPrices(dep, arr);
    }

    void setPrices(string dep, string arr)
    {
        if ((dep == "Lahore" && arr == "Karachi") || (dep == "Karachi" && arr == "Lahore"))
        {
            economyPrice = 800;
            standardPrice = 1000;
            businessPrice = 1500;
        }
        else if ((dep == "Lahore" && arr == "Islamabad") || (dep == "Islamabad" && arr == "Lahore"))
        {
            economyPrice = 500;
            standardPrice = 700;
            businessPrice = 1000;
        }
        else if ((dep == "Islamabad" && arr == "Karachi") || (dep == "Karachi" && arr == "Islamabad"))
        {
            economyPrice = 900;
            standardPrice = 1200;
            businessPrice = 2000;
        }
        else if ((dep == "Lahore" && arr == "Skardu") || (dep == "Skardu" && arr == "Lahore"))
        {
            economyPrice = 1200;
            standardPrice = 1500;
            businessPrice = 2500;
        }
        else if ((dep == "Lahore" && arr == "Kot Addu") || (dep == "Kot Addu" && arr == "Lahore"))
        {
            economyPrice = 300;
            standardPrice = 400;
            businessPrice = 600;
        }
        else if ((dep == "Islamabad" && arr == "Gilgit") || (dep == "Gilgit" && arr == "Islamabad"))
        {
            economyPrice = 1000;
            standardPrice = 1300;
            businessPrice = 1800;
        }
        else if ((dep == "Karachi" && arr == "Pindi") || (dep == "Pindi" && arr == "Karachi"))
        {
            economyPrice = 1300;
            standardPrice = 1600;
            businessPrice = 2200;
        }
        else if ((dep == "Lahore" && arr == "Pindi") || (dep == "Pindi" && arr == "Lahore"))
        {
            economyPrice = 500;
            standardPrice = 700;
            businessPrice = 1000;
        }
        else if ((dep == "Lahore" && arr == "Gilgit") || (dep == "Gilgit" && arr == "Lahore"))
        {
            economyPrice = 500;
            standardPrice = 700;
            businessPrice = 1000;
        }
    }

    void selectClass()
    {
        cout << "Select class:\n";
        cout << "1. Economy ($" << economyPrice << ")\n";
        cout << "2. Standard ($" << standardPrice << ")\n";
        cout << "3. Business ($" << businessPrice << ")\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            flightClass = "Economy";
            price = economyPrice;
            break;
        case 2:
            flightClass = "Standard";
            price = standardPrice;
            break;
        case 3:
            flightClass = "Business";
            price = businessPrice;
            break;
        default:
            cout << "Invalid choice. Defaulting to Economy class." << endl;
            flightClass = "Economy";
            price = economyPrice;
            break;
        }
    }

    void setCheckInTime()
    {
        int hour = stoi(time.substr(0, 2));
        int minute = stoi(time.substr(3, 2));
        hour -= 1;
        if (hour < 0)
        {
            hour = 23;
        }
        checkInTime = (hour < 10 ? "0" : "") + to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute);
    }
};

class Node
{
public:
    Flight data;
    Node *next;

    Node(Flight flight) : data(flight), next(nullptr) {}
};

string toLowerCase(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}

void bookFlight(Node *&head, bool isReturnFlight = false, string returnDeparture = "", string returnArrival = "")
{
    string departure, arrival, date, time;

    if (!isReturnFlight)
    {
        cout << "Enter departure city (Lahore, Karachi, Islamabad, Skardu, Kot Addu, Gilgit, Pindi): ";
        cin >> departure;
        departure = toLowerCase(departure);
        departure[0] = toupper(departure[0]);

        cout << "Enter arrival city (Lahore, Karachi, Islamabad, Skardu, Kot Addu, Gilgit, Pindi): ";
        cin >> arrival;
        arrival = toLowerCase(arrival);
        arrival[0] = toupper(arrival[0]);

        if ((departure != "Lahore" && departure != "Karachi" && departure != "Islamabad" && departure != "Skardu" && departure != "Kot Addu" && departure != "Gilgit" && departure != "Pindi") ||
            (arrival != "Lahore" && arrival != "Karachi" && arrival != "Islamabad" && arrival != "Skardu" && arrival != "Kot Addu" && arrival != "Gilgit" && arrival != "Pindi") || departure == arrival)
        {
            cout << "Invalid cities entered. Booking failed." << endl;
            return;
        }
    }
    else
    {
        departure = returnDeparture;
        arrival = returnArrival;
    }

    cout << "Enter departure date (DD-MM-YYYY): ";
    cin >> date;

    cout << "Available departure times:\n";
    cout << "1. 05:00\n";
    cout << "2. 13:00\n";
    cout << "3. 21:00\n";
    cout << "Enter choice (1-3): ";
    int timeChoice;
    cin >> timeChoice;

    switch (timeChoice)
    {
    case 1:
        time = "05:00";
        break;
    case 2:
        time = "13:00";
        break;
    case 3:
        time = "21:00";
        break;
    default:
        cout << "Invalid time choice. Booking failed." << endl;
        return;
    }

    Flight flight(departure, arrival, date, time);
    flight.setCheckInTime();
    flight.selectClass();

    Node *newNode = new Node(flight);
    newNode->next = head;
    head = newNode;

    cout << "Flight booked successfully!" << endl;
}

// Function to display an invoice
void displayInvoice(const Flight &flight)
{
    cout << "\n--- Invoice ---" << endl;
    cout << "From: " << flight.departure << " To: " << flight.arrival << endl;
    cout << "Date: " << flight.date << " Time: " << flight.time << endl;
    cout << "Check-in Time: " << flight.checkInTime << endl;
    cout << "Class: " << flight.flightClass << " Price: $" << flight.price << endl;
}

void displayCombinedInvoice(const Flight &flight1, const Flight &flight2)
{
    cout << "\n--- Combined Invoice ---" << endl;
    cout << "Outbound Flight:\n";
    cout << "From: " << flight1.departure << " To: " << flight1.arrival << endl;
    cout << "Date: " << flight1.date << " Time: " << flight1.time << endl;
    cout << "Check-in Time: " << flight1.checkInTime << endl;
    cout << "Class: " << flight1.flightClass << " Price: $" << flight1.price << endl;

    cout << "\nReturn Flight:\n";
    cout << "From: " << flight2.departure << " To: " << flight2.arrival << endl;
    cout << "Date: " << flight2.date << " Time: " << flight2.time << endl;
    cout << "Check-in Time: " << flight2.checkInTime << endl;
    cout << "Class: " << flight2.flightClass << " Price: $" << flight2.price << endl;

    int totalPrice = flight1.price + flight2.price;
    cout << "\nTotal Price: $" << totalPrice << endl;
}

int main()
{
    Node *head = nullptr;
    int choice;

    do
    {
        cout << "\n--- Welcome to NUTKANI AIRLINES ---" << endl;
        cout << "1. Book One-Way Flight" << endl;
        cout << "2. Book Return Flight" << endl;
        cout << "3. Invoice Booked Flights" << endl;
        // cout << "4. Cancel Last Flight" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookFlight(head);
            break;
        case 2:
        {
            string returnDeparture, returnArrival;
            bookFlight(head, true, "Pindi", "Lahore"); // Assuming return from Pindi to Lahore
            break;
        }
        case 3:
        {
            Node *current = head;
            while (current != nullptr)
            {
                displayInvoice(current->data);
                current = current->next;
            }
            break;
        }

        case 4:
            cout << "Exiting the system." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
}