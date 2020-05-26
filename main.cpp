#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;


int main()
{
    map <string, vector<string> > dict;
    map <string, vector<string> >:: iterator it;
    ifstream input;
    input.open("input.txt"); // открываем файл
    int n;
    input >> n;
    string s = "", value = "", key;
    int w = 0;
    getline(input, s);
    s.clear();
    for(int i = 0; i < n; i++)
    {
        value = "";
        getline(input, s);
        key = "";
        while (s[w] != ' ')
        {
            key += s[w];
            w++;
        }

        w = w + 3;
        while (s[w] != ',' && w != s.size())
        {
            value += s[w];
            w++;
        }

        dict[value].push_back(key);
        value = "";
        if (s[w] == ',')

        {
            w += 1;
            int pos = w;
            for(int j = w; j < s.size(); j++)
            {
                if(s[j] == ',')
                {
                    pos += 1;
                    string tmpstr = s.substr(pos, j - pos);
                    value += tmpstr;
                    pos = j + 1;
                    dict[tmpstr].push_back(key);
                }
            }
            pos += 1;
            string tmpstr = s.substr(pos, s.size());
            value += tmpstr;
            dict[tmpstr].push_back(key);
        }
        w = 0;
    }
    cout << dict.size() << endl;
    for (it = dict.begin(); it != dict.end(); it++)
    {
        cout << it -> first << " - ";
        int c = (it -> second).size();
        for (int j = 0; j < c; j++)
        {
            cout << (it -> second)[j];
            if (j + 1 < c)
                cout << ", ";
        }
        cout << endl;
    }

    return 0;
}
