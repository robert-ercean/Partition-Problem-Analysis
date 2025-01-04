#include <bits/stdc++.h>

using namespace std;

#define FILENAME "test_cases.txt"

int main(int argc, char* argv[]) {
    /* Choose a test case ID and append it to the test_cases.txt file */
    if (argc != 3) {
        cerr << "Usage: ./test_generator <test_id> <array_size>" << endl;
        return 1;
    }

    int testID = stoi(argv[1]);
    int array_size = stoi(argv[2]); 

    ofstream file(FILENAME, ios::app);

    if (!file) {
        cerr << "Error opening file: " << FILENAME << endl;
        return -1;
    }

    /* Append the test ID and array size */
    file << testID << " " << array_size << " ";

    /* Append the array elements */
    /* Only this function should be changed when adding a new special
     * test case */
    // Test case 3: Huge array with huge elements 
    // Test case 4: Small array with huge elements
    for (int i = 0; i < array_size; i++) {
        int val = 0xfffff + (4 * i);
        file << val << " ";
    }

    file << endl;
    file.close(); 

    return 0;
}
