#include "draw.h"

static string rule_text[4] =  // ����ģʽ�Ĺ����ı�
{
	"���˼�ģʽ����\n1.����һֱ����ֱ�����в��������\n2.�ո˷��棺���һ�λ����ĸ��ֱ��ֹͣ��û�������κ�����Ϊ�ո˷��档\n3.�����򷸹档 \n\n",
	"˫�˼�ģʽ����\n1.AB˫���������������������������߻�ʤ��\n2.�ո˷��棺���һ�λ����ĸ��ֱ��ֹͣ��û�������κ�����Ϊ�ո˷��档"
	"\n3.�����򷸹�\n4.���ˣ���һ����δ���������½�����������Լ�������\n5.��������һ�����棬����һ����һ�������������ĸ��(����WASD����)��Ȼ���ٻ���"
	"�����һ�ָտ�ʼʱ�Ȼ��򷽿�������������������"
	"\n6.��һ���з��沢�����򣬻����Ĳ�����������\n7.��������ﵽ��ε�һ��ֱ���и������ȼ����ڽ��������ж�����\n\n",
	"˫�˾���ģʽ����\n1.Ŀ����Ŀ�����ǵ�ǰ���ϱ����С�Ĳ���ÿ�λ���ĸ���һ���������������Ŀ����"
	"\n2.AB˫����������Ŀ�������ս�9����������߻�ʤ��\n3.�ո˷��棺���һ�λ����ĸ��ֱ��ֹͣ��û�������κ�����Ϊ�ո˷��档"
	"\n4.�����򷸹�\n5.ĸ�����Ȼ��е�����Ŀ������Ϊ���档"
	"\n5.���ˣ���һ����δ���������½�����������Լ�������\n6.��������һ�����棬����һ����һ�������������ĸ��(����WASD����)��Ȼ���ٻ��������һ�ָտ�ʼʱ�Ȼ��򷽿�������������������"
	"\n7.��������ﵽ���ε�һ��ֱ���и������ȼ����ڽ��������ж�����\n8.ÿ�ν����Ĳ�����Ŀ�������۳���Ŀ�������ĸ�����������ź�������ʤ��"
	"\n9.���ڷ��������½��ź�����붴����������Ч�����þź���λ�ã��Է���������\n\n",
	"˫��ʮ����ģʽ����\n1.Ŀ���򣺳������Ϊ��ɫĸ�򡢵�ɫ��1~7�ţ���˫ɫ��9~15�ţ��ͺ�ɫ�˺��򡣿�ʼʱ���в��򣨲�������8������Ŀ����"
	"����һ��������Ȼ���һ�Ų���ʱ�������Ƿ񷸹棩��������������Ĳ�����������Ŀ�����ɫ���ͣ���ɫС��/˫ɫ��ţ�����һ�ֻ�ɫ������Ϊ�Է�Ŀ��������͡�"
	"��˫����û�н��Լ���Ŀ�����ȫ�����붴��ʱ����8������Ŀ����ֱ�����������Լ���Ŀ�����󣬲ſ��Խ�������ΪĿ����"
	"\n2.AB˫����������Ŀ���򣬽�����Ŀ�����ȫ�����붴�����������8�߻�ʤ��\n3.�ո˷��棺���һ�λ����ĸ��ֱ��ֹͣ��û�������κ�����Ϊ�ո˷��档"
	"\n4.�����򷸹�\n5.ĸ�����Ȼ��е�����Ŀ������Ϊ���档"
	"\n5.���ˣ���һ����δ���������»�Ŀ�����������Է�Ŀ������㣩��������Լ�������\n"
	"6.��������һ�����棬����һ����һ�������������ĸ��(����WASD����)��Ȼ���ٻ��������һ�ָտ�ʼʱ�Ȼ��򷽿�������������������"
	"\n7.��������ﵽ���ε�һ��ֱ���и������ȼ����ڽ���8��ʤ����\n8.δ��������£�������Ŀ�����������������ˣ����Է�����"
	"\n9.����8����Ŀ���򣬵��ڷ��������½���8����붴����������Ч�����ú�8λ�ã��Է���������"
	"\n10.��δ���Լ���Ŀ�����ȫ�����붴ʱ����ǰ����8���붴��(����ֱ�ӻ��Ǽ�ӣ���ֱ���и���"
};

static string usage_text =  // �淨�ı�
"1.��������ͣ��ʱ����ס���������Թ̶��˵ķ�������϶��������ɿ�������˻ص����������������п��԰��Ҽ��򽫸˼��ϻ�����ȡ������"
"\n\n2.��˫����Ϸ��ʼ���ҷ�����ʱ����Է�����ʱ�����Ի������򡣰������ϵ�WASD�����Կ���ĸ��λ�ã�ȷ��λ�ú��������򼴿ɡ����ȹر����뷨����"
"\n\n3.< �벻Ҫ�����������н�����ϵ����ڱ�Ե!! >�����ʧȥ���ơ�"
"\n\n4.��Ϸ�����п��԰���ͣ����ͣ��Ϸ��һ����ʤ����Ϸ���Զ���ͣ��"
"\n\n5.��ʱ��ע����Ϸ״̬���л��򷽡�Ŀ���򡢷����������Ϣ��"
"\n\n6.������Ϸǰ�����Ķ���Ϸ�����ر���˫�˾����˫��ʮ����ģʽ����"
"\n\n7.����֡�ʵ�ԭ�򣬿��ܻ���ݳ������ص��������������Զ�������"
"\n\n8.��Ϸ��������ʱ���Ա�����Ϸ���ȣ���ͨ����ȡ�浵������Ϸ��\n�״���Ϸ�޷���ȡ�浵��\n�½���Ϸʱ���Ḳ�Ǵ浵��ֻ���ٴα���ʱ�ŻḲ��ԭ�浵��";

