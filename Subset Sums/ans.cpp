vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> ans;
    helper(arr, N, ans, 0, 0);
    sort(ans.begin(), ans.begin());
    return ans;
}

void helper(vector<int> &arr, int N, vector<int> &ans, int index, int sum)
{
    if (index == N)
    {
        ans.emplace_back(sum);
        return;
    }
    helper(arr, N, ans, index + 1, sum + arr[index]);
    helper(arr, N, ans, index + 1, sum);
}