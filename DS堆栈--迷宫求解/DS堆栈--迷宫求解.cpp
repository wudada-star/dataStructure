#include <iostream>
#include <stack>
using namespace std;

struct position {//用一个结构体来存放横坐标和纵坐标，存放多个变量有时用结构体有时用类
    int x;
    int y;
};

class Maze {
    int** maze;
    int size;
    stack<position> path;//这一步是利用结构体来达到向栈中一次压入两个数据
public:
    Maze(int n);

    ~Maze();

    void Go();
};

Maze::Maze(int n) {
    size = n;
    maze = new int* [n];
    for (int i = 0; i < n; i++)
        maze[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
}

Maze::~Maze() {
    for (int i = 0; i < size; i++)
        delete[]maze[i];
    delete[]maze;
}

void Maze::Go() {
    // 进入迷宫
    if (maze[0][0] == 0)//如果第一个位置是1，那么该迷宫也是没有path
    {
    path.push({ 0, 0 });//这一步是利用结构体来达到向栈中一次压入两个数据
    maze[0][0] = 1;
    int i = 0, j = 0;
    // 迷宫按照右下左上走
    while (true) {
        if (j + 1 < size && maze[i][j + 1] == 0)    //向右
        {
            maze[i][j + 1] = 1;   //代表走过，走过之后回退时就不能再选这一条路
            path.push({ i, ++j }); //走到 i,j+1位置，入栈
        }
        else if (i + 1 < size && maze[i + 1][j] == 0)    //向下
        {
            maze[i + 1][j] = 1;
            path.push({ ++i, j });
        }
        else if (j - 1 >= 0 && maze[i][j - 1] == 0)  //向左
        {
            maze[i][j - 1] = 1;
            path.push({ i, --j });
        }
        else if (i - 1 >= 0 && maze[i - 1][j] == 0)  //向上
        {
            maze[i - 1][j] = 1;
            path.push({ --i, j });
        }
        else    //无路可走
        {
            //回退
            i = path.top().x;
            j = path.top().y;
            //判断回退之后是否还有可以走的路
            if (!((j + 1 < size && maze[i][j + 1] == 0) || (i + 1 < size && maze[i + 1][j] == 0) || (j - 1 >= 0 && maze[i][j - 1] == 0) || (i - 1 >= 0 && maze[i - 1][j] == 0)))
                path.pop();  //出栈
        }
        if (path.empty() || (i == size - 1 && j == size - 1))  //如果回退到起点或者到达终点就结束循环
            break;
    }
    }
    //输出路径
    if (path.empty())
        cout << "no path" << endl;
    else {
        stack<position> path1;

        while (!path.empty())   //将path倒序
        {
            path1.push(path.top());
            path.pop();
        }

       int i = 0;
        while (!path1.empty()) {
            if ((++i) % 4 == 0)
                cout << '[' << path1.top().x << ',' << path1.top().y << ']' << "--" << endl;
            else
                cout << '[' << path1.top().x << ',' << path1.top().y << ']' << "--";
            path1.pop();
        }
        cout << "END" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Maze myMaze(n);
        myMaze.Go();
    }
    return 0;
}