// ʵ�ָ��ֻ��ƹ���
#ifndef _DRAW_H
#define _DRAW_H

#include "global.h"
#include "control.h"

void define_my_colors();  // �Զ�����ɫ
void draw_dot_line(double dx, double dy);  // ͬDrawLine��ֻ��������������
void DrawCircle(coordinate centre, double r, string color);  // �������centreΪԲ�ģ�rΪ�뾶����colorΪ��ɫ����Բ�����ջ��ʻص�Բ��λ��
void draw_background();  // ���Ʊ�����ɫͼ
void draw_one_ball(ball d_ball);  // ����һ����
void draw_balls();  // �������е��ڳ���̨��
void draw_table();  // �������ӣ�����ʵ�ֲ���Ҫ��
void draw_stick();  // ���������Ϣ���������
void draw_indicator();  // ��������ָʾ��
void draw_groove();  // ����ʹ�������ʾ�����
void drawBegin();  // �����ʼ��ѡ��ҳ��
void drawNewGame();  // �����½���Ϸ��ѡ��ģʽ��ҳ��
void drawMenu();  // ����Ϸ�У����Ʋ˵�ҳ��
void draw_text();  // ������Ϸ�е��ı�������ʵ�ֲ���Ҫ��
void draw_win_text(int winner);  // ��ʤ�󣬸���������ƻ�ʤ�ߵ��ı�
void display_game();  // ����Ϸ״̬�л�����Ϸ���棬����turn_control
void display(int timerID);  // ʱ��ص����������ݵ�ǰҳ����Ϣ��ʵ�ֻ���ˢ�¡�

#endif // !_DRAW_H