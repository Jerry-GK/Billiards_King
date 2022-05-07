#include "draw.h"

static string rule_text[4] =  // 四种模式的规则文本
{
	"单人简单模式规则：\n1.单人一直击球，直至所有彩球进洞。\n2.空杆犯规：如果一次击球后母球直至停止后都没有碰到任何球，则为空杆犯规。\n3.进白球犯规。 \n\n",
	"双人简单模式规则：\n1.AB双方轮流击球，最后击进彩球数量多者获胜。\n2.空杆犯规：如果一次击球后母球直至停止后都没有碰到任何球，则为空杆犯规。"
	"\n3.进白球犯规\n4.续杆：若一方在未犯规的情况下进彩球，则其可以继续击球。\n5.自由球：若一方犯规，则下一轮另一方可以任意放置母球(键盘WASD控制)，然后再击球。"
	"另外第一轮刚开始时先击球方可在置球线左侧打自由球"
	"\n6.在一轮中犯规并进彩球，击进的彩球仍算数。\n7.连续犯规达到五次的一方直接判负（优先级高于进球数量判定）。\n\n",
	"双人九球模式规则：\n1.目标球：目标球是当前场上编号最小的彩球。每次击球，母球第一个碰到的球必须是目标球"
	"\n2.AB双方轮流击打目标球，最终将9号球击进洞者获胜。\n3.空杆犯规：如果一次击球后母球直至停止后都没有碰到任何球，则为空杆犯规。"
	"\n4.进白球犯规\n5.母球首先击中的球不是目标球，视为犯规。"
	"\n5.续杆：若一方在未犯规的情况下进彩球，则其可以继续击球。\n6.自由球：若一方犯规，则下一轮另一方可以任意放置母球(键盘WASD控制)，然后再击球。另外第一轮刚开始时先击球方可在置球线左侧打自由球"
	"\n7.连续犯规达到三次的一方直接判负（优先级高于进球数量判定）。\n8.每次进洞的不必是目标球，无论场上目标球是哪个，不犯规进九号球就算获胜。"
	"\n9.若在犯规的情况下将九号球击入洞，则视作无效，重置九号球位置，对方打自由球。\n\n",
	"双人十六球模式规则：\n1.目标球：场上球分为白色母球、单色球（1~7号）、双色球（9~15号）和黑色八号球。开始时所有彩球（不包括黑8）都是目标球，"
	"当有一名玩家最先击进一颗彩球时（无论是否犯规），该玩家所击进的彩球类型是其目标彩球花色类型（单色小号/双色大号），另一种花色类型则为对方目标彩球类型。"
	"当双方都没有将自己的目标彩球全部击入洞内时，黑8都不是目标球。直至击进所有自己的目标彩球后，才可以将黑球作为目标球。"
	"\n2.AB双方轮流击打目标球，将己方目标彩球全部击入洞，并最后击入黑8者获胜。\n3.空杆犯规：如果一次击球后母球直至停止后都没有碰到任何球，则为空杆犯规。"
	"\n4.进白球犯规\n5.母球首先击中的球不是目标球，视为犯规。"
	"\n5.续杆：若一方在未犯规的情况下击目标彩球进洞（对方目标彩球不算），则其可以继续击球。\n"
	"6.自由球：若一方犯规，则下一轮另一方可以任意放置母球(键盘WASD控制)，然后再击球。另外第一轮刚开始时先击球方可在置球线左侧打自由球"
	"\n7.连续犯规达到三次的一方直接判负（优先级高于进黑8获胜）。\n8.未犯规情况下，将对手目标彩球击进洞，不续杆，换对方击球。"
	"\n9.若黑8已是目标球，但在犯规的情况下将黑8球击入洞，则视作无效，重置黑8位置，对方打自由球。"
	"\n10.在未将自己的目标彩球全部击入洞时，提前将黑8击入洞者(无论直接还是间接），直接判负！"
};

static string usage_text =  // 玩法文本
"1.在所有球都停下时，按住鼠标左键可以固定杆的方向，向后拖动蓄力，松开左键，杆回弹并击球。蓄力过程中可以按右键或将杆尖拖回球心取消蓄力"
"\n\n2.当双人游戏开始、我方开球时，或对方犯规时，可以击自由球。按键盘上的WASD键可以控制母球位置，确定位置后正常击球即可。（先关闭输入法！）"
"\n\n3.< 请不要在蓄力过程中将鼠标拖到窗口边缘!! >否则会失去控制。"
"\n\n4.游戏过程中可以按暂停来暂停游戏，一方获胜后游戏会自动暂停。"
"\n\n5.请时刻注意游戏状态栏中击球方、目标球、犯规情况等信息。"
"\n\n6.请在游戏前认真阅读游戏规则（特别是双人九球和双人十六球模式）。"
"\n\n7.由于帧率等原因，可能会短暂出现球重叠的情况，程序会自动纠正。"
"\n\n8.游戏过程中随时可以保存游戏进度，可通过读取存档继续游戏。\n首次游戏无法读取存档。\n新建游戏时不会覆盖存档，只有再次保存时才会覆盖原存档。";

static string about_text =  // “关于游戏”的文本
"游戏名称：Billiards King（台球之王）\n\n"
"开发者：程设某小组（暂时保密）\n\n"
"版本：1.0.0";

void define_my_colors() // 自定义颜色
{
	// 设置自定义颜色的rgb值
	DefineColor("Table Green", 0.2627, 0.804, 0.502);
	DefineColor("Beige", 0.96, 0.87, 0.702);
	DefineColor("Light Beige", 1, 0.937, 0.835);
	DefineColor("Dark Yellow", 1, 0.84313725, 0);
	DefineColor("Edge Brown", 0.545, 0.41176471, 0.07843137);
}

void draw_dot_line(double dx, double dy)  // 同DrawLine，只不过画的是虚线
{
	int n = (int)(getmod((coordinate) { dx, dy }) / 0.12);
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			DrawLine(dx / n, dy / n);
		}
		else
		{
			MovePen(GetCurrentX() + dx / n, GetCurrentY() + dy / n);
		}
	}
}

void DrawCircle(coordinate centre, double r, string color)  // 以坐标点centre为圆心，r为半径，以color为颜色，画圆，最终画笔回到圆心位置
{
	SetPenSize(1);
	SetPenColor(color);
	MovePen(centre.x + r, centre.y);
	StartFilledRegion(1);
	DrawArc(r, 0, 360);
	EndFilledRegion();
	MovePen(centre.x, centre.y);
}

