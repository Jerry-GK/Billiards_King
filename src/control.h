#ifndef _CONTROL_H
#define _CONTROL_H

// ������Ϸ���̵ĸ��ֺ���

#include "global.h"
#include "compute_judge.h"

void set_balls();  // ����ģʽ��������ڳ�ʼλ����
void Init_game_data();  // ����������Ϸ�е�����
void event_control(EVENT eve);  // �غϽ��������������turn_control���ִν����Ϣ
void turn_control(int matter);  // ���ƻغ��ִε���Ϣ���������
void if_win();  // �жϻغϽ���ʱ�Ƿ����˻�ʤ�����У�����win_and_pause
void win_and_pause();  // ��ʤ����ͣ��Ϸ
void balls_hit(ball* b1, ball* b2);  // ģ��������ȫ������ײ�Ĺ��̣��������ķ�����ٶ�,�ٶ��ٳ���˥��ϵ���������¼���turn_control
void edge_hit(ball* b);  // ģ������ǽ��ȫ������ײ�Ĺ���,�ٶ��ٳ���˥��ϵ���������¼���turn_control
void move_ball();  // ��ʱ���������ı����λ�ã������ƶ��������ƽ���
void correct_pos();  // ��һ���ִν������������ص����������ǵ�λ�á���Ҫ�����������λ�þ�����bug��Ԥ��
void myMouseEvent(int x, int y, int button, int event);  // ���ص����������ƻ��򡢰�ť��
void myKeyboardEvent(int key, int event);  // ���̻ص�������������������ƶ�
void delete_list(List head);  // ɾ������

#endif // !_CONTROL_H