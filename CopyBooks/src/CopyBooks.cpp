/*
作者:
题目:p3168 抄书问题 3
http://codevs.cn/problem/3168/

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
//Solution to copy books, the following code is in c++ since wikioi
//only accetps c++
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

int trySpeed(int *books, int M, int K, int speed, int *result) {
    int max = 0;
    int right = M - 1;
    int left = 0;

    for (int i = K - 1; i >= 0; i--) {
        int sum = 0;
        for (left = right; left >= 0; left--) {
            sum += books[left];
            if ((i != 0 && left > 0 && sum + books[left - 1] > speed) || left <= i) {
                break;
            }
        }

        result[2 * i + 1] = right;
        if (left <= 0) {
            left = 0;
        }
        result[2 * i] = left;
        max = sum > max ? sum : max;
        right = left - 1;
        if (left <= 0) {
            break;
        }
    }

    return max;
}

void mySolution() {
    int M, K;
    cin >> M;
    cin >> K;

    int* books = new int[M];
    int* result = new int[K * 2];
    int total = 0;
    for(int i = 0; i < M; i++) {
        cin >> books[i];
        total += books[i];
    }

    int start = total / K;
    int end = total;
    int speed = 0;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        speed = trySpeed(books, M, K, mid, result);
        if (speed == mid) {
            end = mid;
        } else if (speed < mid) {
            end = mid;
        } else {
            start = mid;
        }
    }

    speed = trySpeed(books, M, K, start, result);
    if (speed == start) {
        for (int i = 0; i < K; i++) {
            printf("%d %d\n", result[i * 2] + 1, result[i * 2 + 1] + 1);
        }
    } else {
        speed = trySpeed(books, M, K, end, result);
        if (speed == end) {
            for (int i = 0; i < K; i++) {
                printf("%d %d\n", result[i * 2] + 1, result[i * 2 + 1] + 1);
            }
        }
    }

    delete [] books;
    delete [] result;
}

//Solution to copy books, the following code is in c++ since wikioi
//only accetps c++

// Check whether a given number of pages in a slice is
// valid, i.e. all the books could get copied.
bool isValid(int M, int K, int* pages, int sliceNum) {
    int curSliceNum = 0;
    int curBook = M - 1;
    for(int i = K - 1; i >= 0; i--) {
        curSliceNum = 0;

        while(curSliceNum + pages[curBook] <= sliceNum &&
                curBook >= 0) {
            curSliceNum += pages[curBook];
            curBook--;
        }

        if (curBook < 0) {
            return true;
        }
    }

    return false;
}


// Use binary search to find the optimal number of pages in a slice.
int search(int M, int K, int* pages, int minSliceNum, int maxSliceNum) {
    int beg = minSliceNum;
    int end = maxSliceNum;
    int mid;

    while (beg + 1 < end) {
        mid = (beg + end) / 2;
        if (isValid(M, K, pages, mid)) {
            end = mid;
        } else {
            beg = mid;
        }
    }

    if (isValid(M, K, pages, end)) {
        return end;
    }

    return beg;
}

void nineChapterSolution() {
    int M, K;
    cin >> M;
    cin >> K;

    int* pages = new int[M];
    int* startBook = new int[K];
    int* endBook = new int[K];
    int maxSliceNum = 0;
    int minSliceNum = 0;
    int optimalSliceNum;
    for(int i = 0; i < M; i++) {
        cin >> pages[i];
        minSliceNum = min(pages[i], minSliceNum);
        maxSliceNum += pages[i];
    }

    optimalSliceNum = search(M, K, pages, minSliceNum, maxSliceNum);

    int curSliceNum = 0;
    int curBook = M - 1;
    for(int i = K - 1; i >= 0; i--) {
        curSliceNum = 0;
        endBook[i] = curBook;
        while (curSliceNum + pages[curBook] <= optimalSliceNum &&
                curBook >= i) {
            curSliceNum += pages[curBook];
            curBook--;
        }
        startBook[i] = curBook + 1;
    }

    for(int i = 0; i < K; i++) {
        printf("%d %d\n", startBook[i] + 1, endBook[i] + 1);
    }

    delete [] endBook;
    delete [] startBook;
    delete [] pages;
}

int main() {

	mySolution();
//	nineChapterSolution();
    return 0;
}
