#pragma once
#include <vector>
#include <time.h>  

extern const int graph_width;
extern const int graph_high;

// �����ĸ�����
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
	int b_x;         // �ӵ���x����
	int b_y;         // �ӵ���y����
	int bullet_speed = 10; // �ӵ����ƶ��ٶ�
	bool active = false; // �ӵ��Ƿ����ƶ�
	Direction dir; // �ӵ��ķ���

	Bullet() : b_x(0), b_y(0), dir(UP) {}  // Ĭ�Ϲ��캯��
	Bullet(int x, int y , Direction d) {
		b_x = x; 
		b_y = y;
		dir = d;
	} 
	void fire();
	void draw() const;
	void move();//�ӵ��ƶ�
	bool isActive() const;
	
};

class EnemyTank {
	int x, y;            // ���˵�λ��
	Direction dir;        // ���˵ķ���
	int speed = 2;        // �����ƶ����ٶ�
	bool active = true;   // �����Ƿ񻹻�Ծ
	time_t now = time(NULL); // ���˴�����ʱ��
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
	
	int x = 255; //̹�˵ĳ�ʼ����x
	int y = 200; //̹�˵ĳ�ʼ����y
	int tank_speed = 5; //̹�˵��ƶ��ٶ�

	Body body;
	Barrel barrel;

	Direction dir;          // ̹�˵ķ���
	
public:
	std::vector<Bullet> bullets;  // �ӵ�������
	std::vector<EnemyTank> enemies;        // ����̹�˵�����

	void move(int);
	void attack();
	void draw();
	void clear();
	void updateBullets();  // ���������ӵ���λ�ú�״̬
	void updateEnemies(); 
	void checkCollisions(); // ����ӵ�����˵���ײ

	Tank() {
		dir = UP;
		// ��ʼ������
		enemies.push_back(EnemyTank(100, 100, DOWN));
		enemies.push_back(EnemyTank(300, 300, UP));
		enemies.push_back(EnemyTank(500, 200, LEFT));
	}
};
