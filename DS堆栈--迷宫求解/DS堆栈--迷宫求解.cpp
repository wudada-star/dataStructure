#include <iostream>
#include <stack>
using namespace std;

struct position {//��һ���ṹ������ź�����������꣬��Ŷ��������ʱ�ýṹ����ʱ����
    int x;
    int y;
};

class Maze {
    int** maze;
    int size;
    stack<position> path;//��һ�������ýṹ�����ﵽ��ջ��һ��ѹ����������
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
    // �����Թ�
    if (maze[0][0] == 0)//�����һ��λ����1����ô���Թ�Ҳ��û��path
    {
    path.push({ 0, 0 });//��һ�������ýṹ�����ﵽ��ջ��һ��ѹ����������
    maze[0][0] = 1;
    int i = 0, j = 0;
    // �Թ���������������
    while (true) {
        if (j + 1 < size && maze[i][j + 1] == 0)    //����
        {
            maze[i][j + 1] = 1;   //�����߹����߹�֮�����ʱ�Ͳ�����ѡ��һ��·
            path.push({ i, ++j }); //�ߵ� i,j+1λ�ã���ջ
        }
        else if (i + 1 < size && maze[i + 1][j] == 0)    //����
        {
            maze[i + 1][j] = 1;
            path.push({ ++i, j });
        }
        else if (j - 1 >= 0 && maze[i][j - 1] == 0)  //����
        {
            maze[i][j - 1] = 1;
            path.push({ i, --j });
        }
        else if (i - 1 >= 0 && maze[i - 1][j] == 0)  //����
        {
            maze[i - 1][j] = 1;
            path.push({ --i, j });
        }
        else    //��·����
        {
            //����
            i = path.top().x;
            j = path.top().y;
            //�жϻ���֮���Ƿ��п����ߵ�·
            if (!((j + 1 < size && maze[i][j + 1] == 0) || (i + 1 < size && maze[i + 1][j] == 0) || (j - 1 >= 0 && maze[i][j - 1] == 0) || (i - 1 >= 0 && maze[i - 1][j] == 0)))
                path.pop();  //��ջ
        }
        if (path.empty() || (i == size - 1 && j == size - 1))  //������˵������ߵ����յ�ͽ���ѭ��
            break;
    }
    }
    //���·��
    if (path.empty())
        cout << "no path" << endl;
    else {
        stack<position> path1;

        while (!path.empty())   //��path����
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