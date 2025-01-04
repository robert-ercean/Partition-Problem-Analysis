#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>

using namespace std;

class SolutionDP {
public:
    bool isSubsetSum(int n, vector<int>& arr, int sum, vector<vector<int>> &memo) {
        if (sum == 0) return true;
        if (n == 0) return false;
        
        if (memo[n-1][sum] != -1) 
            return memo[n-1][sum];

        if (arr[n-1] > sum)
            return isSubsetSum(n-1, arr, sum, memo);

        return memo[n-1][sum] = 
               isSubsetSum(n-1, arr, sum, memo) || 
               isSubsetSum(n-1, arr, sum - arr[n-1], memo);
    }

    bool canPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2 != 0) return false;
        
        vector<vector<int>> memo(arr.size(), vector<int>(sum+1, -1));
        return isSubsetSum(arr.size(), arr, sum / 2, memo);
    }
};

vector<int> readTestCase(const string& filename, int testID) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int id, size;
        ss >> id >> size;
        
        if (id == testID) {
            vector<int> arr(size);
            for (int i = 0; i < size; i++) {
                ss >> arr[i];
            }
            return arr;
        }
    }
    
    cerr << "Test ID not found: " << testID << endl;
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: ./dp_partition <testID>" << endl;
        return 1;
    }

    int testID = stoi(argv[1]);
    vector<int> nums;
    nums = readTestCase("test_cases.txt", testID);
    SolutionDP dpSolution;
    string ret = (dpSolution.canPartition(nums)) ? "Can Partition" : "CANNOT Partition";
    cout << ret << endl;
    return 0;
}
