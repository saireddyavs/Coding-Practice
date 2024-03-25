bool static comparision(Job a, Job b)
{
    return a.profit > b.profit;
}
// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    int jobs = 0;
    int profit = 0;

    sort(arr, arr + n, comparision);

    Job max_deadline_job = *max_element(arr, arr + n, [](Job a, Job b)
                                        { return a.dead < b.dead; });

    // for(int i=0;i<n;++i){
    //     Job ele=arr[i];
    //     cout<<ele.id<<" "<<ele.dead<<" "<<ele.profit<<endl;
    // }

    int max_deadline = max_deadline_job.dead;

    vector<int> deadlines(max_deadline + 1);
    fill(deadlines.begin(), deadlines.end(), -1);

    // for(int i=0;i<=max_deadline;++i)cout<<deadlines[i]<<" ";
    // cout<<endl;

    for (int i = 0; i < n; ++i)
    {
        // cout<<arr[i].dead<<" "<<deadlines[arr[i].dead]<<endl;
        for (int j = arr[i].dead; j >= 1; --j)
        {
            if (deadlines[j] == -1)
            {
                profit += arr[i].profit;
                ++jobs;
                deadlines[j] = 0;
                break;
            }
        }
    }

    return vector<int>{jobs, profit};
}