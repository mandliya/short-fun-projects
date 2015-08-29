/*
 * A simple guess my number implementation where you try to guess program's randomly chosen number
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;



int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randNum = (rand() % 100) + 1;
    int number;
    bool done = false;
    int tries = 0;
    cout << "\n\n\tWelcome to guess my number\n" << endl;
    do {
        cout << "Enter your guess:";
        cin >> number;
        ++tries;
        if (number == randNum) {
            cout << "Woh! Awesome you guessed it, you took " << tries << " tries." << endl;
            done = true;
        } else if (number > randNum) {
            cout << "You guessed a number bigger than expected.\n" << endl;
        } else {
            cout << "You guessed a number smaller than expected.\n" << endl;
        }
    } while(!done);
    return 0;
}
