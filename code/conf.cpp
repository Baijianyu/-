#include "stdafx.h"
#include "data.h"
 
//�������ܣ���ʼ������
int fillform(CONF *data) {
	data->time = 0;
	data->elevator = (ELEVATORSTATE *)malloc(sizeof(ELEVATORSTATE));
	data->elevator->current_floor = 1;
	data->elevator->run_state = 'S';
	data->elevator->serve_list = NULL;
	data->readynode.list_num = 0;
	data->elevator->serve_list = NULL;
	data->ii = 0;
	data->filename = "�ı��ļ�.txt";
	return 0;
}