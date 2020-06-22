# Mycodes

这里是我的自学代码，包含c++以及python

## 顺便带一些学习git代码的地址[Github 简明教程](https://www.runoob.com/w3cnote/git-guide.html)

>刚学会使用git，操作指令都没记熟==
____

## *[javaguide/git](https://snailclimb.gitee.io/javaguide/#/docs/tools/Git?i=%e9%9b%86%e4%b8%ad%e5%8c%96%e7%9a%84%e7%89%88%e6%9c%ac%e6%8e%a7%e5%88%b6%e7%b3%bb%e7%bb%9f)有更好的说明··*

- ## 本地创建一个库

右键所选文件夹，选择git(Bash)打开，然后在bash里输入：

```bash
echo "你想写在README.md文件里的" >>README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:Realtyxxx/Mycodes.git
git push -u origin master
#最后一行也可以写成 -f 表达强行删除
```

- ## 删除github上的文件夹，但不删除本地文件夹，比如.idea

```bash
git rm -r --cached .idea  #--cached不会把本地的.idea删除
git commit -m 'delete .idea dir'
git push -u origin master
```