void draw_background()  // 绘制背景颜色图
{
	MovePen(0, 0);
	StartFilledRegion(1);
	SetPenColor(g_page == IN_GAME ? "Light Beige" : "Table Green");
	DrawLine(g_winwidth, 0);
	DrawLine(0, g_winheight);
	DrawLine(-g_winwidth, 0);
	DrawLine(0, -g_winheight);
	EndFilledRegion();

	// 控制双子球的逆时针旋转动画
	static double max_x = 38.5, min_x = 1.5, max_y = 18.5, min_y = 1.5, x = 1.5, y = 1.5, speed = 0.18;
	if (g_page != IN_GAME)
	{
		if (x >= max_x)
		{
			x = max_x;
			y += speed;
		}
		if (y >= max_y)
		{
			y = max_y;
			x -= speed;
		}
		if (x <= min_x)
		{
			x = min_x;
			y -= speed;
		}
		if (y <= min_y)
		{
			y = min_y;
			x += speed;
		}

		DrawCircle((coordinate) { x, y }, 0.5, "Red");
		MovePen(x - 0.15, y - 0.2);
		SetPenColor("Black");
		SetPointSize(20);
		DrawTextString("6");
		SetPointSize(15);

		DrawCircle((coordinate) { 40 - x, 20 - y }, 0.5, "Cyan");
		SetPenColor("White");
		drawRectangle(40 - x - 0.95 * 0.5, 20 - y - 0.4 * 0.5, 1.9 * 0.5, 0.8 * 0.5, 1);
		MovePen(40 - x - 0.15, 20 - y - 0.2);
		SetPenColor("Black");
		SetPointSize(20);
		DrawTextString("9");
		SetPointSize(15);
	}
} 
// 绘制背景颜色图
void draw_one_ball(ball d_ball)  // 画出一个球
{
	// 画球
	SetPenColor(d_ball.color);
	DrawCircle(d_ball.pos, R, d_ball.color);
	// 画大号球（双色球）中间的白色横条
	if (9 <= d_ball.id && d_ball.id <= 15)
	{
		SetPenColor("White");
		drawRectangle(d_ball.pos.x - 0.95 * R, d_ball.pos.y - 0.4 * R, 1.9 * R, 0.8 * R, 1);
	}
	// 写上编号
	string ball_id = (string)malloc(5 * sizeof(char));
	if (1 <= d_ball.id && d_ball.id <= 9)
		MovePen(d_ball.pos.x - 0.12, d_ball.pos.y - 0.15);
	else
		MovePen(d_ball.pos.x - 0.24, d_ball.pos.y - 0.15);
	if (d_ball.color == "Black")
		SetPenColor("White");
	else
		SetPenColor("Black");
	if (d_ball.id != 0)
		DrawTextString(itoa(d_ball.id, ball_id, 10));

	// 非简单模式下标识目标球（套上一个白环）
	if ((g_mode == DOUBLE_NINE_BALLS || g_mode == DOUBLE_SIXTEEN_BALLS) && is_target(g_turn, d_ball.id) && d_ball.present == 1)
	{
		MovePen(g_balls[d_ball.id].pos.x + R + 0.045, g_balls[d_ball.id].pos.y);
		SetPenSize(3);
		SetPenColor("White");
		DrawArc(R + 0.045, 0, 360);
	}
}