static string about_text =  // ��������Ϸ�����ı�
"��Ϸ���ƣ�Billiards King��̨��֮����\n\n"
"�����ߣ�����ĳС�飨��ʱ���ܣ�\n\n"
"�汾��1.0.0";

void define_my_colors() // �Զ�����ɫ
{
	// �����Զ�����ɫ��rgbֵ
	DefineColor("Table Green", 0.2627, 0.804, 0.502);
	DefineColor("Beige", 0.96, 0.87, 0.702);
	DefineColor("Light Beige", 1, 0.937, 0.835);
	DefineColor("Dark Yellow", 1, 0.84313725, 0);
	DefineColor("Edge Brown", 0.545, 0.41176471, 0.07843137);
}

void draw_dot_line(double dx, double dy)  // ͬDrawLine��ֻ��������������
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

void DrawCircle(coordinate centre, double r, string color)  // �������centreΪԲ�ģ�rΪ�뾶����colorΪ��ɫ����Բ�����ջ��ʻص�Բ��λ��
{
	SetPenSize(1);
	SetPenColor(color);
	MovePen(centre.x + r, centre.y);
	StartFilledRegion(1);
	DrawArc(r, 0, 360);
	EndFilledRegion();
	MovePen(centre.x, centre.y);
}

void draw_background()  // ���Ʊ�����ɫͼ
{
	MovePen(0, 0);
	StartFilledRegion(1);
	SetPenColor(g_page == IN_GAME ? "Light Beige" : "Table Green");
	DrawLine(g_winwidth, 0);
	DrawLine(0, g_winheight);
	DrawLine(-g_winwidth, 0);
	DrawLine(0, -g_winheight);
	EndFilledRegion();

	// ����˫�������ʱ����ת����
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
// ���Ʊ�����ɫͼ
void draw_one_ball(ball d_ball)  // ����һ����
{
	// ����
	SetPenColor(d_ball.color);
	DrawCircle(d_ball.pos, R, d_ball.color);
	// �������˫ɫ���м�İ�ɫ����
	if (9 <= d_ball.id && d_ball.id <= 15)
	{
		SetPenColor("White");
		drawRectangle(d_ball.pos.x - 0.95 * R, d_ball.pos.y - 0.4 * R, 1.9 * R, 0.8 * R, 1);
	}
	// д�ϱ��
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

	// �Ǽ�ģʽ�±�ʶĿ��������һ���׻���
	if ((g_mode == DOUBLE_NINE_BALLS || g_mode == DOUBLE_SIXTEEN_BALLS) && is_target(g_turn, d_ball.id) && d_ball.present == 1)
	{
		MovePen(g_balls[d_ball.id].pos.x + R + 0.045, g_balls[d_ball.id].pos.y);
		SetPenSize(3);
		SetPenColor("White");
		DrawArc(R + 0.045, 0, 360);
	}
}

void draw_balls()  // �������е��ڳ���̨��
{
	// ����
	if (g_balls[0].present == 0 && is_allball_still(1) == 1)  // ĸ�����Ҫ����λ��
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
void draw_table()  // ����Ļ�м�������棬����ʵ�ֲ���Ҫ
{
	double pen_size_loss = 0.04;
	double loss_1 = HOLE_BALL_RATIO * R + pen_size_loss;
	double loss_2 = (pen_size_loss + loss_1) / 2;
	// ������
	SetPenSize(1);
	MovePen(g_table_llc.x, g_table_llc.y);
	StartFilledRegion(1);
	SetPenColor("Table Green");
	DrawLine(0, g_table_height);
	DrawLine(g_table_width, 0);
	DrawLine(0, -g_table_height);
	DrawLine(-g_table_width, 0);
	EndFilledRegion();
	// ���߿�
	SetPenSize(12 * TABLE_SIZE);
	SetPenColor("Edge Brown");
	// ���ڿ�
	MovePen(g_table_llc.x - pen_size_loss, g_table_llc.y - pen_size_loss);
	DrawLine(0, g_table_height + 2 * pen_size_loss);
	DrawLine(g_table_width + 2 * pen_size_loss, 0);
	DrawLine(0, -g_table_height - 2 * pen_size_loss);
	DrawLine(-g_table_width - 2 * pen_size_loss, 0);
	// �����
	SetPenSize(20 * TABLE_SIZE);
	MovePen(g_table_llc.x - loss_1, g_table_llc.y - loss_1);
	DrawLine(0, g_table_height + 2 * loss_1);
	DrawLine(g_table_width + 2 * loss_1, 0);
	DrawLine(0, -g_table_height - 2 * loss_1);
	DrawLine(-g_table_width - 2 * loss_1, 0);
	// ��������
	SetPenSize(26 * TABLE_SIZE);
	SetPenColor("Beige");
	MovePen(g_table_llc.x - loss_2, g_table_llc.y - loss_2);
	DrawLine(0, g_table_height + 2 * loss_2);
	DrawLine(g_table_width + 2 * loss_2, 0);
	DrawLine(0, -g_table_height - 2 * loss_2);
	DrawLine(-g_table_width - 2 * loss_2, 0);
	// ��װ��
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 4, g_table_llc.y + g_table_height + 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width * 3 / 4, g_table_llc.y + g_table_height + 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 4, g_table_llc.y - 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width * 3 / 4, g_table_llc.y - 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 4, g_table_llc.y + g_table_height + 0.3 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x - 0.3, g_table_llc.y + g_table_height / 2 }, 0.15, "Edge Brown");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width + 0.3, g_table_llc.y + g_table_height / 2 }, 0.15, "Edge Brown");
	// ��������
	if (g_total_round == 1 && g_mode != SINGLE_EASY)
	{
		SetPenSize(1);
		SetPenColor("White");
		MovePen(g_table_llc.x + g_table_width / 4, g_table_llc.y);
		DrawLine(0, g_table_height);
	}
	// ����
	DrawCircle((coordinate) { g_table_llc.x - pen_size_loss, g_table_llc.y - pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 2, g_table_llc.y - pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width + pen_size_loss, g_table_llc.y - pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x - pen_size_loss, g_table_llc.y + g_table_height + pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width / 2, g_table_llc.y + g_table_height + pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
	DrawCircle((coordinate) { g_table_llc.x + g_table_width + pen_size_loss, g_table_llc.y + g_table_height + pen_size_loss }, HOLE_BALL_RATIO* R, "Black");
}

void draw_stick()  // ���ƻ���ˣ�ͬʱ���ƻ���ʵ�ֽ�Ϊ���ӣ���ҪӦ����������
{
	coordinate stick_vec = (coordinate){ g_mystick.tip.x - g_mystick.tail.x, g_mystick.tip.y - g_mystick.tail.y };  // �˵ķ�������
	if (g_mystick.if_fixed == 0 && getmod((coordinate) { g_mystick.tip.x - g_balls[0].pos.x, g_mystick.tip.y - g_balls[0].pos.y }) < 0.02)  // ����δ�̶�
	{
		g_mystick.tip = g_balls[0].pos;  // �˼����ĸ��
		g_mystick.tail = (coordinate){ g_mystick.tip.x - L * (g_mystick.tip.x - g_mouse_x) / getmod((coordinate) { g_mystick.tip.x - g_mouse_x, g_mystick.tip.y - g_mouse_y }),
			g_mystick.tip.y - L * (g_mystick.tip.y - g_mouse_y) / getmod((coordinate) { g_mystick.tip.x - g_mouse_x,g_mystick.tip.y - g_mouse_y }) };
	}
	else if (g_mystick.if_fixed == 1)  // ���Ѿ��̶���׼������
	{
		coordinate move_vec = (coordinate){ g_mouse_x - g_press_pos.x, g_mouse_y - g_press_pos.y };  // ����밴�µ�λ��֮�������

		double move_vec_proj = (move_vec.x * stick_vec.x + move_vec.y * stick_vec.y) / getmod(stick_vec);  // ����밴�µ�λ��֮�������,�ڸ˷����ͶӰ�������ľ��Ծ���
		if (move_vec_proj <= 0)  // �˲��ܴ���̨��
		{
			g_mystick.tip.x = g_balls[0].pos.x + move_vec_proj * getcos(stick_vec);
			g_mystick.tip.y = g_balls[0].pos.y + move_vec_proj * getsin(stick_vec);
			g_mystick.tail.x = g_mystick.tip.x - L * getcos(stick_vec);
			g_mystick.tail.y = g_mystick.tip.y - L * getsin(stick_vec);
		}
		
			g_release_tip = g_mystick.tip;  // ʱ�̼�¼��һʱ�̸˼�λ�ã�����ʱֹͣ��¼
	}
	else if (g_mouse_out == 1)  // ����Ƶ������ⲿ���˻ص������������
	{
		g_mystick.tip = g_balls[0].pos;
	}
	else  // ���ص������а���
	{
		double hit_speed =HIT_STRENGTH * min(HIT_UPBOUND, getmod((coordinate) { g_release_tip.x - g_balls[0].pos.x, g_release_tip.y - g_balls[0].pos.y }));  // �����ٶ�,���ٶ�����
		// �˵Ļص�
		g_mystick.tip.x += hit_speed * getcos(stick_vec);
		g_mystick.tip.y += hit_speed * getsin(stick_vec);
		g_mystick.tail.x += hit_speed * getcos(stick_vec);
		g_mystick.tail.y += hit_speed * getsin(stick_vec);
		if (getmod((coordinate) { g_mystick.tip.x - g_balls[0].pos.x, g_mystick.tip.y - g_balls[0].pos.y }) < hit_speed)  // �����ж�
		{
			g_mystick.tip = g_balls[0].pos;  // �˼����
			// �������������ĸ����������������ȵĳ��ٶȣ��������������ͬ
			g_balls[0].speed = (coordinate){ hit_speed * getcos(stick_vec), hit_speed * getsin(stick_vec) };
		}
	}

	// �����˻���
	MovePen(g_mystick.tail.x, g_mystick.tail.y);
	SetPenSize(STICK_THICKNESS);
	SetPenColor("Black");
	DrawLine((g_mystick.tip.x - g_mystick.tail.x) * 2 / 5, (g_mystick.tip.y - g_mystick.tail.y) * 2 / 5);
	SetPenSize(0.8 * STICK_THICKNESS);
	SetPenColor("Beige");
	DrawLine((g_mystick.tip.x - g_mystick.tail.x) * 3 / 5 - R * getcos(stick_vec), (g_mystick.tip.y - g_mystick.tail.y) * 3 / 5 - R * getsin(stick_vec));
	MovePen(g_mystick.tip.x, g_mystick.tip.y);

}
void draw_indicator()  // ��������������ƻ���ָʾ��
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

	// ����������ֱ����С��1.99*R(��һ�����)���ڻ������������ı��
	if (hit_ball_id != -1)  // ײ��ָʾ��
	{
		SetPenColor(is_target(g_turn, hit_ball_id) ? "White" : "Red");  // ��Ŀ����ָʾ��Ϊ��ɫ������Ϊ��ɫ
		// ��Ϊ���ӵ��������㣬ʵ��ָʾ����
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

		// ������������
		draw_dot_line(cos_arc * INDICATOR_LENGTH * vec.x / (2 * R), cos_arc * INDICATOR_LENGTH * vec.y / (2 * R));  // 2R=getmod(vec)
		// ����������
		MovePen(ind_pos.x + R, ind_pos.y);
		SetPenSize(2);
		DrawArc(R, 0, 360);
		// �������������·��򣨲���ȫ׼ȷ��
		coordinate stick_vec = { g_mystick.tip.x - g_mystick.tail.x, g_mystick.tip.y - g_mystick.tail.y };
		coordinate direction = { -vec.y,vec.x };  // ȷ�������˶��ķ�������
		MovePen(ind_pos.x, ind_pos.y);
		int judge = vec.x * stick_vec.y - vec.y * stick_vec.x > 0 ? 1 : -1;  // �жϰ����˶��������ң�
		DrawLine(sin_arc * INDICATOR_LENGTH * judge * direction.x / (2 * R), sin_arc * INDICATOR_LENGTH * judge * direction.y / (2 * R));
	}
	else  // ײǽָʾ��
	{
		SetPenColor("White");
		coordinate stick_vec = { g_mystick.tip.x - g_mystick.tail.x, g_mystick.tip.y - g_mystick.tail.y };
		double t[4];  // ������Ҫ����������С��t
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

		if (hit_i == 0 || hit_i == 2)  // ��������
		{
			draw_dot_line(t[hit_i] * stick_vec.x + (getcos(stick_vec) < 0 ? 1 : -1) * R,
				t[hit_i] * stick_vec.y + (getcos(stick_vec) < 0 ? 1 : -1) * getsin(stick_vec) / getcos(stick_vec) * R);
			// ��ײǽ����·��
			stick_vec.x *= -1;
			DrawLine(INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));
			MovePen(GetCurrentX() - INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), GetCurrentY() - INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));

			MovePen(GetCurrentX() + R, GetCurrentY());
		}
		else if (hit_i == 1 || hit_i == 3)  // ��������
		{
			draw_dot_line(t[hit_i] * stick_vec.x + (getsin(stick_vec) < 0 ? 1 : -1) * getcos(stick_vec) / getsin(stick_vec) * R,
				t[hit_i] * stick_vec.y + (getsin(stick_vec) < 0 ? 1 : -1) * R);
			// ��ײǽ����·��
			stick_vec.y *= -1;
			DrawLine(INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));
			MovePen(GetCurrentX() - INDICATOR_LENGTH / 2 * stick_vec.x / getmod(stick_vec), GetCurrentY() - INDICATOR_LENGTH / 2 * stick_vec.y / getmod(stick_vec));

			MovePen(GetCurrentX() + R, GetCurrentY());
		}
		SetPenSize(2);
		DrawArc(R, 0, 360);
	}
	// �����������ʶ
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
	DrawCircle(g_balls[0].pos, 0.02, g_turn == -1 ? "Red" : "Blue");  // ��ĸ��Բ�Ļ�СԲ��
}

