#include "stdafx.h"
#include"data.h"
#include"loadfile.h"
#include"view.h"
#include"conf.h"
#include"main.h"
#include"check.h"
#include"response.h"
#include"view.h"
#include"change.h"

int run(int argc, char* argv[]) {
	CONF *data = (CONF *)malloc(sizeof(CONF));
	fillform(data);
	system("�����ļ�.exe");
	fileread(data);
	while (data->leng)
	{
		while (data->dataitem[data->ii].item3 == data->time)//���﷢��ָ���ʱ�� 
			elect(data);//����һ���û�ָ�����Ӧ�� 
		if (data->elevator->run_state != 'S')//�������Ŀǰֹͣ 
			checkinstruct(data);//���������Ӧ��ָ�� 
		else if (data->readynode.list_num > 0 && data->elevator->serve_list == NULL)
		{
			ftol1(data);//��һ���û����ݴӴ���Ӧ�б��ͷ��������ݷ����б��β��  
			checkinstruct(data);	//���������Ӧ���ָ�� 
		}
		change(data);//�ı����Ϊ��һ�������״̬ 
		view(data);//������״̬��ʾ����Ļ�� 
		data->time++;
		printf("������%d¥��״̬��%c��ʱ����%d\n", data->elevator->current_floor, data->elevator->run_state, data->time);
		Sleep(1000);
		if (data->time > 80)break;
		
	}
	printf("���ݳɹ�������񣬹���ʱ%d�� \n", data->time);
	system("pause");
	return 0;
}





