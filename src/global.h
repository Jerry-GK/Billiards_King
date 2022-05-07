// �ⲿͷ�ļ�������ö�١��ṹ��Ķ��塢�궨�塢Main��ȫ�ֱ����ĵ���
#ifndef _GLOBAL_H
#define _GLOBAL_H

#include "libgraphics\extgraph.h"
#include "simpleGUI\imgui.h"
#include "libgraphics\simpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

// �궨�岿��
#define MOVE_DISC 1  // ʱ��ص����������������Ϸ֡�ʣ����Խ��֡��Խ�ߣ�
#define BUTTONWIDTH 7.5  // ��ť��׼����
#define BUTTONHEIGHT (GetFontHeight()*1.5)  // ��ť��׼�߶�
#define TABLE_SIZE 0.55  // ������Դ�С
#define R (0.6*TABLE_SIZE)  // ̨��뾶
#define L (11*TABLE_SIZE)  // �˵ĳ���
#define STICK_THICKNESS (15*TABLE_SIZE)  // �˵Ĵ�ϸ
#define SLOWING_SPEED (0.0035*TABLE_SIZE)  // �ȼ���ϵ����0.0002~0.0030��
#define HIT_REMAIN_RATIO 0.975  // �ٶ�˥��ϵ���������������ǽ��ײ���ٶ�����ȫ������ײ����ٶȵı���(0.8~1)
#define HIT_STRENGTH 0.125  // �������ȣ�0.05~0.5��
#define HIT_UPBOUND 12.5  //��������,��������15~35
#define ACCURACY_NEED 0.82  // ����ľ�ȷ��Ҫ�󣬱���������0.5~1֮��,��ֵԽ�ߣ�����Խ����
#define HOLE_BALL_RATIO 1.5  // �������ֱ������
#define WIDTH_HEIGHT_RATIO 1.99608501  // ̨�����ĳ�����
#define INDICATOR_LENGTH 2  // ���ֵԽ�ߣ�ָʾ��ָʾ����ԽԶ

// �����������ڿ��ƻغϺͷ����ж�
#define RES_HITANDOUT 1  // ����ɹ�����δ��
#define RES_HITANDIN 2  // ����ɹ������
#define RES_HITORNOT 3  // ������ɣ����һ���ж�
#define RES_NOTHIT 4  // ����ʧ��
#define RES_WHITEBALLIN 5  // �������
#define RES_MISS 6  // �ո�
#define RES_BLACKBALLIN 7  // ��ǰ������ʮ����ģʽ�£�

// ����״��
#define MAT_NULL 0  // ��
#define MAT_COLOREDBALLIN 1  // ������
#define MAT_NOTTAGRETBALL 2  // ���з�Ŀ����
#define MAT_TARGETBALL 3  // ����Ŀ����
#define MAT_WHITEBALLIN 4  // �������
#define MAT_BLACKBALLIN 5  // ��8��ǰ������ʮ����ģʽ�£�

// File�˵�ѡ��
#define FILE_STOP 1  // ��ͣ
#define FILE_STORE 2  // �������
#define FILE_RETURN 3  // ������һ��
#define FILE_EXIT 4  // �˳�

// Help�˵�ѡ��
#define HELP_ABOUT 1  // ���ڱ���Ϸ
#define HELP_RULE 2  // ��Ϸ����
#define HELP_INTRODUCE 3  // �淨˵��

// ö�١��ṹ�嶨�岿��
// ����ģʽö������
typedef enum
{
	SINGLE_EASY = 0,  // ���˼�ģʽ
	DOUBLE_EASY,  // ˫�˼�ģʽ
	DOUBLE_NINE_BALLS,  // ˫�˾���ģʽ
	DOUBLE_SIXTEEN_BALLS  // ˫��ʮ����ģʽ
}MODE;

// �����ʱ��ö������
typedef enum
{
	TIMER_GAME,
	TIMER_MENU
}MYTIMER;

// �����ִν��ö������
typedef enum
{
	PREPARE,  // ��δ���򣬴���׼��״̬��
	WHITE_IN,  // ������
	TARGET_MISS,  // δ���Ȼ���Ŀ����
	EMPTY,  // �ո�
	BALL_IN,  // δ�������в������
	NO_BALL_IN,  // δ���浫û�����
	BLACK_8_IN_ADVANCE  // �ڰ���ǰ������ʮ����ģʽ�£�
}EVENT;

// ����ʮ����ģʽ��Ŀ����ö������
typedef enum
{
	ALLCOLORBALL,  // ���в���
	SMALLBALL,  // С���򣨵�ɫ��1~7�ţ�
	BIGBALL,  // �����˫ɫ��9~15�ţ�
	BLACK_8  // ��ɫ8����
}TARGET_BALL;

// ������Ϸ����ö������
typedef enum
{
	BEGIN,  // ��Ϸ��ʼҳ��
	NEWGAME,  // ׼���½���Ϸ����
	IN_GAME  // ������Ϸ�н���
}PAGE;

// �����Ķ�Ԫ���꣨ coordinate ��ʾ��Ԫ���꣬Ҳ���Ա�ʾ��������
typedef struct _coordinate
{
	double x;
	double y;
}coordinate;

