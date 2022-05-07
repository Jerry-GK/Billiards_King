#include "record.h"

// �浵����
// �������
void save_data() {
	FILE* fp1, * fp2;
	delete_data();  // ����ǰ����ɾ�����д浵

	// ��txtfiles.txt�ļ����ڴ���ı��ļ�,����һ��������
	if ((fp1 = fopen("../doc/txtfiles.txt", "w")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	fprintf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d\n",
		g_begin_time, g_total_time, g_ball_num, g_total_round, g_prev_if_all_ball_still, g_result, g_score, g_single_foul, g_score_A, g_score_B, g_target_A, g_target_B, g_turn);//int�ͱ����ı���
	fprintf(fp1, "%lf %lf %lf %lf %lf %lf\n", g_mouse_x, g_mouse_y, g_winwidth, g_winheight, g_table_width, g_table_height);
	fprintf(fp1, "%d %d %d %d\n", g_is_win, g_free_ball, g_mouse_out, g_is_pause);
	for (int i = 0; i < 4; i++)
		fprintf(fp1, "%d\n", g_is_press[i]);
	if (fclose(fp1)) {
		printf("Can not close the file!\n");
		exit(0);
	};

	// ��binaryfiles.txt�ļ����ڴ�Ŷ������ļ�,ʣ�µı����ö������ı�����
	if ((fp2 = fopen("../doc/binaryfiles.txt", "wb")) == NULL) {
		printf("File open error!\n");
		exit(0);
	}
	for (int i = 0; i < 4; i++)
		fwrite(&g_is_press[i], sizeof(g_is_press[i]), 1, fp2);

	fwrite(&g_press_pos, sizeof(g_press_pos), 1, fp2);
	fwrite(&g_release_tip, sizeof(g_release_tip), 1, fp2);
	fwrite(&g_mystick, sizeof(g_mystick), 1, fp2);

	for (int i = 0; i < 16; i++)
		fwrite(&g_balls[i], sizeof(g_balls[i]), 1, fp2);

	fwrite(&g_mystick, sizeof(g_mystick), 1, fp2);
	fwrite(&g_page, sizeof(g_page), 1, fp2);
	fwrite(&g_mode, sizeof(g_mode), 1, fp2);
	fwrite(&g_player_event[0], sizeof(g_player_event[0]), 1, fp2);
	fwrite(&g_player_event[1], sizeof(g_player_event[1]), 1, fp2);
	fwrite(&g_single_player_event, sizeof(g_single_player_event), 1, fp2);

	// �洢�����������
	fwrite(&g_groove_A_len, sizeof(g_groove_A_len), 1, fp2);
	fwrite(&g_groove_B_len, sizeof(g_groove_B_len), 1, fp2);

	for (Node* p = g_groove_list_A->next; p != NULL; p = p->next)
	{
		fwrite(&p->id, sizeof(p->id), 1, fp2);
	}

	for (Node* p = g_groove_list_B->next; p != NULL; p = p->next)
	{
		fwrite(&p->id, sizeof(p->id), 1, fp2);
	}
	if (fclose(fp2)) {
		printf("Can not close the file!\n");
		exit(0);
	}
}

// ��ȡ�浵
void read_data() {
	FILE* fp1, * fp2;
	// ��txtfiles.txt�ļ����ڶ�ȡ�ı��ļ�
	if ((fp1 = fopen("../doc/txtfiles.txt", "r")) == NULL) {
		printf("File open error!\n");
		return;
	}
	fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d\n", &g_begin_time, &g_total_time, &g_ball_num, &g_total_round, &g_prev_if_all_ball_still, &g_result, &g_score, &g_single_foul, &g_score_A, &g_score_B, &g_target_A, &g_target_B, &g_turn);//int�ͱ����ı���
	fscanf(fp1, "%lf %lf %lf %lf %lf %lf\n", &g_mouse_x, &g_mouse_y, &g_winwidth, &g_winheight, &g_table_width, &g_table_height); 
	fscanf(fp1, "%d %d %d %d\n", &g_is_win, &g_free_ball, &g_mouse_out, &g_is_pause);
	
	for (int i = 0; i < 4; i++)
		fscanf(fp1, "%d\n", &g_is_press[i]);  
	if (fclose(fp1)) {
		printf("Can not close the file!\n");
		return;
	};

	// ��binaryfiles.txt
	if ((fp2 = fopen("../doc/binaryfiles.txt", "rb")) == NULL) {
		printf("File open error!\n");
		return;
	}

	for (int i = 0; i < 4; i++)
		fread(&g_is_press[i], sizeof(g_is_press[i]), 1, fp2);

	fread(&g_press_pos, sizeof(g_press_pos), 1, fp2);
	fread(&g_release_tip, sizeof(g_release_tip), 1, fp2);
	fread(&g_mystick, sizeof(g_mystick), 1, fp2);

	for (int i = 0; i < 16; i++)
		fread(&g_balls[i], sizeof(g_balls[i]), 1, fp2);

	fread(&g_mystick, sizeof(g_mystick), 1, fp2);
	fread(&g_page, sizeof(g_page), 1, fp2);
	fread(&g_mode, sizeof(g_mode), 1, fp2);
	fread(&g_player_event[0], sizeof(g_player_event[0]), 1, fp2);
	fread(&g_player_event[1], sizeof(g_player_event[1]), 1, fp2);
	fread(&g_single_player_event, sizeof(g_single_player_event), 1, fp2);

	delete_list(g_groove_list_A);
	delete_list(g_groove_list_B);
	fread(&g_groove_A_len, sizeof(g_groove_A_len), 1, fp2);
	fread(&g_groove_B_len, sizeof(g_groove_B_len), 1, fp2);

	// ��ȡ�����������
	Node* p;
	g_groove_list_A = (Node*)malloc(sizeof(Node));
	g_groove_list_A->id = -1;
	g_groove_list_A->next = NULL;
	for (int i = 0; i < g_groove_A_len; i++)
	{
		for (p = g_groove_list_A; p->next != NULL; p = p->next)
		{

		}
		p->next = (Node*)malloc(sizeof(Node));
		fread(&p->next->id, sizeof(p->next->id), 1, fp2);
		p->next->next = NULL;
	}

	g_groove_list_B = (Node*)malloc(sizeof(Node));
	g_groove_list_B->id = -2;
	g_groove_list_B->next = NULL;

	for (int i = 0; i < g_groove_B_len; i++)
	{
		for (p = g_groove_list_B; p->next != NULL; p = p->next)
		{

		}
		p->next = (Node*)malloc(sizeof(Node));
		fread(&p->next->id, sizeof(p->next->id), 1, fp2);
		p->next->next = NULL;
	}

	if (fclose(fp2)) {
		printf("Can not close the file!\n");
		return;
	}
}

// ɾ���浵�����¶���ʱ���ã�
void delete_data()
{
	if (remove("../doc/txtfiles.txt") == 0) // ɾ���浵�ļ�
		printf("Deleted successfully\n");
	else
	{
		printf("Unable to delete the file\n");
		return;
	}
	if (remove("binaryfiles.txt") == 0)

		printf("Deleted successfully\n");
	else
	{
		printf("Unable to delete the file\n");
		return;
	}
}
