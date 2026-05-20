#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class MovieTicket {
private:

    // movieID -> set of customerIDs
    unordered_map<int, unordered_set<int>> bookings;

    const int MAX_TICKETS = 100;

public:

    bool BOOK(int customerID, int movieID) {

        if (bookings[movieID].count(customerID))
            return false;

        if (bookings[movieID].size() >= MAX_TICKETS)
            return false;

        bookings[movieID].insert(customerID);
        return true;
    }

    bool CANCEL(int customerID, int movieID) {

        if (!bookings[movieID].count(customerID))
            return false;

        bookings[movieID].erase(customerID);
        return true;
    }

    bool IS_BOOKED(int customerID, int movieID) {

        return bookings[movieID].count(customerID);
    }

    // Remaining tickets
    int AVAILABLE_TICKETS(int movieID) {

        return MAX_TICKETS - bookings[movieID].size();
    }
};

int main() {

    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {

        string query;
        cin >> query;

        if (query == "BOOK") {

            int X, Y;
            cin >> X >> Y;

            cout << (mt.BOOK(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "CANCEL") {

            int X, Y;
            cin >> X >> Y;

            cout << (mt.CANCEL(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "IS_BOOKED") {

            int X, Y;
            cin >> X >> Y;

            cout << (mt.IS_BOOKED(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "AVAILABLE_TICKETS") {

            int Y;
            cin >> Y;

            cout << mt.AVAILABLE_TICKETS(Y) << endl;
        }
    }

    return 0;
}
