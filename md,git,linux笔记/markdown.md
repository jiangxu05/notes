# 知识点/注意点

## 标题语法
很简单就用#就完事，不同的 Markdown 应用程序处理 # 和标题之间的空格方式并不一致。为了兼容考虑，用一个空格在 # 和标题之间进行分隔。

## 段落语法
不要用空格（spaces）或制表符（ tabs）缩进段落。

## 换行语法
在一行的末尾添加两个或多个空格，然后按回车键,即可创建一个换行  

## 强调语法
#### 粗体
在单词或短语的前后各添加两个**星号**
#### 斜体
*前后各添加一个星号，中间不要带空格。*
##### 斜体粗体同时用
前后***三颗星***

## 引用语法
> 在段落前添加一个 > 符号
>
>多段落引用中间加 >
>
>> 嵌套引用
>
>- hello! ***xxc***

## 列表语法
#### 有序列表
1. 数字加英文点并且***空格！***   
2. 第二行  
4. 第**三**行
#### 无序列表
- 在每个列表项前面添加破折号 (-)、星号 (*) 或加号 (+) 并且空格。缩进一个或多个列表项可创建嵌套列表两格。不需混淆用破折号就行。
    - 没错
      >也可以嵌套引用

## 代码语法
- 要将单词或短语表示为`代码`，请将其包裹在反引号 (`) 中
- ``如果你要表示为代码的单词或短语中包含`一个或多个反引号`，则可以通过将单词或短语包裹在双反引号中``  

#### ***围栏式代码块***
在代码块之前和之后的行上使用三个反引号（(```）或三个波浪号（~~~）
```
{
    abcdefg
}
```

## 分隔线语法
为了兼容性，请在分隔线的前后均添加空白行。

---

123

## 链接语法
链接文本放在中括号内，链接地址放在后面的括号中，链接title可选。
超链接Markdown语法代码：`[超链接显示名](超链接地址)`  
#### 链接title
- 这是一个链接[jiangxu's blog](https://jiangxu05.github.io/ "个人博客")  
- 链接title是当鼠标悬停在链接上时会出现的文字，这个title是可选的，它放在圆括号中链接地址后面，跟链接地址之间以 空格 分隔。用英文状态的双引号引起来！
#### 网址邮箱
- 使用尖括号可以很方便地把URL或者email地址变成可点击的链接。
- <https://markdown.com.cn>
- <fake@example.com>
- 不同的 Markdown 应用程序处理URL中间的空格方式不一样。为了兼容性，尽量使用%20代替空格。

## 图片语法
插入图片Markdown语法代码：`![图片alt](图片链接 "图片title")。`
![这是壁纸](https://markdown.com.cn/assets/img/shiprock.c3b9a023.jpg)。
- 一定要顶格
- 地址里面的空格要用%20替代

## 扩展语法
#### 表格
使用三个连字符创建每列的标题，并使用管道（|）分隔每列。单元格宽度可以变化
| Syntax      | Description |
| ----------- | ----------|
| Header      | Title       |
| Paragraph   | Text        |   
#### 表格对齐
可以通过在标题行中的连字符的左侧，右侧或两侧添加冒号（:），将列中的文本对齐到左侧，右侧或中心  
**表格中可以添加链接，代码和强调，不能添加标题，块引用，列表，水平规则，图像**
| Syntax      | Description | Test Text     |
| :---        |    :----:   |          ---: |
| Header      | Title       | Here's this   |
| Paragraph   | Text        | And more      |
#### 删除线
在单词前后使用两个波浪号(English Status)~~  
~~markdown基础语法~~ done
#### 任务列表
在任务列表项之前添加破折号-和方括号[ ]，并在[ ]前面加上空格。要选择一个复选框，请在方括号[x]之间添加 x   
- [ ] write 
- [x] read，vscode可能不支持这个表示
