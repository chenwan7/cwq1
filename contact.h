#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>

#define SIZE 128
#define TOTAL 1000

#pragma warning(disable:4996)

//�������Ա����䡢�绰��סַ
typedef struct person{
	char name[SIZE/4];
	char sex; //f,m
	int age;
	char telphone[SIZE/4];   //key
	char address[SIZE];
}person_t;

typedef struct contact{
	int size; //��ǰ�ж�����
	int cap; //�������Ƕ���
	person_t persons[TOTAL];
}contact_t;

void AddPerson(contact_t *ct);
void DeletePerson(contact_t *ct);
//index :-1 :show all
//index>=0 : show index person
void ShowContact(contact_t *ct, int index);
void SearchPerson(contact_t *ct);
void ModPerson(contact_t *ct); //�������
void ClsContact(contact_t *ct);
void SortContact(contact_t *ct);

#endif