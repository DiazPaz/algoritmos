#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

vector<vector<vector<pair<int,int>>>> extract(vector<vector<vector<bool>>> &templates, vector<vector<bool>> &input)
{
    vector<vector<int>> ans(9);
    for(int i = 0; i < 27; i+=3)
    {
        for(int num = 0; num < 10; ++num)
        {
            pair<int,int> curr = {0,num};
            for(int x = 0; x < 3; ++x)
            {
                for(int y = 0; y < 3; ++y)
                {
                    if(input[i + x][y] && !templates[num][x][y])
                    {
                        ++curr.first;
                    }
                }
            }
            ans[i/3].push_back(num);
        }
        sort(ans[i/3].begin(), ans[i/3].end());
    }
    return ans;
}

bool validate(vector<int> &query)
{
    int ans = 0;
    for(int i = 0; i < 10; ++i)
        ans += query[i] * (9-i);
    return ans % 11 == 0; 
}

int bactrackig(vector<vector<pair<int,int>>> &possibles, vector<int> &curr)
{
    
}

int main(void)
{
    int cases; 
    cin >> cases; 

    vector<vector<vector<bool>>> templates = {
        {
            {false, true, false},
            {true, false, true},
            {true, true, true},
        },
        {
            {false, false, false},
            {false, false, true},
            {false, false, true},
        },
        {
            {false, true, false},
            {true, true, true},
            {true, true, false},
        },
        {
            {false, true, false},
            {false, true, true},
            {false, true, true},
        },
        {
            {false, false, false},
            {true, true, true},
            {false, false, true},
        },
        {
            {false, true, false},
            {true, true, true},
            {false, true, true},
        },
        {
            {false, true, false},
            {true, true, false},
            {true, true, true},
        },
        {
            {false, true, false},
            {false, false, true},
            {false, false, true},
        },
        {
            {false, true, false},
            {true, true, true},
            {true, true, true},
        },
        {
            {false, true, false},
            {true, true, true},
            {false, true, true},
        },
    };

    while(cases--)
    {
        string line; 
        // getline(cin,line);
        cin.ignore();
        vector<vector<bool>> input(3, vector<bool> (27, false));
        for(int i = 0; i < 3; i++)
        {
            getline(cin, line);
            for(int j = 0; j < 27; ++j)
            {
                if(line[j] == '|' ||  line[j] == '_')
                    input[i][j] = true; 
            }
            cin.ignore();
        }
    }
    vector<vector<pair<int,int>>> possibles = extract(templates, input);
    bool solved = false; 
    int invalid = 0; 
    int invalid_i = 0; 
    vector<int> attempt;  
    {
        bool valid = true; 
        for(int i = 0; i < 10; ++i)
        {
            attempt.push_back(possibles[i][0].second);
            if(possibles[i][0].first != 0)
            {
                valid = false; 
                ++invalid;
                invalid_i = i;
            }
        }
        if(valid && validate(attempt))
        {
            solved = true; 
            for(int i = 0; i <10; ++i)
            {
                cout << (i == 0 ? "" : " ") << attempt[i];
            }
        }
    }
    bool ambiguo = false;
    if(!solved && invalid == 1)
    {
        for(pair<int,int> att : possibles[invalid_i])
        {
            attempt[invalid_i] = att.second;
            bool valid = validate(attempt);
            if(valid)
            {
                if(solved)
                {
                    ambiguo = true;
                }
                ambiguo = true;
            }
        }
        if(ambiguo)
        {
            cout << "ambiguo\n";
        }
        else if(solved){
            for(int i = 0; i < 10; ++i)
            {
                cout << (i == 0 ? "" : " ") << attempt[i] << "\n";
            }
        }
        else 
        {
            cout << "failure\n"; 
        }
        if(!solved && invalid == 0) {}
        if(!solved) { cout << "failure"}
    }

    return 0; 
}