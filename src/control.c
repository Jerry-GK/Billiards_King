#include "control.h"

void set_balls()  // 根据模式，将球放在初始位置上
{
	double r = 1.25 * R;  // 较大的R，初始放置时球之间的间距要稍大一些，防止出现重叠等问题
	// 根据几何关系确定各球的位置
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
 
void Init_game_data()  // 重置所有游戏中的数据
{
	set_balls();  // 初始化球的位置
	g_mystick.tip = g_balls[0].pos;  // 不击球时，时刻让杆尖与母球球心重合

	// 初始化球槽链表，创建头节点，头节点的数据无意义
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

	// 初始化各种全局控制变量
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
	g_free_ball = TRUE;  // 第一轮可以发自由球
	if (g_mode == SINGLE_EASY)
		g_free_ball = FALSE;
	g_mouse_out = FALSE;
	g_is_pause = FALSE;
	g_is_press[0] = g_is_press[1] = g_is_press[2] = g_is_press[3] = FALSE;

	g_player_event[0] = (EVENT_TIME){ PREPARE,0 };
	g_player_event[1] = (EVENT_TIME){ PREPARE,0 };
	g_single_player_event = (EVENT_TIME){ PREPARE,0 };
}

void event_control(EVENT eve)  // 回合结果处理，接受来自turn_control的轮次结果信息
{
	// 此函数每个轮次结束后调用

	// 根据回合的结果，记录玩家的时间和连续犯规次数，必要时换击球方
	if (eve == BLACK_8_IN_ADVANCE)
	{
		if (g_mode == DOUBLE_SIXTEEN_BALLS)  // 此判断语句可以省略
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

	// 九球模式下，犯规但击进九球，九球位置重置于置球点,球槽链表删除该球
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

	// 十六球模式下，黑8是目标球，但犯规击进黑8，黑8重置于置球点
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
	g_total_round++;  // 每各轮次结束，total_round加一
	correct_pos();  // 回合结束，如果有需要，纠正重叠球的位置
	// 判断回合结束后是否获胜
	if_win();
}

void turn_control(int matter)  // 控制回合和犯规判定（写的有点丑）
{
	//result和matter取值参考global.h中的宏定义
	//matter代表外部传入的事件
	//result代表此函数传给event_control的击球结果
	while (TRUE)  // 只进行一次循环，为了方便break用
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

	if (g_prev_if_all_ball_still == 0 && is_allball_still(0) == 1)  // 开始新的回合
	{
		if (RES_BLACKBALLIN == g_result)  // 十六球模式下黑8提前进洞
			event_control(BLACK_8_IN_ADVANCE);
		if (RES_MISS == g_result)  // 空杆
			event_control(EMPTY);
		else if (RES_WHITEBALLIN == g_result)  // 进白球
			event_control(WHITE_IN);
		else if (RES_NOTHIT == g_result || RES_HITORNOT == g_result)  // 没进白球，但没打到目标球
			event_control(TARGET_MISS);
		else if (RES_HITANDIN == g_result)  // 没进白球，击打目标球并进了彩球
			event_control(BALL_IN);
		else if (RES_HITANDOUT == g_result)  // 击打目标球但没进球
			event_control(NO_BALL_IN);
		g_result = RES_MISS;  // result回归原始状态
	}
	g_prev_if_all_ball_still = is_allball_still(0);  // 此语句可以原来结合上面的if语句判定一个击球轮次何时开始或结束
}

void if_win()  // 判断回合结束时是否有人获胜，若有，调用win_and_pause
{
	// 判断回合结束时是否有人获胜，若有，调用win_and_pause
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

void win_and_pause()  // 获胜，暂停游戏
{
	// 轮次结束时，若一方胜利，此函数将被调用，关闭游戏的计时器（界面靠TIMER_MENU刷新），同时修改判定变量。
	cancelTimer(TIMER_GAME);
	g_is_pause = TRUE;
	g_is_win = TRUE;
} 

void balls_hit(ball* b1, ball* b2)  // 模拟两球完全弹性碰撞的过程，速度再乘以衰减系数，交换对心方向的速度,传入事件给turn_control
{
	// 分别得到两个球沿的速度沿两球圆心连线的水平和垂直分量
	coordinate bb_vec = { b2->pos.x - b1->pos.x, b2->pos.y - b1->pos.y };
	coordinate b1_vec_hor = { (bb_vec.x / getmod(bb_vec)) * ((b1->speed.x * bb_vec.x + b1->speed.y * bb_vec.y) / getmod(bb_vec)), (bb_vec.y / getmod(bb_vec)) * ((b1->speed.x * bb_vec.x + b1->speed.y * bb_vec.y) / getmod(bb_vec)) };
	coordinate b1_vec_ver = { b1->speed.x - b1_vec_hor.x, b1->speed.y - b1_vec_hor.y };
	coordinate b2_vec_hor = { (bb_vec.x / getmod(bb_vec)) * ((b2->speed.x * bb_vec.x + b2->speed.y * bb_vec.y) / getmod(bb_vec)), (bb_vec.y / getmod(bb_vec)) * ((b2->speed.x * bb_vec.x + b2->speed.y * bb_vec.y) / getmod(bb_vec)) };
	coordinate b2_vec_ver = { b2->speed.x - b2_vec_hor.x, b2->speed.y - b2_vec_hor.y };
	// 交换两个球速度向量沿球心连线方向的分量
	coordinate temp = b1_vec_hor;
	b1_vec_hor = b2_vec_hor;
	b2_vec_hor = temp;

	b1->speed = (coordinate){ HIT_REMAIN_RATIO*b1_vec_hor.x + b1_vec_ver.x, HIT_REMAIN_RATIO * b1_vec_hor.y + b1_vec_ver.y };
	b2->speed = (coordinate){ HIT_REMAIN_RATIO * b2_vec_hor.x + b2_vec_ver.x, HIT_REMAIN_RATIO * b2_vec_hor.y + b2_vec_ver.y };
	b1->just_hit = b2->id;
	b2->just_hit = b1->id;

	if (b1->id == 0 && is_target(g_turn, b2->id) || b2->id == 0 && is_target(g_turn, b1->id))
	{
		turn_control(MAT_TARGETBALL);  // 传递事件：母球击中目标球
	}

	if (b1->id == 0 && !is_target(g_turn, b2->id) || b2->id == 0 && !is_target(g_turn, b1->id))
	{
		turn_control(MAT_NOTTAGRETBALL);  // 传递事件：母球击中非目标球
	}
}
void edge_hit(ball* b)  // 模拟球与墙完全弹性碰撞的过程,速度再乘以衰减系数，传入事件给turn_control
{
	// 依次判断与墙四边是否发生碰撞，若碰撞，则将与墙垂直的速度分量反向。
	// 上下左右四面墙的代表数字分别为-2、-4、-3、-1，
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

void move_ball()  // 定时器触发，改变球的位置（控制移动），控制进球
{
	// 是否进球
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
					//给turn_control传事件
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
						)  // 正常进彩球
						turn_control(MAT_COLOREDBALLIN);
					else if (i == 8 &&
								!(g_turn == -1 && g_target_A == BLACK_8
								|| g_turn == 1 && g_target_B == BLACK_8)
							)
						turn_control(MAT_BLACKBALLIN);

					//更新目标球信息
					if (g_target_A == ALLCOLORBALL || g_target_B == ALLCOLORBALL)//事实上这两者肯定同时为0或同时不为0, 根据第一个进球确定花色
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

					bool target_all_in = TRUE;  // 判断是否所有目标球都进，从而确定一方是否可以击黑8
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

				g_balls[i].speed.x = g_balls[i].speed.y = 0;  // 进球后速度归零

				// 将刚进的球存入链表尾部
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

			if (i == 0)  // 白球进洞
			{
				turn_control(MAT_WHITEBALLIN);
				g_balls[0].speed.x = g_balls[0].speed.y = min(SLOWING_SPEED, 0.00001);  // 0球的速度归零处理，先不设为绝对的0，防止if_all_still为0引发bug
			}
		}
	}

	// 是否有球撞到边缘
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

	// 是否有两球碰撞
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

	// 移动球
	for (int i = 0; i < g_ball_num; i++)
	{
		if (!g_balls[i].present)
			continue;
		// 每一次display_game调用一次，在场的球都通过此处进行位置的更新（帧率较快时，类似以一定的速度移动）
		g_balls[i].pos.x += g_balls[i].speed.x;
		g_balls[i].pos.y += g_balls[i].speed.y;

		// 控制球的匀减速，最终慢慢减为0
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
void correct_pos()  // 在一个轮次结束后，若有球重叠，纠正它们的位置。主要用于重置球的位置纠正和bug的预防
{
	for (int i = 0; i < g_ball_num; i++)
	{
		for (int j = i + 1; j < g_ball_num; j++)
		{
			if (g_balls[i].present == 0 || g_balls[j].present == 0)
				continue;

			else if (bb_distance(g_balls[i], g_balls[j]) < 1.99 * R)
			{
				// 让发生重叠的两个球沿彼此方向稍稍错开
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
	//若母球出桌，重置（未知意外情况）
	if (g_balls[0].pos.x<g_table_llc.x || g_balls[0].pos.x > g_table_llc.x + g_table_width
		|| g_balls[0].pos.y < g_table_llc.y || g_balls[0].pos.y > g_table_llc.y + g_table_height)
	{
		g_balls[0].pos = g_ball_0_pos;
		g_mystick.tip = g_balls[0].pos;
	}
}
void myMouseEvent(int x, int y, int button, int event)  // 鼠标回调函数，控制击球、按钮等,更新if_fixed（杆是否固定蓄力）
{
	g_mouse_x = ScaleXInches(x);
	g_mouse_y = ScaleYInches(y);
	double mouse_pos_loss = 0.2;
	uiGetMouse(x, y, button, event);

	// 鼠标的点击，控制杆是否固定（蓄力）
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
	// 右键取消蓄力
	if (g_mystick.if_fixed == 1 && button == RIGHT_BUTTON)
	{
		g_mystick.if_fixed = 0;
		g_mystick.tip = g_balls[0].pos;
	}

}
void myKeyboardEvent(int key, int event)  // 键盘回调函数，控制自由球的移动
{
	if (g_page == IN_GAME && g_free_ball == TRUE && is_allball_still(0) == 1 && g_mystick.if_fixed == 0)
	{
		// 将信号转化为判定按键是否按下的依据if_press[]
		char move_c[4] = { 'W','S','D','A' };
		for (int i = 0; i < 4; i++)
		{
			if (g_is_press[i] == FALSE && key == move_c[i] && event == KEY_DOWN)
				g_is_press[i] = TRUE;
			else if (g_is_press[i] == TRUE && key == move_c[i] && event == KEY_UP)
				g_is_press[i] = FALSE;
		}

		// 根据当前按下的键进行母球移动（不能发生重叠或出界）
		double move_speed = 0.15;
		double begin_line = g_table_llc.x + g_table_width / 4;  // 第一轮置球线位置，第一轮自由球不能在这条线右侧
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

// 删除链表
void delete_list(List head)  // 删除链表
{
	Node* q;
	for (Node* p = head; p != NULL; )
	{
		q = p->next;
		free(p);
		p = q;
	}
}