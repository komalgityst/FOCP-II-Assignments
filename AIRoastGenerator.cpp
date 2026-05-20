#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Store user name
    string name;

    // Ask for input
    cout << "Enter your name: ";
    getline(cin, name);

    // Roast templates
    vector<string> roasts = {
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If procrastination were an Olympic sport, {name} would win gold every year.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name}'s typing speed is slower than a loading screen from 2005.",
        "{name} writes comments like mystery novels — nobody understands them.",
        "{name}'s coding style scares even antivirus software.",
        "{name} spends more time choosing a font than writing actual code.",
        "{name}'s programs crash so often that even the computer gets nervous.",
        "{name} debugs by staring at the screen until the bug feels guilty.",
        "{name}'s Wi-Fi disconnects out of embarrassment during online classes."
    };

    // Random seed
    srand(time(0));

    // Random roast index
    int randomIndex = rand() % roasts.size();

    // Select roast
    string roast = roasts[randomIndex];

    // Replace {name}
    size_t position = roast.find("{name}");

    if (position != string::npos)
    {
        roast.replace(position, 6, name);
    }

    // Display roast
    cout << "\nGenerated Roast:\n";
    cout << roast << endl;

    return 0;
}
