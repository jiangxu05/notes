## 基本概念
区别：数组是静态空间，vector是动态扩展
> 动态扩展不是在原空间接续新空间，而是找到更大的空间，将原数据拷贝，释放原空间。

![vector](vector.png)

### - ***打印接口***
```
void printvector(vector<int>& v){
    for(vector<int>::iterater it = v.begin(); it != v.end();i++{
        cout<< *it << " ";
    })
}
```
## 构造
```
vector<int> v0;
// 1. 创建空vector; 常数复杂度
v0.reserve(3);// 1+. 这句代码可以使得向vector中插入前3个元素时，保证常数时间复杂度
vector<int> v1(3);
vector<int> v2(3, 2);
// 3. 创建一个初始空间为3的vector，其元素的默认值是2; 线性复杂度
vector<int> v3(3, 1, v2.get_allocator());
// 4. 创建一个初始空间为3的vector，其元素的默认值是1，
// 并且使用v2的空间配置器; 线性复杂度
vector<int> v4(v2);
// 5. 创建一个v2的拷贝vector v4， 其内容元素和v2一样; 线性复杂度
vector<int> v5(v4.begin() + 1, v4.begin() + 3);
// 6. 创建一个v4的拷贝vector v5，其内容是{v4[1], v4[2]}; 线性复杂度
vector<int> v6(std::move(v2));
// 7. 移动v2到新创建的vector v6，不发生拷贝; 常数复杂度; 需要 C++11// 或者 v6 = std::move(v2);
```
## 访问
```
1.at()
v.at(pos) 返回容器中下标为 pos 的引用。如果数组越界抛出 std::out_of_range 类型的异常。
```

## 赋值操作
- 等号
- assign
```
vector<int>v4;
v4.assign(v1.begin(),v1.end());
printvectorv4;
```
- assign,n个elem;
```
vector<int>v5;
v5,assign(10,100);
printvector(v5);
```

## vector容量和大小
```
if(v1.empty()){
    cout <<"v1为空"<<endl;
}
else {
    cout <<"v1的容量为: "<<v1.capacity()<<endl;
    cout << "v1的大小为: "<<v1.size()<<endl;//容量永远大于等于大小
}
//重新指定大小
v1.resize(15);//默认空的补0
v1.resize(15.100);//使用100来填充
v1.resize(5);//超出的会被删掉
```
## vector插入和删除
```
v1.push_back(ele); //尾部插入elm
v1.pop_back();//删除最后一个元素
v1.insert(v1.begin(),2,100);//在第一个元素后插入两个一百
v1.erase(v1.begin());//删掉第一个元素
v1.erase(v1.begin(),v1.end());//全删完了
```
## 数据存取
```
for (int i = 0; i < v1.size(); i++){
    cout << v1[i] << " ";//也可以v1.at(i)
}
cout << endl;

//第一个元素
cout << v1.front() << endl;

//第二个元素
cout << v1.back() << endl;
```
## 互换容器
```
//在void test01中加上：
vector<int.v2;
for (int i =10; i>0; i--){
    v2.push_back(i);
}


//交换
v1.swap(v2);



//实际用途，巧用swap收缩内存空间；
```



