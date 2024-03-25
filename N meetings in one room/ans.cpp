int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int, int>> end_index;

    for (int i = 0; i < n; ++i)
    {
        end_index.emplace_back(make_pair(end[i], i));
    }

    sort(end_index.begin(), end_index.end());

    // for(int i=0;i<n;++i)cout<<end_index[i].first<<" "<<end_index[i].second<<endl;
    // cout<<endl;

    int result = 1;
    int prevEndTime = end_index[0].first;
    for (int i = 1; i < n; ++i)
    {
        if (start[end_index[i].second] > prevEndTime)
        {
            ++result;
            prevEndTime = end_index[i].first;
        }
    }
    return result;
}