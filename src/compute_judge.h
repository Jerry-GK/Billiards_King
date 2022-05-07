// 支持各种向量运算、求值函数、判断函数
#ifndef _COMPUTE_JUDGE_H
#define _COMPUTE_JUDGE_H
#include "global.h"

// 数学向量运算函数
double getmod(coordinate vec);  // 获得二元向量模长
double getcos(coordinate vec);  // 获得二元向量与水平向右方向夹角（逆时针方向）的余弦值
double getsin(coordinate vec);  // 获得二元向量与水平向右方向夹角（逆时针方向）的正弦值
double b_s_v_distance(ball ball_to_hit);  // 向量运算，求出白球沿杆方向与待击球之间的垂直距离
double b_s_h_distance(ball ball_to_hit);  // 向量运算，求出白球沿杆方向与待击球之间的水平距离
double bb_distance(ball b1, ball b2);  // 返回两球球心之间的距离（以判断是否相碰）

// 判断/求值类型的函数
bool is_allball_still(int start);  // 从编号为start的台球开始判断往后的球是否全部静止，一般start取0或1；
bool is_in_hole(ball b);  // 判断球b是否进洞
bool is_overlap(int id, coordinate pos);  // 判断编号为id的球是否能放置在坐标pos处，用于防止球与球、球与墙的重叠
bool is_target(int m_turn, int id);  // 判断在该模式、该轮次时，id号球是不是击球者的目标球
int get_min_ball();  // 返回在场的编号最小的台球的编号（双人九球模式下确定目标球用）

#endif // ! _COMPUTE_JUDGE_H