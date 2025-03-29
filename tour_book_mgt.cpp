#include <iostream>
#include <string>
using namespace std;


// Structure for Booking
struct Booking {
    int bookingId;
    string customerName;
    int tourId;
    Booking* next;
};

// Linked List for Bookings
class BookingList {
    private:
        Booking* head;
    
    public:
        BookingList() : head(nullptr) {}
        //To add booking 
        void addBooking(int bookingId, string customerName, int tourId) {
            Booking* newBooking = new Booking{bookingId, customerName, tourId, nullptr};
            if (!head) {
                head = newBooking;
            } else {
                Booking* temp = head;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newBooking;
            }
            cout << "Booking added successfully!\n";
        }

        //To cancel booking 
        void cancelBooking(int bookingId) {
            if (!head) {
                cout << "No bookings found!\n";
                return;
            }
            if (head->bookingId == bookingId) {
                Booking* temp = head;
                head = head->next;
                delete temp;
                cout << "Booking canceled successfully!\n";
                return;
            }
            Booking* temp = head;
            while (temp->next && temp->next->bookingId != bookingId) {
                temp = temp->next;
            }
            if (temp->next) {
                Booking* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Booking canceled successfully!\n";
            } else {
                cout << "Booking not found!\n";
            }
        }
        //To display booking
        void displayBookings() {
            if (!head) {
                cout << "No bookings found!\n";
                return;
            }
            Booking* temp = head;
            while (temp) {
                cout << "Booking ID: " << temp->bookingId << ", Customer: " << temp->customerName << ", Tour ID: " << temp->tourId << "\n";
                temp = temp->next;
            }
        }
    };


int main(){
    BookingList bookings;
    int choice;

    do {
        cout << "\nTour Booking & Travel Package Management\n";
        cout << "1. Book Tour\n";
        cout << "2. Cancel Booking\n";
        cout << "3. Display Bookings\n";
        cout << "20. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int bookingId, tourId;
                string customerName;
                cout << "Enter Booking ID: ";
                cin >> bookingId;
                cout << "Enter Customer Name: ";
                cin >> customerName;
                cout << "Enter Tour ID: ";
                cin >> tourId;
                bookings.addBooking(bookingId, customerName, tourId);
                break;
            }
            case 2: {
                int bookingId;
                cout << "Enter Booking ID to cancel: ";
                cin >> bookingId;
                bookings.cancelBooking(bookingId);
                break;
            }
            case 3: {
                bookings.displayBookings();
                break;
            }
            default: {
                cout << "Invalid choice! Try again.\n";
            }
            }
        } while (choice != 20);
    
    return 0;
}