void draw_balls()  // 画出所有的在场的台球
{
	// 画球
	if (g_balls[0].present == 0 && is_allball_still(1) == 1)  // 母球进洞要重置位置
	{
		g_balls[0].pos = g_ball_0_pos;
		g_balls[0].present = 1;
	}

	for (int i = 0; i < g_ball_num; i++)
	{
		if (!g_balls[i].present)
			continue;
		draw_one_ball(g_balls[i]);
	}
}
void draw_table()  // 在屏幕中间绘制桌面，具体实现不重要
{
	double pen_size_loss = 0.04;
	double loss_1 = HOLE_BALL_RATIO * R + pen_size_loss;
	double loss_2 = (pen_size_loss + loss_1) / 2;
	// 画桌布
	SetPenSize(1);
	MovePen(g_table_llc.x, g_table_llc.y);
	StartFilledRegion(1);
	SetPenColor("Table Green");
	DrawLine(0, g_table_height);
	DrawLine(g_table_width, 0);
	DrawLine(0, -g_table_height);
	DrawLine(-g_table_width, 0);
	EndFilledRegion();
	// 画边框
	SetPenSize(12 * TABLE_SIZE);
	SetPenColor("Edge Brown");
	// 画内框
	MovePen(g_table_llc.x - pen_size_loss, g_table_llc.y - pen_size_loss);
	DrawLine(0, g_table_height + 2 * pen_size_loss);
	DrawLine(g_table_width + 2 * pen_size_loss, 0);
	DrawLine(0, -g_table_height - 2 * pen_size_loss);
	DrawLine(-g_table_width - 2 * pen_size_loss, 0);
	// 画外框
	SetPenSize(20 * TABLE_SIZE);
	MovePen(g_table_llc.x - loss_1, g_table_llc.y - loss_1);
	DrawLine(0, g_table_height + 2 * loss_1);
	DrawLine(g_table_width + 2 * loss_1, 0);
	DrawLine(0, -g_table_height - 2 * loss_1);
	DrawLine(-g_table_width - 2 * loss_1, 0);
	// 填充内外框
	SetPenSize(26 * TABLE_SIZE);
	SetPenColor("Beige");
	MovePen(g_table_llc.x - loss_2, g_table_llc.y - loss_2);
	DrawLine(0, g_table_height + 2 * loss_2);
	DrawLine(g_table_width + 2 * loss_2, 0);
	DrawLine(0, -g_table_height - 2 * loss_2);
	DrawLine(-g_table_width - 2 * loss_2, 0);
	// 画装饰
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 4, g_table_llc.y + g_table_height + 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width * 3 / 4, g_table_llc.y + g_table_height + 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 4, g_table_llc.y - 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width * 3 / 4, g_table_llc.y - 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 4, g_table_llc.y + g_table_height + 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x - 0.3, g_table_llc.y + g_table_height / 2 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width + 0.3, g_table_llc.y + g_table_height / 2 }, 0.15, "Edge Brown");
	// 画置球线
	if (g_total_round == 1 && g_mode != SINGLE_EASY)
	{
		SetPenSize(1);
		SetPenColor("White");
		MovePen(g_table_llc.x + g_table_width / 4, g_table_llc.y);
		DrawLine(0, g_table_height);
	}
	// 画洞
	DrawCircle((coordinate) { g_table_llc.x - pen_size_loss, g_table_llc.y - pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 2, g_table_llc.y - pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width + pen_size_loss, g_table_llc.y - pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x - pen_size_loss, g_table_llc.y + g_table_height + pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 2, g_table_llc.y + g_table_height + pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width + pen_size_loss, g_table_llc.y + g_table_height + pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
}

void draw_stick()  // 绘制击球杆，同时控制击球，实现较为复杂，主要应用向量运算
{
	coordinate stick_vec = (coordinate){ g_mystick.tip.x - g_mystick.tail.x, g_mystick.tip.y - g_mystick.tail.y };  // 杆的方向向量
	if (g_mystick.if_fixed == 0 && getmod((coordinate) { g_mystick.tip.x - g_balls[0].pos.x, g_mystick.tip.y - g_balls[0].pos.y }) < 0.02)  // 棒并未固定
	{
		g_mystick.tip = g_balls[0].pos;  // 杆尖跟随母球
		g_mystick.tail = (coordinate){ g_mystick.tip.x - L * (g_mystick.tip.x - g_mouse_x) / getmod((coordinate) { g_mystick.tip.x - g_mouse_x, g_mystick.tip.y - g_mouse_y }),
			g_mystick.tip.y - L * (g_mystick.tip.y - g_mouse_y) / getmod((coordinate) { g_mystick.tip.x - g_mouse_x,g_mystick.tip.y - g_mouse_y }) };
	}
	else if (g_mystick.if_fixed == 1)  // 棒已经固定，准备击球
	{
		coordinate move_vec = (coordinate){ g_mouse_x - g_press_pos.x, g_mouse_y - g_press_pos.y };  // 鼠标与按下的位置之间的向量

		double move_vec_proj = (move_vec.x * stick_vec.x + move_vec.y * stick_vec.y) / getmod(stick_vec);  // 鼠标与按下的位置之间的向量,在杆方向的投影是蓄力的绝对距离
		if (move_vec_proj <= 0)  // 杆不能穿过台球
		{
			g_mystick.tip.x = g_balls[0].pos.x + move_vec_proj * getcos(stick_vec);
			g_mystick.tip.y = g_balls[0].pos.y + move_vec_proj * getsin(stick_vec);
			g_mystick.tail.x = g_mystick.tip.x - L * getcos(stick_vec);
			g_mystick.tail.y = g_mystick.tip.y - L * getsin(stick_vec);
		}
		
			g_release_tip = g_mystick.tip;  // 时刻记录上一时刻杆尖位置，松手时停止记录
	}
	else if (g_mouse_out == 1)  // 鼠标移到窗口外部，杆回弹但不击打白球
	{
		g_mystick.tip = g_balls[0].pos;
	}
	else  // 棒回弹并击中白球
	{
		double hit_speed =HIT_STRENGTH * min(HIT_UPBOUND, getmod((coordinate) { g_release_tip.x - g_balls[0].pos.x, g_release_tip.y - g_balls[0].pos.y }));  // 击打速度,有速度上限
		// 杆的回弹
		g_mystick.tip.x += hit_speed * getcos(stick_vec);
		g_mystick.tip.y += hit_speed * getsin(stick_vec);
		g_mystick.tail.x += hit_speed * getcos(stick_vec);
		g_mystick.tail.y += hit_speed * getsin(stick_vec);
		if (getmod((coordinate) { g_mystick.tip.x - g_balls[0].pos.x, g_mystick.tip.y - g_balls[0].pos.y }) < hit_speed)  // 击球判定
		{
			g_mystick.tip = g_balls[0].pos;  // 杆尖跟随
			// 击球结束，赋予母球与蓄力距离成正比的初速度，方向与击球方向相同
			g_balls[0].speed = (coordinate){ hit_speed * getcos(stick_vec), hit_speed * getsin(stick_vec) };
		}
	}

	// 分两端画杆
	MovePen(g_mystick.tail.x, g_mystick.tail.y);
	SetPenSize(STICK_THICKNESS);
	SetPenColor("Black");
	DrawLine((g_mystick.tip.x - g_mystick.tail.x) * 2 / 5, (g_mystick.tip.y - g_mystick.tail.y) * 2 / 5);
	SetPenSize(0.8 * STICK_THICKNESS);
	SetPenColor("Beige");
	DrawLine((g_mystick.tip.x - g_mystick.tail.x) * 3 / 5 - R * getcos(stick_vec), (g_mystick.tip.y - g_mystick.tail.y) * 3 / 5 - R * getsin(stick_vec));
	MovePen(g_mystick.tip.x, g_mystick.tip.y);

}
void draw_indicator()  // 根据向量运算绘制击球指示器
{
	int hit_ball_id = -1;
	for (int i = 1; i < g_ball_num; i++)
	{
		if (g_balls[i].present == 0)
			continue;
		if (b_s_v_distance(g_balls[i]) < 1.99 * R && b_s_h_distance(g_balls[i]) >= 0)
		{
			if (hit_ball_id == -1 || b_s_h_distance(g_balls[hit_ball_id]) > b_s_h_distance(g_balls[i]))
			{
				hit_ball_id = i;
			}
		}
	}

	// 算出离击球方向垂直距离小于1.99*R(留一点空余)且在击球方向正向的球的编号
	if (hit_ball_id != -1)  // 撞球指示器
	{
		SetPenColor(is_target(g_turn, hit_ball_id) ? "White" : "Red");  // 是目标球指示器为白色，否则为红色
		// 较为复杂的向量运算，实现指示方向
		coordinate tail_tip_vec = { g_balls[0].pos.x - g_mystick.tail.x,g_balls[0].pos.y - g_mystick.tail.y };
		coordinate tip_ball_vec = { g_balls[hit_ball_id].pos.x - g_balls[0].pos.x,g_balls[hit_ball_id].pos.y - g_balls[0].pos.y };
		double dot_product = tail_tip_vec.x * tip_ball_vec.x + tail_tip_vec.y * tip_ball_vec.y;

		coordinate proj_vec = { tail_tip_vec.x * dot_product / (getmod(tail_tip_vec) * getmod(tail_tip_vec)),
			tail_tip_vec.y * dot_product / (getmod(tail_tip_vec) * getmod(tail_tip_vec)) };
		double back_d = sqrt(4 * R * R - b_s_v_distance(g_balls[hit_ball_id]) * b_s_v_distance(g_balls[hit_ball_id]));

		coordinate ind_pos = { g_balls[0].pos.x + (getmod(proj_vec) - back_d) * getcos(proj_vec),
			g_balls[0].pos.y + (getmod(proj_vec) - back_d) * getsin(proj_vec) };
		coordinate vec = { g_balls[hit_ball_id].pos.x - ind_pos.x,g_balls[hit_ball_id].pos.y - ind_pos.y };
		coordinate ind_hit_vec = { g_balls[hit_ball_id].pos.x - ind_pos.x, g_balls[hit_ball_id].pos.y - ind_pos.y };
		double cos_arc = (tail_tip_vec.x * ind_hit_vec.x + tail_tip_vec.y * ind_hit_vec.y) / (getmod(tail_tip_vec) * getmod(ind_hit_vec));
		double sin_arc = sqrt(1 - cos_arc * cos_arc);
		SetPenSize(2);
		MovePen(g_balls[0].pos.x, g_balls[0].pos.y);
		draw_dot_line(ind_pos.x - GetCurrentX(), ind_pos.y - GetCurrentY());

		// 画出被击球方向
		draw_dot_line(cos_arc * INDICATOR_LENGTH * vec.x / (2 * R), cos_arc * INDICATOR_LENGTH * vec.y / (2 * R));  // 2R=getmod(vec)
		// 画出虚拟球
		MovePen(ind_pos.x + R, ind_pos.y);
		SetPenSize(2);
		DrawArc(R, 0, 360);
		// 画出白球击后大致方向（不完全准确）
		coordinate stick_vec = { g_mystick.tip.x - g_mystick.tail.x, g_mystick.tip.y - g_mystick.tail.y };
		coordinate direction = { -vec.y,vec.x };  // 确定白球运动的方向向量
		MovePen(ind_pos.x, ind_pos.y);
		int judge = vec.x * stick_vec.y - vec.y * stick_vec.x > 0 ? 1 : -1;  // 判断白球运动方向（左右）
		DrawLine(sin_arc * INDICATOR_LENGTH * judge * direction.x / (2 * R), sin_arc * INDICATOR_LENGTH * judge * direction.y / (2 * R));
	}
	else  // 撞墙指示器
	{
		SetPenColor("White");
		coordinate stick_vec = { g_mystick.tip.x - g_mystick.tail.x, g_mystick.tip.y - g_mystick.tail.y };
		double t[4];  // 参数，要求正的且最小的t
		t[0] = (g_table_llc.x + g_table_width - g_balls[0].pos.x) / stick_vec.x;
		t[1] = (g_table_llc.y + g_table_height - g_balls[0].pos.y) / stick_vec.y;
		t[2] = (g_table_llc.x - g_balls[0].pos.x) / stick_vec.x;
		t[3] = (g_table_llc.y - g_balls[0].pos.y) / stick_vec.y;
		int hit_i = -1;
		for (int i = 0; i < 4; i++)
		{
			if (t[i] > 0 && (hit_i == -1 || t[i] < t[hit_i]))
			{
				hit_i = i;
			}
		};
		SetPenSize(2);
		MovePen(g_balls[0].pos.x, g_balls[0].pos.y);

		if (hit_i == 0 || hit_i == 2)  // 在左右碰
		{
			draw_dot_line(t[hit_i] * stick_vec.x + (getcos(stick_vec) < 0 ? 1 : -1) * R,
				t[hit_i] * stick_vec.y + (getcos(stick_vec) < 0 ? 1 : -1) * getsin(stick_vec) / getcos(stick_vec) * R);
			// 画撞墙反弹路线
			stick_vec.x *= -1;
			DrawLine(INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));
			MovePen(GetCurrentX() - INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), GetCurrentY() - INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));

			MovePen(GetCurrentX() + R, GetCurrentY());
		}
		else if (hit_i == 1 || hit_i == 3)  // 在上下碰
		{
			draw_dot_line(t[hit_i] * stick_vec.x + (getsin(stick_vec) < 0 ? 1 : -1) * getcos(stick_vec) / getsin(stick_vec) * R,
				t[hit_i] * stick_vec.y + (getsin(stick_vec) < 0 ? 1 : -1) * R);
			// 画撞墙反弹路线
			stick_vec.y *= -1;
			DrawLine(INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));
			MovePen(GetCurrentX() - INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), GetCurrentY() - INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));

			MovePen(GetCurrentX() + R, GetCurrentY());
		}
		SetPenSize(2);
		DrawArc(R, 0, 360);
	}
	// 画出自由球标识
	if (TRUE == g_free_ball && 1 == is_allball_still(0))
	{
		MovePen(g_balls[0].pos.x, g_balls[0].pos.y);
		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		SetPenSize(1.5);
		DrawLine(R, 0);
		MovePen(g_balls[0].pos.x, g_balls[0].pos.y);
		DrawLine(-R, 0);
		MovePen(g_balls[0].pos.x, g_balls[0].pos.y);
		DrawLine(0, R);
		MovePen(g_balls[0].pos.x, g_balls[0].pos.y);
		DrawLine(0, -R);
	}
	DrawCircle(g_balls[0].pos, 0.02, g_turn == -1 ? "Red" : "Blue");  // 再母球圆心画小圆点
}

