/*
 * Created on Thu Sep 24 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

#include <bits/stdc++.h>
using namespace std;

priority_queue<double> max_heap;
priority_queue<double, vector<double>, greater<double>> min_heap;

double number_to_compare = 0;

double medianStream(double number)
{

    // cout<<max_heap.size()<<" , "<<min_heap.size()<<endl;

    // cout<<min_heap.top()<<" , "<<max_heap.top()<<endl;

    if (!max_heap.size() && !min_heap.size())
    {

        max_heap.emplace(number);
        number_to_compare = number;
        return (double)number;
    }

    if (number_to_compare < number)
    {
        min_heap.emplace(number);
    }
    else
    {
        max_heap.emplace(number);
    }

    int maxi = max_heap.size();
    int mini = min_heap.size();

    if (abs(maxi - mini) == 2)
    {
        if (max_heap.size() < min_heap.size())
        {
            max_heap.emplace(min_heap.top());
            min_heap.pop();
        }
        else
        {
            min_heap.emplace(max_heap.top());
            number_to_compare = min_heap.top();
            max_heap.pop();
        }
    }

    if (max_heap.size() > min_heap.size())
    {
        return max_heap.top();
    }
    else if (max_heap.size() < min_heap.size())
    {
        return min_heap.top();
    }
    else
    {

        return (max_heap.top() + min_heap.top()) / 2;
    }
}

int main()
{

    double number;
    vector<double> numbers;
    number = 10;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";

    cout << "---->" << medianStream(number) << endl;

    number = 11;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    //  cout<<medianStream(number)<<endl;
    cout << "---->" << medianStream(number) << endl;

    number = 145;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 150;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 1;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 12;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 89;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 1;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 190;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 56;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 3;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 56;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 90;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 8;

    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 34.34;
    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    number = 34.35;
    numbers.emplace_back(number);
    sort(numbers.begin(), numbers.end());
    for (auto num : numbers)
        cout << num << " ";
    cout << "---->" << medianStream(number) << endl;

    // 10 ---->10
    // 10 11 ---->10.5
    // 10 11 145 ---->11
    // 10 11 145 150 ---->78
    // 1 10 11 145 150 ---->11
    // 1 10 11 12 145 150 ---->11.5
    // 1 10 11 12 89 145 150 ---->12
    // 1 1 10 11 12 89 145 150 ---->11.5
    // 1 1 10 11 12 89 145 150 190 ---->12
    // 1 1 10 11 12 56 89 145 150 190 ---->34
    // 1 1 3 10 11 12 56 89 145 150 190 ---->12
    // 1 1 3 10 11 12 56 56 89 145 150 190 ---->34
    // 1 1 3 10 11 12 56 56 89 90 145 150 190 ---->56
    // 1 1 3 8 10 11 12 56 56 89 90 145 150 190 ---->34
    // 1 1 3 8 10 11 12 34.34 56 56 89 90 145 150 190 ---->34.34
    // 1 1 3 8 10 11 12 34.34 34.35 56 56 89 90 145 150 190 ---->34.345

    return 0;
}
