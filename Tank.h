#pragma once
class Pos {
public:
	int x=200; //̹�˵ĳ�ʼ����x
	int y=200; //̹�˵ĳ�ʼ����y
	int dx=5; // ÿ֡ x �����ƶ���������
	int dy=3; // ÿ֡ y �����ƶ���������

};

class TankPart {

public:
	virtual void draw() = 0;
	virtual void clear() = 0;
};


class Wheel : TankPart,Pos {

public:
	void draw() override;
	void clear() override;
};

class Body : TankPart,Pos {
public:
	void draw() override;
	void clear() override;
};

class Barrel : TankPart,Pos {
public:
	void draw() override;
	void clear() override;
};

class Tank : Pos{
	//̹�˵����
	//Wheel wheel[2];
	Wheel wheel;
	Body body;
	int bullet;
	Barrel barrel;
	

public:
	
	// ����һЩ����
	/*int getX() { return x; }
	int getY() { return y; }
	int getDx() { return dx; }
	int getDy() { return dy; }
	*/
	void move();
	void attack();

	void draw();
	void clear();
};