void draw_groove()  // 利用球槽链表，绘制球槽，具体绘画部分不重要
{
	double r = 1.1 * R;  // 球槽中球心间距的一半
	double d = 0.25;  // 两球槽与桌面左右边框的间距

	// 画左侧A的进球槽（数值请忽略）
	SetPenSize(1);
	SetPenColor("Beige");
	drawRectangle(g_table_llc.x - 3.3 * r - r - d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 30 * r, 2 * r, 30 * r, 1);
	SetPenSize(5);
	SetPenColor("Edge Brown");
	drawRectangle(g_table_llc.x - 3.3 * r - r - d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 30 * r, 2 * r, 30 * r, 0);

	SetPenColor("Beige");
	SetPenSize(1);
	StartFilledRegion(1);
	MovePen(g_table_llc.x - 3.3 * r - r - d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 0.055);
	DrawLine(HOLE_BALL_RATIO * R + 1.57 * r + d, 2 * HOLE_BALL_RATIO * R);
	DrawLine(0, -2 * HOLE_BALL_RATIO * R);
	DrawLine(-(HOLE_BALL_RATIO * R + 1.57 * r + d), 0);
	EndFilledRegion();

	MovePen(g_table_llc.x - 3.38 * r - r - d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 0.055);
	SetPenColor("Edge Brown");
	SetPenSize(5);
	DrawLine(HOLE_BALL_RATIO * R + 1.57 * r + d, 2 * HOLE_BALL_RATIO * R + 0.15);
	MovePen(g_table_llc.x - 3.3 * r + r - d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 0.05);
	DrawLine(0.25 + d, 0);

	// 根据链表信息（来自于move_ball进球过程中对链表的修改），控制已进球的位置，画出
	int i = 0;
	for (Node* p = g_groove_list_A; p->next != NULL; p = p->next)
	{
		g_balls[p->next->id].pos.x = g_table_llc.x - 3.3 * r - d;
		g_balls[p->next->id].pos.y = g_table_llc.y + g_table_height + 2 * i * r - 30 * r + r - HOLE_BALL_RATIO * R;
		draw_one_ball(g_balls[p->next->id]);
		i++;
	}

	// 画右侧B的进球槽
	if (g_mode != SINGLE_EASY)
	{
		SetPenColor("Beige");
		drawRectangle(g_table_llc.x + g_table_width + 6.6 * r - 3.3 * r - r + d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 30 * r, 2 * r, 30 * r, 1);
		SetPenSize(5);
		SetPenColor("Edge Brown");
		drawRectangle(g_table_llc.x + g_table_width + 6.6 * r - 3.3 * r - r + d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 30 * r, 2 * r, 30 * r, 0);

		SetPenColor("Beige");
		SetPenSize(1);
		StartFilledRegion(1);
		MovePen(g_table_llc.x + g_table_width + 6.6 * r - 3.3 * r - r + 2 * r + d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 0.055);
		DrawLine(-(HOLE_BALL_RATIO * R + 1.57 * r + d), 2 * HOLE_BALL_RATIO * R);
		DrawLine(0, -2 * HOLE_BALL_RATIO * R);
		DrawLine(HOLE_BALL_RATIO * R + 1.57 + d * r, 0);
		EndFilledRegion();

		MovePen(g_table_llc.x + g_table_width + 6.6 * r - 3.3 * r - r + 2.1 * r + d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 0.055);
		SetPenColor("Edge Brown");
		SetPenSize(5);
		DrawLine(-(HOLE_BALL_RATIO * R + 1.57 * r + d), 2 * HOLE_BALL_RATIO * R + 0.15);
		MovePen(g_table_llc.x + g_table_width + 6.6 * r - 3.3 * r - r + d, g_table_llc.y + g_table_height - HOLE_BALL_RATIO * R - 0.05);
		DrawLine(-(0.25 + d), 0);

		// 根据链表信息（来自于move_ball进球过程中对链表的修改），控制已进球的位置，画出
		i = 0;
		for (Node* p = g_groove_list_B; p->next != NULL; p = p->next)
		{
			g_balls[p->next->id].pos.x = g_table_llc.x + g_table_width + 6.6 * r - 3.3 * r + d;
			g_balls[p->next->id].pos.y = g_table_llc.y + g_table_height + 2 * i * r - 30 * r + r - HOLE_BALL_RATIO * R;
			draw_one_ball(g_balls[p->next->id]);
			i++;
		}
	}
}