void draw_groove()  // �����������������ۣ�����滭���ֲ���Ҫ
{
	double r = 1.1 * R;  // ��������ļ���һ��
	double d = 0.25;  // ��������������ұ߿�ļ��

	// �����A�Ľ���ۣ���ֵ����ԣ�
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

	// ����������Ϣ��������move_ball��������ж�������޸ģ��������ѽ����λ�ã�����
	int i = 0;
	for (Node* p = g_groove_list_A; p->next != NULL; p = p->next)
	{
		g_balls[p->next->id].pos.x = g_table_llc.x - 3.3 * r - d;
		g_balls[p->next->id].pos.y = g_table_llc.y + g_table_height + 2 * i * r - 30 * r + r - HOLE_BALL_RATIO * R;
		draw_one_ball(g_balls[p->next->id]);
		i++;
	}

	// ���Ҳ�B�Ľ����
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

		// ����������Ϣ��������move_ball��������ж�������޸ģ��������ѽ����λ�ã�����
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

void drawBegin()  // �����ʼ��ѡ��ҳ��
{
	// ��д��Ϸ�����ı�
	MovePen(g_winwidth / 2 - 6, g_winheight / 2 + 5.8);
	SetPointSize(75);
	SetPenColor("Dark Yellow");
	DrawTextString("Billiards  King");
	SetPointSize(15);
	SetPenSize(2);
	// ��ʼ��ť
	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 + 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "��ʼ��Ϸ"))
	{
		g_page = NEWGAME;  // display�����condition�Զ����»���
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 + 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "��Ϸ����"))
	{
		static char all_rules[3000];  // ��ʼ�����й���ĺϲ��ı�
		all_rules[0] = '\0';
		strcat(all_rules, rule_text[0]);
		strcat(all_rules, rule_text[1]);
		strcat(all_rules, rule_text[2]);
		strcat(all_rules, rule_text[3]);
		MessageBox(NULL, all_rules, "��Ϸ����", MB_OK);
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�淨˵��"))
	{
		MessageBox(NULL, usage_text, "�淨˵��", MB_OK);
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "������Ϸ"))
	{
		MessageBox(NULL, about_text, "������Ϸ", MB_OK);
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 5, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�˳���Ϸ"))
	{
		exit(-1);
	}

}
void drawNewGame()  // �����½���Ϸ��ѡ��ģʽ��ҳ��
{
	MovePen(g_winwidth / 2 - 6.7, g_winheight / 2 + 6);
	SetPointSize(40);
	SetPenColor("Dark Yellow");
	DrawTextString("��ѡ����Ϸģʽ�����");
	SetPointSize(15);
	SetPenSize(2);
	// ѡ��һ����Ϸģʽ������ģʽ��������ҳ���������ʼ���������ݣ���ʼ��ʱ
	if (button(GenUIID(0), g_winwidth / 2 - 1.5 * BUTTONWIDTH - 1, g_winheight / 2 + 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "���˼�"))
	{
		g_mode = SINGLE_EASY;
		g_free_ball = FALSE;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 + 1, g_winheight / 2 + 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "˫�˼�"))
	{
		g_mode = DOUBLE_EASY;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 - 1.5 * BUTTONWIDTH - 1, g_winheight / 2 + 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "˫�˾���"))
	{
		g_mode = DOUBLE_NINE_BALLS;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 + 1, g_winheight / 2 + 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "˫��ʮ����"))
	{
		g_mode = DOUBLE_SIXTEEN_BALLS;
		g_page = IN_GAME;
		Init_game_data();
		g_begin_time = clock();
	}

	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 1, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "��ȡ�浵"))
	{
		read_data();  // ��������������ȫ�ֿ��Ʊ�����ֱ�ӽ����Ӧ����Ϸ����
	}
	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 3, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�� ��")) {
		g_page = BEGIN;
	}
	if (button(GenUIID(0), g_winwidth / 2 - 0.75 * BUTTONWIDTH, g_winheight / 2 - 5, 1.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�˳���Ϸ")) {
		exit(-1);
	} 

	// ����ģʽ������ʾ����ĸ���
	if (g_mode == DOUBLE_SIXTEEN_BALLS)
		g_ball_num = 16;
	else
		g_ball_num = 10;
}

