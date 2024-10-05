#include "Tank.h"
#include <iostream>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
/*
*	̹�������С��110 * 50
*	���ڴ�С��640 * 480
*/



void Body::draw(int x,int y,Direction dir) {
	switch (dir) {
	case UP:
		// ��������
		rectangle(x-25, y - 25, x + 25, y + 55);
		break;
	case DOWN:
		// ��������
		rectangle(x - 25, y - 55, x + 25, y + 25);
		break;
	case LEFT:
		// ��������
		rectangle(x - 25, y - 25, x + 55, y + 25);
		break;
	case RIGHT:
		// ��������
		rectangle(x - 55, y - 25, x + 25, y + 25);
		break;
	}
}
void Body::clear() {
}

void Wheel::draw(int ,int,Direction) {
	//circle(200, 200, 10);	// ��Բ��Բ��(200, 200)���뾶 100
	//circle(200, 250, 10);
	//circle(280, 200, 10);
	//circle(280, 250, 10);
}
void Wheel::clear() {
}

void Barrel::draw(int x ,int y,Direction dir) {
	switch (dir) {
	case UP:
		rectangle(x - 5, y - 55, x + 5, y - 25);// ǹ��

		break;
	case DOWN:
		rectangle(x - 5, y + 25, x + 5, y + 55);// ǹ��

		break;
	case LEFT:
		rectangle(x - 55, y - 5, x - 25, y + 5);// ǹ��

		break;
	case RIGHT:
		rectangle(x + 25, y - 5, x + 55, y + 5);// ǹ��

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
		dir = UP;  // �ı䷽��Ϊ����
		if (y > 55) {
			y -= 5;   // �����ƶ�
			break;
		}
	case 1:
		dir = DOWN;  // �ı䷽��Ϊ����
		if (y < 425) {
			y += 5;   // �����ƶ�
			break;
		}
	case 2:
		dir = LEFT;  // �ı䷽��Ϊ����
		if (x > 55) {
			x -= 3;   // �����ƶ�
			break;
		}
	case 3:
		dir = RIGHT;  // �ı䷽��Ϊ����
		if (x < 585) {
			x += 3;   // �����ƶ�
			break;
		}
		
	}
}

void Tank::attack() {
	std::cout << "tank ����" << std::endl;
}