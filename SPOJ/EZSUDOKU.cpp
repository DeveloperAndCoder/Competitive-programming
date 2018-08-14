#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#define ll long long
#define ul unsigned long long
#define forn(i,a,b) for(ul i = a; i < b; i++)
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define fr first
#define sc second
#define MAX 1000001
#define N 1000001

using namespace std;

bool check(int grid[8][8], pair<int, int> position, int value)
{
    for(int i = 0; i < 8; i++)
    {
        if((grid[i][position.second] && i != position.first && grid[i][position.second] == value) ||
                (grid[position.first][i] && i != position.second && grid[position.first][i] == value))
            return false;
    }
    int i = position.first;
    int j = position.second;
    int val[8];
    fill(val, val+8, 0);
    if(i < 4 && j < 4)  // grid 1
    {
        forn(i,0,4)
        {
            forn(j,0,4)
            {
               if(i == position.first && j == position.second) val[value-1]++;
               else if(grid[i][j]) val[grid[i][j]-1]++;
            }
        }
    }
    else if(i >= 4 && j < 4) // grid 2
    {
        forn(i,4,8)
        {
            forn(j,0,4)
            {
               if(i == position.first && j == position.second) val[value-1]++;
               else if(grid[i][j]) val[grid[i][j]-1]++;
            }
        }
    }
    else if(i < 4 && j >= 4) // grid 3
    {
        forn(i,0,4)
        {
            forn(j,4,8)
            {
               if(i == position.first && j == position.second) val[value-1]++;
               else if(grid[i][j]) val[grid[i][j]-1]++;
            }
        }
    }
    else
    {
        forn(i,4,8)
        {
            forn(j,4,8)
            {
               if(i == position.first && j == position.second) val[value-1]++;
               else if(grid[i][j]) val[grid[i][j]-1]++;
            }
        }
    }
    forn(i,0,8)
    {
        if(val[i] > 2) return false;
    }
    return true;
}

bool solve(int grid[8][8], vector<pair<int, int> > voids, int index)
{
    if(index == voids.size()) return true;
    auto present = voids[index];
    forn(i,0,8)
    {
        if(check(grid, present, i+1))
        {
            grid[present.first][present.second] = i+1;
            if(solve(grid, voids, index+1)) return true;
            grid[present.first][present.second] = 0;
        }
    }
    return false;
}

bool check_present(int grid[8][8])
{
    forn(i,0,8)
    {
        forn(j,0,8)
        {
            int val = grid[i][j];
            if(val == 0) continue;
            if(!check(grid, {i,j}, val)) return false;
        }
    }
    return true;
}

void print(int grid[8][8])
{
    cout << "YES\n";
    forn(i,0,8)
    {
        forn(j,0,8) cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    boost;
    int test;
    cin >> test;
    int sudoku[8][8];
    int testcase = 1;
    while(test--)
    {
        forn(i,0,8)
        forn(j,0,8) cin >> sudoku[i][j];

        vector<pair<int, int> > empty_grid;
        forn(i,0,8)
        forn(j,0,8)
        if(sudoku[i][j] == 0)  empty_grid.push_back({i,j});
        cout << "Test case #" << testcase++ << ": ";
        if(check_present(sudoku) && solve(sudoku, empty_grid, 0))
        {
            print(sudoku);
        }
        else cout << "NO\n";
    }
    return 0;
}
