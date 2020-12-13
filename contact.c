#include "contact.h"

static int IsFull(contact_t *ct)
{
	assert(ct);
	return ct->size == ct->cap;
}
//exist: person index
//not exist: -1
static int IsExist(contact_t *ct, const char *telphone)
{
	assert(telphone);
	person_t *end = ct->persons + ct->size;
	int index = 0;
	for (person_t *p = ct->persons; p < end; p++, index++){
		if (0 == strcmp(p->telphone, telphone)){
			//return p - ct->persons;
			return index;
		}
	}
	return -1;
}
static void SearchPersonTelHelper(contact_t *ct)
{
	assert(ct);

	char search_key[SIZE / 4];
	printf("请输入你要查找人的电话号码# ");
	scanf("%s", search_key);

	int index = IsExist(ct, search_key);
	if (-1 == index){
		printf("你要找的人[%s]不存在!\n", search_key);
		return;
	}
	else{
		ShowContact(ct, index);
	}
}
static int CompPerson(const void *x, const void *y)
{
	person_t *x_p = (person_t *)x;
	person_t *y_p = (person_t *)y;

	return strcmp(x_p->name, y_p->name);
}

void AddPerson(contact_t *ct)
{
	assert(ct);

	if (IsFull(ct) /*IsExist()*/){
		printf("contact is full!\n");
		return;
	}
	person_t *p = ct->persons + ct->size;
	printf("姓名# ");
	scanf(" %s", p->name);
	printf("电话# ");
	scanf(" %s", p->telphone);
	if (IsExist(ct, p->telphone) >= 0){
		printf("%s is exist!\n", p->name);
		return;
	}
	printf("性别# ");
	scanf(" %c", &(p->sex));
	printf("年纪# ");
	scanf(" %d", &(p->age));
	printf("地址# ");
	scanf(" %s", p->address);
	ct->size += 1;

	printf(" ...  add success ！\n");
}
void DeletePerson(contact_t *ct)
{
	assert(ct);

	char del_key[SIZE / 4];
	printf("请输入你要删除人的电话号码# ");
	scanf("%s", del_key);
	int index = 0;
	if ((index = IsExist(ct, del_key)) >= 0){
		//删他
		ct->persons[index] = ct->persons[ct->size - 1];
		ct->size -= 1;
	}
	else{
		printf("你要删除的用户 [ %s ]， 是不存在的!\n", del_key);
	}
}

void SearchPerson(contact_t *ct)
{
	assert(ct);
	printf("###########################\n");
	printf("# 1. 按照姓名  2. 按照电话#\n");
	printf("###########################\n");
	printf("select:> ");
	int select = 0;
	scanf("%d", &select);
	switch (select){
	case 1:
		//TODO
		break;
	case 2:
		SearchPersonTelHelper(ct);
		break;
	}
}

void ModPerson(contact_t *ct)
{
	assert(ct);
	//查找
	//修改特定信息
}

void ClsContact(contact_t *ct)
{
	assert(ct);
	ct->size = 0;
}

void SortContact(contact_t *ct)
{
	assert(ct);
	qsort(ct->persons, ct->size, sizeof(person_t), CompPerson);
}
void ShowContact(contact_t *ct, int index)
{
	assert(ct);
	if (-1 == index){
		person_t *end = ct->persons + ct->size;
		//姓名、性别、年龄、电话、住址
		printf("统计: %d/%d\n", ct->size, ct->cap);
		printf("----------------------------------------\n");
		for (person_t *p = ct->persons; p < end; p++){
			printf("|%-8s|%-2c|%-3d|%-11s|%-10s|\n", \
				p->name, p->sex, p->age, p->telphone, p->address);
		}
		printf("----------------------------------------\n");
	}
	else{
		person_t *p = ct->persons + index;
		printf("|%-8s|%-2c|%-3d|%-11s|%-10s|\n", \
			p->name, p->sex, p->age, p->telphone, p->address);
	}
}