#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
    vector<vector<int>> sheet;

public:
    Spreadsheet(int rows)
    {
        sheet = vector<vector<int>>(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value)
    {
        pair<int, int> position = convertToPosition(cell);
        sheet[position.first][position.second] = value;
    }

    void resetCell(string cell)
    {
        pair<int, int> position = convertToPosition(cell);
        sheet[position.first][position.second] = 0;
    }

    int getValue(string formula)
    {
        int addPosition = 0;
        string x = "", y = "";
        for (int i = 0, n = formula.size(); i < n; i++)
        {
            if (formula[i] != '+')
                continue;
            x = formula.substr(1, i);
            y = formula.substr(i + 1, n - i);
            break;
        }
        int xVal = (isalpha(x[0])) ? getValue(convertToPosition(x)) : stoi(x);
        int yVal = (isalpha(y[0])) ? getValue(convertToPosition(y)) : stoi(y);

        return xVal + yVal;
    }

    int getValue(pair<int, int> position)
    {
        return sheet[position.first][position.second];
    }

    pair<int, int> convertToPosition(const string &cell)
    {
        int row = stoi(cell.substr(1, cell.size() - 1)) - 1;
        int column = cell[0] - 'A';
        return pair<int, int>(row, column);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */

/*
Input:
["Spreadsheet", "getValue", "setCell", "getValue", "setCell", "getValue", "resetCell", "getValue"]
[[3], ["=5+7"], ["A1", 10], ["=A1+6"], ["B2", 15], ["=A1+B2"], ["A1"], ["=A1+B2"]]

Output:
[null, 12, null, 16, null, 25, null, 15]
*/

int main()
{
    Spreadsheet *obj = new Spreadsheet(3);
    cout << obj->getValue("=5+7") << endl;
    obj->setCell("A1", 10);
    cout << obj->getValue("=A1+6") << endl;
    obj->setCell("B2", 15);
    cout << obj->getValue("=A1+B2") << endl;
    obj->resetCell("A1");
    cout << obj->getValue("=A1+B2") << endl;
    return 0;
}