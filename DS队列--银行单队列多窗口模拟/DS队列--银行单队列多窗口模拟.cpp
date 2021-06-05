#include <iostream>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

class customer {
public:
 int arr_time, use_time;//用类来存放数据
 customer(int ct, int ut) {//有参构造
  arr_time = ct;
  use_time = ut;
 }

};
class service {
public:
 bool busy;//判断窗口是否空闲
 int finish_time;
 service() :busy(0), finish_time(0) {}
};

int main() {
 int n, come_time, use_time, k;
 int all_wait_time = 0, wait_time = 0, finish_time = 0, max_wait_time = 0;
 queue<customer> cus;//最开始的一条顾客队列
 cin >> n; //顾客人数
 int n1 = n;
 while (n1--) {
  cin >> come_time >> use_time;
  cus.push(customer(come_time, use_time));
 }
 cin >> k; //窗口个数
 service* win = new service[k];
 int clock = 0;//瞬时时间点
 while (!cus.empty()) {//当存在客户时
  if (clock >= cus.front().arr_time) {  //顾客到达窗口
   for (int i = 0; i < k; i++) {
    if (win[i].finish_time <= clock) {  //窗口已经完成业务，重置为空闲状态，先把完成业务的顾客先去掉
     win[i].busy = 0;
    }
   }
   for (int i = 0; i < k; i++) {  //判断每一个窗口是否空闲
    if (!win[i].busy && (!cus.empty()) && (clock >= cus.front().arr_time)) {//存在一个空闲窗口，变更为忙碌状态
     win[i].busy = 1;//变更状态
     win[i].finish_time = clock + cus.front().use_time;//该窗口的业务完成时间为当前时间加上业务需要时间
     wait_time = clock - cus.front().arr_time;//已等待时间为当前时间与该客户到来时间之差
     all_wait_time += wait_time;
     if (wait_time > max_wait_time) {
      max_wait_time = wait_time;
     }
     if (win[i].finish_time > finish_time) {//当某个窗口的完成时间大于原最大的完成时间时，进行更换
      finish_time = win[i].finish_time;
     }
     cus.pop();//该客户业务完成，出队
    }

   }
  }
  clock++;//时钟一直在以一分钟的速度在走
 }
 cout << fixed << setprecision(1) << (double)all_wait_time / n << " " << max_wait_time << " " << finish_time << endl;
 delete[]win;
 return 0;
}
