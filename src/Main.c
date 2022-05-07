// Billiards_King

#include "libgraphics\extgraph.h"
#include "simpleGUI\imgui.h"
#include "libgraphics\simpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "compute_judge.h"
#include "control.h"
#include "draw.h"
#include "record.h"
#include "global.h"

// 枚举和结构体定义参见global.h

// 固定的全局变量*****************************************************************************************************************************************
coordinate g_table_llc;  // 桌面左下角坐标
coordinate g_ball_0_pos;  // 白球的起始位置
coordinate g_ball_9_pos;  // 双人九球模式下九号球的起始位置
coordinate g_ball_8_pos;  // 双人十六球模式下八号球的起始位置
double g_winwidth;  // 窗口宽度
double g_winheight;  // 窗口高度
double g_table_width;  // 桌面横向宽度
double g_table_height;  // 桌面纵向高度

// 决定游戏进程的全局变量区(文件保存部分）:*****************************************************************************************************************************************************
int g_begin_time;  // 记录开始时间
int g_total_time;  // 记录游戏总时间（不包括暂停时间）
int g_ball_num;  // 球的总数，为10或16
int g_total_round;  // 记录游戏轮数（目前是第几次击球）
int g_prev_if_all_ball_still;  // 判定回合用的临时变量
int g_result;  // 回合结果
int g_score;  // 记录单人模式进球数
int g_single_foul;  // 记录单人简单模式的犯规次数
int g_score_A;  // 记录双人简单模式中A的进球数
int g_score_B;  // 记录双人简单模式中B的进球数
TARGET_BALL g_target_A;  // 十六球模式下AB的目标球代表值，0代表未定，1代表小号球（1~7，单色），2代表大号球（9~15，双色）,3代表可以击打黑8
TARGET_BALL g_target_B;  // 同上
int g_turn;  // 记录当前是谁的回合，-1代表A，1代表B

double g_mouse_x;  // 记录鼠标横坐标
double g_mouse_y;  // 记录鼠标纵坐标

bool g_is_win;  // 记录当前是否有人已经获胜
bool g_free_ball;  // 记录当前轮次的击球方是否可以发自由球
bool g_mouse_out;  // 判断鼠标是否移到窗口之外，与操作纠正有关
bool g_is_pause;  // 判断程序是否暂停
bool g_is_press[4];  // 记录WSDA键是否正在按下

coordinate g_press_pos;  // 记录固定杆时鼠标点击的位置
coordinate g_release_tip;  // 记录松手时杆尖的位置，用来计算击打速度

stick g_mystick;  // 构造球杆

ball g_balls[16];  // 十六个台球的数组，set_balls()中初始化。本程序台球不使用链表存储，因为碰撞等操作经常需要随机读取，不太适合链表存储。

List g_groove_list_A;  // 球槽A链表(单人模式下代表单人的球槽链表）
List g_groove_list_B;  // 球槽B链表
int g_groove_A_len;  // 记录球槽A链表的长度（不包括头节点）
int g_groove_B_len;  // 记录球槽B链表的长度（不包括头节点）

PAGE g_page;  // 界面状态
MODE g_mode;  // 记录当前游戏模式（四种）
EVENT_TIME g_player_event[2];  // 记录双人模式下A和B的上一轮结果和连续犯规数
EVENT_TIME g_single_player_event;  // 记录单人模式下玩家的上一轮结果和连续犯规数


// 主函数******************************************************************************************************************************************88
void Main()
{
	// 设置窗口基本信息
	SetWindowTitle("Billiards_King");
	SetWindowSize(40, 20);
	InitGraphics();
	SetPointSize(15);
	setButtonColors("Brown", "Red", "Cyan", "Red", 0);
	// 设置自定义的颜色
	define_my_colors();
	// 注册响应函数
	registerTimerEvent(display);  // 定时器不断调用display，实现画面刷新
	registerKeyboardEvent(myKeyboardEvent);  //  注册键盘回调函数
	registerMouseEvent(myMouseEvent);  // 注册鼠标回调函数

	// 初始化全局控制变量
	Init_game_data();

	// 初始化固定的全局变量
	g_winwidth = GetWindowWidth();
	g_winheight = GetWindowHeight();
	g_table_width = GetWindowWidth() * TABLE_SIZE;  // 桌子的宽度
	g_table_height = GetWindowHeight() * TABLE_SIZE;  // 桌子的高度
	g_table_llc = (coordinate){ (GetWindowWidth() - g_table_width) / 2, (GetWindowHeight() - g_table_height) / 2 };



	g_ball_0_pos = (coordinate){ 13.5,10 };  // 白球的起始位置
	g_ball_9_pos = (coordinate){ 25,10 };  // 双人九球模式下九号球的起始位置
	g_ball_8_pos = (coordinate){ 25,10 };  // 双人十六球模式下八号球的起始位置

	// 开启定时器
	startTimer(TIMER_GAME, MOVE_DISC);  // 游戏界面定时器，暂停时删除此计时器
	startTimer(TIMER_MENU, MOVE_DISC);  // 菜单计时器，一直存在，只在暂停时启用display里的菜单显示
}