void drawBegin()  // 绘制最开始的选择页面
{
	// 大写游戏名称文本
	MovePen(g_winwidth / 2 - 6, g_winheight / 2 + 5.8);
	SetPointSize(75);
	SetPenColor("Dark Yellow");
	DrawTextString("Billiards  King");
	SetPointSize(15);
	SetPenSize(2);
	// 开始按钮
	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 + 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "开始游戏"))
	{
		g_page = NEWGAME;  // display会根据condition自动更新画面
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 + 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "游戏规则"))
	{
		static char all_rules[3000];  // 初始化所有规则的合并文本
		all_rules[0] = '\0';
		strcat(all_rules, rule_text[0]);
		strcat(all_rules, rule_text[1]);
		strcat(all_rules, rule_text[2]);
		strcat(all_rules, rule_text[3]);
		MessageBox(NULL, all_rules, "游戏规则", MB_OK);
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "玩法说明"))
	{
		MessageBox(NULL, usage_text, "玩法说明", MB_OK);
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "关于游戏"))
	{
		MessageBox(NULL, about_text, "关于游戏", MB_OK);
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 5, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "退出游戏"))
	{
		exit(-1);
	}

}
void drawNewGame()  // 绘制新建游戏中选择模式的页面
{
	MovePen(g_winwidth / 2 - 6.7, g_winheight / 2 + 6);
	SetPointSize(40);
	SetPenColor("Dark Yellow");
	DrawTextString("请选择游戏模式或读档");
	SetPointSize(15);
	SetPenSize(2);
	// 选择一种游戏模式后，设置模式、自由球、页面情况，初始化各个数据，开始计时
	if (button(GenUIID(0), g_winwidth / 2 - 1.5 * BUTTONWIDTH - 1, g_winheight / 2 + 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "单人简单"))
	{
		g_mode = SINGLE_EASY;
		g_free_ball = FALSE;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 + 1, g_winheight / 2 + 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "双人简单"))
	{
		g_mode = DOUBLE_EASY;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 - 1.5 * BUTTONWIDTH - 1, g_winheight / 2 + 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "双人九球"))
	{
		g_mode = DOUBLE_NINE_BALLS;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 + 1, g_winheight / 2 + 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "双人十六球"))
	{
		g_mode = DOUBLE_SIXTEEN_BALLS;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "读取存档"))
	{
		read_data();  // 读档，读入所有全局控制变量，直接进入对应的游戏界面
	}
	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "返 回")) {
		g_page = BEGIN;
	}
	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 5, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "退出游戏")) {
		exit(-1);
	} 

	// 根据模式设置显示的球的个数
	if (g_mode == DOUBLE_SIXTEEN_BALLS)
		g_ball_num = 16;
	else
		g_ball_num = 10;
}

