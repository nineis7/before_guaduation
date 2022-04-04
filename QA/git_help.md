#Git使用手册

前提是不造轮子，丰富的学习资源互联网上都有。

所需要的仅仅是：clone repo，学习，将学习记录保存至本地，上传

1. 下载注册git
```
sudo apt-get install git
git config --global user.name "你的github账户名"
git config --global user.email "你的github账户默认的邮箱地址"
```

2. [更新ssh并保存至github中](https://www.liaoxuefeng.com/wiki/896043488029600/896954117292416) 以后通过ssh来访问远程仓库，因为后续无法再通过输入密码的方式update仓库了

3. 在本地新建文件夹，通过ssh clone repo保存到本地
```
git clone git@github.com:nineis7/before_guaduation.git
```

4. 本地的数据随意访问和修改，可自如添加进before_guaduation文件夹中

5. 当一天学习完毕，通过以下步骤上传至远程仓库
```
git status  #查询状态，红色表示本地修改未同步至远端服务器
git add .
git commit -m "Here is my comment"
git remote add master git@github.com:nineis7/before_guaduation.git  #仅第一次需要，创建master分支
git push master
```

6. 第二天将新仓库更新至本地仓库（当其他朋友有所修改）
```
git pull
```
