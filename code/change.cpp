#include"stdafx.h"
#include"data.h"
#include"response.h"
#include"change.h"


//��������:�ı����Ϊ��һ�������״̬


int change(CONF *data)
{
	int floor = data->elevator->current_floor;
	int i;
	SERVELISTNODE *A = data->elevator->serve_list;
	
	switch (data->elevator->run_state)
	{
	case 'U'://����״̬ 
		for (i = 0; A != NULL; i++)//��������ָ���б�
		{
			if (A->user_call->user_target == floor + 1 && A->serve_state == 'E')
			{
				
				data->elevator->run_state = 'S';
				delete2(data, A);
			}

			if (A->user_call->user_floor == floor + 1 && A->serve_state == 'P')
			{
				
				data->elevator->run_state = 'S';
				A->serve_state = 'E';
			}
			A= A->next_node;
		}
		data->elevator->current_floor++;
		break;
	case 'D'://�½�״̬ 
		for (i = 0; A != NULL; i++)//��������ָ���б�
		{
			if (A->user_call->user_target == floor - 1 &&A->serve_state == 'E')//�û��µ���
			{
				
				data->elevator->run_state = 'S';
				delete2(data, A);
			}
			if (A->user_call->user_floor == floor - 1 && A->serve_state == 'P')//�û��ϵ���
			{
				
				data->elevator->run_state = 'S';
				A->serve_state = 'E';
			}
			A = A->next_node;
		}
		data->elevator->current_floor--;
		break;
	case 'S'://ֹͣ״̬ 
		if (A != NULL)
		{
			if (A->serve_state == 'E')
			{
				if (A->user_call->user_target >floor)
					data->elevator->run_state = 'U';
				else data->elevator->run_state = 'D';
			}
			else
			{
				if (A->user_call->user_floor >floor)
					data->elevator->run_state = 'U';
				else data->elevator->run_state = 'D';
			}
			A = A->next_node;
		}
		break;
	}
	return 0;
}