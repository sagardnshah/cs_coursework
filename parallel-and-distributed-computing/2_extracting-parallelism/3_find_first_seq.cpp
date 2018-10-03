int search(int* array, int n, int val){
    int val_pos=n;
    for(i=0; i<n; i++){
        if(array[i]==val){
            val_pos=n;
        }
    }
    return val_pos;
}

#include <iostream>
using namespace std;
int main(){
    int array = {1,4,5,9,2,1,8};
    int n = (sizeof(array)/sizeof(*array));
    int val = 5;
    int val_pos = search(&array, n, val);
    cout<<val_pos;
    return 0;
}