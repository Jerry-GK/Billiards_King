#include "control.h"

void set_balls()  // ����ģʽ��������ڳ�ʼλ����
{
	double r = 1.25 * R;  // �ϴ��R����ʼ����ʱ��֮��ļ��Ҫ�Դ�һЩ����ֹ�����ص�������
	// ���ݼ��ι�ϵȷ�������λ��
	if (g_mode == DOUBLE_SIXTEEN_BALLS)
	{
		g_balls[0] = (ball){ 0, 1, g_ball_0_pos, "White", { 0.0,0.0 }, -5, };
		g_balls[1] = (ball){ 1,1,{g_ball_9_pos.x - 2 * r * sqrt(3),g_ball_9_pos.y},"Magenta",{0.00,0.0},-5 };
		g_balls[2] = (ball){ 2,1,{g_ball_9_pos.x - r * sqrt(3),g_ball_9_pos.y + r},"Blue",{0.00,0.0},-5 };
		g_balls[3] = (ball){ 3,1,{g_ball_9_pos.x + r * sqrt(3) ,g_ball_9_pos.y - 3 * r},"Dark Yellow",{0.00,0.0},-5 };
		g_balls[4] = (ball){ 4,1,{g_ball_9_pos.x + r * sqrt(3),g_ball_9_pos.y + r},"Violet",{0.0,0.0} ,-5 };
		g_balls[5] = (ball){ 5,1,{g_ball_9_pos.x + 2 * r * sqrt(3),g_ball_9_pos.y - 2 * r},"Orange",{0.00,0.0} ,-5 };
		g_balls[6] = (ball){ 6,1,{g_ball_9_pos.x + 2 * r * sqrt(3),g_ball_9_pos.y + 2 * r},"Red",{0.00,0.0} ,-5 };
		g_balls[7] = (ball){ 7,1,{g_ball_9_pos.x + 2 * r * sqrt(3),g_ball_9_pos.y + 4 * r},"Brown",{0.00,0.0} ,-5 };
		g_balls[8] = (ball){ 8,1,g_ball_9_pos,"Black",{0.00,0.0} ,-5 };
		g_balls[9] = (ball){ 9,1,{g_ball_9_pos.x - r * sqrt(3),g_ball_9_pos.y - r},"Cyan",{0.00,0.0},-5 };


		g_balls[10] = (ball){ 10, 1, { g_ball_9_pos.x, g_ball_9_pos.y - 2 * r }, "Brown", { 0.0,0.0 }, -5 };
		g_balls[11] = (ball){ 11,1,{g_ball_9_pos.x, g_ball_9_pos.y + 2 * r},"Blue",{0.00,0.0},-5 };
		g_balls[12] = (ball){ 12,1,{g_ball_9_pos.x + r * sqrt(3),g_ball_9_pos.y - r},"Dark Yellow",{0.00,0.0},-5 };
		g_balls[13] = (ball){ 13,1,{g_ball_9_pos.x + r * sqrt(3),g_ball_9_pos.y + 3 * r},"Violet",{0.00,0.0},-5 };
		g_balls[14] = (ball){ 14,1,{g_ball_9_pos.x + 2 * r * sqrt(3),g_ball_9_pos.y - 4 * r},"Orange",{0.0,0.0} ,-5 };
		g_balls[15] = (ball){ 15,1,{g_ball_9_pos.x + 2 * r * sqrt(3),g_ball_9_pos.y},"Red",{0.00,0.0} ,-5 };
	}
	else
	{
		g_balls[0] = (ball){ 0, 1, g_ball_0_pos, "White", { 0.0,0.0 }, -5, };
		g_balls[1] = (ball){ 1,1,{g_ball_9_pos.x - 2 * r * sqrt(3),g_ball_9_pos.y},"Magenta",{0.00,0.0},-5 };
		g_balls[2] = (ball){ 2,1,{g_ball_9_pos.x - r * sqrt(3),g_ball_9_pos.y + r},"Blue",{0.00,0.0},-5 };
		g_balls[3] = (ball){ 3,1,{g_ball_9_pos.x,g_ball_9_pos.y - 2 * r},"Dark Yellow",{0.00,0.0},-5 };
		g_balls[4] = (ball){ 4,1,{g_ball_9_pos.x,g_ball_9_pos.y + 2 * r},"Violet",{0.0,0.0} ,-5 };
		g_balls[5] = (ball){ 5,1,{g_ball_9_pos.x + 2 * r * sqrt(3),g_ball_9_pos.y},"Orange",{0.00,0.0} ,-5 };
		g_balls[6] = (ball){ 6,1,{g_ball_9_pos.x - r * sqrt(3),g_ball_9_pos.y - r},"Red",{0.00,0.0} ,-5 };
		g_balls[7] = (ball){ 7,1,{g_ball_9_pos.x + r * sqrt(3),g_ball_9_pos.y + r},"Brown",{0.00,0.0} ,-5 };
		g_balls[8] = (ball){ 8,1,{g_ball_9_pos.x + r * sqrt(3),g_ball_9_pos.y - r},"Black",{0.00,0.0} ,-5 };
		g_balls[9] = (ball){ 9,1,g_ball_9_pos,"Cyan",{0.00,0.0},-5 };

		g_balls[10] = (ball){ 10, 0, { 10,8 }, "Brown", { 0.0,0.0 }, -5 };
		g_balls[11] = (ball){ 11,0,{11,8},"Blue",{0.00,0.0},-5 };
		g_balls[12] = (ball){ 12,0,{14,8},"Dark Yellow",{0.00,0.0},-5 };
		g_balls[13] = (ball){ 13,0,{16,8},"Violet",{0.00,0.0},-5 };
		g_balls[14] = (ball){ 14,0,{18,8},"Orange",{0.0,0.0} ,-5 };
		g_balls[15] = (ball){ 15,0,{20,8},"Red",{0.00,0.0} ,-5 };
	}

}
 