void drawMenu()  // 在游戏中，绘制菜单页面
{
	// 此函数在IN_GAME状态下调用，用于显示游戏中的菜单
	char* menuListFile[] =
	{    // 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
	"Game",
	 "pause or Continue",
	 "Preserve",
	 "Go Back",
	 "Exit"
	};
	char* menuListHelp[] =
	{
	"About",
	"About",
	 "Rules",
	 "Usage"
	};

	// 基本界面的绘制
	char* selectedLabel = NULL;
	double fH = GetFontHeight();
	double x = 0; 
	double y = g_winheight;
	double h = fH * 1.5; // 控件高度
	double w = TextStringWidth(menuListHelp[0]) * 2; // 控件宽度
	double wlist = TextStringWidth(menuListFile[0]) * 6;// 点击后的列表宽度
	double xindent = g_winheight / 20; // red缩进
	string gameMode[4] = { "单人简单", "双人简单", "双人九球", "双人十六球" };
	int selection;

	SetPenSize(1);
	setMenuColors("Blue", "White", "Blue", "Red", 1);
	// File 菜单
	selection = menuList(GenUIID(0), x, y - h, w, wlist, h, menuListFile, sizeof(menuListFile) / sizeof(menuListFile[0]));

	if (FILE_STOP == selection) // 暂停或继续
	{
		if (FALSE == g_is_pause)
			g_is_pause = TRUE;
		else if (TRUE == g_is_pause)
		{
			startTimer(TIMER_GAME, MOVE_DISC);
			g_is_pause = FALSE;
		}
	}
	if (FILE_STORE == selection)  // 保存进度
	{
		save_data();
	}
	if (FILE_RETURN == selection)  // 返回
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_page = NEWGAME;
	}
	if (FILE_EXIT == selection)  // 退出
		exit(-1); // choose to exit

	// Help 菜单
	selection = menuList(GenUIID(0), x + w, y - h, w, wlist, h, menuListHelp, sizeof(menuListHelp) / sizeof(menuListHelp[0]));
	if (HELP_ABOUT == selection) 
		MessageBox(NULL, about_text, "关于游戏", MB_OK);
	if (HELP_RULE == selection) 
		MessageBox(NULL, rule_text[g_mode], "游戏规则", MB_OK);
	if (HELP_INTRODUCE == selection) 
		MessageBox(NULL, usage_text, "玩法说明", MB_OK);

	// 设置菜单栏范围
	SetPenColor("Blue");
	MovePen(0, g_winheight / 1.037);
	DrawLine(g_winwidth, 0);

	SetPenSize(2);
	// 暂停按钮
	bool button_available = getmod((coordinate) { g_balls[0].pos.x - g_mystick.tip.x, g_balls[0].pos.y - g_mystick.tip.y }) < 0.3;  // 判断是否没在击球，可按
	if (!g_is_win && !g_is_pause && button(GenUIID(0), g_winwidth - 5, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "暂停") && button_available)
	{
		g_is_pause = TRUE;
	}

	// 继续按钮
	if (!g_is_win && g_is_pause && button(GenUIID(0), g_winwidth - 5, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "继续游戏") && button_available)
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_is_pause = FALSE;
	}

	// 获胜后重新开始按钮
	if (TRUE == g_is_win)
	{
		setButtonColors("Cyan", "Red", "Cyan", "Red", 0);
		if (button(GenUIID(0), g_winwidth - 5, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "重新开始") && button_available)
		{
			MODE temp_mode = g_mode;
			Init_game_data();
			startTimer(TIMER_GAME, MOVE_DISC);
			g_is_pause = FALSE;
			g_is_win = FALSE;
			g_page = IN_GAME;
			g_mode = temp_mode;
			if (g_mode == DOUBLE_SIXTEEN_BALLS)
				g_ball_num = 16;
		}
		setButtonColors("Brown", "Red", "Cyan", "Red", 0);
	}

	// 存档按钮（暂停后才能保存）
	if (button(GenUIID(0), g_winwidth - 5, 8, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "保存当前进度") && button_available)
	{
		// 具体操作
		save_data();
	}

	// 直接返回上一个界面，不保存
	if (button(GenUIID(0), g_winwidth - 5, 6, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "返回") && button_available)
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_is_pause = FALSE;
		g_is_win = FALSE;
		g_page = NEWGAME;
	}

	// 帮助按钮
	if (button(GenUIID(0), 5 - 0.5 * BUTTONWIDTH, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "查看规则") && button_available)
	{
		MessageBox(NULL, rule_text[g_mode], "游戏规则", MB_OK);
	}

	// 返回主菜单（不保存）
	if (button(GenUIID(0), 5 - 0.5 * BUTTONWIDTH, 8, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "返回主菜单") && button_available)
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_is_pause = FALSE;
		g_is_win = FALSE;
		g_page = BEGIN;
	}

	// 退出按钮
	if (button(GenUIID(0), 5 - 0.5 * BUTTONWIDTH, 6, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "退出游戏") && button_available)
	{
		exit(-1);
	}

	// 状态栏
	// 更新时间
	SetPenSize(1);
	if (FALSE == g_is_pause && (clock() - g_begin_time - g_total_time) < 100)
		g_total_time = (clock() - g_begin_time);
	else if (FALSE == g_is_pause && clock() - g_begin_time - g_total_time >= 100) // 如果时间差距大（>0.1s），说明之前暂停过，更新begintime的时间（加上暂停的时间）
	{
		g_begin_time += clock() - g_begin_time - g_total_time;
		g_total_time = (clock() - g_begin_time);
	}
	SetPenColor("Blue");
	MovePen(0, g_winheight / 25);
	DrawLine(g_winwidth, 0);
	drawLabel(g_winwidth / 40 + 3, g_winheight / 80, "游戏时间（秒）:");
	string str_time = (string)malloc(100 * sizeof(char));
	MovePen(g_winwidth / 40 + 6.5, g_winheight / 80);
	DrawTextString(itoa(g_total_time / 1000, str_time, 10));
	// 显示当前模式
	string str_mode = (string)malloc(100 * sizeof(char));
	str_mode[0] = '\0';
	strcat(str_mode, "当前模式：");
	strcat(str_mode, gameMode[g_mode]);
	drawLabel(g_winwidth / 1.45, g_winheight / 80, str_mode);

	// 如果获胜，绘制获胜文本
	if (TRUE == g_is_win)
	{
		if (g_mode == SINGLE_EASY)
			draw_win_text(0);
		else if (g_mode == DOUBLE_EASY)
		{
			if (g_player_event[0].y >= 5)
				draw_win_text(1);
			else if (g_player_event[1].y >= 5)
				draw_win_text(0);
			else  // 这种情况下必为所有球都进了
				draw_win_text(g_score_A < g_score_B);
		}
		else if (g_mode == DOUBLE_NINE_BALLS)
		{
			if (g_player_event[0].y >= 3)
				draw_win_text(1);
			else if (g_player_event[1].y >= 3)
				draw_win_text(0);
			else if (g_player_event[(g_turn + 1) / 2].y == 0 && g_balls[9].present == 0)
				draw_win_text((g_turn + 1) / 2);
		}
		else if (g_mode == DOUBLE_SIXTEEN_BALLS)
		{
			if (g_turn == -1 && g_target_A == BLACK_8 && g_balls[8].present == 0 && g_player_event[0].y == 0 || g_player_event[1].x == BLACK_8_IN_ADVANCE || g_player_event[1].y >= 3)
				draw_win_text(0);
			else if (g_turn == 1 && g_target_B == BLACK_8 && g_balls[8].present == 0 && g_player_event[1].y == 0 || g_player_event[0].x == BLACK_8_IN_ADVANCE || g_player_event[0].y >= 3)
				draw_win_text(1);
		}
	}
}

