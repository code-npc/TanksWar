#include "Tank.h" 
#include <iostream>

#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>


int main()
{
	Tank tank;
	initgraph(640, 480); // ������ͼ���ڣ���СΪ 640x480 ����

	// ����˫�����ͼ
	BeginBatchDraw();

	while (true) { 
		// ������׼�������µ�֡
		cleardevice();

		tank.draw();

		// ˢ����Ļ��ʾ
		FlushBatchDraw();

		tank.move();

		// ����֡�ʣ��ӳ� 15 ����
		Sleep(15);
	}


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}