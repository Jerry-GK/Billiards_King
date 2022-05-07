// 实现各种绘制功能
#ifndef _DRAW_H
#define _DRAW_H

#include "global.h"
#include "control.h"

void define_my_colors();  // 自定义颜色
void draw_dot_line(double dx, double dy);  // 同DrawLine，只不过画的是虚线
void DrawCircle(coordinate centre, double r, string color);  // 以坐标点centre为圆心，r为半径，以color为颜色，画圆，最终画笔回到圆心位置
void draw_background();  // 绘制背景颜色图
void draw_one_ball(ball d_ball);  // 画出一个球
void draw_balls();  // 画出所有的在场的台球
void draw_table();  // 画出桌子（具体实现不重要）
void draw_stick();  // 根据鼠标信息，画出球杆
void draw_indicator();  // 画出击球指示器
void draw_groove();  // 画出使用链表表示的球槽
void drawBegin();  // 绘制最开始的选择页面
void drawNewGame();  // 绘制新建游戏中选择模式的页面
void drawMenu();  // 在游戏中，绘制菜单页面
void draw_text();  // 绘制游戏中的文本（具体实现不重要）
void draw_win_text(int winner);  // 获胜后，根据情况绘制获胜者的文本
void display_game();  // 在游戏状态中绘制游戏画面，调用turn_control
void display(int timerID);  // 时间回调函数，根据当前页面信息，实现画面刷新。

#endif // !_DRAW_H