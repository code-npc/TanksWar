#include "Tank.h"
#include <iostream>
#include <graphics.h>		
#include <conio.h>
/*
*	坦克整体大小：110 * 50
*	窗口大小：640 * 480
*/
const int graph_width = 640;//640
const int graph_high = 480; //480

int tank_high = 50;
int tank_width = 110;

void Body::draw(int x,int y,Direction dir) {
    switch (dir) {
    case UP:
        // 绘制躯体
        rectangle(x-25, y - 25, x + 25, y + 55);
        break;
    case DOWN:
        // 绘制躯体
        rectangle(x - 25, y - 55, x + 25, y + 25);
        break;
    case LEFT:
        // 绘制躯体
        rectangle(x - 25, y - 25, x + 55, y + 25);
        break;
    case RIGHT:
        // 绘制躯体
        rectangle(x - 55, y - 25, x + 25, y + 25);
        break;
    }
}
void Body::clear() {
}


void Barrel::draw(int x ,int y,Direction dir) {
    switch (dir) {
    case UP:
        rectangle(x - 5, y - 55, x + 5, y - 25);// 枪管

        break;
    case DOWN:
        rectangle(x - 5, y + 25, x + 5, y + 55);// 枪管

        break;
    case LEFT:
        rectangle(x - 55, y - 5, x - 25, y + 5);// 枪管

        break;
    case RIGHT:
        rectangle(x + 25, y - 5, x + 55, y + 5);// 枪管

        break;
    }

    
}
void Barrel::clear() {

}

void Bullet::draw() const {
    if (active) {
        rectangle(b_x - 2, b_y - 2, b_x + 2, b_y + 2);  // 画出一个小矩形来表示子弹
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

    // 如果子弹超出屏幕范围，将其设为非活动状态
    if (b_x < 0 || b_x > graph_width || b_y < 0 || b_y > graph_high) {
        active = false;
    }
}

void Tank::updateBullets() {
    // 更新所有子弹的状态
    for (auto& bullet : bullets) {
        bullet.move();
    }

    // 移除已经超出屏幕的子弹
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(), [](Bullet& b) { return !b.isActive(); }),
        bullets.end()
    );
}

void Tank::updateEnemies() {
    // 更新敌人的状态
    for (auto& enemy : Tank::enemies) {
        enemy.move();
    }

    // 移除已被摧毁的敌人
    Tank::enemies.erase(
        std::remove_if(Tank::enemies.begin(), Tank::enemies.end(), [](EnemyTank& e) { return !e.isActive(); }),
        Tank::enemies.end()
    );
}

void Tank::checkCollisions() {
    // 检查每个子弹是否打中敌人
    for (auto& bullet : bullets) {
        for (auto& enemy : enemies) {
            if (enemy.isActive() && enemy.isHit(bullet)) {
                enemy.destory();  // 敌人被摧毁
                bullet.active = false;  // 子弹也失效
            }
        }
    }
}

void Tank::draw() {
    body.draw(x,y,dir);
    barrel.draw(x,y,dir);
    //bullet.draw();  // 绘制子弹（如果存在）

    // 绘制所有有效的子弹
    for (auto& bullet : bullets) {
        bullet.draw();
    }

    // 绘制所有活跃的敌人
    for (auto& enemy : enemies) {
        enemy.draw();
    }
}

void Tank::move(int direction) {
    switch (direction) {
    case UP:
        if (y > tank_width/2) {
            y -= tank_speed;   // 向上移动
            break;
        }
    case DOWN:
        if (y < graph_high - (tank_width / 2)) {
            y += tank_speed;   // 向下移动
            break;
        }
    case LEFT:
        if (x > tank_width/2) {
            x -= tank_speed;   // 向左移动
            break;
        }
    case RIGHT:
        if (x < graph_width - (tank_width / 2)) {
            x += tank_speed;   // 向右移动
            break;
        }
        
    }
    dir = static_cast<decltype(dir)>(direction);
}

void Tank::attack() {
    // 根据坦克的方向发射子弹
    int bulletStartX = x;
    int bulletStartY = y;

    switch (dir) {
    case UP:    bulletStartY -= 55; break;
    case DOWN:  bulletStartY += 55; break;
    case LEFT:  bulletStartX -= 55; break;
    case RIGHT: bulletStartX += 55; break;
    }
    
    // 发射新的子弹，添加到容器中
    bullets.emplace_back(Bullet(bulletStartX, bulletStartY, dir));
    for (auto& bullet : bullets) {
        bullet.fire();  // 发射子弹
    }
}


void EnemyTank::move()
{
    // 根据方向移动
    c_time = time(NULL);

    switch (dir) {
    case UP: 
        y -= speed;
        if (y < 25) {
            dir = (Direction)(rand() % 4); // 随机改变方向
        }
        else if (difftime(c_time, now) > 2) {
            now = time(NULL);
            dir = (Direction)(rand() % 4); 
        }
        break;
    case DOWN:
        y += speed;
        if (y > graph_high-25) {
            dir = (Direction)(rand() % 4); // 随机改变方向
        }
        else if (difftime(c_time, now) > 2) {
            now = time(NULL);
            dir = (Direction)(rand() % 4);
        }
        break;
    case LEFT:
        x -= speed;
        if (x < 25) {
            dir = (Direction)(rand() % 4); // 随机改变方向
        }
        else if (difftime(c_time, now) > 2) {
            now = time(NULL);
            dir = (Direction)(rand() % 4);
        }
        
        break;
    case RIGHT:
        x += speed;
        if (x > graph_width-25) {
            dir = (Direction)(rand() % 4); // 随机改变方向
        }
        else if (difftime(c_time, now) > 2) {
            now = time(NULL);
            dir = (Direction)(rand() % 4);
        }
        break;
    }
}

void EnemyTank::draw()
{
    if (active) {
        // 绘制敌人坦克 (可自定义样式)
        rectangle(x - 25, y - 25, x + 25, y + 25);
    }
}

bool EnemyTank::isHit(Bullet& bullet)
{
    // 碰撞检测：如果子弹打中敌人
    return (bullet.b_x > x - 25 && bullet.b_x < x + 25 &&
        bullet.b_y > y - 25 && bullet.b_y < y + 25);
}

void EnemyTank::destory()
{
    active = false;  // 敌人被摧毁
}

bool EnemyTank::isActive()
{
    return active;
}
