#include <iostream>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

class customer {
public:
 int arr_time, use_time;//�������������
 customer(int ct, int ut) {//�вι���
  arr_time = ct;
  use_time = ut;
 }

};
class service {
public:
 bool busy;//�жϴ����Ƿ����
 int finish_time;
 service() :busy(0), finish_time(0) {}
};

int main() {
 int n, come_time, use_time, k;
 int all_wait_time = 0, wait_time = 0, finish_time = 0, max_wait_time = 0;
 queue<customer> cus;//�ʼ��һ���˿Ͷ���
 cin >> n; //�˿�����
 int n1 = n;
 while (n1--) {
  cin >> come_time >> use_time;
  cus.push(customer(come_time, use_time));
 }
 cin >> k; //���ڸ���
 service* win = new service[k];
 int clock = 0;//˲ʱʱ���
 while (!cus.empty()) {//�����ڿͻ�ʱ
  if (clock >= cus.front().arr_time) {  //�˿͵��ﴰ��
   for (int i = 0; i < k; i++) {
    if (win[i].finish_time <= clock) {  //�����Ѿ����ҵ������Ϊ����״̬���Ȱ����ҵ��Ĺ˿���ȥ��
     win[i].busy = 0;
    }
   }
   for (int i = 0; i < k; i++) {  //�ж�ÿһ�������Ƿ����
    if (!win[i].busy && (!cus.empty()) && (clock >= cus.front().arr_time)) {//����һ�����д��ڣ����Ϊæµ״̬
     win[i].busy = 1;//���״̬
     win[i].finish_time = clock + cus.front().use_time;//�ô��ڵ�ҵ�����ʱ��Ϊ��ǰʱ�����ҵ����Ҫʱ��
     wait_time = clock - cus.front().arr_time;//�ѵȴ�ʱ��Ϊ��ǰʱ����ÿͻ�����ʱ��֮��
     all_wait_time += wait_time;
     if (wait_time > max_wait_time) {
      max_wait_time = wait_time;
     }
     if (win[i].finish_time > finish_time) {//��ĳ�����ڵ����ʱ�����ԭ�������ʱ��ʱ�����и���
      finish_time = win[i].finish_time;
     }
     cus.pop();//�ÿͻ�ҵ����ɣ�����
    }

   }
  }
  clock++;//ʱ��һֱ����һ���ӵ��ٶ�����
 }
 cout << fixed << setprecision(1) << (double)all_wait_time / n << " " << max_wait_time << " " << finish_time << endl;
 delete[]win;
 return 0;
}