void draw_text()  // 绘制游戏中的文本（具体实现不重要）
{
	// 临时的字符串，用于控制输出
	string str = (string)malloc(100 * sizeof(char));
	string text = (string)malloc(100 * sizeof(char));
	// 显示当前轮次（击一次球，轮次加一）
	SetPenColor("Black");
	MovePen(GetWindowWidth() - 8, GetWindowHeight() - 3.2);
	DrawTextString("当前轮次：");
	MovePen(GetWindowWidth() - 5.8, GetWindowHeight() - 3.2);
	DrawTextString(itoa(g_total_round, str, 10));

	if (g_mode == SINGLE_EASY)
	{
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "进球数：0");
		text[strlen(text) - 1] = g_score + '0';
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "上一轮：");
		if (g_single_player_event.x == PREPARE)
			strcat(text, "还未击球。\t");
		else if (g_single_player_event.x == WHITE_IN)
			strcat(text, "犯规：进白球。\t");
		else if (g_single_player_event.x == EMPTY)
			strcat(text, "犯规：空杆。\t");
		else if (g_single_player_event.x == BALL_IN)
			strcat(text, "未犯规，进彩球。\t");
		else if (g_single_player_event.x == NO_BALL_IN)
			strcat(text, "未犯规，未进球。\t");
		strcat(text, "连续犯规次数：");
		DrawTextString(text);
		MovePen(GetWindowWidth() - 13.75, GetWindowHeight() - 3.2);
		DrawTextString(itoa(g_single_player_event.y, str, 10));
	}
	else if (g_mode == DOUBLE_EASY)
	{
		SetPenColor("Red");
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		DrawTextString("玩家A进球数：");
		MovePen(GetWindowWidth() - 4.8, GetWindowHeight() - 2);
		DrawTextString(itoa(g_score_A, str, 10));

		SetPenColor("Blue");
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2.6);
		DrawTextString("玩家B进球数：");
		MovePen(GetWindowWidth() - 4.8, GetWindowHeight() - 2.6);
		DrawTextString(itoa(g_score_B, str, 10));

		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		MovePen(g_table_llc.x - 0.75, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "当前击球方：A");
		text[strlen(text) - 1] = (g_turn + 1) / 2 + 'A';
		if (g_free_ball == TRUE)
			strcat(text, "(自由球! 键盘WASD控制)");
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 2.6);
		text[0] = '\0';
		strcat(text, "A的上一轮：");
		if (g_player_event[0].x == PREPARE)
			strcat(text, "还未击球。 ");
		else if (g_player_event[0].x == WHITE_IN)
			strcat(text, "犯规：进白球。 ");
		else if (g_player_event[0].x == TARGET_MISS)
			strcat(text, "犯规：未先击中目标球。 ");
		else if (g_player_event[0].x == EMPTY)
			strcat(text, "犯规：空杆. ");
		else if (g_player_event[0].x == BALL_IN)
			strcat(text, "击中目标球，并进彩球，续杆。 ");
		else if (g_player_event[0].x == NO_BALL_IN)
			strcat(text, "击中目标球，未进球，换杆。 ");
		strcat(text, "连续犯规次数(五次判负)：0");
		text[strlen(text) - 1] = (char)g_player_event[0].y + '0';
		DrawTextString(text);

		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "B的上一轮：");
		if (g_player_event[1].x == PREPARE)
			strcat(text, "还未击球。 ");
		else if (g_player_event[1].x == WHITE_IN)
			strcat(text, "犯规：进白球。 ");
		else if (g_player_event[1].x == TARGET_MISS)
			strcat(text, "犯规：未先击中目标球。 ");
		else if (g_player_event[1].x == EMPTY)
			strcat(text, "犯规：空杆. ");
		else if (g_player_event[1].x == BALL_IN)
			strcat(text, "击中目标球，并进彩球，续杆。 ");
		else if (g_player_event[1].x == NO_BALL_IN)
			strcat(text, "击中目标球，未进球，换杆。 ");
		strcat(text, "连续犯规次数(五次判负)：0");
		text[strlen(text) - 1] = (char)g_player_event[1].y + '0';
		DrawTextString(text);
	}
	else if (g_mode == DOUBLE_NINE_BALLS)
	{
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "当前目标球：0");
		text[strlen(text) - 1] = get_min_ball() + '0';
		DrawTextString(text);

		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		MovePen(g_table_llc.x - 0.75, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "当前击球方：A");
		text[strlen(text) - 1] = (g_turn + 1) / 2 + 'A';
		if (g_free_ball == TRUE)
			strcat(text, "(自由球! 键盘WASD控制)");
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 2.6);
		text[0] = '\0';
		strcat(text, "A的上一轮：");
		if (g_player_event[0].x == PREPARE)
			strcat(text, "还未击球。 ");
		else if (g_player_event[0].x == WHITE_IN)
			strcat(text, "犯规：进白球。 ");
		else if (g_player_event[0].x == TARGET_MISS)
			strcat(text, "犯规：未先击中目标球。 ");
		else if (g_player_event[0].x == EMPTY)
			strcat(text, "犯规：空杆. ");
		else if (g_player_event[0].x == BALL_IN)
			strcat(text, "击中目标球，并进球，续杆。 ");
		else if (g_player_event[0].x == NO_BALL_IN)
			strcat(text, "击中目标球，未进球，换杆。 ");
		strcat(text, "连续犯规次数(三次判负)：0");
		text[strlen(text) - 1] = (char)g_player_event[0].y + '0';
		DrawTextString(text);

		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "B的上一轮：");
		if (g_player_event[1].x == PREPARE)
			strcat(text, "还未击球。 ");
		else if (g_player_event[1].x == WHITE_IN)
			strcat(text, "犯规：进白球。 ");
		else if (g_player_event[1].x == TARGET_MISS)
			strcat(text, "犯规：未先击中目标球。 ");
		else if (g_player_event[1].x == EMPTY)
			strcat(text, "犯规：空杆. ");
		else if (g_player_event[1].x == BALL_IN)
			strcat(text, "击中目标球，并进球，续杆。 ");
		else if (g_player_event[1].x == NO_BALL_IN)
			strcat(text, "击中目标球，未进球，换杆。 ");
		strcat(text, "连续犯规次数(三次判负)：0");
		text[strlen(text) - 1] = (char)g_player_event[1].y + '0';
		DrawTextString(text);
	}

	else if (g_mode == DOUBLE_SIXTEEN_BALLS)
	{
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "玩家A的目标球：");
		if (g_target_A == ALLCOLORBALL)
			strcat(text, "所有彩球");
		else if (g_target_A == SMALLBALL)
			strcat(text, "所有单色球（1~7号）");
		else if (g_target_A == BIGBALL)
			strcat(text, "所有双色球（9~15号）");
		else if (g_target_A == BLACK_8)
			strcat(text, "黑色8号球");
		DrawTextString(text);

		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2.6);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "玩家B的目标球：");
		if (g_target_B == ALLCOLORBALL)
			strcat(text, "所有彩球");
		else if (g_target_B == SMALLBALL)
			strcat(text, "所有单色球（1~7号）");
		else if (g_target_B == BIGBALL)
			strcat(text, "所有双色球（9~15号）");
		else if (g_target_B == BLACK_8)
			strcat(text, "黑色8号球");
		DrawTextString(text);

		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		MovePen(g_table_llc.x - 0.75, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "当前击球方：A");
		text[strlen(text) - 1] = (g_turn + 1) / 2 + 'A';
		if (g_free_ball == TRUE)
			strcat(text, "(自由球! 键盘WASD控制)");
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 2.6);
		text[0] = '\0';
		strcat(text, "A的上一轮：");
		if (g_player_event[0].x == PREPARE)
			strcat(text, "还未击球。 ");
		else if (g_player_event[0].x == BLACK_8_IN_ADVANCE)
			strcat(text, "提前将黑8击进洞，直接判负！");
		else if (g_player_event[0].x == WHITE_IN)
			strcat(text, "犯规：进白球。 ");
		else if (g_player_event[0].x == TARGET_MISS)
			strcat(text, "犯规：未先击中目标球。 ");
		else if (g_player_event[0].x == EMPTY)
			strcat(text, "犯规：空杆. ");
		else if (g_player_event[0].x == BALL_IN)
			strcat(text, "击中目标球，并进目标球，续杆。 ");
		else if (g_player_event[0].x == NO_BALL_IN)
			strcat(text, "击中目标球，未进目标球，换杆。 ");
		strcat(text, "连续犯规次数(三次判负)：0");
		text[strlen(text) - 1] = (char)g_player_event[0].y + '0';
		DrawTextString(text);

		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "B的上一轮：");
		if (g_player_event[1].x == PREPARE)
			strcat(text, "还未击球。 ");
		else if (g_player_event[1].x == BLACK_8_IN_ADVANCE)
			strcat(text, "提前将黑8击进洞，直接判负！");
		else if (g_player_event[1].x == WHITE_IN)
			strcat(text, "犯规：进白球。 ");
		else if (g_player_event[1].x == TARGET_MISS)
			strcat(text, "犯规：未先击中目标球。 ");
		else if (g_player_event[1].x == EMPTY)
			strcat(text, "犯规：空杆. ");
		else if (g_player_event[1].x == BALL_IN)
			strcat(text, "击中目标球，并进彩球，续杆。 ");
		else if (g_player_event[1].x == NO_BALL_IN)
			strcat(text, "击中目标球，未进球，换杆。 ");
		strcat(text, "连续犯规次数(三次判负)：0");
		text[strlen(text) - 1] = (char)g_player_event[1].y + '0';
		DrawTextString(text);
	}
}

