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

		// 检测键盘输入，控制移动方向
		if (_kbhit()) {  // 如果有键盘输入
			char ch = _getch();  // 获取键盘输入
			switch (ch) {
			case 72:  // 上箭头键（ASCII 72）
				tank.move(0);
				break;
			case 80:  // 下箭头键（ASCII 80）
				tank.move(1);
				break;
			case 75:  // 左箭头键（ASCII 75）
				tank.move(2);
				break;
			case 77:  // 右箭头键（ASCII 77）
				tank.move(3);
				break;
			case 27:  // ESC 键（ASCII 27），退出程序
				return 0;
			}
		}
		tank.draw();
		// 刷新屏幕显示
		FlushBatchDraw();
		// 控制帧率，延迟 15 毫秒
		Sleep(15);
	}

	return 0;
}