// ����̨��Ľṹ��
typedef struct _ball
{
	int id;  // ���
	bool present;  // �Ƿ��ڳ����Ƿ��Ѿ�����,���ڳ�Ϊ0���ڳ�Ϊ1
	coordinate pos;  // λ������
	string color;  // ��ɫ�ַ���
	coordinate speed;  // �ٶ�����
	int just_hit;  // ��¼��֮�ո�ײ���Ķ�����������Ϊ��ı�ţ���Ϊǽ���ҡ��ϡ��������ζ�Ӧ-1~-4
}ball;

// ����˵Ľṹ��
typedef struct _stick
{
	coordinate tip;  // ��˵Ļ��������
	coordinate tail;  // ��˵�β������
	int if_fixed;  // ����Ƿ��Ѿ�����̶������û���׼����1�����ǣ�0�������ǣ�
}stick;

// ���������һ�ֵĽ��_��������ṹ
typedef struct 
{
  /*��¼A��B��{��һ���¼����ͣ������������}
  ����
  ,0�������򷸹棬
  1��δ����Ŀ���򷸹棨����ģʽ��ָ��С��ʮ����ģʽ��ָ��С�ţ���
  2���ո˷��棬
  3����8��ǰ������ʮ����ģʽ�£���
  4��δ���棬�в�����������ˡ�
  5��δ���棬�޲����������������Ȩ
  ����0~2���ڷ��棬�����ֻ�������(freeball)
  */
	EVENT x;
	int y;
}EVENT_TIME;

// ���������Ľڵ㣬�洢������ı�ţ����ڱ�ʾ���
typedef struct _Node
{
	int id;
	struct _Node* next;
}Node;

// ����������ͷָ�룩
typedef Node* List;

// extern Main�е�ȫ�ֱ���*****************************************************************************************************************************************************
// �̶���ȫ�ֱ���
extern coordinate g_table_llc;  // �������½�����
extern coordinate g_ball_0_pos;  // �������ʼλ��
extern coordinate g_ball_9_pos;  // ˫�˾���ģʽ�¾ź������ʼλ��
extern coordinate g_ball_8_pos;  // ˫��ʮ����ģʽ�°˺������ʼλ��
extern double g_winwidth;  // ���ڿ���
extern double g_winheight;  // ���ڸ߶�
extern double g_table_width;  // ����������
extern double g_table_height;  // ��������߶�

// ������Ϸ���̵�ȫ�ֱ�����(�ļ����沿�֣�:*****************************************************************************************************************************************************
extern int g_begin_time;  // ��¼��ʼʱ��
extern int g_total_time;  // ��¼��Ϸ��ʱ�䣨��������ͣʱ�䣩
extern int g_ball_num;  // ���������Ϊ10��16
extern int g_total_round;  // ��¼��Ϸ������Ŀǰ�ǵڼ��λ���
extern int g_prev_if_all_ball_still;  // �ж��غ��õ���ʱ����
extern int g_result;  // �غϽ��
extern int g_score;  // ��¼����ģʽ������
extern int g_single_foul;  // ��¼���˼�ģʽ�ķ������
extern int g_score_A;  // ��¼˫�˼�ģʽ��A�Ľ�����
extern int g_score_B;  // ��¼˫�˼�ģʽ��B�Ľ�����
extern TARGET_BALL g_target_A;  // ʮ����ģʽ��AB��Ŀ�������ֵ��0����δ����1����С����1~7����ɫ����2���������9~15��˫ɫ��,3�������Ի����8
extern TARGET_BALL g_target_B;  // ͬ��
extern int g_turn;  // ��¼��ǰ��˭�Ļغϣ�-1����A��1����B

extern double g_mouse_x;  // ��¼��������
extern double g_mouse_y;  // ��¼���������

extern bool g_is_win;  // ��¼��ǰ�Ƿ������Ѿ���ʤ
extern bool g_free_ball;  // ��¼��ǰ�ִεĻ����Ƿ���Է�������
extern bool g_mouse_out;  // �ж�����Ƿ��Ƶ�����֮�⣬����������й�
extern bool g_is_pause;  // �жϳ����Ƿ���ͣ
extern bool g_is_press[4];  // ��¼WSDA���Ƿ����ڰ���

extern coordinate g_press_pos;  // ��¼�̶���ʱ�������λ��
extern coordinate g_release_tip;  // ��¼����ʱ�˼��λ�ã�������������ٶ�

extern stick g_mystick;  // �������
extern ball g_balls[16];  // ʮ����̨������飬set_balls()�г�ʼ��
extern List g_groove_list_A;  // ���A����(����ģʽ�´������˵����������
extern List g_groove_list_B;  // ���B����
extern int g_groove_A_len;  // ��¼���A�����ĳ��ȣ�������ͷ�ڵ㣩
extern int g_groove_B_len;  // ��¼���B�����ĳ��ȣ�������ͷ�ڵ㣩

extern PAGE g_page;  // ����״̬
extern MODE g_mode;  // ��¼��ǰ��Ϸģʽ�����֣�
extern EVENT_TIME g_player_event[2];  // ��¼˫��ģʽ��A��B����һ�ֽ��������������
extern EVENT_TIME g_single_player_event;  // ��¼����ģʽ����ҵ���һ�ֽ��������������

#endif // !_GLOBAL_H