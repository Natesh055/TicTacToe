
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<char>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        if (i != n - 1)
            cout << "__|___|___|";
        cout << endl;
    }
}

bool markans(vector<vector<char>> &board, int c, int n, char &t)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 48 + c)
            {
                board[i][j] = t;
                return true;
            }
        }
    }
    return false;
}
bool left(vector<vector<char>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'Y')
                return true;
        }
    }
    return false;
}

bool calcans(vector<vector<char>> board, vector<vector<string>> temp, int n, char c)
{
    for (int i = 0; i < temp.size(); i++)
    {
        int count = 0;

        for (auto it : temp[i])
        {
            char c1 = it[0];
            char c2 = it[1];
            if (board[c1 - '0'][c2 - '0'] == c)
            {
                count++;
            }
        }
        if (count == 3)
            return true;
    }
    return false;
}
int main()
{
    int n = 3;
    int a = 49; // ascii of 1
    vector<vector<char>> board(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = a++;
        }
    }
    // print(board, n);

    vector<vector<string>> temp = {{"00", "01", "02"}, {"10", "11", "12"}, {"20", "21", "22"}, {"00", "10", "20"}, {"01", "11", "21"}, {"02", "12", "22"}, {"00", "11", "22"}, {"02", "11", "20"}};

    bool turn = true;
        print(board, n);
    while (left(board, n))
    {
        if (turn && left(board, n))
        {
        print(board, n);
            cout << "Turn of x:" << endl;
            int x;
            cin >> x;
            char s = 'X';
            if (markans(board, x, n, s))
            {
                turn = !turn;

                if (calcans(board, temp, n, 'X'))
                {
                    cout << "X is the winner" << endl;
                    break;
                }
            }
            else
            cout<<"Enter Again"<<endl;
            continue;
        }
        if (!turn && left(board, n))
        {
        print(board, n);
            cout << "Turn of Y:" << endl;
            int y;
            cin >> y;
            char s = 'Y';
            if(markans(board, y, n, s))
            {

            
            turn = !turn;

            if (calcans(board, temp, n, 'Y'))
            {
                cout << "Y is the winner" << endl;
                break;
            }
        }
        else
            cout<<"Enter Again"<<endl;
            continue;
        }
    }
    if (!left(board, n))
        cout << "No one was the winner";
}