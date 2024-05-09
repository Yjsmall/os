# 2024 OS Course

这里就是jyy老师2024操作系统课程代码，会增加自己Notes.

> Get the course codes

```shell
wget -nH -m [ftp:]
-nH：不创建以主机名命名的目录。
–cut-dirs：希望去掉原来的目录层数，从根目录开始计算。如果想完全保留FTP原有的目录结构，则不要加该参数。
-m：下载所有子目录并且保留目录结构。
```

concurrency: 里面的Makefile文件的TLIB_PATH 环境变量放置在你的shell配置文件中.
它的值是thread-lib文件夹的目录.
`zsh: export TLIB_PATH="pwd"`
