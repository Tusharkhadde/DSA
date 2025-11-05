#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter no of students";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cout<<endl;
    }
    int min_scores = arr[0];
    int max_scores = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min_scores) min_scores=arr[i];
        if(arr[i]>max_scores) max_scores=arr[i];
    }
    cout<<"least score"<<min_scores;
    cout<<"high score"<<max_scores;
    return 0;

}