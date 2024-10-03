#include "Tank.h"
#include <iostream>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>




void Body::draw() {

	// ��������
	rectangle(x, y - 25, x + 80, y + 25);

	// ���������λ��
	x += dx;
	y += dy;

	// ��ײ��⣺�������ڴ��ڱ߽��ڷ���
	if (x + 110 >= 640 || x <= 0) {
		dx = -dx;  // ��ת x ������ƶ�
	}
	if (y + 25 >= 480 || y <= 25) {
		dy = -dy;  // ��ת y ������ƶ�
	}
}
void Body::clear() {
}

void Wheel::draw() {
	circle(200, 200, 10);	// ��Բ��Բ��(200, 200)���뾶 100
	circle(200, 250, 10);
	circle(280, 200, 10);
	circle(280, 250, 10);
}
void Wheel::clear() {
}

void Barrel::draw() {

	rectangle(x+80, y-5, x+110, y+5);// ǹ��
	// ����ǹ�ܵ�λ��
	x += dx;
	y += dy;
	// ��ײ��⣺�������ڴ��ڱ߽��ڷ���
	if (x + 110 >= 640 || x <= 0) {
		dx = -dx;  // ��ת x ������ƶ�
	}
	if (y + 25 >= 480 || y <= 25) {
		dy = -dy;  // ��ת y ������ƶ�
	}
}
void Barrel::clear() {

}


void Tank::draw() {

		body.draw(); // ��������
		wheel.draw(); // ��������
		barrel.draw(); // ����ǹ��
}

void Tank::move() {
	// ���������룬�����ƶ�����
	if (_kbhit()) {  // ����м�������
		char ch = _getch();  // ��ȡ��������
		switch (ch) {
		case 72:  // �ϼ�ͷ����ASCII 72��
			dx = 0;
			dy = -5;  // �����ƶ�
			break;
		case 80:  // �¼�ͷ����ASCII 80��
			dx = 0;
			dy = 5;   // �����ƶ�
			break;
		case 75:  // ���ͷ����ASCII 75��
			dx = -5;
			dy = 0;   // �����ƶ�
			break;
		case 77:  // �Ҽ�ͷ����ASCII 77��
			dx = 5;
			dy = 0;   // �����ƶ�
			break;
		case 27:  // ESC ����ASCII 27�����˳�����
			EndBatchDraw();  // �ر�˫����
			closegraph();    // �ر�ͼ�δ���
		}
	}
	
}

void Tank::attack() {
	std::cout << "tank ����" << std::endl;
}