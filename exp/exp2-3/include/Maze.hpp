/*** 
 * @Date: 2022-09-28 10:58:06
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-28 11:52:53
 * @FilePath: /DSM/exp/exp2-3/include/Maze.hpp
 */
/***
 * @Date: 2022-09-28 10:58:06
 * @LastEditors: Shujakuinkuraudo zhouyunyao1@gmail.com
 * @LastEditTime: 2022-09-28 11:51:49
 * @FilePath: /DSM/exp/exp2-3/include/Maze.hpp
 */
#pragma once
#include "head.h"
class NodeMaze
{
    int data;

public:
    NodeMaze()
    {
        data = 0;
    }
    friend istream &operator>>(istream &in, NodeMaze &node)
    {
        in >> node.data;
        return in;
    }
    bool blocked()
    {
        return data == 0;
    }
};
template <class T, int MAXSIZE>
class Maze
{
    T (*data)
    [MAXSIZE];
    pair<int, int> (*pre)[MAXSIZE];
    int row, col;
    pair<int, int> start, end;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    Maze()
    {
        data = new T[MAXSIZE][MAXSIZE];
        pre = new pair<int, int>[MAXSIZE][MAXSIZE];
        cin >> row >> col;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;
        _for(i, 0, row)
            _for(j, 0, col)
        {
            cin >> data[i][j];
            pre[i][j] = make_pair(-1, -1);
        }
    }
    ~Maze()
    {
        delete[] data;
        delete[] pre;
    }
    void Solve()
    {
        queue<pair<int, int>> q;
        q.push(start);
        pre[start.first][start.second] = make_pair(-2, -2);
        while (!q.empty())
        {
            pair<int, int> now = q.front();
            q.pop();
            if (now == end)
            {
                Show();
                cout << "找到" << endl;
                return;
            }
            _for(i, 0, 4)
            {
                int x = now.first + directions[i][0];
                int y = now.second + directions[i][1];
                if (x < 0 || x >= row || y < 0 || y >= col || pre[x][y].first != -1 || data[x][y].blocked())
                    continue;
                q.push(make_pair(x, y));
                pre[x][y] = now;
            }
        }
        Show();
        cout << "未找到" << endl;
    }
    void Show()
    {
        _for(i, 0, row)
        {
            _for(j, 0, col)
                    cout
                << pre[i][j].first << " " << pre[i][j].second << "\t";
            cout << endl;
        }
    }
};