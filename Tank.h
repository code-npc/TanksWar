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

class Tank{
	int x = 255; //̹�˵ĳ�ʼ����x
	int y = 200; //̹�˵ĳ�ʼ����y
	int dx = 5; //ÿ�� x ���ƶ�����
	int dy = 3;

	Wheel wheel;//̹�˵����
	Body body;
	int bullet;
	Barrel barrel;
	Direction dir;          // ̹�˵ķ���
	

public:
	void move(int);
	void attack();

	void draw();
	void clear();

	Tank() {
		dir = UP;
	}
};
