#include "stdafx.h"
#include"data.h"
#include"view.h"


//��������:�����ݷ����б������չʾ

int view(CONF *data) {
	int num;
	SERVELISTNODE *C = data->elevator->serve_list;
	if (C == NULL)return 0;;

	puts("\n���ݹ���״̬:");
	for (num = 1; C != NULL; num++)
	{
		printf("�����еĵ�%d�ˣ�����Ŀǰ״̬��%c����%d��ȥ%d��\n", num, C->serve_state, C->user_call->user_floor, C->user_call->user_target);
		C = C->next_node;
	}
	putchar('\n');
	return 0;
}

