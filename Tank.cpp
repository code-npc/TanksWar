#include "Tank.h"
#include <iostream>
#include <graphics.h>		
#include <conio.h>
/*
*	̹�������С��110 * 50
*	���ڴ�С��640 * 480
*/
const int graph_width = 640;
const int graph_high = 480;

int tank_high = 50;
int tank_width = 110;

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

void Bullet::draw() const {
	if (active) {
		rectangle(b_x - 2, b_y - 2, b_x + 2, b_y + 2);  // ����һ��С��������ʾ�ӵ�
	}
}

bool Bullet::isActive() const {
		return active;
}

void Bullet::fire() {
	active = true;
}

void Bullet::move() {
	if (!active) return;

	switch (dir) {
	case UP: b_y -= bullet_speed; break;
	case DOWN: b_y += bullet_speed; break;
	case LEFT: b_x -= bullet_speed; break;
	case RIGHT: b_x += bullet_speed; break;
	}

	// ����ӵ�������Ļ��Χ��������Ϊ�ǻ״̬
	if (b_x < 0 || b_x > 640 || b_y < 0 || b_y > 480) {
		active = false;
	}
}

void Tank::updateBullets() {
	// ���������ӵ���״̬
	for (auto& bullet : bullets) {
		bullet.move();
	}

	// �Ƴ��Ѿ�������Ļ���ӵ�
	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(), [](Bullet& b) { return !b.isActive(); }),
		bullets.end()
	);
}

void Tank::draw() {
	body.draw(x,y,dir);
	barrel.draw(x,y,dir);
	//bullet.draw();  // �����ӵ���������ڣ�

	// ����������Ч���ӵ�
	for (auto& bullet : bullets) {
		bullet.draw();
		
	}
}

void Tank::move(int direction) {
	switch (direction) {
	case 0:
		dir = UP;  // �ı䷽��Ϊ����
		if (y > tank_width/2) {
			y -= tank_speed;   // �����ƶ�
			break;
		}
	case 1:
		dir = DOWN;  // �ı䷽��Ϊ����
		if (y < graph_high - (tank_width / 2)) {
			y += tank_speed;   // �����ƶ�
			break;
		}
	case 2:
		dir = LEFT;  // �ı䷽��Ϊ����
		if (x > tank_width/2) {
			x -= tank_speed;   // �����ƶ�
			break;
		}
	case 3:
		dir = RIGHT;  // �ı䷽��Ϊ����
		if (x < graph_width - (tank_width/2)) {
			x += tank_speed;   // �����ƶ�
			break;
		}
		
	}
}

void Tank::attack() {
	// ����̹�˵ķ������ӵ�
	int bulletStartX = x;
	int bulletStartY = y;

	switch (dir) {
	case UP:    bulletStartY -= 55; break;
	case DOWN:  bulletStartY += 55; break;
	case LEFT:  bulletStartX -= 55; break;
	case RIGHT: bulletStartX += 55; break;
	}
	
	// �����µ��ӵ�����ӵ�������
	bullets.emplace_back(Bullet(bulletStartX, bulletStartY, dir));
	for (auto& bullet : bullets) {
		bullet.fire();  // �����ӵ�
	}
}