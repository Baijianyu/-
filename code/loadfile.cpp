#include "stdafx.h"
#include"data.h"
#include"loadfile.h"
//�������ܣ�����
int cmp(const void *a, const void *b) {
	return ((int*)a)[2] - ((int*)b)[2];
}

//�������ܣ����ļ��е����ݵ���
int fileread(CONF *data) {
	FILE *fp;
	fp = fopen(data->filename, "r");
	fscanf(fp, "%d", &data->leng);
	data->dataitem = (DATAITEM *)malloc(sizeof(DATAITEM)* data->leng);
	int num;
	for (num = 0; num != data->leng; num++)
		fscanf(fp, "%d,%d,%d", &data->dataitem[num].item1, &data->dataitem[num].item2, &data->dataitem[num].item3);

	printf("�����ǵ�����Ҫ������б�\n");
	Sleep(1000);
	printf("һ����%d�˵ȴ����ݷ���\n", data->leng);
	Sleep(1000);
	printf("��������¥�㣬Ŀ��¥�㣬�ͷ���ָ���ʱ������\n");
	Sleep(1000);
	qsort(data->dataitem, data->leng, sizeof(DATAITEM), cmp);
	for (num = 0; num < data->leng; num++) {
		printf("%d %d %d\n", data->dataitem[num].item1, data->dataitem[num].item2, data->dataitem[num].item3);
		Sleep(1000);
	}
	fclose(fp);
	return 0;

}
























