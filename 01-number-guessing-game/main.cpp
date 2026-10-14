
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;

    cout << "Guess a number between 1 and 100: ";

    do {
        cin >> guess;

        if (guess < secretNumber) {
            cout << "Too low! Try again: ";
        } else if (guess > secretNumber) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You guessed it!\n";
        }
    } while (guess != secretNumber);

    return 0;
}
