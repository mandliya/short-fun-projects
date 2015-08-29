#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "\n\n\t\tWelcome to guess my number\n\n";
    cout << "Enter a number between 1 and 100, computer will try to guess "
            " this number and lets see how many attemts it takes:";
    int number;
    cin >> number;
    bool done = false;
    srand(static_cast<unsigned int>(time(0)));
    int tries = 0;
    int min = 1;
    int max = 100;
    do {
        ++tries;
        int guess = min +  (rand() % (max - min + 1));
        cout << "Computer guessed " << guess << endl;
        if (guess == number) {
            cout << "Game Over! computer guessed " << number << " in " << tries << " tries." << endl;
            done = true;
        } else if ( guess > number) {
            cout << "Computer guess is bigger, it will try again\n";
            max = guess - 1;
        } else {
            cout << "Computer guess is smaller, it will try again\n";
            min = guess + 1;
        }
        sleep(1);
    } while(!done);
    return 0;
}
