#include <iostream>

using namespace std;

int main() {

    int n;
    int temp;

    cout << "How many numbers do you want to check?" << endl;
    cin >> n;

    int sortingArray[n];

    cout << "Insert the numbers: " << endl;
    for(int i = 0; i < n; i++){
        cout << "Number " << i + 1 << ": ";
        cin >> sortingArray[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(sortingArray[j] < sortingArray[i]){
                temp = sortingArray[i];
                sortingArray[i] = sortingArray[j];
                sortingArray[j] = temp;
            }
        }
    }

    cout << "Here is the array in ascending order: " << endl;

    for(int k = 0; k < n; k++){
        cout << "Number " << k << " is: "<< sortingArray[k] << endl;
    }

   return 0;
}
