#include "Tank.h"
#include <iostream>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>




void Body::draw() {

	// 绘制躯体
	rectangle(x, y - 25, x + 80, y + 25);

	// 更新躯体的位置
	x += dx;
	y += dy;

	// 碰撞检测：让躯体在窗口边界内反弹
	if (x + 110 >= 640 || x <= 0) {
		dx = -dx;  // 反转 x 方向的移动
	}
	if (y + 25 >= 480 || y <= 25) {
		dy = -dy;  // 反转 y 方向的移动
	}
}
void Body::clear() {
}

void Wheel::draw() {
	circle(200, 200, 10);	// 画圆，圆心(200, 200)，半径 100
	circle(200, 250, 10);
	circle(280, 200, 10);
	circle(280, 250, 10);
}
void Wheel::clear() {
}

void Barrel::draw() {

	rectangle(x+80, y-5, x+110, y+5);// 枪管
	// 更新枪管的位置
	x += dx;
	y += dy;
	// 碰撞检测：让躯体在窗口边界内反弹
	if (x + 110 >= 640 || x <= 0) {
		dx = -dx;  // 反转 x 方向的移动
	}
	if (y + 25 >= 480 || y <= 25) {
		dy = -dy;  // 反转 y 方向的移动
	}
}
void Barrel::clear() {

}


void Tank::draw() {

		body.draw(); // 绘制身躯
		wheel.draw(); // 绘制轮子
		barrel.draw(); // 绘制枪管
}

void Tank::move() {
	// 检测键盘输入，控制移动方向
	if (_kbhit()) {  // 如果有键盘输入
		char ch = _getch();  // 获取键盘输入
		switch (ch) {
		case 72:  // 上箭头键（ASCII 72）
			dx = 0;
			dy = -5;  // 向上移动
			break;
		case 80:  // 下箭头键（ASCII 80）
			dx = 0;
			dy = 5;   // 向下移动
			break;
		case 75:  // 左箭头键（ASCII 75）
			dx = -5;
			dy = 0;   // 向左移动
			break;
		case 77:  // 右箭头键（ASCII 77）
			dx = 5;
			dy = 0;   // 向右移动
			break;
		case 27:  // ESC 键（ASCII 27），退出程序
			EndBatchDraw();  // 关闭双缓冲
			closegraph();    // 关闭图形窗口
		}
	}
	
}

void Tank::attack() {
	std::cout << "tank 攻击" << std::endl;
}