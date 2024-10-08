#pragma once
#include <vector>

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

class Bullet {
public:
	int b_x;         // 子弹的x坐标
	int b_y;         // 子弹的y坐标
	int bullet_speed = 10; // 子弹的移动速度
	bool active = false; // 子弹是否在移动
	Direction dir; // 子弹的方向

	Bullet() : b_x(0), b_y(0), dir(UP) {}  // 默认构造函数
	Bullet(int x, int y , Direction d) {
		b_x = x; 
		b_y = y;
		dir = d;
	} 
	void fire();
	void draw() const;
	void move();//子弹移动
	bool isActive() const;
	
};

class Tank{
	
	int x = 255; //坦克的初始坐标x
	int y = 200; //坦克的初始坐标y
	int tank_speed = 5; //坦克的移动速度

	Wheel wheel;//坦克的组成
	Body body;
	Barrel barrel;

	Direction dir;          // 坦克的方向
	
public:
	std::vector<Bullet> bullets;  // 子弹的容器

	void move(int);
	void attack();
	void draw();
	void clear();
	void updateBullets();  // 更新所有子弹的位置和状态

	Tank() {
		dir = UP;
	}
};
