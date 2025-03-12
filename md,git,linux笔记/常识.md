# shell
有多种不同的 Shell 程序，每个都有自己独特的特性和语法。以下是一些常见的 Shell 类型：
- zsh (Z SHell)：是 Bash 的一个功能丰富的替代品，提供了许多额外的改进和特性//我电脑用的这个

> - Bash (Bourne Again SHell)：是大多数 Linux 发行版和 macOS 系统中的默认 Shell。  

> - sh (Bourne SHell)：是最初的 Unix Shell，由 Stephen Bourne 编写。
> - csh (C SHell)：语法类似于 C 语言。
> - tcsh：是 csh 的一个改进版本。

Shell 和终端（Terminal）经常一起使用，但它们是不同的概念：

> Shell：是一个程序，它解释用户输入的命令并执行它们。
Terminal：是一个程序，它提供了命令行界面，允许用户输入命令到 Shell。在物理意义上，终端曾经是连接到大型计算机的输入/输出设备，而现在通常指的是终端模拟器。

## node
Node.js 是一个基于 Chrome V8 引擎的 JavaScript 运行时环境，它允许开发者使用 JavaScript 编写服务器端代码。Node.js 是异步的、事件驱动的，并且非常适合 I/O 密集型的应用程序.

## npm (Node Package Manager)

npm 是 Node.js 的默认包管理器，它随着 Node.js 一起安装。npm 提供了一个巨大的软件库，开发者可以从这个库中下载和使用他人编写的代码包，也可以发布自己的代码包。
- 安装、更新和卸载 Node.js 应用程序依赖的包。
- 管理项目依赖关系，通过 package.json 文件跟踪。
- 运行脚本，比如启动应用、运行测试等。

- npm i ：npm i 是 npm install 命令的简写形式。

## nvm (Node Version Manager)

nvm 是一个开源的版本管理工具，用于在同一个系统上安装和管理多个 Node.js 版本。它允许开发者在不同的项目之间轻松切换 Node.js 版本，这对于那些需要特定 Node.js 版本才能运行的应用程序来说非常有用。
- 安装和卸载不同版本的 Node.js。
- 切换当前使用的 Node.js 版本。
- 设置默认的 Node.js 版本。
- 管理 npm 版本与 Node.js 版本的关联

## Hexo 
Hexo 是一个快速、简洁且高效的博客框架，它允许用户使用 Markdown（或其他渲染引擎）编写文章，然后生成静态网页。
- hexo g : hexo generate 的缩写，用于生成静态文件。   
> 当你运行 hexo g 命令时，Hexo 会根据你的博客配置和 Markdown 文件，生成 HTML、CSS 和 JavaScript 等静态文件，并将它们放置在 public 目录下。
- hexo d : hexo deploy 的缩写，用于部署你的博客到服务器上。  
> hexo d 命令会根据你在 _config.yml 文件中的部署配置，将 public 目录下的文件上传到指定的服务器或仓库（例如 GitHub Pages、GitLab Pages、Netlify 等）。


