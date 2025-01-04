#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>

using namespace std;

class SolutionBrute {
public:
    bool canPartition(vector<int> &nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;

        int subSetSum = totalSum / 2;
        int n = nums.size();
        return dfs(nums, n - 1, subSetSum);
    }

    bool dfs(vector<int> &nums, int n, int subSetSum) {
        if (subSetSum == 0) return true;
        if (n < 0 || subSetSum < 0) return false;

        return dfs(nums, n - 1, subSetSum - nums[n]) || dfs(nums, n - 1, subSetSum);
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
        cerr << "Usage: ./brute_partition <testID>" << endl;
        return 1;
    }

    int testID = stoi(argv[1]);
    vector<int> nums;
    nums = readTestCase("test_cases.txt", testID);
    SolutionBrute bruteSolution;
    string ret = (bruteSolution.canPartition(nums)) ? "Can Partition" : "CANNOT Partition";
    cout << ret << endl;

    return 0;
}
