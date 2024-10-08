#include "Tank.h"
#include <iostream>
#include <graphics.h>		
#include <conio.h>
/*
*	坦克整体大小：110 * 50
*	窗口大小：640 * 480
*/
const int graph_width = 640;
const int graph_high = 480;

int tank_high = 50;
int tank_width = 110;

void Body::draw(int x,int y,Direction dir) {
	switch (dir) {
	case UP:
		// 绘制躯体
		rectangle(x-25, y - 25, x + 25, y + 55);
		break;
	case DOWN:
		// 绘制躯体
		rectangle(x - 25, y - 55, x + 25, y + 25);
		break;
	case LEFT:
		// 绘制躯体
		rectangle(x - 25, y - 25, x + 55, y + 25);
		break;
	case RIGHT:
		// 绘制躯体
		rectangle(x - 55, y - 25, x + 25, y + 25);
		break;
	}
}
void Body::clear() {
}

void Wheel::draw(int ,int,Direction) {
	//circle(200, 200, 10);	// 画圆，圆心(200, 200)，半径 100
	//circle(200, 250, 10);
	//circle(280, 200, 10);
	//circle(280, 250, 10);
}
void Wheel::clear() {
}

void Barrel::draw(int x ,int y,Direction dir) {
	switch (dir) {
	case UP:
		rectangle(x - 5, y - 55, x + 5, y - 25);// 枪管

		break;
	case DOWN:
		rectangle(x - 5, y + 25, x + 5, y + 55);// 枪管

		break;
	case LEFT:
		rectangle(x - 55, y - 5, x - 25, y + 5);// 枪管

		break;
	case RIGHT:
		rectangle(x + 25, y - 5, x + 55, y + 5);// 枪管

		break;
	}

	
}
void Barrel::clear() {

}

void Tank::draw() {
	body.draw(x,y,dir);
	barrel.draw(x,y,dir);
}

void Tank::move(int direction) {
	switch (direction) {
	case 0:
		dir = UP;  // 改变方向为向上
		if (y > tank_width/2) {
			y -= dy;   // 向上移动
			break;
		}
	case 1:
		dir = DOWN;  // 改变方向为向下
		if (y < graph_high - (tank_width / 2)) {
			y += dy;   // 向下移动
			break;
		}
	case 2:
		dir = LEFT;  // 改变方向为向左
		if (x > tank_width/2) {
			x -= dx;   // 向左移动
			break;
		}
	case 3:
		dir = RIGHT;  // 改变方向为向右
		if (x < graph_width - (tank_width/2)) {
			x += dx;   // 向右移动
			break;
		}
		
	}
}

void Tank::attack() {
	std::cout << "tank 攻击" << std::endl;
}