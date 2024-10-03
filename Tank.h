#pragma once
class Pos {
public:
	int x=200; //坦克的初始坐标x
	int y=200; //坦克的初始坐标y
	int dx=5; // 每帧 x 方向移动的像素数
	int dy=3; // 每帧 y 方向移动的像素数

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
	//坦克的组成
	//Wheel wheel[2];
	Wheel wheel;
	Body body;
	int bullet;
	Barrel barrel;
	

public:
	
	// 定义一些方法
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

