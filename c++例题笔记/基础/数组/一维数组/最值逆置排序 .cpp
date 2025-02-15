#include <iostream>

using namespace std;

int main(){
 /*
 找出数组中最大值
 */
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int max = arr[0];
    for(int i = 0; i < 10; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << "max = " << max << endl;
/*
元素逆置
*/
    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int start = 0;
    int end = sizeof(arr1)/sizeof(arr1[0]) - 1; //末尾元素下标
    while(start < end){
        int temp = arr1[start];
        arr1[start] = arr1[end];
        arr1[end] = temp;
        start++;
        end--;
    }
/*
冒泡排序
*/
    int arr2[10] = {1,3,5,7,9,2,4,6,8,10};
    for(int i = 0; i < 10; i++){                //外层循环控制比较的轮数
        for(int j = 0; j < 10 - i - 1; j++){    //内层循环控制每轮比较的次数
            if(arr2[j] > arr2[j+1]){            //如果前一个元素大于后一个元素，交换位置
                int temp = arr2[j];             //千万别忘记int
                arr2[j] = arr2[j+1];
                arr2[j+1] = temp;
            }
        }
    } 
//别忘记了打印步骤

    return 0;
}