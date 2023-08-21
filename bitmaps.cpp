#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& nums) {
    int n = nums.size();

    for (int mask = 0; mask < (1 < < n); ++mask) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        } 

        // Print the current subset
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "All subsets of the given set:" << endl;
    generateSubsets(nums);

    return 0;
}
