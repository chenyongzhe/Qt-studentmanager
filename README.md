# Qt-studentmanager
C++ Qt 基于数据库Mysql学生信息管理系统<br>
看到这个项目有这么多网友们关注，我很意外也很高兴。<br>
###本项目为本人大一时小学期C++程序设计的大作业，项目每行代码都是本人从头到尾写的。<br>
PS：现在本人已经大三了，在准备保研夏令营的事情。挺忙的。<br>
有Coder问项目问题我哦没有及时和详细地回复,深感抱歉<br>
这个可以作为很多同学的入门项目。<br>由于项目用到了数据库Mysql 不懂mysql 的话要去了解下MySQL 的安装和基本增删改查。<br>
本人如果没有及时回复相关问题可以给本人发邮件1276316543@qq.com.  或者加本人QQ 1276316543本人很乐意回答大家。<br>

本项目用的Qtcreater 开发的 大家最好用Qtcreater 打开项目. <br>
程序依赖于mysql数据库先要解决Qt连接数据库问题，大家出问题八成是连接数据库的配置没做。
可以参考如下连接
<a href="https://blog.csdn.net/qq_35158695/article/details/53022565">https://blog.csdn.net/qq_35158695/article/details/53022565</a> <br>
###一．使用说明<br>
该学生信息管理系统使用的数据库为MySQL；<br>
在另外一台电脑上（老师的电脑）运行时运行环境必须满足以下要求：<br>
1,那台电脑必须要安装数据库MySQL;<br>
2,在那台电脑的MySQL中导入本人数据库脚本文件  studentmanager.sql  （该文件已打包好）（在后面写了导入studentmanager.sql 的方法）<br>
3，在MySQL的安装目录下的lib文件夹中的libmysql.dll文件复制到Qt安装目录下的bin目录中<br>
4，最后在原代码中的globle.cpp 文件中更改连接数据库的账号和密码( 更改QString sqluser="root"  的值为更改账号。更改QString sqlpass="123456" 的值为更改密码。<br>
此处我的数据库账号为root   密码为123456。此处账号密码要对应自己MySQL账号密码）<br>
以上步骤若没完成则会编译运行不了<br>
##运行后进入登录页面<br>
<img src="http://chenyongzhe.github.io/login.png" ><br>
学生端登录账密码在student表中可以找到 用该表的name作为账号， password 作为密码可登录学生端如：陈永喆  5252<br>
管理员端登录账号密码在admin表中 用该表的username作为账号和password作为密码可登录管理员端 如admin  admin<br>
具体的东西可以看我的实验报告里面<br> 我当时传到上面去了那个doc文件。


