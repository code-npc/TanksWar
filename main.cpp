#include "Tank.h" 
#include <iostream>

#include <graphics.h>
#include <conio.h>

int main()
{
	
	Tank tank;
	initgraph(graph_width, graph_high); // ������ͼ���ڣ���СΪ 640x480 ����

	// ����˫�����ͼ
	BeginBatchDraw();

	while (true) { 
		// ������׼�������µ�֡
		cleardevice();

		// ���������룬�����ƶ�����
		if (_kbhit()) {  // ����м�������
			char ch = _getch();  // ��ȡ��������
			switch (ch) {
			case 72:  // �ϼ�ͷ����ASCII 72��
				tank.move(0);
				break;
			case 80:  // �¼�ͷ����ASCII 80��
				tank.move(1);
				break;
			case 75:  // ���ͷ����ASCII 75��
				tank.move(2);
				break;
			case 77:  // �Ҽ�ͷ����ASCII 77��
				tank.move(3);
				break;
			case 32:  // �ո�������ӵ�
				tank.attack();
				break;
			case 27:  // ESC ����ASCII 27�����˳�����
				return 0;
			}
		}
		// ����̹�ˡ��ӵ��͵���
		tank.updateBullets();
		tank.updateEnemies();
		tank.checkCollisions();
		tank.draw();
		// ˢ����Ļ��ʾ
		FlushBatchDraw();
		// ����֡�ʣ��ӳ� 15 ����
		Sleep(15);
	}

	return 0;
}