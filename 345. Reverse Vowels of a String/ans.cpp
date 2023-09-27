class Solution
{
private:
    bool isVowel(char c)
    {
        c = std::tolower(c); // Convert character to lowercase
        return std::string("aeiou").find(c) != std::string::npos;
    }

public:
    string reverseVowels(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {

            int start_vowel_index = -1;
            while (start < end)
            {
                if (isVowel(s[start]))
                {
                    start_vowel_index = start;

                    break;
                }
                ++start;
            }

            int end_vowel_index = -1;

            while (end > start)
            {
                if (isVowel(s[end]))
                {
                    end_vowel_index = end;

                    break;
                }
                --end;
            }

            if (start_vowel_index == -1 || end_vowel_index == -1)
                break;

            swap(s[start_vowel_index], s[end_vowel_index]);

            ++start;
            --end;
        }
        return s;
    }
};