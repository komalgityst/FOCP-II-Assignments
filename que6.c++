#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Bank {
private:

    // userID -> balance
    unordered_map<int, int> accounts;

public:

    bool CREATE(int userID, int amount) {

        if (accounts.count(userID)) {
            accounts[userID] += amount;
            return false;
        }

        accounts[userID] = amount;
        return true;
    }

    bool DEBIT(int userID, int amount) {

        if (!accounts.count(userID) || accounts[userID] < amount)
            return false;

        accounts[userID] -= amount;
        return true;
    }

    bool CREDIT(int userID, int amount) {

        if (!accounts.count(userID))
            return false;

        accounts[userID] += amount;
        return true;
    }

    int BALANCE(int userID) {

        if (!accounts.count(userID))
            return -1;

        return accounts[userID];
    }
};

int main() {

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {

        string query;
        cin >> query;

        if (query == "CREATE") {

            int X, Y;
            cin >> X >> Y;

            cout << (bank.CREATE(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "DEBIT") {

            int X, Y;
            cin >> X >> Y;

            cout << (bank.DEBIT(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "CREDIT") {

            int X, Y;
            cin >> X >> Y;

            cout << (bank.CREDIT(X, Y) ? "true" : "false") << endl;
        }

        else if (query == "BALANCE") {

            int X;
            cin >> X;

            cout << bank.BALANCE(X) << endl;
        }
    }

    return 0;
}
