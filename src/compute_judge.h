// ֧�ָ����������㡢��ֵ�������жϺ���
#ifndef _COMPUTE_JUDGE_H
#define _COMPUTE_JUDGE_H
#include "global.h"

// ��ѧ�������㺯��
double getmod(coordinate vec);  // ��ö�Ԫ����ģ��
double getcos(coordinate vec);  // ��ö�Ԫ������ˮƽ���ҷ���нǣ���ʱ�뷽�򣩵�����ֵ
double getsin(coordinate vec);  // ��ö�Ԫ������ˮƽ���ҷ���нǣ���ʱ�뷽�򣩵�����ֵ
double b_s_v_distance(ball ball_to_hit);  // �������㣬��������ظ˷����������֮��Ĵ�ֱ����
double b_s_h_distance(ball ball_to_hit);  // �������㣬��������ظ˷����������֮���ˮƽ����
double bb_distance(ball b1, ball b2);  // ������������֮��ľ��루���ж��Ƿ�������

// �ж�/��ֵ���͵ĺ���
bool is_allball_still(int start);  // �ӱ��Ϊstart��̨��ʼ�ж���������Ƿ�ȫ����ֹ��һ��startȡ0��1��
bool is_in_hole(ball b);  // �ж���b�Ƿ����
bool is_overlap(int id, coordinate pos);  // �жϱ��Ϊid�����Ƿ��ܷ���������pos�������ڷ�ֹ����������ǽ���ص�
bool is_target(int m_turn, int id);  // �ж��ڸ�ģʽ�����ִ�ʱ��id�����ǲ��ǻ����ߵ�Ŀ����
int get_min_ball();  // �����ڳ��ı����С��̨��ı�ţ�˫�˾���ģʽ��ȷ��Ŀ�����ã�

#endif // ! _COMPUTE_JUDGE_H