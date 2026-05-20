#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Store student name
    string name;

    // Ask for user input
    cout << "Enter student name: ";
    getline(cin, name);

    // Vector storing excuse templates
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop decided to update for 6 hours.",
        "{name} was ready to submit the homework when the Wi-Fi suddenly disappeared.",
        "{name} tried completing the assignment, but the keyboard stopped working.",
        "{name} accidentally deleted the homework file at the last moment.",
        "{name}'s pet sat on the keyboard and closed the assignment.",
        "{name} was about to finish the work when the electricity went out.",
        "{name} forgot the assignment because the alarm clock betrayed them.",
        "{name} couldn't complete the task because the browser crashed repeatedly.",
        "{name} spent hours solving the problem but saved the file in the wrong folder.",
        "{name} was preparing the assignment when the laptop battery died unexpectedly."
    };

    // Seed random number generator
    srand(time(0));

    // Generate random index
    int randomIndex = rand() % excuses.size();

    // Get random excuse
    string excuse = excuses[randomIndex];

    // Replace {name} with actual user input
    size_t position = excuse.find("{name}");

    if (position != string::npos)
    {
        excuse.replace(position, 6, name);
    }

    // Display final excuse
    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}
