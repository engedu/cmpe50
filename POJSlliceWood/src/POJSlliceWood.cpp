/*
作者:hotpro
题目:p3297 木材加工
*/

/*
//如何写一份可以提交的代码？以P1000 A+B为例
#include <iostream>
using namespace std;
int main()
{
    int a, b; //定义两个变量名
    cin >> a >> b; //从标准输入流中输入两个整数
    cout << a + b << endl; //输出到标准输出流中

}
// 完成程序以后，点击下方的提交，即可看到测试结果
*/

#include <iostream>
using namespace std;

int cut_by_length(int *wood, int N, int length) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += (wood[i] / length);
    }
    return count;
}

int main() {
    int N, K;
    int *wood;

    cin >> N >> K;
    wood = new int[N];

    int total = 0;

    for (int i = 0; i < N; i++) {
        cin >> wood[i];
        total += wood[i];
    }

    int start = 1;
    int end = total / K;
    int count;

    if (end == 0) {
    	cout << 0;
    	return 0;
    }

    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        count = cut_by_length(wood, N, mid);
        if (count == K) {
            start = mid;
        } else if (count > K) {
            start = mid;
        } else {
            end = mid;
        }
    }

    count = cut_by_length(wood, N, end);
    if (count >= K) {
        cout << end;
    } else {
        cout << start;
    }

    delete [] wood;

    return 0;
}




