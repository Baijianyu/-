#include"stdafx.h"
#include"data.h"
#include"response.h"
#include"check.h"

//��������:����Ƿ���Կ���ͬʱ��Ӧ����û�ָ��


int checkinstruct(CONF *data)
{
	int floor = data->elevator->current_floor;
	char state = data->elevator->run_state;
	RESPONSELISTHEADNODE node = data->readynode;
	RESPONSELISTNODE  *A = node.head;
	int i;
	switch (state)
	{
	case 'U'://����״̬ 
		for (i = 0; i < node.list_num && A != NULL; i++)//��������Ӧָ���б�
		{
			if (floor < A->user_call->user_floor && A->user_call->user_floor <  A->user_call->user_target)
			{
				ftol2(A, data, 0);

				delete1(data,A);
			}
			A = A->next_node;
		}
		break;
	case 'D'://�½�״̬ 
		for (i = 0; i < node.list_num&&A != NULL; i++)//��������Ӧָ���б�
		{
			if (floor > A->user_call->user_floor && A->user_call->user_floor >  A->user_call->user_target)
			{
				ftol2(A, data, 0);
				delete1(data, A);
			}
			A = A->next_node;
		}
		break;
	case 'S'://ֹͣ״̬ 
		if (data->elevator->serve_list->user_call->user_target > floor)//��������Ӧָ���б�
		{
			for (i = 0; i < node.list_num && A != NULL; i++)
			{
				if (A->user_call->user_floor >= floor && A->user_call->user_floor < A->user_call->user_target)
				{
					ftol2(A, data, floor == A->user_call->user_floor);
					delete1(data, A);
				}
				A = A->next_node;
			}
		}
		else
		{
			for (i = 0; i < node.list_num && A != NULL; i++)//��������Ӧָ���б�
			{
				if (A->user_call->user_floor <= floor && A->user_call->user_floor >A->user_call->user_target)
				{
					ftol2(A, data, floor == A->user_call->user_floor);
					delete1(data, A);
				}
				A = A->next_node;
			}
		}
	}
	return 0;
}
