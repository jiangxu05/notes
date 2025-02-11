//利用指针访问数组中的元素
#include <iostream>
using namespace std;
int main() {
    int a[5] = {1, 2, 3, 4, 5};     //定义数组a
    int *p = a;                      //定义指针变量p，指向数组a，a是数组的首地址
    for (int i = 0; i < 5; i++) {
        cout << "a[" << i << "] = " << a[i] << ", *(p + " << i << ") = " << *(p + i) << endl;
    }                              //输出数组a和指针p访问数组a中的元素
    return 0;
}



//地址传递：
void swap(int *a, int *b) {         //定义函数swap，参数为指针变量a和b
    int temp = *a;                  //定义临时变量temp，存储a指向的值
    *a = *b;                        //将b指向的值赋给a指向的值
    *b = temp;                      //将temp的值赋给b指向的值
}
int main() {
    int a = 10, b = 20;
    cout << "a = " << a << ", b = " << b << endl; //输出a = 10, b = 20
    swap(&a, &b);                   //调用函数swap，传入a和b的地址
    cout << "a = " << a << ", b = " << b << endl; //输出a = 20, b = 10
    return 0;
}


//数组函数冒泡排序
void bubbleSort(int arr[], int len) {   //定义函数bubbleSort，参数为数组arr和数组长度len
    for (int i = 0; i < len; i++) {     //外层循环控制比较的轮数    “可参考一维数组md笔记”
        for (int j = 0; j < len - i - 1; j++) { //内层循环控制每轮比较的次数
            if (arr[j] > arr[j + 1]) {  //如果前一个元素大于后一个元素，交换位置
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    int len = sizeof(arr) / sizeof(arr[0]); //计算数组arr的长度
    bubbleSort(arr, len);                //调用函数bubbleSort，传入数组arr和数组长度10
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";          //输出排序后的数组
    }
    return 0;
}