void Init_game_data()  // ����������Ϸ�е�����
{
	set_balls();  // ��ʼ�����λ��
	g_mystick.tip = g_balls[0].pos;  // ������ʱ��ʱ���ø˼���ĸ�������غ�

	// ��ʼ�������������ͷ�ڵ㣬ͷ�ڵ������������
	delete_list(g_groove_list_A);
	delete_list(g_groove_list_B);
	g_groove_list_A = (Node*)malloc(sizeof(Node));
	g_groove_list_A->id = -1;
	g_groove_list_A->next = NULL;
	g_groove_list_B = (Node*)malloc(sizeof(Node));
	g_groove_list_B->id = -2;
	g_groove_list_B->next = NULL;
	g_groove_A_len = 0;
	g_groove_B_len = 0;

	// ��ʼ������ȫ�ֿ��Ʊ���
	g_begin_time = 0;
	g_total_time = 0;
	g_ball_num = 10;
	g_total_round = 1;
	g_prev_if_all_ball_still = 1;
	g_result = RES_MISS;
	g_score = 0;
	g_single_foul = 0;
	g_score_A = 0;
	g_score_B = 0;
	g_target_A = ALLCOLORBALL;
	g_target_B = ALLCOLORBALL;
	g_turn = -1;

	g_mouse_x = 0;
	g_mouse_y = 0;

	g_is_win = FALSE;
	g_free_ball = TRUE;  // ��һ�ֿ��Է�������
	if (g_mode == SINGLE_EASY)
		g_free_ball = FALSE;
	g_mouse_out = FALSE;
	g_is_pause = FALSE;
	g_is_press[0] = g_is_press[1] = g_is_press[2] = g_is_press[3] = FALSE;

	g_player_event[0] = (EVENT_TIME){ PREPARE,0 };
	g_player_event[1] = (EVENT_TIME){ PREPARE,0 };
	g_single_player_event = (EVENT_TIME){ PREPARE,0 };
}

