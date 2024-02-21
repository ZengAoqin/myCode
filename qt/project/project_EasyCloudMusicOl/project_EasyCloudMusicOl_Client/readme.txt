项目功能；
1.用户登录
2.发现音乐页面实现播放随机网络歌曲
3.添加本地音乐并加入播放列表 点击开始播放即可从第一首歌开始播放 点击歌曲项即可播放当前点击歌曲 
4.加入播放列表后 可由播放栏实现停止播放 开始播放 下一首 上一首功能 列表自动播放下一首
5.在线音乐 获取播放列表 点击单曲即可下载到本地进行播放

警告：
1.使用QMediaPlayer播放mp3格式音乐 系统需安装解码器 如:K-Lite_Codec_Pack_1805_Basic
2.使用QNetworkAccessManager请求https需将Qt\Qt5.9.1\Tools\mingw530_32\opt\bin目录下的libeay32.dll和ssleay32.dll拷贝到程序生成目录下（即生成exe的同级目录 debug）