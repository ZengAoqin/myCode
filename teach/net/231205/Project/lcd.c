#include "lcd.h"

//lcd设备初始化
LCD lcd_init()
{
	//初始化结构体指针
	LCD lcd_device = malloc(sizeof(lcd));
	if(NULL == lcd_device)
	{
		fprintf(stderr, "line[%d] malloc lcd_device failed \n", __LINE__);
		return NULL;
	}
	
	//打开lcd屏幕
	lcd_device->lcdfd = open(LCD_PATH, O_RDWR);
	if(-1 == lcd_device->lcdfd)
	{
		fprintf(stderr, "line[%d] open lcd_path failed \n", __LINE__);
		free(lcd_device);
		lcd_device = NULL;
		return NULL;
	}
	
	//映射内存空间
	lcd_device->mmp = mmap(NULL, LCD_SIZE, PROT_READ|PROT_WRITE, \
							MAP_SHARED, lcd_device->lcdfd, 0);
	if(MAP_FAILED == lcd_device->mmp) //MAP_FAILED (void*)-1
	{
		fprintf(stderr, "line[%d] mmap failed \n", __LINE__);
		free(lcd_device);
		lcd_device = NULL;
		return NULL;
	}
	
	printf("映射初始化成功\n");
	return lcd_device;
}

//lcd设备销毁
void lcd_destroy(LCD lcd_device)
{
	//关闭映射
	int ret = munmap(lcd_device->mmp, LCD_SIZE);
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] munmap failed \n", __LINE__);
		return;
	}
	
	//关闭lcd文件描述符
	ret = close(lcd_device->lcdfd);
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] close failed \n", __LINE__);
		return;
	}
	
	//释放指针
	free(lcd_device);
	lcd_device = NULL;
}

//图片显示
void showBmp(int x, int y, const char* bmpName, LCD lcd_device)
{
	//1.打开图片对象
	int bmpfd = open(bmpName, O_RDWR);
	if(-1 == bmpfd)
	{
		fprintf(stderr, "line[%d] open bmp failed\n", __LINE__);
		return ;
	}
	
	unsigned char headinfo[54] = {0};
	int ret = read(bmpfd, headinfo, sizeof(headinfo));
	printf("当前读取的字节数为%d\n", ret);
	//宽从第18个字节开始
	unsigned int off_size = headinfo[10]|(headinfo[11]<<8)|(headinfo[12]<<16)|(headinfo[13]<<24);
	unsigned int bmp_w = headinfo[18]|(headinfo[19]<<8)|(headinfo[20]<<16)|(headinfo[21]<<24);
	unsigned int bmp_h = headinfo[22]|(headinfo[23]<<8)|(headinfo[24]<<16)|(headinfo[25]<<24);
	
	printf("当前获取图片的文件到数据偏移为%d\n", off_size);
	printf("当前图片的宽:%d和高:%d\n", bmp_w, bmp_h);
	
	//偏移占位符的位置
	lseek(bmpfd, off_size, SEEK_SET);
	//2.读取bmp中的像素(因为bmp图片是RGB，横向字节数需要图片宽乘以3)
	int win_size = (4- (bmp_w*3)%4)%4;//图片现在宽=横向像素点个数+需求长度
	unsigned int bm_lenth = bmp_w*3+win_size;
	unsigned char* bmpbuf = malloc(bm_lenth*bmp_h*3); //申请内存
	ret = read(bmpfd, bmpbuf, bmp_w*bmp_h*3); //读取像素
	printf("当前显示图片的宽度调整为：%d\n", bm_lenth);
	
	//3.进行bmp图像的像素3字节转化到lcd像素4字节显示
	unsigned int lcdbuf[bmp_w*bmp_h];	//总字节数：bmp_w*bmp_h*4
	for(int j = 0; j < bmp_h; j++) //按像素点转换
	{
		for(int i = 0; i < bmp_w; i++)
		{
			//4字节   1个字节B        1个字节G           1个字节R            1个字节自己补位
			lcdbuf[i+bmp_w*j] = bmpbuf[3*i+0]|(bmpbuf[3*i+1]<<8)|(bmpbuf[3*i+2]<<16)|(0x00<<24);
		}
		//移动像素的位置
		bmpbuf += bm_lenth;
	}
	
	//4.翻转图片（上下翻转）
	for(int j = 0; ((y+bmp_h) <= LCD_HEIGH)&&(j<bmp_h); j++) //遍历高度
	{
		for(int i = 0; ((x+bmp_w) <= LCD_WIDTH)&&(i<bmp_w); i++) //遍历宽度
		{
			//将(i,j)翻转成(i, LCD_HEIGH-1-j)
			lcd_device->mmp[LCD_WIDTH*(j+y)+(i+x)] = lcdbuf[(bmp_h-1-j)*bmp_w+i];
		}
	}
	
	//5.关闭文件描述符
	close(bmpfd);
}

//清空屏幕
void clearLCD(LCD lcd_device, unsigned int color)
{
	//将color填满所有像素点
	for(int i = 0; i < LCD_SIZE/4; i++)
	{
		lcd_device->mmp[i] = color;
	}
}

//显示正方形
void show_square(LCD lcd_device, int x, int y, int lenth, int color)
{
	int x1,y1;
	int off_set;
	for(x1 = x; x1 < x+lenth; x1++)
	{
		for(y1 = y; y1 < y+lenth; y1++)
		{
			off_set = x1+LCD_WIDTH*y1;
			*(lcd_device->mmp+off_set) = color;
		}
	}
}