void event_control(EVENT eve)  // �غϽ��������������turn_control���ִν����Ϣ
{
	// �˺���ÿ���ִν��������

	// ���ݻغϵĽ������¼��ҵ�ʱ������������������Ҫʱ������
	if (eve == BLACK_8_IN_ADVANCE)
	{
		if (g_mode == DOUBLE_SIXTEEN_BALLS)  // ���ж�������ʡ��
		{
			g_player_event[(g_turn + 1) / 2].x = BLACK_8_IN_ADVANCE;
			g_player_event[(g_turn + 1) / 2].y++;
			g_turn *= -1;
			g_free_ball = TRUE;
		}
	}
	else if (eve == WHITE_IN)
	{
		if (g_mode == SINGLE_EASY)
		{
			g_single_player_event.x = WHITE_IN;
			g_single_player_event.y++;
		}
		else
		{
			g_player_event[(g_turn + 1) / 2].x = WHITE_IN;
			g_player_event[(g_turn + 1) / 2].y++;
			g_turn *= -1;
			g_free_ball = TRUE;
		}
	}
	else if (eve == TARGET_MISS)
	{
		g_player_event[(g_turn + 1) / 2].x = TARGET_MISS;
		g_player_event[(g_turn + 1) / 2].y++;
		g_turn *= -1;
		g_free_ball = TRUE;
	}
	else if (eve == EMPTY)
	{
		if (g_mode == SINGLE_EASY)
		{
			g_single_player_event.x = EMPTY;
			g_single_player_event.y++;
		}
		else
		{
			g_player_event[(g_turn + 1) / 2].x = EMPTY;
			g_player_event[(g_turn + 1) / 2].y++;
			g_turn *= -1;
			g_free_ball = TRUE;
		}
	}
	else if (eve == BALL_IN)
	{
		if (g_mode == SINGLE_EASY)
		{
			g_single_player_event.x = BALL_IN;
			g_single_player_event.y = 0;
		}
		else
		{
			g_player_event[(g_turn + 1) / 2].x = BALL_IN;
			g_player_event[(g_turn + 1) / 2].y = 0;;
			g_free_ball = FALSE;
		}
	}
	else if (eve == NO_BALL_IN)
	{
		if (g_mode == SINGLE_EASY)
		{
			g_single_player_event.x = NO_BALL_IN;
			g_single_player_event.y = 0;
		}
		else
		{
			g_player_event[(g_turn + 1) / 2].x = NO_BALL_IN;
			g_player_event[(g_turn + 1) / 2].y = 0;
			g_turn *= -1;
			g_free_ball = FALSE;
		}
	}

	// ����ģʽ�£����浫�������򣬾���λ�������������,�������ɾ������
	if (g_mode == DOUBLE_NINE_BALLS && (eve == WHITE_IN || eve == TARGET_MISS || eve == EMPTY) && g_balls[9].present == 0)
	{
		Node* q;
		for (Node* p = g_groove_list_A; p->next != NULL;)
		{
			if (p->next->id == 9)
			{
				q = p->next;
				p->next = p->next->next;
				free(q);
				g_groove_A_len--;
			}
			else
				p = p->next;
		}
		for (Node* p = g_groove_list_B; p->next != NULL;)
		{
			if (p->next->id == 9)
			{
				q = p->next;
				p->next = p->next->next;
				free(q);
				g_groove_B_len--;
			}
			else
				p = p->next;
		}
		g_balls[9].pos = g_ball_9_pos;
		g_balls[9].present = 1;
		g_balls[9].speed = (coordinate){ 0 ,0 };
		g_balls[9].just_hit = -5;
	}

	// ʮ����ģʽ�£���8��Ŀ���򣬵����������8����8�����������
	if (is_target(-g_turn, 8) && g_mode == DOUBLE_SIXTEEN_BALLS && (eve == WHITE_IN || eve == TARGET_MISS || eve == EMPTY) && g_balls[8].present == 0)
	{
		Node* q;
		for (Node* p = g_groove_list_A; p->next != NULL;)
		{
			if (p->next->id == 8)
			{
				q = p->next;
				p->next = p->next->next;
				free(q);
				g_groove_A_len--;
			}
			else
				p = p->next;
		}
		for (Node* p = g_groove_list_B; p->next != NULL;)
		{
			if (p->next->id == 8)
			{
				q = p->next;
				p->next = p->next->next;
				free(q);
				g_groove_B_len--;
			}
			else
				p = p->next;
		}
		g_balls[8].pos = g_ball_8_pos;
		g_balls[8].present = 1;
		g_balls[8].speed = (coordinate){ 0 ,0 };
		g_balls[8].just_hit = -5;
	}
	g_total_round++;  // ÿ���ִν�����total_round��һ
	correct_pos();  // �غϽ������������Ҫ�������ص����λ��
	// �жϻغϽ������Ƿ��ʤ
	if_win();
}