void draw_win_text(int winner)  // 获胜后，根据情况绘制获胜者的文本
{
	// 若获胜，绘制对应文本。A为红色，B为蓝色
	SetPenColor(g_mode == SINGLE_EASY || winner == 0 ? "Red" : "Blue");
	drawRectangle(GetWindowWidth() / 2 - 4.5, 18.3, 12, 0.7, 0);
	if (g_mode == SINGLE_EASY)
	{
		MovePen(GetWindowWidth() / 2 - 4, 18.5);
		string text = (string)malloc(100 * sizeof(char));
		text = "您已将所有球击进洞!(可点击重新开始按钮再来一局)";
		DrawTextString(text);
	}
	else
	{
		MovePen(GetWindowWidth() / 2 - 4, 18.5);
		string text = (string)malloc(100 * sizeof(char));
		text[0] = '\0';
		strcat(text, "< 本局获胜者: A > ");
		text[strlen(text) - 4] = winner + 'A';
		strcat(text, " (可点击重新开始按钮再来一局)");
		DrawTextString(text);
	}
}

void display_game()  // 游戏显示函数，在没暂停的情况下不断调用，更新游戏画面
{
	// 依次画桌子、球槽、球、杆(如果可以击球，绘制指示器)、文本，然后调用回合控制函数
	move_ball();
	draw_table();
	draw_groove();
	draw_balls();
	// 画杆
	if (is_allball_still(0) == 1 && g_balls[0].present == 1)
	{
		for (int i = 0; i < g_ball_num; i++)
		{
			g_balls[i].just_hit = -5;
		}
		draw_stick();
		draw_indicator();
	}
	else
		g_mystick.tip = g_balls[0].pos;
	draw_text();
	// 控制回合
	turn_control(0);
}

void display(int timerID) // 关键函数，不断被定时器回调的函数，实现页面的刷新。
{
	SetPenSize(3);
	// 根据情况调用页面显示函数
	if (g_is_pause == FALSE && timerID == TIMER_GAME)
	{
		DisplayClear();
		draw_background();
		if (g_is_pause == TRUE)
			cancelTimer(TIMER_GAME);
		if (g_page == BEGIN)
		{
			drawBegin();
		}
		else if (g_page == NEWGAME)
		{
			drawNewGame();
		}
		else if (g_page == IN_GAME)
		{
			drawMenu();
			display_game();
		}
	}
	else if (TRUE == g_is_pause && timerID == TIMER_MENU)  // 游戏暂停，画一帧游戏页面（不更新数据），通过TIMER_MENU刷新菜单页面
	{
		DisplayClear();
		draw_background();
		draw_table();
		draw_balls();
		draw_text();
		draw_groove();
		drawMenu();
	}
}