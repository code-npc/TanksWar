#pragma once

extern const int graph_width;
extern const int graph_high;

// 定义四个方向
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
	int x = 255; //坦克的初始坐标x
	int y = 200; //坦克的初始坐标y
	int dx = 5; //每次 x 的移动距离
	int dy = 3;

	Wheel wheel;//坦克的组成
	Body body;
	int bullet;
	Barrel barrel;
	Direction dir;          // 坦克的方向
	

public:
	void move(int);
	void attack();

	void draw();
	void clear();

	Tank() {
		dir = UP;
	}
};