void turn_control(int matter)  // ���ƻغϺͷ����ж���д���е��
{
	//result��matterȡֵ�ο�global.h�еĺ궨��
	//matter�����ⲿ������¼�
	//result����˺�������event_control�Ļ�����
	while (TRUE)  // ֻ����һ��ѭ����Ϊ�˷���break��
	{
		if (RES_BLACKBALLIN == g_result)
			break;

		if (RES_MISS == g_result)
		{
			if (MAT_BLACKBALLIN == matter)
				g_result = RES_BLACKBALLIN;
			else if (MAT_TARGETBALL == matter)
				g_result = RES_HITANDOUT;
			else if (MAT_NOTTAGRETBALL == matter)
				g_result = RES_NOTHIT;
			else if (MAT_WHITEBALLIN == matter)
				g_result = RES_WHITEBALLIN;
			break;
		}

		if (RES_WHITEBALLIN == g_result)
		{
			if (MAT_BLACKBALLIN == matter)
				g_result = RES_BLACKBALLIN;
			break;
		}

		if (RES_NOTHIT == g_result)
		{
			if (MAT_BLACKBALLIN == matter)
				g_result = RES_BLACKBALLIN;
			else if (MAT_BLACKBALLIN == matter)

				g_result = RES_WHITEBALLIN;
			break;
		}

		if (RES_HITORNOT == g_result)
		{
			if (MAT_BLACKBALLIN == matter)
				g_result = RES_BLACKBALLIN;
			else if (MAT_WHITEBALLIN == matter)
				g_result = RES_WHITEBALLIN;
			else if (MAT_TARGETBALL == matter)
				g_result = RES_HITANDOUT;
			else if (MAT_NOTTAGRETBALL == matter)
				g_result = RES_NOTHIT;
			break;
		}

		if (RES_HITANDIN == g_result)
		{
			if (MAT_BLACKBALLIN == matter)
				g_result = RES_BLACKBALLIN;
			else if (MAT_WHITEBALLIN == matter)
				g_result = RES_WHITEBALLIN;
			break;
		}

		if (RES_HITANDOUT == g_result)
		{
			if (MAT_BLACKBALLIN == matter)
				g_result = RES_BLACKBALLIN;
			else if (MAT_WHITEBALLIN == matter)
				g_result = RES_WHITEBALLIN;
			else if (MAT_COLOREDBALLIN == matter)
				g_result = RES_HITANDIN;
			break;
		}
		break;
	}

	if (g_prev_if_all_ball_still == 0 && is_allball_still(0) == 1)  // ��ʼ�µĻغ�
	{
		if (RES_BLACKBALLIN == g_result)  // ʮ����ģʽ�º�8��ǰ����
			event_control(BLACK_8_IN_ADVANCE);
		if (RES_MISS == g_result)  // �ո�
			event_control(EMPTY);
		else if (RES_WHITEBALLIN == g_result)  // ������
			event_control(WHITE_IN);
		else if (RES_NOTHIT == g_result || RES_HITORNOT == g_result)  // û�����򣬵�û��Ŀ����
			event_control(TARGET_MISS);
		else if (RES_HITANDIN == g_result)  // û�����򣬻���Ŀ���򲢽��˲���
			event_control(BALL_IN);
		else if (RES_HITANDOUT == g_result)  // ����Ŀ����û����
			event_control(NO_BALL_IN);
		g_result = RES_MISS;  // result�ع�ԭʼ״̬
	}
	g_prev_if_all_ball_still = is_allball_still(0);  // ��������ԭ����������if����ж�һ�������ִκ�ʱ��ʼ�����
}

void if_win()  // �жϻغϽ���ʱ�Ƿ����˻�ʤ�����У�����win_and_pause
{
	// �жϻغϽ���ʱ�Ƿ����˻�ʤ�����У�����win_and_pause
	if (g_mode == SINGLE_EASY)
	{
		bool all_in = TRUE;
		for (int i = 1; i < g_ball_num; i++)
		{
			if (g_balls[i].present == 1)
			{
				all_in = FALSE;
				break;
			}
		}
		if (all_in == TRUE)
			win_and_pause();
	}
	else if (g_mode == DOUBLE_EASY)
	{
		bool all_in = TRUE;
		for (int i = 1; i < g_ball_num; i++)
		{
			if (g_balls[i].present == 1)
			{
				all_in = FALSE;
				break;
			}
		}
		if (g_player_event[0].y >= 5 || g_player_event[1].y >= 5 || all_in == TRUE)
			win_and_pause();
	}

	else if (g_mode == DOUBLE_NINE_BALLS && (g_player_event[0].y >= 3 || g_player_event[1].y >= 3 ||
		g_player_event[(g_turn + 1) / 2].y == 0 && g_balls[9].present == 0))
	{
		win_and_pause();
	}

	else if (g_mode == DOUBLE_SIXTEEN_BALLS)
	{
		if (g_target_A == BLACK_8 && g_balls[8].present == 0 && g_player_event[(g_turn + 1) / 2].y == 0 || g_target_B != BLACK_8 && g_balls[8].present == 0
			|| g_target_B == BLACK_8 && g_balls[8].present == 0 && g_player_event[(g_turn + 1) / 2].y == 0 || g_target_A != BLACK_8 && g_balls[8].present == 0
			|| g_player_event[0].y >= 3 || g_player_event[1].y >= 3)
		{
			win_and_pause();
		}
	}
}

