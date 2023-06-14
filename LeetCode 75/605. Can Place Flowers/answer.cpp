class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {

        int i = 0;
        int counter = 0;

        while (i < flowerbed.size())
        {
            if (flowerbed[i] == 1)
                break;
            ++i;
        }

        if (i == flowerbed.size())
        {

            counter = (i / 2);
            counter += i % 2 == 1 ? 1 : 0;

            cout << counter;
            return counter >= n;
        }

        counter += i / 2;
        ++i;
        int midStart = i;
        cout << midStart << endl;
        while (i < flowerbed.size())
        {
            if (flowerbed[i] == 1)
            {
                cout << midStart << " " << i << " " << counter << endl;
                counter += (i - midStart - 1) / 2;
                midStart = i + 1;
            }
            ++i;
        }

        cout << counter << " " << midStart << " " << flowerbed.size() << endl;

        counter += (flowerbed.size() - midStart) / 2;

        cout << counter;

        return counter >= n;
    }
};

// 0 - 1
// 0 0 - 1
// 0 0 0 -2
// 0 0 0 0 - 2
// 0 0 0 0 0 -3
// 0 0 0 0 0 0 - 3