void drawMenu()  // ����Ϸ�У����Ʋ˵�ҳ��
{
	// �˺�����IN_GAME״̬�µ��ã�������ʾ��Ϸ�еĲ˵�
	char* menuListFile[] =
	{    // ��ݼ��������[Ctrl-X]��ʽ�������ַ����Ľ�β
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

	// ��������Ļ���
	char* selectedLabel = NULL;
	double fH = GetFontHeight();
	double x = 0; 
	double y = g_winheight;
	double h = fH * 1.5; // �ؼ��߶�
	double w = TextStringWidth(menuListHelp[0]) * 2; // �ؼ����
	double wlist = TextStringWidth(menuListFile[0]) * 6;// �������б���
	double xindent = g_winheight / 20; // red����
	string gameMode[4] = { "���˼�", "˫�˼�", "˫�˾���", "˫��ʮ����" };
	int selection;

	SetPenSize(1);
	setMenuColors("Blue", "White", "Blue", "Red", 1);
	// File �˵�
	selection = menuList(GenUIID(0), x, y - h, w, wlist, h, menuListFile, sizeof(menuListFile) / sizeof(menuListFile[0]));

	if (FILE_STOP == selection) // ��ͣ�����
	{
		if (FALSE == g_is_pause)
			g_is_pause = TRUE;
		else if (TRUE == g_is_pause)
		{
			startTimer(TIMER_GAME, MOVE_DISC);
			g_is_pause = FALSE;
		}
	}
	if (FILE_STORE == selection)  // �������
	{
		save_data();
	}
	if (FILE_RETURN == selection)  // ����
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_page = NEWGAME;
	}
	if (FILE_EXIT == selection)  // �˳�
		exit(-1); // choose to exit

	// Help �˵�
	selection = menuList(GenUIID(0), x + w, y - h, w, wlist, h, menuListHelp, sizeof(menuListHelp) / sizeof(menuListHelp[0]));
	if (HELP_ABOUT == selection) 
		MessageBox(NULL, about_text, "������Ϸ", MB_OK);
	if (HELP_RULE == selection) 
		MessageBox(NULL, rule_text[g_mode], "��Ϸ����", MB_OK);
	if (HELP_INTRODUCE == selection) 
		MessageBox(NULL, usage_text, "�淨˵��", MB_OK);

	// ���ò˵�����Χ
	SetPenColor("Blue");
	MovePen(0, g_winheight / 1.037);
	DrawLine(g_winwidth, 0);

	SetPenSize(2);
	// ��ͣ��ť
	bool button_available = getmod((coordinate) { g_balls[0].pos.x - g_mystick.tip.x, g_balls[0].pos.y - g_mystick.tip.y }) < 0.3;  // �ж��Ƿ�û�ڻ��򣬿ɰ�
	if (!g_is_win && !g_is_pause && button(GenUIID(0), g_winwidth - 5, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "��ͣ") && button_available)
	{
		g_is_pause = TRUE;
	}

	// ������ť
	if (!g_is_win && g_is_pause && button(GenUIID(0), g_winwidth - 5, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "������Ϸ") && button_available)
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_is_pause = FALSE;
	}

	// ��ʤ�����¿�ʼ��ť
	if (TRUE == g_is_win)
	{
		setButtonColors("Cyan", "Red", "Cyan", "Red", 0);
		if (button(GenUIID(0), g_winwidth - 5, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "���¿�ʼ") && button_available)
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

	// �浵��ť����ͣ����ܱ��棩
	if (button(GenUIID(0), g_winwidth - 5, 8, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "���浱ǰ����") && button_available)
	{
		// �������
		save_data();
	}

	// ֱ�ӷ�����һ�����棬������
	if (button(GenUIID(0), g_winwidth - 5, 6, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "����") && button_available)
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_is_pause = FALSE;
		g_is_win = FALSE;
		g_page = NEWGAME;
	}

	// ������ť
	if (button(GenUIID(0), 5 - 0.5 * BUTTONWIDTH, 10, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�鿴����") && button_available)
	{
		MessageBox(NULL, rule_text[g_mode], "��Ϸ����", MB_OK);
	}

	// �������˵��������棩
	if (button(GenUIID(0), 5 - 0.5 * BUTTONWIDTH, 8, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�������˵�") && button_available)
	{
		startTimer(TIMER_GAME, MOVE_DISC);
		g_is_pause = FALSE;
		g_is_win = FALSE;
		g_page = BEGIN;
	}

	// �˳���ť
	if (button(GenUIID(0), 5 - 0.5 * BUTTONWIDTH, 6, 0.5 * BUTTONWIDTH, 2 * BUTTONHEIGHT, "�˳���Ϸ") && button_available)
	{
		exit(-1);
	}

	// ״̬��
	// ����ʱ��
	SetPenSize(1);
	if (FALSE == g_is_pause && (clock() - g_begin_time - g_total_time) < 100)
		g_total_time = (clock() - g_begin_time);
	else if (FALSE == g_is_pause && clock() - g_begin_time - g_total_time >= 100) // ���ʱ�����>0.1s����˵��֮ǰ��ͣ��������begintime��ʱ�䣨������ͣ��ʱ�䣩
	{
		g_begin_time += clock() - g_begin_time - g_total_time;
		g_total_time = (clock() - g_begin_time);
	}
	SetPenColor("Blue");
	MovePen(0, g_winheight / 25);
	DrawLine(g_winwidth, 0);
	drawLabel(g_winwidth / 40 + 3, g_winheight / 80, "��Ϸʱ�䣨�룩:");
	string str_time = (string)malloc(100 * sizeof(char));
	MovePen(g_winwidth / 40 + 6.5, g_winheight / 80);
	DrawTextString(itoa(g_total_time / 1000, str_time, 10));
	// ��ʾ��ǰģʽ
	string str_mode = (string)malloc(100 * sizeof(char));
	str_mode[0] = '\0';
	strcat(str_mode, "��ǰģʽ��");
	strcat(str_mode, gameMode[g_mode]);
	drawLabel(g_winwidth / 1.45, g_winheight / 80, str_mode);

	// �����ʤ�����ƻ�ʤ�ı�
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
			else  // ��������±�Ϊ�����򶼽���
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

void draw_text()  // ������Ϸ�е��ı�������ʵ�ֲ���Ҫ��
{
	// ��ʱ���ַ��������ڿ������
	string str = (string)malloc(100 * sizeof(char));
	string text = (string)malloc(100 * sizeof(char));
	// ��ʾ��ǰ�ִΣ���һ�����ִμ�һ��
	SetPenColor("Black");
	MovePen(GetWindowWidth() - 8, GetWindowHeight() - 3.2);
	DrawTextString("��ǰ�ִΣ�");
	MovePen(GetWindowWidth() - 5.8, GetWindowHeight() - 3.2);
	DrawTextString(itoa(g_total_round, str, 10));

	if (g_mode == SINGLE_EASY)
	{
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "��������0");
		text[strlen(text) - 1] = g_score + '0';
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "��һ�֣�");
		if (g_single_player_event.x == PREPARE)
			strcat(text, "��δ����\t");
		else if (g_single_player_event.x == WHITE_IN)
			strcat(text, "���棺������\t");
		else if (g_single_player_event.x == EMPTY)
			strcat(text, "���棺�ոˡ�\t");
		else if (g_single_player_event.x == BALL_IN)
			strcat(text, "δ���棬������\t");
		else if (g_single_player_event.x == NO_BALL_IN)
			strcat(text, "δ���棬δ����\t");
		strcat(text, "�������������");
		DrawTextString(text);
		MovePen(GetWindowWidth() - 13.75, GetWindowHeight() - 3.2);
		DrawTextString(itoa(g_single_player_event.y, str, 10));
	}
	else if (g_mode == DOUBLE_EASY)
	{
		SetPenColor("Red");
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		DrawTextString("���A��������");
		MovePen(GetWindowWidth() - 4.8, GetWindowHeight() - 2);
		DrawTextString(itoa(g_score_A, str, 10));

		SetPenColor("Blue");
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2.6);
		DrawTextString("���B��������");
		MovePen(GetWindowWidth() - 4.8, GetWindowHeight() - 2.6);
		DrawTextString(itoa(g_score_B, str, 10));

		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		MovePen(g_table_llc.x - 0.75, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "��ǰ���򷽣�A");
		text[strlen(text) - 1] = (g_turn + 1) / 2 + 'A';
		if (g_free_ball == TRUE)
			strcat(text, "(������! ����WASD����)");
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 2.6);
		text[0] = '\0';
		strcat(text, "A����һ�֣�");
		if (g_player_event[0].x == PREPARE)
			strcat(text, "��δ���� ");
		else if (g_player_event[0].x == WHITE_IN)
			strcat(text, "���棺������ ");
		else if (g_player_event[0].x == TARGET_MISS)
			strcat(text, "���棺δ�Ȼ���Ŀ���� ");
		else if (g_player_event[0].x == EMPTY)
			strcat(text, "���棺�ո�. ");
		else if (g_player_event[0].x == BALL_IN)
			strcat(text, "����Ŀ���򣬲����������ˡ� ");
		else if (g_player_event[0].x == NO_BALL_IN)
			strcat(text, "����Ŀ����δ���򣬻��ˡ� ");
		strcat(text, "�����������(����и�)��0");
		text[strlen(text) - 1] = (char)g_player_event[0].y + '0';
		DrawTextString(text);

		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "B����һ�֣�");
		if (g_player_event[1].x == PREPARE)
			strcat(text, "��δ���� ");
		else if (g_player_event[1].x == WHITE_IN)
			strcat(text, "���棺������ ");
		else if (g_player_event[1].x == TARGET_MISS)
			strcat(text, "���棺δ�Ȼ���Ŀ���� ");
		else if (g_player_event[1].x == EMPTY)
			strcat(text, "���棺�ո�. ");
		else if (g_player_event[1].x == BALL_IN)
			strcat(text, "����Ŀ���򣬲����������ˡ� ");
		else if (g_player_event[1].x == NO_BALL_IN)
			strcat(text, "����Ŀ����δ���򣬻��ˡ� ");
		strcat(text, "�����������(����и�)��0");
		text[strlen(text) - 1] = (char)g_player_event[1].y + '0';
		DrawTextString(text);
	}
	else if (g_mode == DOUBLE_NINE_BALLS)
	{
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "��ǰĿ����0");
		text[strlen(text) - 1] = get_min_ball() + '0';
		DrawTextString(text);

		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		MovePen(g_table_llc.x - 0.75, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "��ǰ���򷽣�A");
		text[strlen(text) - 1] = (g_turn + 1) / 2 + 'A';
		if (g_free_ball == TRUE)
			strcat(text, "(������! ����WASD����)");
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 2.6);
		text[0] = '\0';
		strcat(text, "A����һ�֣�");
		if (g_player_event[0].x == PREPARE)
			strcat(text, "��δ���� ");
		else if (g_player_event[0].x == WHITE_IN)
			strcat(text, "���棺������ ");
		else if (g_player_event[0].x == TARGET_MISS)
			strcat(text, "���棺δ�Ȼ���Ŀ���� ");
		else if (g_player_event[0].x == EMPTY)
			strcat(text, "���棺�ո�. ");
		else if (g_player_event[0].x == BALL_IN)
			strcat(text, "����Ŀ���򣬲��������ˡ� ");
		else if (g_player_event[0].x == NO_BALL_IN)
			strcat(text, "����Ŀ����δ���򣬻��ˡ� ");
		strcat(text, "�����������(�����и�)��0");
		text[strlen(text) - 1] = (char)g_player_event[0].y + '0';
		DrawTextString(text);

		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "B����һ�֣�");
		if (g_player_event[1].x == PREPARE)
			strcat(text, "��δ���� ");
		else if (g_player_event[1].x == WHITE_IN)
			strcat(text, "���棺������ ");
		else if (g_player_event[1].x == TARGET_MISS)
			strcat(text, "���棺δ�Ȼ���Ŀ���� ");
		else if (g_player_event[1].x == EMPTY)
			strcat(text, "���棺�ո�. ");
		else if (g_player_event[1].x == BALL_IN)
			strcat(text, "����Ŀ���򣬲��������ˡ� ");
		else if (g_player_event[1].x == NO_BALL_IN)
			strcat(text, "����Ŀ����δ���򣬻��ˡ� ");
		strcat(text, "�����������(�����и�)��0");
		text[strlen(text) - 1] = (char)g_player_event[1].y + '0';
		DrawTextString(text);
	}

	else if (g_mode == DOUBLE_SIXTEEN_BALLS)
	{
		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "���A��Ŀ����");
		if (g_target_A == ALLCOLORBALL)
			strcat(text, "���в���");
		else if (g_target_A == SMALLBALL)
			strcat(text, "���е�ɫ��1~7�ţ�");
		else if (g_target_A == BIGBALL)
			strcat(text, "����˫ɫ��9~15�ţ�");
		else if (g_target_A == BLACK_8)
			strcat(text, "��ɫ8����");
		DrawTextString(text);

		MovePen(GetWindowWidth() - 8, GetWindowHeight() - 2.6);
		text[0] = '\0';
		SetPenColor("Black");
		strcat(text, "���B��Ŀ����");
		if (g_target_B == ALLCOLORBALL)
			strcat(text, "���в���");
		else if (g_target_B == SMALLBALL)
			strcat(text, "���е�ɫ��1~7�ţ�");
		else if (g_target_B == BIGBALL)
			strcat(text, "����˫ɫ��9~15�ţ�");
		else if (g_target_B == BLACK_8)
			strcat(text, "��ɫ8����");
		DrawTextString(text);

		SetPenColor(g_turn == -1 ? "Red" : "Blue");
		MovePen(g_table_llc.x - 0.75, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "��ǰ���򷽣�A");
		text[strlen(text) - 1] = (g_turn + 1) / 2 + 'A';
		if (g_free_ball == TRUE)
			strcat(text, "(������! ����WASD����)");
		DrawTextString(text);

		SetPenColor("Black");
		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 2.6);
		text[0] = '\0';
		strcat(text, "A����һ�֣�");
		if (g_player_event[0].x == PREPARE)
			strcat(text, "��δ���� ");
		else if (g_player_event[0].x == BLACK_8_IN_ADVANCE)
			strcat(text, "��ǰ����8��������ֱ���и���");
		else if (g_player_event[0].x == WHITE_IN)
			strcat(text, "���棺������ ");
		else if (g_player_event[0].x == TARGET_MISS)
			strcat(text, "���棺δ�Ȼ���Ŀ���� ");
		else if (g_player_event[0].x == EMPTY)
			strcat(text, "���棺�ո�. ");
		else if (g_player_event[0].x == BALL_IN)
			strcat(text, "����Ŀ���򣬲���Ŀ�������ˡ� ");
		else if (g_player_event[0].x == NO_BALL_IN)
			strcat(text, "����Ŀ����δ��Ŀ���򣬻��ˡ� ");
		strcat(text, "�����������(�����и�)��0");
		text[strlen(text) - 1] = (char)g_player_event[0].y + '0';
		DrawTextString(text);

		MovePen(GetWindowWidth() - 23, GetWindowHeight() - 3.2);
		text[0] = '\0';
		strcat(text, "B����һ�֣�");
		if (g_player_event[1].x == PREPARE)
			strcat(text, "��δ���� ");
		else if (g_player_event[1].x == BLACK_8_IN_ADVANCE)
			strcat(text, "��ǰ����8��������ֱ���и���");
		else if (g_player_event[1].x == WHITE_IN)
			strcat(text, "���棺������ ");
		else if (g_player_event[1].x == TARGET_MISS)
			strcat(text, "���棺δ�Ȼ���Ŀ���� ");
		else if (g_player_event[1].x == EMPTY)
			strcat(text, "���棺�ո�. ");
		else if (g_player_event[1].x == BALL_IN)
			strcat(text, "����Ŀ���򣬲����������ˡ� ");
		else if (g_player_event[1].x == NO_BALL_IN)
			strcat(text, "����Ŀ����δ���򣬻��ˡ� ");
		strcat(text, "�����������(�����и�)��0");
		text[strlen(text) - 1] = (char)g_player_event[1].y + '0';
		DrawTextString(text);
	}
}