void win_and_pause()  // ��ʤ����ͣ��Ϸ
{
	// �ִν���ʱ����һ��ʤ�����˺����������ã��ر���Ϸ�ļ�ʱ�������濿TIMER_MENUˢ�£���ͬʱ�޸��ж�������
	cancelTimer(TIMER_GAME);
	g_is_pause = TRUE;
	g_is_win = TRUE;
} 

void balls_hit(ball* b1, ball* b2)  // ģ��������ȫ������ײ�Ĺ��̣��ٶ��ٳ���˥��ϵ�����������ķ�����ٶ�,�����¼���turn_control
{
	// �ֱ�õ��������ص��ٶ�������Բ�����ߵ�ˮƽ�ʹ�ֱ����
	coordinate bb_vec = { b2->pos.x - b1->pos.x, b2->pos.y - b1->pos.y };
	coordinate b1_vec_hor = { (bb_vec.x / getmod(bb_vec)) * ((b1->speed.x * bb_vec.x + b1->speed.y * bb_vec.y) / getmod(bb_vec)), (bb_vec.y / getmod(bb_vec)) * ((b1->speed.x * bb_vec.x + b1->speed.y * bb_vec.y) / getmod(bb_vec)) };
	coordinate b1_vec_ver = { b1->speed.x - b1_vec_hor.x, b1->speed.y - b1_vec_hor.y };
	coordinate b2_vec_hor = { (bb_vec.x / getmod(bb_vec)) * ((b2->speed.x * bb_vec.x + b2->speed.y * bb_vec.y) / getmod(bb_vec)), (bb_vec.y / getmod(bb_vec)) * ((b2->speed.x * bb_vec.x + b2->speed.y * bb_vec.y) / getmod(bb_vec)) };
	coordinate b2_vec_ver = { b2->speed.x - b2_vec_hor.x, b2->speed.y - b2_vec_hor.y };
	// �����������ٶ��������������߷���ķ���
	coordinate temp = b1_vec_hor;
	b1_vec_hor = b2_vec_hor;
	b2_vec_hor = temp;

	b1->speed = (coordinate){ HIT_REMAIN_RATIO*b1_vec_hor.x + b1_vec_ver.x, HIT_REMAIN_RATIO * b1_vec_hor.y + b1_vec_ver.y };
	b2->speed = (coordinate){ HIT_REMAIN_RATIO * b2_vec_hor.x + b2_vec_ver.x, HIT_REMAIN_RATIO * b2_vec_hor.y + b2_vec_ver.y };
	b1->just_hit = b2->id;
	b2->just_hit = b1->id;

	if (b1->id == 0 && is_target(g_turn, b2->id) || b2->id == 0 && is_target(g_turn, b1->id))
	{
		turn_control(MAT_TARGETBALL);  // �����¼���ĸ�����Ŀ����
	}

	if (b1->id == 0 && !is_target(g_turn, b2->id) || b2->id == 0 && !is_target(g_turn, b1->id))
	{
		turn_control(MAT_NOTTAGRETBALL);  // �����¼���ĸ����з�Ŀ����
	}
}
void edge_hit(ball* b)  // ģ������ǽ��ȫ������ײ�Ĺ���,�ٶ��ٳ���˥��ϵ���������¼���turn_control
{
	// �����ж���ǽ�ı��Ƿ�����ײ������ײ������ǽ��ֱ���ٶȷ�������
	// ������������ǽ�Ĵ������ֱַ�Ϊ-2��-4��-3��-1��
	if (b->pos.x > g_table_llc.x + g_table_width - R && b->just_hit != -1)
	{
		b->speed.x *= -HIT_REMAIN_RATIO;
		b->speed.y*= HIT_REMAIN_RATIO;
		b->just_hit = -1;
	}
	else if (b->pos.x < g_table_llc.x + R && b->just_hit != -3)
	{
		b->speed.x *= -HIT_REMAIN_RATIO;
		b->speed.y *= HIT_REMAIN_RATIO;
		b->just_hit = -3;
	}
	else if (b->pos.y > g_table_llc.y + g_table_height - R && b->just_hit != -2)
	{
		b->speed.y *= -HIT_REMAIN_RATIO;
		b->speed.x *= HIT_REMAIN_RATIO;
		b->just_hit = -2;
	}
	else if (b->pos.y < g_table_llc.y + R && b->just_hit != -4)
	{
		b->speed.y *= -HIT_REMAIN_RATIO;
		b->speed.x *= HIT_REMAIN_RATIO;
		b->just_hit = -4;
	}
} 

