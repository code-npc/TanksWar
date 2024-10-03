#include "Tank.h" 
#include <iostream>

#include <graphics.h>		// 引用图形库头文件
#include <conio.h>


int main()
{
	Tank tank;
	initgraph(640, 480); // 创建绘图窗口，大小为 640x480 像素

	// 启动双缓冲绘图
	BeginBatchDraw();

	while (true) { 
		// 清屏，准备绘制新的帧
		cleardevice();

		tank.draw();

		// 刷新屏幕显示
		FlushBatchDraw();

		tank.move();

		// 控制帧率，延迟 15 毫秒
		Sleep(15);
	}


	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}