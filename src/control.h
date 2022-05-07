#ifndef _CONTROL_H
#define _CONTROL_H

// 控制游戏进程的各种函数

#include "global.h"
#include "compute_judge.h"

void set_balls();  // 根据模式，将球放在初始位置上
void Init_game_data();  // 重置所有游戏中的数据
void event_control(EVENT eve);  // 回合结果处理，接受来自turn_control的轮次结果信息
void turn_control(int matter);  // 控制回合轮次等信息，给出结果
void if_win();  // 判断回合结束时是否有人获胜，若有，调用win_and_pause
void win_and_pause();  // 获胜，暂停游戏
void balls_hit(ball* b1, ball* b2);  // 模拟两球完全弹性碰撞的过程，交换对心方向的速度,速度再乘以衰减系数，传入事件给turn_control
void edge_hit(ball* b);  // 模拟球与墙完全弹性碰撞的过程,速度再乘以衰减系数，传入事件给turn_control
void move_ball();  // 定时器触发，改变球的位置（控制移动），控制进球
void correct_pos();  // 在一个轮次结束后，若有球重叠，纠正它们的位置。主要用于重置球的位置纠正和bug的预防
void myMouseEvent(int x, int y, int button, int event);  // 鼠标回调函数，控制击球、按钮等
void myKeyboardEvent(int key, int event);  // 键盘回调函数，控制自由球的移动
void delete_list(List head);  // 删除链表

#endif // !_CONTROL_H