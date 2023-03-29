#include <iostream>

using namespace std;

int maxCross(int arr[], int a, int m, int b){
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= a; i--){
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int j = m; j <= b; j++){
        sum += arr[j];
        if (sum > right_sum) right_sum = sum;
    }

    int max_of_leftNright = max(left_sum, right_sum);
    return max(max_of_leftNright, left_sum+ right_sum - arr[m]);
}

int maxSubarray(int arr[], int p, int r){
    if (p==r){ 
        return arr[p];
    }
    else{
        int m = (p+r)/2;
        int leftMax = maxSubarray(arr, p, m);
        int rightMax = maxSubarray(arr, m+1, r);
        int crossMax = maxCross(arr, p, m, r);
        int max_leftNright = max(leftMax, rightMax);
        return max(max_leftNright, crossMax);
    }
}

int main()
{
    int arr[] = {2, -4, 1, 9, -6, 7, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sub = maxSubarray(arr, 0, n - 1);
    cout << "Maximum sub array sum is " << max_sub;
    return 0;
}
