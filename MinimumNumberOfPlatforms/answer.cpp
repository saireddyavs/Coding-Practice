/*
 * Created on Tue Dec 21 2021
 *
 * Copyright (c) 2021 SaiReddy
 */

#include<iostream>
#include<algorithm>
using namespace std;

int minPlatform(int arrival[], int departure[], int n) {

    sort(arrival, arrival + n);
    sort(departure, departure + n);

    int result = 0, platforms = 0;

    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arrival[i] < departure[j]) {
            ++platforms;
            ++i;
            result = max(result, platforms);
        }
        else {
            ++j;
            --platforms;
        }
    }

    return result;
}

int main() {
    int arrival[] = { 900, 940, 950, 1100, 1500, 1800 };
    int departure[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = 6;
    cout << "Minimum Number of Platforms Required: " << minPlatform(arrival, departure, n);
}