void draw_win_text(int winner)  // ��ʤ�󣬸���������ƻ�ʤ�ߵ��ı�
{
	// ����ʤ�����ƶ�Ӧ�ı���AΪ��ɫ��BΪ��ɫ
	SetPenColor(g_mode == SINGLE_EASY || winner == 0 ? "Red" : "Blue");
	drawRectangle(GetWindowWidth() / 2 - 4.5, 18.3, 12, 0.7, 0);
	if (g_mode == SINGLE_EASY)
	{
		MovePen(GetWindowWidth() / 2 - 4, 18.5);
		string text = (string)malloc(100 * sizeof(char));
		text = "���ѽ������������!(�ɵ�����¿�ʼ��ť����һ��)";
		DrawTextString(text);
	}
	else
	{
		MovePen(GetWindowWidth() / 2 - 4, 18.5);
		string text = (string)malloc(100 * sizeof(char));
		text[0] = '\0';
		strcat(text, "< ���ֻ�ʤ��: A > ");
		text[strlen(text) - 4] = winner + 'A';
		strcat(text, " (�ɵ�����¿�ʼ��ť����һ��)");
		DrawTextString(text);
	}
}

void display_game()  // ��Ϸ��ʾ��������û��ͣ������²��ϵ��ã�������Ϸ����
{
	// ���λ����ӡ���ۡ��򡢸�(������Ի��򣬻���ָʾ��)���ı���Ȼ����ûغϿ��ƺ���
	move_ball();
	draw_table();
	draw_groove();
	draw_balls();
	// ����
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
	// ���ƻغ�
	turn_control(0);
}

void display(int timerID) // �ؼ����������ϱ���ʱ���ص��ĺ�����ʵ��ҳ���ˢ�¡�
{
	SetPenSize(3);
	// �����������ҳ����ʾ����
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
	else if (TRUE == g_is_pause && timerID == TIMER_MENU)  // ��Ϸ��ͣ����һ֡��Ϸҳ�棨���������ݣ���ͨ��TIMER_MENUˢ�²˵�ҳ��
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