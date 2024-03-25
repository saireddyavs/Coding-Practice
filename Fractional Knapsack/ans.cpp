class Solution
{
public:
    bool static comparision(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here

        double result = 0;
        sort(arr, arr + n, comparision);

        double currWeight = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i].weight + currWeight <= W)
            {
                currWeight += (double)arr[i].weight;
                result += (double)arr[i].value;
            }
            else
            {
                double remaining = W - currWeight;
                result += ((double)arr[i].value * remaining) / (double)arr[i].weight;
                break;
            }
        }
    }
};