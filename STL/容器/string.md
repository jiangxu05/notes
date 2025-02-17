# 基本概念 
- string是c++风格的字符串，本质是一个类，char*是一个指针，类内部封装了char*，管理这个字符串，是一个char*类型的容器

# 构造函数
- ```string();```//创建空的字符串
```string(const char*s)```//使用字符串s初始化


# 赋值操作
```
只记录下常见的：
void test1(){
    string str;
    str = "hello,world";
    cout << str;
}
void test2(){
    string str1;
    str1.assign("hello c++");
    cout << str1;
}
```

# 字符串拼接
```
void test3(){
    string str3 ="我";
    str3 += "爱学习";  //也可以strn1 + strn2;
    str4 = "肯定必须一定“;
    str4.append(str3,4，2);//变成一定我爱学习
}
```
# 字符串查找和替换
```
查找：
void test4(){
    string str4 = "abcdefg";
    int pos = str4.find("de");
    cout<<"pos ="<<pos   //输出 3 ，如果没找到就是输出-1
}
替换：
void test5(){
    string str5 = "abcdefg";
    str5.replace(1,3,"1111");
    cout<<"str5"     //输出a11113fg
}
```
# 字符串之间的比较
- 按字符的ASCII码进行对比
> = 返回0  
>      >返回1
> < 返回-1
```
void test6(){
    string str61 = "xello";
    string str62 = "hello";//是竖向一个一个比的
    if (str61.compare(str62)==0){
        cout<<"str61大于str62"<<endl;//往后类似
    }
}
```
# string字符存取
```
void7 test7(){
    string str7 = "hello";
    for(int i =0;i<string.size();i++){
        cout<<str[i]<<endl//也可以用这个格式改字符
    }
}
```

# 插入和删除
```
void test8 (){
    string str8 = "hello";
    str8.insert(1."111");
    cout << str8
    //输出h111ello;删除把 insert改成erase就行，注意其实下标从0开始
}
```
# 子串获取
```
void test9(){
    string str9 = "abcdef";
    string subStr = str9.substr(1,3);
    //输出为"bcd"
}
```

## 操作
```
void test01(){
    stirng email = "zhangsan@sina.com";
    //从邮箱中获取用户名
    int pos = email.find("@");//这时候输出8
    string username = email.substr(0,pos);
    //再输出就行了
    
}
```