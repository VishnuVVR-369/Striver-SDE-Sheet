// Change arr[arr[i]] to negative and if it is already negative then it is repeating...

int findDuplicate(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[abs(arr[i])] < 0) return abs(arr[i]);
        else arr[abs(arr[i])] *= -1;
    }
    return -1;
}

// Fast and Slow Pointer Technique.

int findDuplicate(vector<int> &arr, int n) {
    int slow = arr[0], fast = arr[0];
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    fast = arr[0];
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

/*
Other Techniques
1. Check evey element if it is repeating.
2. Use map to store frequency.
3. Sort the array and check adjacent elements. 
*/