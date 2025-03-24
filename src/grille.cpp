#include <iostream>
using namespace std;

int main(){
    cout <<"Printing array : ";

    int array[] = {12, 0, 1, 3, 0};

    int n = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}

