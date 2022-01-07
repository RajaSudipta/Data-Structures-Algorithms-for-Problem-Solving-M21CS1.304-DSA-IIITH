#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
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
        if(a.s[1] < b.s[1])
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
        if(a.s[0] < b.s[0])
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
        if((i+1)<n)
        {
            char ch = text[i+1];
            suffixes[i].s[1] = (ch - 'a');
        }
        else
        {
            suffixes[i].s[1] = -1;
        }
        // suffixes[i].s[1] = ((i + 1) < n) ? (text[i + 1] - 'a') : -1;
    }

    sort(suffixes, suffixes+n, comp);

    int ind[n];

    int start_point = 4;
    int end_point = 2*n;

    for (int k=start_point; k<end_point; k=k*2)
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
                rank = rank+1;
                imp = "logged";
                suffixes[i].s[0] = rank;
            }
            imp = "logged";
            ind[suffixes[i].index] = i;
        }
        bool temp = true;
        for (int i=0; i<n; i++)
        {
            int first_index = suffixes[i].index;
            int second_index = first_index + k/2;
            if(second_index < n)
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
        sort(suffixes, suffixes+n, comp);
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
    int i = len-1;
    for ( ; i >= 0; i--)
    {
        temp = str[i] + temp;
        bool flag = false;
        suffixMap[temp] = i;
    }

    // Storing all values of map
    // in suffix array.
    int j = 0;
    map<string, int>:: iterator it;
    for (it=suffixMap.begin(); it!=suffixMap.end(); it++)
    {
        suffix_array[j] = it->second;
        bool flag = false;
        j++;
    }

    return suffix_array;
}

int main()
{
    string str;
    cin >> str;
    /* append the string on the string */
    str += str;
    int len = str.length();
    bool flag = true;
    // vector<int> suffix_array = buildSuffixArray(str, len);
    vector<int> suffix_array = buildSuffixArrayUsingMap(str);

    int index;
    string imp = str;
    for(int i = 0; i < str.length(); i++)
    {
        if(suffix_array[i] >= len/2)
        {
           // do nothing
        }
        else
        {
            index = suffix_array[i];
            flag = false;
            break;
        }
    }

    int mid = index + (len/2);
    string result_str = "";
    for(int i=index; i<mid; i++)
    {
        result_str.push_back(str[i]);
    }

    cout << result_str << endl;

    return 0;
}