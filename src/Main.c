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

// ö�ٺͽṹ�嶨��μ�global.h

// �̶���ȫ�ֱ���*****************************************************************************************************************************************
coordinate g_table_llc;  // �������½�����
coordinate g_ball_0_pos;  // �������ʼλ��
coordinate g_ball_9_pos;  // ˫�˾���ģʽ�¾ź������ʼλ��
coordinate g_ball_8_pos;  // ˫��ʮ����ģʽ�°˺������ʼλ��
double g_winwidth;  // ���ڿ��
double g_winheight;  // ���ڸ߶�
double g_table_width;  // ���������
double g_table_height;  // ��������߶�

// ������Ϸ���̵�ȫ�ֱ�����(�ļ����沿�֣�:*****************************************************************************************************************************************************
int g_begin_time;  // ��¼��ʼʱ��
int g_total_time;  // ��¼��Ϸ��ʱ�䣨��������ͣʱ�䣩
int g_ball_num;  // ���������Ϊ10��16
int g_total_round;  // ��¼��Ϸ������Ŀǰ�ǵڼ��λ���
int g_prev_if_all_ball_still;  // �ж��غ��õ���ʱ����
int g_result;  // �غϽ��
int g_score;  // ��¼����ģʽ������
int g_single_foul;  // ��¼���˼�ģʽ�ķ������
int g_score_A;  // ��¼˫�˼�ģʽ��A�Ľ�����
int g_score_B;  // ��¼˫�˼�ģʽ��B�Ľ�����
TARGET_BALL g_target_A;  // ʮ����ģʽ��AB��Ŀ�������ֵ��0����δ����1����С����1~7����ɫ����2��������9~15��˫ɫ��,3������Ի����8
TARGET_BALL g_target_B;  // ͬ��
int g_turn;  // ��¼��ǰ��˭�Ļغϣ�-1����A��1����B

double g_mouse_x;  // ��¼��������
double g_mouse_y;  // ��¼���������

bool g_is_win;  // ��¼��ǰ�Ƿ������Ѿ���ʤ
bool g_free_ball;  // ��¼��ǰ�ִεĻ����Ƿ���Է�������
bool g_mouse_out;  // �ж�����Ƿ��Ƶ�����֮�⣬����������й�
bool g_is_pause;  // �жϳ����Ƿ���ͣ
bool g_is_press[4];  // ��¼WSDA���Ƿ����ڰ���

coordinate g_press_pos;  // ��¼�̶���ʱ�������λ��
coordinate g_release_tip;  // ��¼����ʱ�˼��λ�ã�������������ٶ�

stick g_mystick;  // �������

ball g_balls[16];  // ʮ����̨������飬set_balls()�г�ʼ����������̨��ʹ������洢����Ϊ��ײ�Ȳ���������Ҫ�����ȡ����̫�ʺ�����洢��

List g_groove_list_A;  // ���A����(����ģʽ�´����˵��������
List g_groove_list_B;  // ���B����
int g_groove_A_len;  // ��¼���A����ĳ��ȣ�������ͷ�ڵ㣩
int g_groove_B_len;  // ��¼���B����ĳ��ȣ�������ͷ�ڵ㣩

PAGE g_page;  // ����״̬
MODE g_mode;  // ��¼��ǰ��Ϸģʽ�����֣�
EVENT_TIME g_player_event[2];  // ��¼˫��ģʽ��A��B����һ�ֽ��������������
EVENT_TIME g_single_player_event;  // ��¼����ģʽ����ҵ���һ�ֽ��������������


// ������******************************************************************************************************************************************88
void Main()
{
	// ���ô��ڻ�����Ϣ
	SetWindowTitle("Billiards_King");
	SetWindowSize(40, 20);
	InitGraphics();
	SetPointSize(15);
	setButtonColors("Brown", "Red", "Cyan", "Red", 0);
	// �����Զ������ɫ
	define_my_colors();
	// ע����Ӧ����
	registerTimerEvent(display);  // ��ʱ�����ϵ���display��ʵ�ֻ���ˢ��
	registerKeyboardEvent(myKeyboardEvent);  //  ע����̻ص�����
	registerMouseEvent(myMouseEvent);  // ע�����ص�����

	// ��ʼ��ȫ�ֿ��Ʊ���
	Init_game_data();

	// ��ʼ���̶���ȫ�ֱ���
	g_winwidth = GetWindowWidth();
	g_winheight = GetWindowHeight();
	g_table_width = GetWindowWidth() * TABLE_SIZE;  // ���ӵĿ��
	g_table_height = GetWindowHeight() * TABLE_SIZE;  // ���ӵĸ߶�
	g_table_llc = (coordinate){ (GetWindowWidth() - g_table_width) / 2, (GetWindowHeight() - g_table_height) / 2 };



	g_ball_0_pos = (coordinate){ 13.5,10 };  // �������ʼλ��
	g_ball_9_pos = (coordinate){ 25,10 };  // ˫�˾���ģʽ�¾ź������ʼλ��
	g_ball_8_pos = (coordinate){ 25,10 };  // ˫��ʮ����ģʽ�°˺������ʼλ��

	// ������ʱ��
	startTimer(TIMER_GAME, MOVE_DISC);  // ��Ϸ���涨ʱ������ͣʱɾ���˼�ʱ��
	startTimer(TIMER_MENU, MOVE_DISC);  // �˵���ʱ����һֱ���ڣ�ֻ����ͣʱ����display��Ĳ˵���ʾ
}
