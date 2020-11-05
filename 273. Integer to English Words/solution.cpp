/*
 * Created on Thu Nov 05 2020
 *
 * Copyright (c) 2020 SaiReddy
 */

const string one[] = {"", "One ", "Two ", "Three ", "Four ",
                      "Five ", "Six ", "Seven ", "Eight ",
                      "Nine ", "Ten ", "Eleven ", "Twelve ",
                      "Thirteen ", "Fourteen ", "Fifteen ",
                      "Sixteen ", "Seventeen ", "Eighteen ",
                      "Nineteen "};

const string ten[] = {"", "", "Twenty ", "Thirty ", "Forty ",
                      "Fifty ", "Sixty ", "Seventy ", "Eighty ",
                      "Ninety "};
class Solution
{

    string convert(int num, string suffix)
    {
        if (!num)
            return "";
        string res;
        // cout << num << " " << suffix << endl;
        if (num > 99)
        {

            res = one[num / 100] + "Hundred ";
        }

        num %= 100;

        if (num > 19)
        {
            res += ten[num / 10] + one[num % 10];
        }
        else
        {
            res += one[num];
        }

        return res + suffix;
    }

public:
    string numberToWords(int num)
    {

        if (num == 0)
            return "Zero";

        string res;

        // cout<<(num/1000000000)<<endl;
        res += convert((num / 1000000000), "Billion ");

        // cout<<(num/1000000)%1000<<endl;
        res += convert((num / 1000000) % 1000, "Million ");

        // cout<<(num/1000)%1000<<endl;
        res += convert((num / 1000) % 1000, "Thousand ");
        res += convert((num) % 1000, "");

        return res.substr(0, res.find_last_of(" "));
    }
};