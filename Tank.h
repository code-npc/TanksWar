#pragma once

extern const int graph_width;
extern const int graph_high;

// �����ĸ�����
enum Direction { UP, DOWN, LEFT, RIGHT };

class TankPart {

public:
	virtual void draw(int ,int,Direction) = 0;
	virtual void clear() = 0;
};


class Wheel : TankPart{

public:
	void draw(int ,int, Direction) override;
	void clear() override;
};

class Body : TankPart{
public:
	void draw(int ,int, Direction) override;
	void clear() override;
};

class Barrel : TankPart{
public:
	void draw(int ,int, Direction) override;
	void clear() override;
};

class Bullet {
public:
	int b_x;         // �ӵ���x����
	int b_y;         // �ӵ���y����
	int bullet_speed = 10; // �ӵ����ƶ��ٶ�
	bool active = false; // �ӵ��Ƿ����ƶ�
	Direction dir; // �ӵ��ķ���

	Bullet() : b_x(0), b_y(0), dir(UP) {}  // Ĭ�Ϲ��캯��
	void fire(int startX, int startY, Direction direction);

	void draw();
	void move();//�ӵ��ƶ�
	
};

class Tank{
	
	int x = 255; //̹�˵ĳ�ʼ����x
	int y = 200; //̹�˵ĳ�ʼ����y
	int tank_speed = 5; //̹�˵��ƶ��ٶ�

	Wheel wheel;//̹�˵����
	Body body;
	Barrel barrel;

	Direction dir;          // ̹�˵ķ���
	
public:
	Bullet bullet;
	void move(int);
	void attack();
	void draw();
	void clear();

	Tank() {
		dir = UP;
	}
};
