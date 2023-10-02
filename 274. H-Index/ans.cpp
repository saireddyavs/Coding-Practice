class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int size = citations.size();
        if (size == 1)
        {
            if (citations[0] == 0)
                return 0;
            return 1;
        }

        sort(citations.begin(), citations.end());

        int zeros = count(citations.begin(), citations.end(), 0);
        if (zeros == size)
            return 0;

        int low = 0;

        int high = size - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (citations[mid] == size - mid)
            {
                return citations[mid];
            }
            else if (citations[mid] > size - mid)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return size - low;
    }
};