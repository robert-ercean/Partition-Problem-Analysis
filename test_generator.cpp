#include <bits/stdc++.h>

using namespace std;

#define FILENAME "test_cases.txt"

int main(int argc, char* argv[]) {
    /* Choose a test case ID and append it to the test_cases.txt file */
    if (argc != 4) {
        cerr << "Usage: ./test_generator <test_id> <array_size> <big_numbers_flag>" << endl;
        return 1;
    }

    int testID = stoi(argv[1]);
    int array_size = stoi(argv[2]);
    int big_numbers = stoi(argv[3]);

    ofstream file(FILENAME, ios::app);

    if (!file) {
        cerr << "Error opening file: " << FILENAME << endl;
        return -1;
    }

    /* Append the test ID and array size */
    file << testID << " " << array_size << " ";

    if (big_numbers) {
        /* We'll want to see the running time of the DP approach 
        * against a huge total sum */
        for (int i = 0; i < array_size; i++) {
            int divider_metric = (int) pow(2, (15 - testID));
            int val = (testID + 1) * 1000000 / divider_metric + (i * 20000); // Large values to increase sum
            file << val << " ";
        }
    } else {
        /* Append the array elements */
        /* Only this function should be changed when adding a new special
        * test case */
        for (int i = 0; i < array_size; i++) {
            int val = 10 + (i * 2);
            file << i << " ";
        }
    }

    file << endl;
    file.close(); 

    return 0;
}
