#include "contact.h"

//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
static void Menu()
{
	printf("############################\n");
	printf("# 1. Add           2. Del  #\n");
	printf("# 3. Search        4. Mod  #\n");
	printf("# 5. Show          6. Cls  #\n");
	printf("# 7. Sort          0. Quit #\n");
	printf("############################\n");
	printf("Please Select:> ");
}

int main()
{
	contact_t ct;
	memset(&ct, 0, sizeof(ct));
	ct.cap = TOTAL;

	int quit = 0;
	int select = 0;
	while (!quit){
		Menu();
		scanf("%d", &select);
		switch (select){
			case 1: //Add 
				AddPerson(&ct);
				break;
			case 2:
				DeletePerson(&ct);
				break;
			case 3:
				//查找指定联系人信息
				SearchPerson(&ct);
				break;
			case 4:
				ModPerson(&ct);
				break;
			case 5:
				ShowContact(&ct, -1);
				break;
			case 6:
				//清空所有联系人
				ClsContact(&ct);
				break;
			case 7:
				//以名字排序所有联系人
				SortContact(&ct);
				break;
			default:
				quit = 1;
				break;
		}
	}

	system("pause");
	return 0;
}