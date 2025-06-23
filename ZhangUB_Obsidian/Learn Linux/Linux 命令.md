Linux 命令由三部分组成:本体(command)，选项(option)，参数(parameter)

# \[命令] --help
- 说明书
# pwd
print work directory
- `pwd` 当前所在目录位置 
# ls
- `ls`列出目录下的内容
- `ls [-a -l -h] [Linux路径]`
	- `ls /` 列出根目录下内容
	- `-a` all，列出全部文件内容
	- `-l` 列表形式详细列出
		- 三个权限分别是，read，write，excute，可读，可写，可执行
		- 所看到的三组权限分别对应：所有者，所有小组，其他
	- `-h` 易于理解的形式列出
	- `ls -la` 详细列出全部内容
# cd
Chang Directory
- `cd [Linux路径]`
- `cd` 回到home
- `cd -` 回到上一次的目录
- 特殊路径符
	- `.`当前目录
	- `..`上一级目录
	- `~`HOME目录
- 绝对路径和相对路径
	- 绝对路径以`/`开始，比表示从根目录开始
	- 相对路径无需`/`开头，直接从当前目录下寻找
# mkdir
Make Directory 创建文件夹
- `mkdir [-p] [Linux路径]`
- `-p`自动创建不存在的父目录
- 在home外需要超级管理员权限
# touch
- 创建文件
- `touch [Linux路径]`
- touch命令无选项，参数必填，参数为路径，最后写文件
# cat
- catch 查看内容
- `cat [Linux路径]`
# more
- more支持翻页，语法和cat相同
- 空格翻页，q退出
# cp
- copy 
- `dp [-r] 参数1 参数2`
- `-r`表示递归/级联，用于复制文件夹
- 参数1表示source，参数2表示副本名称
# mv
- move
- `mv 参数1 参数2`
- 把1挪到2
# rm
- remove
- `rm [-r -f] 参数1 …… 参数n`
-  `-r`用于删除文件夹
- `-f`force 强制删除，一般开root才会出现
- 参数表示要删除的文件或者文件夹路径
- `rm -rf /`全部删除
# 通配符 *
- 模糊匹配
- test\* 表示任何以test开头的内容
- \*test 表示任何以test结尾的内容
- \*test\* 表示任何包含test的内容
# which
- `which 命令`
- 查看命令存放位置
# find 
- 查找指定文件
- `find 起始路径 -name "被查找的文件名"`名称搜索
- `find 起始路径 -size +|-[num] [kMG]"被查找的文件名"`大小搜索
- 起始路径：表示从哪里开始搜索
- `+|z`表示大于或小于，`num`表示数字，`kMG`表示单位：kb，MB，GB
- 双引号别丢，不写路径从当前目录下寻找
# grep
- 通过关键字过滤
- `grep [-n] 关键字 文件路径`
- `-n`表示显示行号
- 关键字中如果又特殊符号可以整体用双引号括起来
- 文件路径可以作为内容输入端口
# wc
- 统计行数，单词数等
- `wc [-c -m -l -w] 文件路径`
- `-c 统计bytes数量，-m统计字符数量，-l统计行数，-w统计单词数量`
- 文件路径可以作为内容输入端口
# 管道符 |
- 将左边命令的结果作为右边命令的输入
# echo
- 在terminal中输出
- `echo 输的内容`
#  \`反引号
- 被反引号包围的内容会作为命令执行
# 重定向符
- `> 和 >>
- `>`将左侧命令的结果覆盖写入右侧符号指定的文件中
- `>>`将左侧命令的结果追加写入右侧指定的文件中
# tail
- 使用tail命令查看文件尾部内容，跟踪文件更改
- `tail [-f -num] Linux路径`
- `-f`持续跟踪，一直跟踪不停
- `-num`查看尾部多少行，不填默认10行
# tee
- `tee [option] [file]` 从stdin读入并输出到文件和stdout
- `-a` 追加
# xdg-open
- `xdg-open [file|URL]` 使用用户偏好的应用打开一个文件或链接
# shell 脚本

`su - root` 进入root账户
`exit`退出root账户
`sudo ntfsfix -d /dev/nvme0n1p3` 修复这个分区信息，无法访问win盘使用
`sudo df -h`查看所有挂在的分区使用信息
挂载磁盘
`mkdir /media/zhangletian/xxx`建目录
`sudo mount  -t ntfs /dev/nvme0n1p2 /media/zhangletian/xxx`挂载
`umount  /dev/nvme0n1p2` 卸载磁盘