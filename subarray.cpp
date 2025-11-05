#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printMinInSubarrays(vector<int>& arr, int n, int k) {
    deque<int> dq; // Will store *indexes* of elements
    vector<int> result;

    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() && arr[dq.back()]>=arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1){
            result.push_back(arr[dq.front()]);;
        }
    }
      // Print result
    cout << "Minimums of each subarray of size " << k << ": ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

}

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter window size (k): ";
    cin >> k;

    printMinInSubarrays(arr, n, k);
    return 0;
}