void move_ball()  // ��ʱ���������ı����λ�ã������ƶ��������ƽ���
{
	// �Ƿ����
	for (int i = 0; i < g_ball_num; i++)
	{
		if (!g_balls[i].present)
			continue;
		if (is_in_hole(g_balls[i]) == 1)
		{
			g_balls[i].present = 0;
			if (i != 0)
			{
				if (g_mode == SINGLE_EASY)
				{
					g_score++;
					turn_control(MAT_COLOREDBALLIN);
				}

				else if (g_mode == DOUBLE_EASY)
				{
					if (g_turn == -1)
						g_score_A++;
					else if (g_turn == 1)
						g_score_B++;
					turn_control(MAT_COLOREDBALLIN);
				}

				else if (g_mode == DOUBLE_NINE_BALLS)
				{
					turn_control(MAT_COLOREDBALLIN);
				}

				else if (g_mode == DOUBLE_SIXTEEN_BALLS )
				{
					//��turn_control���¼�
					if (i != 8 &&
						(
							g_target_A == ALLCOLORBALL && g_target_B == ALLCOLORBALL
							||g_turn == -1 && g_target_A == SMALLBALL && i >= 1 && i <= 7
							|| g_turn == -1 && g_target_A == BIGBALL && i >= 9 && i <= 15
							|| g_turn == 1 && g_target_B == SMALLBALL && i >= 1 && i <= 7
							|| g_turn == 1 && g_target_B == BIGBALL && i >= 9 && i <= 15
						)
						|| i == 8 && g_turn == -1 && g_target_A == BLACK_8
						|| i == 8 && g_turn == 1 && g_target_B == BLACK_8
						)  // ����������
						turn_control(MAT_COLOREDBALLIN);
					else if (i == 8 &&
								!(g_turn == -1 && g_target_A == BLACK_8
								|| g_turn == 1 && g_target_B == BLACK_8)
							)
						turn_control(MAT_BLACKBALLIN);

					//����Ŀ������Ϣ
					if (g_target_A == ALLCOLORBALL || g_target_B == ALLCOLORBALL)//��ʵ�������߿϶�ͬʱΪ0��ͬʱ��Ϊ0, ���ݵ�һ������ȷ����ɫ
					{
						if (g_turn == -1)
						{
							if (1 <= i && i <= 7)
							{
								g_target_A = SMALLBALL;
								g_target_B = BIGBALL;
							}
							else if (9 <= i && i <= 15)
							{
								g_target_A = BIGBALL;
								g_target_B = SMALLBALL;
							}
						}
						else if (g_turn == 1)
						{
							if (1 <= i && i <= 7)
							{
								g_target_A = BIGBALL;
								g_target_B = SMALLBALL;
							}
							else if (9 <= i && i <= 15)
							{
								g_target_A = SMALLBALL;
								g_target_B = BIGBALL;
							}
						}
					}

					bool target_all_in = TRUE;  // �ж��Ƿ�����Ŀ���򶼽����Ӷ�ȷ��һ���Ƿ���Ի���8
					if (g_target_A != BLACK_8)
					{
						for (int i = 1; i <= 15; i++)
						{
							if (is_target(-1, i) && g_balls[i].present == 1 && i != 8)
							{
								target_all_in = FALSE;
								break;
							}
						}
						if (target_all_in == TRUE)
							g_target_A = BLACK_8;
					}
					target_all_in = TRUE;
					if (g_target_B != BLACK_8)
					{
						for (int i = 1; i <= 15; i++)
						{
							if (is_target(1, i) && g_balls[i].present == 1 && i != 8)
							{
								target_all_in = FALSE;
								break;
							}
						}
						if (target_all_in == TRUE)
							g_target_B = BLACK_8;
					}			
				}

				g_balls[i].speed.x = g_balls[i].speed.y = 0;  // ������ٶȹ���

				// ���ս������������β��
				Node* p;
				if (g_turn == -1 || g_mode == SINGLE_EASY)
				{
					for (p = g_groove_list_A; p->next != NULL; p = p->next)
					{

					}
					p->next = (Node*)malloc(sizeof(Node));
					p->next->id = i;
					p->next->next = NULL;
					g_groove_A_len++;
				}
				else if (g_turn == 1)
				{
					for (p = g_groove_list_B; p->next != NULL; p = p->next)
					{

					}
					p->next = (Node*)malloc(sizeof(Node));
					p->next->id = i;
					p->next->next = NULL;
					g_groove_B_len++;
				}
			}

			if (i == 0)  // �������
			{
				turn_control(MAT_WHITEBALLIN);
				g_balls[0].speed.x = g_balls[0].speed.y = min(SLOWING_SPEED, 0.00001);  // 0����ٶȹ��㴦���Ȳ���Ϊ���Ե�0����ֹif_all_stillΪ0����bug
			}
		}
	}

	// �Ƿ�����ײ����Ե
	for (int i = 0; i < g_ball_num; i++)
	{
		if (!g_balls[i].present)
			continue;
		if (g_balls[i].pos.x > g_table_llc.x + g_table_width - R && g_balls[i].just_hit != -1
			|| g_balls[i].pos.x < g_table_llc.x + R && g_balls[i].just_hit != -3
			|| g_balls[i].pos.y > g_table_llc.y + g_table_height - R && g_balls[i].just_hit != -2
			|| g_balls[i].pos.y < g_table_llc.y + R && g_balls[i].just_hit != -4)
		{
			edge_hit(&g_balls[i]);
		}
	}

	// �Ƿ���������ײ
	for (int i = 0; i < g_ball_num; i++)
	{
		for (int j = i + 1; j < g_ball_num; j++)
		{
			if (!(g_balls[i].present && g_balls[j].present))
				continue;

			if (!(g_balls[i].just_hit == j && g_balls[j].just_hit == i) && bb_distance(g_balls[i], g_balls[j]) < 2 * R)
			{
				balls_hit(&g_balls[i], &g_balls[j]);
			}
		}
	}

	// �ƶ���
	for (int i = 0; i < g_ball_num; i++)
	{
		if (!g_balls[i].present)
			continue;
		// ÿһ��display_game����һ�Σ��ڳ�����ͨ���˴�����λ�õĸ��£�֡�ʽϿ�ʱ��������һ�����ٶ��ƶ���
		g_balls[i].pos.x += g_balls[i].speed.x;
		g_balls[i].pos.y += g_balls[i].speed.y;

		// ��������ȼ��٣�����������Ϊ0
		if (getmod(g_balls[i].speed) > SLOWING_SPEED)
		{
			g_balls[i].speed.x -= SLOWING_SPEED * g_balls[i].speed.x / getmod(g_balls[i].speed);
			g_balls[i].speed.y -= SLOWING_SPEED * g_balls[i].speed.y / getmod(g_balls[i].speed);
		}
		else
		{
			g_balls[i].speed.x = g_balls[i].speed.y = 0;
		}
	}
}
void correct_pos()  // ��һ���ִν������������ص����������ǵ�λ�á���Ҫ�����������λ�þ�����bug��Ԥ��
{
	for (int i = 0; i < g_ball_num; i++)
	{
		for (int j = i + 1; j < g_ball_num; j++)
		{
			if (g_balls[i].present == 0 || g_balls[j].present == 0)
				continue;

			else if (bb_distance(g_balls[i], g_balls[j]) < 1.99 * R)
			{
				// �÷����ص����������ر˴˷������Դ�
				double d = 2 * R - bb_distance(g_balls[i], g_balls[j]);
				coordinate bb_vec = { g_balls[i].pos.x - g_balls[j].pos.x,g_balls[i].pos.y - g_balls[j].pos.y };
				g_balls[i].pos.x += d * getcos(bb_vec);
				g_balls[i].pos.y += d * getsin(bb_vec);
				g_balls[j].pos.x -= d * getcos(bb_vec);
				g_balls[j].pos.y -= d * getsin(bb_vec);
				g_mystick.tip.x = g_balls[0].pos.x;
				g_mystick.tip.y = g_balls[0].pos.y;
			}
		}
	}
	//��ĸ����������ã�δ֪���������
	if (g_balls[0].pos.x<g_table_llc.x || g_balls[0].pos.x > g_table_llc.x + g_table_width
		|| g_balls[0].pos.y < g_table_llc.y || g_balls[0].pos.y > g_table_llc.y + g_table_height)
	{
		g_balls[0].pos = g_ball_0_pos;
		g_mystick.tip = g_balls[0].pos;
	}
}
void myMouseEvent(int x, int y, int button, int event)  // ���ص����������ƻ��򡢰�ť��,����if_fixed�����Ƿ�̶�������
{
	g_mouse_x = ScaleXInches(x);
	g_mouse_y = ScaleYInches(y);
	double mouse_pos_loss = 0.2;
	uiGetMouse(x, y, button, event);

	// ���ĵ�������Ƹ��Ƿ�̶���������
	if (g_is_pause == FALSE && g_page == IN_GAME)
	{
		if (event == BUTTON_DOWN)
		{
			if (g_mystick.if_fixed == 0)
				g_press_pos = (coordinate){ g_mouse_x,g_mouse_y };
			g_mystick.if_fixed = 1;
		}
		else if (event == BUTTON_UP)
		{
			g_mystick.if_fixed = 0;
		}
		if (!(g_mouse_x > mouse_pos_loss && g_mouse_x<GetWindowWidth() - mouse_pos_loss
			&& g_mouse_y>mouse_pos_loss && g_mouse_y < GetWindowHeight() - mouse_pos_loss))
		{
			g_mystick.if_fixed = 0;
			g_mouse_out = 1;
		}
		else
			g_mouse_out = 0;
	}
	// �Ҽ�ȡ������
	if (g_mystick.if_fixed == 1 && button == RIGHT_BUTTON)
	{
		g_mystick.if_fixed = 0;
		g_mystick.tip = g_balls[0].pos;
	}

}
void myKeyboardEvent(int key, int event)  // ���̻ص�������������������ƶ�
{
	if (g_page == IN_GAME && g_free_ball == TRUE && is_allball_still(0) == 1 && g_mystick.if_fixed == 0)
	{
		// ���ź�ת��Ϊ�ж������Ƿ��µ�����if_press[]
		char move_c[4] = { 'W','S','D','A' };
		for (int i = 0; i < 4; i++)
		{
			if (g_is_press[i] == FALSE && key == move_c[i] && event == KEY_DOWN)
				g_is_press[i] = TRUE;
			else if (g_is_press[i] == TRUE && key == move_c[i] && event == KEY_UP)
				g_is_press[i] = FALSE;
		}

		// ���ݵ�ǰ���µļ�����ĸ���ƶ������ܷ����ص�����磩
		double move_speed = 0.15;
		double begin_line = g_table_llc.x + g_table_width / 4;  // ��һ��������λ�ã���һ�������������������Ҳ�
		if (g_is_press[0] == TRUE && !is_overlap(0, (coordinate) { g_balls[0].pos.x, g_balls[0].pos.y + move_speed }))
			g_mystick.tip.y = g_balls[0].pos.y += move_speed;
		if (g_is_press[1] == TRUE && !is_overlap(0, (coordinate) { g_balls[0].pos.x, g_balls[0].pos.y - move_speed }))
			g_mystick.tip.y = g_balls[0].pos.y -= move_speed;
		if (g_is_press[2] == TRUE && !is_overlap(0, (coordinate) { g_balls[0].pos.x + move_speed, g_balls[0].pos.y }) && (g_total_round != 1 || g_balls[0].pos.x + move_speed + R <= begin_line))
			g_mystick.tip.x = g_balls[0].pos.x += move_speed;
		if (g_is_press[3] == TRUE && !is_overlap(0, (coordinate) { g_balls[0].pos.x - move_speed, g_balls[0].pos.y }))
			g_mystick.tip.x = g_balls[0].pos.x -= move_speed;
		g_mystick.tip.x = g_balls[0].pos.x;
		g_mystick.tip.y = g_balls[0].pos.y;
	}
} 

// ɾ������
void delete_list(List head)  // ɾ������
{
	Node* q;
	for (Node* p = head; p != NULL; )
	{
		q = p->next;
		free(p);
		p = q;
	}
}