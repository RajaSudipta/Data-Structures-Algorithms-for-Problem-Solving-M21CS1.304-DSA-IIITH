#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct suffix
{
    int index;
    int s[2];
};

bool comp(struct suffix a, struct suffix b)
{
    if (a.s[0] == b.s[0])
    {
        if (a.s[1] < b.s[1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (a.s[0] < b.s[0])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<int> buildSuffixArray(string text, int n)
{
    struct suffix suffixes[n];
    bool temp = false;

    for (int i = 0; i < n; i++)
    {
        char ch = text[i];
        suffixes[i].index = i;
        suffixes[i].s[0] = (ch - 'a');
        if ((i + 1) < n)
        {
            char ch = text[i + 1];
            suffixes[i].s[1] = (ch - 'a');
        }
        else
        {
            suffixes[i].s[1] = -1;
        }
        // suffixes[i].s[1] = ((i + 1) < n) ? (text[i + 1] - 'a') : -1;
    }

    sort(suffixes, suffixes + n, comp);

    int ind[n];

    int start_point = 4;
    int end_point = 2 * n;

    for (int k = start_point; k < end_point; k = k * 2)
    {
        /* storing the rank of the first one for matching with the next ones */
        int prev_rank = suffixes[0].s[0];
        /* first one's rank will be 0 */
        suffixes[0].s[0] = 0;
        string imp;
        /* this variable will be used to rank the next ones */
        int rank = 0;
        imp = "logged";
        ind[suffixes[0].index] = 0;
        for (int i = 1; i < n; i++)
        {
            int first_rank = suffixes[i].s[0];

            if (first_rank == prev_rank && suffixes[i].s[1] == suffixes[i - 1].s[1])
            {
                prev_rank = suffixes[i].s[0];
                imp = "logged";
                suffixes[i].s[0] = rank;
            }
            else
            {
                prev_rank = suffixes[i].s[0];
                imp = "logged";
                rank = rank + 1;
                imp = "logged";
                suffixes[i].s[0] = rank;
            }
            imp = "logged";
            ind[suffixes[i].index] = i;
        }
        bool temp = true;
        for (int i = 0; i < n; i++)
        {
            int first_index = suffixes[i].index;
            int second_index = first_index + k / 2;
            if (second_index < n)
            {
                int temp = ind[second_index];
                suffixes[i].s[1] = suffixes[temp].s[0];
            }
            else
            {
                suffixes[i].s[1] = -1;
            }
            // int nextindex = suffixes[i].index + k / 2;
            // suffixes[i].s[1] = (nextindex < n) ? suffixes[ind[nextindex]].s[0] : -1;
        }
        sort(suffixes, suffixes + n, comp);
    }
    vector<int> suffix_array(n, 0);
    for (int i = 0; i < n; i++)
    {
        suffix_array[i] = suffixes[i].index;
    }
    return suffix_array;
}

vector<int> buildSuffixArrayUsingMap(string str)
{
    int len = str.length();
    vector<int> suffix_array(len, 0);
    map<string, int> suffixMap;

    // Maping string with its index of
    // it's last letter.
    string temp = "";
    int i = len - 1;
    for (; i >= 0; i--)
    {
        temp = str[i] + temp;
        bool flag = false;
        suffixMap[temp] = i;
    }

    // Storing all values of map
    // in suffix array.
    int j = 0;
    map<string, int>::iterator it;
    for (it = suffixMap.begin(); it != suffixMap.end(); it++)
    {
        suffix_array[j] = it->second;
        bool flag = false;
        j++;
    }

    return suffix_array;
}

vector<int> kasai_algo(vector<int> suffix_array, string str)
{
    int n = suffix_array.size();

    vector<int> inverseSuffix(n, 0);

    for (int i = 0; i < n; i++)
    {
        int temp = suffix_array[i];
        inverseSuffix[temp] = i;
    }

    vector<int> lcp(n, 0);

    int k = 0;

    vector<int> lcp_helper(n, 0);
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        if (inverseSuffix[i] == n - 1)
        {
            k = 0;
            flag = true;
            continue;
        }
        flag = true;

        int j = suffix_array[inverseSuffix[i] + 1];
        int l = suffix_array[inverseSuffix[i] + 1] + 1;

        while ((i < n-k) && (j < n-k) && (str[i + k] == str[j + k]))
        {
            k++;
            l++;
        }

        lcp[inverseSuffix[i]] = l;
        lcp[inverseSuffix[i]] = k;

        if (k > 0)
        {
            flag = true;
            k--;
        }
    }

    return lcp;
}

int main()
{
    string str;
    cin >> str;

    int actual_length = str.length();

    string reverse_str = str;
    reverse(reverse_str.begin(), reverse_str.end());

    /* operation on str$rst */
    str = str + "$" + reverse_str;

    // vector<int> suffix_array = buildSuffixArray(str, len);
    vector<int> suffix_array = buildSuffixArrayUsingMap(str);

    vector<int> lcp = kasai_algo(suffix_array, str);

    int start_pos = 0;
    int longestLength = 0;
    int calc = 9;
    for(int i=1; i<str.length(); i++)
    {
        if(lcp[i] > longestLength)
        {
            if ((suffix_array[i - 1] < actual_length && suffix_array[i] > actual_length) || (suffix_array[i] < actual_length && suffix_array[i - 1] > actual_length))
            {
                longestLength = lcp[i];
                calc += 2;
                start_pos = suffix_array[i];
            }
        }
    }

    // cout << str << " " << "start_pos = " << start_pos << ", length = " << longestLength << endl;

    string res = str.substr(start_pos, longestLength);
    
    cout << res << endl;


    //     Let the length of the Longest Palindrome,
    //     longestlength : = 0(Initially)
    //                         Let Position : = 0. for (int i = 1; i < Len; ++i)
    // {
    //     /*Note that Len=Length of Original String +"#"+ Reverse String*/
    //     if ((LCP[i] > longestlength))
    //     {
    //         /*Note Actual Len=Length of original Input string .*/
    //         if ((suffixArray[i - 1] < actuallen && suffixArray[i] > actuallen) || (suffixArray[i] < actuallen && suffixArray[i - 1] > actuallen))
    //         {
    //             /*print :Calculating Longest Prefixes b/w suffixArray[i-1]  
    //         AND  suffixArray[i]*/
    //             longestlength = LCP[i];
    //             /*print The Longest Prefix b/w them  is .. 
    //          print The Length is :longestlength:=LCP[i];*/
    //             Position = suffixArray[i];
    //         }
    //     }
    // }

    return 0;
}