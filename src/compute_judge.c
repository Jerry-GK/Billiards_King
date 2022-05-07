#include "compute_judge.h"

// 数学向量运算
double getmod(coordinate vec)  // 获得二元向量模长
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

double getcos(coordinate vec)  // 获得二元向量与水平向右方向夹角（逆时针方向）的余弦值
{
	return vec.x / getmod(vec);
}

double getsin(coordinate vec)  // 获得二元向量与水平向右方向夹角（逆时针方向）的正弦值
{
	return vec.y / getmod(vec);
}

double b_s_v_distance(ball ball_to_hit)  // 向量运算，求出白球沿杆方向与待击球之间的垂直距离
{
	// 向量运算，求出白球沿杆方向与待击球之间的垂直距离
	coordinate tail_tip_vec = { g_balls[0].pos.x - g_mystick.tail.x,g_balls[0].pos.y - g_mystick.tail.y };  // 杆的方向向量
	coordinate tip_ball_vec = { ball_to_hit.pos.x - g_balls[0].pos.x,ball_to_hit.pos.y - g_balls[0].pos.y };  // 杆尖与待击球之间的向量
	double dot_product = tail_tip_vec.x * tip_ball_vec.x + tail_tip_vec.y * tip_ball_vec.y;  // 两向量的点积
	coordinate proj_vec = { tail_tip_vec.x * dot_product / (getmod(tail_tip_vec) * getmod(tail_tip_vec)),  // 求出杆尖-球向量到杆向量上的投影向量
		tail_tip_vec.y * dot_product / (getmod(tail_tip_vec) * getmod(tail_tip_vec)) };

	return sqrt(getmod(tip_ball_vec) * getmod(tip_ball_vec) - getmod(proj_vec) * getmod(proj_vec));  // 利用勾股定理算出垂直距离
}

double b_s_h_distance(ball ball_to_hit)  // 向量运算，求出白球沿杆方向与待击球之间的水平距离
{
	coordinate tail_tip_vec = { g_balls[0].pos.x - g_mystick.tail.x,g_balls[0].pos.y - g_mystick.tail.y };  // 杆的方向向量
	coordinate tip_ball_vec = { ball_to_hit.pos.x - g_balls[0].pos.x,ball_to_hit.pos.y - g_balls[0].pos.y };  // 杆尖与待击球之间的向量
	coordinate tail_tip_unit_vec = { tail_tip_vec.x / getmod(tail_tip_vec),tail_tip_vec.y / getmod(tail_tip_vec) };  // 杆的方向单位向量

	return tail_tip_unit_vec.x * tip_ball_vec.x + tail_tip_unit_vec.y * tip_ball_vec.y;  // 水平方向的向量
}

double bb_distance(ball b1, ball b2)  // 返回两球球心之间的距离（以判断是否相碰）
{
	return sqrt((b1.pos.x - b2.pos.x) * (b1.pos.x - b2.pos.x) + (b1.pos.y - b2.pos.y) * (b1.pos.y - b2.pos.y));  // 返回两球圆心之间的距离
}

// 判断和求值
bool is_allball_still(int start)  // 从编号为start的台球开始判断往后的球是否全部静止，一般start取0或1；
{
	// 判断哦那个start球开始，是否全部静止
	for (int i = start; i < g_ball_num; i++)
	{
		if (getmod(g_balls[i].speed) != 0)
			return FALSE;
	}
	return TRUE;
}

bool is_in_hole(ball b)  // 判断球b是否进洞
{
	double in_range = ACCURACY_NEED * (R + R * HOLE_BALL_RATIO);  // 若球和洞的圆心距离小于这个阙值，判定为进球
	// 六个洞，依次判定	
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

bool is_overlap(int id, coordinate pos)  // 判断以pos位置能否放自由球，防止自由球与洞口、桌边、其他求重合
{
	ball ball_temp = { -1,1,pos,"White",{0.0,0.0},-5, };  // 暂时球
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

bool is_target(int m_turn, int id) // 判断在该模式、该轮次时，id号球是不是击球者的目标球
{
	if (g_mode == SINGLE_EASY || g_mode == DOUBLE_EASY)
		return TRUE;  // 简单模式任意球都是目标球
	else if (g_mode == DOUBLE_NINE_BALLS)
		return id == get_min_ball();  // 九球模式下编号最小的球是目标球
	else if (g_mode == DOUBLE_SIXTEEN_BALLS)  // 十六球模式下目标球由target决定
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

int get_min_ball()  // 返回在场编号最小的彩球的编号
{
	for (int i = 1; i <= 9; i++)
	{
		if (g_balls[i].present == 1)
			return i;
	}
	return -1;
}