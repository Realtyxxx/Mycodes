# Mycodes
这里是我的自学代码，包含c++以及python


# 顺便带一些学习git代码的地址[Github 简明教程](https://www.runoob.com/w3cnote/git-guide.html)

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
