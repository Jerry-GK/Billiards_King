#include "compute_judge.h"

// ��ѧ��������
double getmod(coordinate vec)  // ��ö�Ԫ����ģ��
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

double getcos(coordinate vec)  // ��ö�Ԫ������ˮƽ���ҷ���нǣ���ʱ�뷽�򣩵�����ֵ
{
	return vec.x / getmod(vec);
}

double getsin(coordinate vec)  // ��ö�Ԫ������ˮƽ���ҷ���нǣ���ʱ�뷽�򣩵�����ֵ
{
	return vec.y / getmod(vec);
}

double b_s_v_distance(ball ball_to_hit)  // �������㣬��������ظ˷����������֮��Ĵ�ֱ����
{
	// �������㣬��������ظ˷����������֮��Ĵ�ֱ����
	coordinate tail_tip_vec = { g_balls[0].pos.x - g_mystick.tail.x,g_balls[0].pos.y - g_mystick.tail.y };  // �˵ķ�������
	coordinate tip_ball_vec = { ball_to_hit.pos.x - g_balls[0].pos.x,ball_to_hit.pos.y - g_balls[0].pos.y };  // �˼��������֮�������
	double dot_product = tail_tip_vec.x * tip_ball_vec.x + tail_tip_vec.y * tip_ball_vec.y;  // �������ĵ��
	coordinate proj_vec = { tail_tip_vec.x * dot_product / (getmod(tail_tip_vec) * getmod(tail_tip_vec)),  // ����˼�-���������������ϵ�ͶӰ����
		tail_tip_vec.y * dot_product / (getmod(tail_tip_vec) * getmod(tail_tip_vec)) };

	return sqrt(getmod(tip_ball_vec) * getmod(tip_ball_vec) - getmod(proj_vec) * getmod(proj_vec));  // ���ù��ɶ��������ֱ����
}

double b_s_h_distance(ball ball_to_hit)  // �������㣬��������ظ˷����������֮���ˮƽ����
{
	coordinate tail_tip_vec = { g_balls[0].pos.x - g_mystick.tail.x,g_balls[0].pos.y - g_mystick.tail.y };  // �˵ķ�������
	coordinate tip_ball_vec = { ball_to_hit.pos.x - g_balls[0].pos.x,ball_to_hit.pos.y - g_balls[0].pos.y };  // �˼��������֮�������
	coordinate tail_tip_unit_vec = { tail_tip_vec.x / getmod(tail_tip_vec),tail_tip_vec.y / getmod(tail_tip_vec) };  // �˵ķ���λ����

	return tail_tip_unit_vec.x * tip_ball_vec.x + tail_tip_unit_vec.y * tip_ball_vec.y;  // ˮƽ���������
}

double bb_distance(ball b1, ball b2)  // ������������֮��ľ��루���ж��Ƿ�������
{
	return sqrt((b1.pos.x - b2.pos.x) * (b1.pos.x - b2.pos.x) + (b1.pos.y - b2.pos.y) * (b1.pos.y - b2.pos.y));  // ��������Բ��֮��ľ���
}

// �жϺ���ֵ
bool is_allball_still(int start)  // �ӱ��Ϊstart��̨��ʼ�ж���������Ƿ�ȫ����ֹ��һ��startȡ0��1��
{
	// �ж�Ŷ�Ǹ�start��ʼ���Ƿ�ȫ����ֹ
	for (int i = start; i < g_ball_num; i++)
	{
		if (getmod(g_balls[i].speed) != 0)
			return FALSE;
	}
	return TRUE;
}

bool is_in_hole(ball b)  // �ж���b�Ƿ����
{
	double in_range = ACCURACY_NEED * (R + R * HOLE_BALL_RATIO);  // ����Ͷ���Բ�ľ���С�������ֵ���ж�Ϊ����
	// �������������ж�	
	if (getmod((coordinate) { b.pos.x - g_table_llc.x, b.pos.y - g_table_llc.y }) < in_range)
		return TRUE;
	else if (getmod((coordinate) { b.pos.x - (g_table_llc.x + g_table_width / 2), b.pos.y - g_table_llc.y }) < in_range)
		return TRUE;
	else if (getmod((coordinate) { b.pos.x - (g_table_llc.x + g_table_width), b.pos.y - g_table_llc.y }) < in_range)
		return TRUE;
	else if (getmod((coordinate) { b.pos.x - (g_table_llc.x + g_table_width), b.pos.y - (g_table_llc.y + g_table_height) }) < in_range)
		return TRUE;
	else if (getmod((coordinate) {
		b.pos.x - (g_table_llc.x + g_table_width / 2), b.pos.y - (g_table_llc.y + g_table_height)
	}) < in_range)
		return TRUE;
	else if (getmod((coordinate) { b.pos.x - g_table_llc.x, b.pos.y - (g_table_llc.y + g_table_height) }) < in_range)
		return TRUE;
	else
		return FALSE;
}

bool is_overlap(int id, coordinate pos)  // �ж���posλ���ܷ�������򣬷�ֹ�������붴�ڡ����ߡ��������غ�
{
	ball ball_temp = { -1,1,pos,"White",{0.0,0.0},-5, };  // ��ʱ��
	for (int i = 0; i < g_ball_num; i++)
	{
		if (i != id && getmod((coordinate) { pos.x - g_balls[i].pos.x, pos.y - g_balls[i].pos.y }) < 1.99 * R
			|| pos.x + R > g_table_llc.x + g_table_width || pos.x - R<g_table_llc.x
			|| pos.y + R>g_table_llc.y + g_table_height || pos.y - R < g_table_llc.y
			|| is_in_hole(ball_temp)
			)
			return TRUE;
	}
	return FALSE;
}

bool is_target(int m_turn, int id) // �ж��ڸ�ģʽ�����ִ�ʱ��id�����ǲ��ǻ����ߵ�Ŀ����
{
	if (g_mode == SINGLE_EASY || g_mode == DOUBLE_EASY)
		return TRUE;  // ��ģʽ��������Ŀ����
	else if (g_mode == DOUBLE_NINE_BALLS)
		return id == get_min_ball();  // ����ģʽ�±����С������Ŀ����
	else if (g_mode == DOUBLE_SIXTEEN_BALLS)  // ʮ����ģʽ��Ŀ������target����
	{
		if (m_turn == -1)
		{
			if (g_target_A == ALLCOLORBALL && id != 8 || (g_target_A == SMALLBALL && 1 <= id && id <= 7)
				|| (g_target_A == BIGBALL && 9 <= id && id <= 15) || (g_target_A == BLACK_8 && id == 8))
				return TRUE;
			else
				return FALSE;
		}
		else if (m_turn == 1)
		{
			if (g_target_B == ALLCOLORBALL && id != 8 || (g_target_B == SMALLBALL && 1 <= id && id <= 7)
				|| (g_target_B == BIGBALL && 9 <= id && id <= 15) || (g_target_B == BLACK_8 && id == 8))
				return TRUE;
			else
				return FALSE;
		}
	}
}

int get_min_ball()  // �����ڳ������С�Ĳ���ı��
{
	for (int i = 1; i <= 9; i++)
	{
		if (g_balls[i].present == 1)
			return i;
	}
	return -1;
}