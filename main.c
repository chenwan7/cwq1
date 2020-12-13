#include "contact.h"

//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
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
				//����ָ����ϵ����Ϣ
				SearchPerson(&ct);
				break;
			case 4:
				ModPerson(&ct);
				break;
			case 5:
				ShowContact(&ct, -1);
				break;
			case 6:
				//���������ϵ��
				ClsContact(&ct);
				break;
			case 7:
				//����������������ϵ��
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