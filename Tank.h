#pragma once
#include <vector>
#include <time.h>  

extern const int graph_width;
extern const int graph_high;

// 定义四个方向
enum Direction { UP, DOWN, LEFT, RIGHT };

class TankPart {

public:
	virtual void draw(int ,int,Direction) = 0;
	virtual void clear() = 0;
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

class EnemyTank {
	int x, y;            // 敌人的位置
	Direction dir;        // 敌人的方向
	int speed = 2;        // 敌人移动的速度
	bool active = true;   // 敌人是否还活跃
	time_t now = time(NULL); // 敌人创建的时间
	time_t c_time; //

public:
	EnemyTank(int startX, int startY, Direction direction)
		: x(startX), y(startY), dir(direction) {}
	void move();
	void draw();
	bool isHit(Bullet& bullet);
	void destory();
	bool isActive();
};

class Tank{
	
	int x = 255; //坦克的初始坐标x
	int y = 200; //坦克的初始坐标y
	int tank_speed = 5; //坦克的移动速度

	Body body;
	Barrel barrel;

	Direction dir;          // 坦克的方向
	
public:
	std::vector<Bullet> bullets;  // 子弹的容器
	std::vector<EnemyTank> enemies;        // 敌人坦克的容器

	void move(int);
	void attack();
	void draw();
	void clear();
	void updateBullets();  // 更新所有子弹的位置和状态
	void updateEnemies(); 
	void checkCollisions(); // 检测子弹与敌人的碰撞

	Tank() {
		dir = UP;
		// 初始化敌人
		enemies.push_back(EnemyTank(100, 100, DOWN));
		enemies.push_back(EnemyTank(300, 300, UP));
		enemies.push_back(EnemyTank(500, 200, LEFT));
	}
};
