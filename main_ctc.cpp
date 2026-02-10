#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE_PW = 100000000;//relates to the size of the password

// Function to generate a random x-digit passcode
int generatePasscode() {
    return rand() % SIZE_PW; // Ensures x-digit number (1000-9999)
}

int main() {
    srand(time(0)); // Seed for random number generation
    int passcode = generatePasscode();

    cout << "A x-digit passcode has been generated. Try to crack it!" << endl;
    cout<<passcode<<endl;

    // Start Timer
    auto start = high_resolution_clock::now();

    // Students will write their algorithm here to find 'passcode'
    

    // Stop Timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Passcode cracked in: " << duration.count() << " nanoseconds!" << endl;

    return 0;
}
