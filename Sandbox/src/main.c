//test Dynamic List

#include <CDataStructs\List.h>
#include <CDataStructs\Logger.h>

#include <stdlib.h>

typedef struct
{
	uint32_t age;
	uint32_t sex;
	char* name;

} Aniamal;

Aniamal* CreateAnimal(const char* name, uint32_t age, uint32_t sex)
{
	Aniamal* a = malloc(sizeof(Aniamal));
	a->age = name;
	a->sex = sex;
	a->name = name;
	return a;
}

void FreeMethod(void* data)
{
	CDataStructs_LogMessage(((Aniamal*)data)->name);
	//free(((Aniamal*)data)->name);
	free(data);
	data = NULL;
}

int main(int args, char* argv[])
{
	Aniamal* an1 = CreateAnimal("Mooo", 16, 2000);
	Aniamal* an2 = CreateAnimal("Die", 12226, 2990);
	Aniamal* an3 = CreateAnimal("Cutt", 100, 20);

	CDataStructs_List* animals = CDataStructs_List_Create(sizeof(Aniamal));
	CDataStructs_List_Append(animals, an1);
	CDataStructs_List_Append(animals, an2);
	CDataStructs_List_Append(animals, an3);

	CDataStructs_List_Print(animals);

	CDataStructs_List_RemoveItem(animals, an1, FreeMethod);
	CDataStructs_List_RemoveItem(animals, an3, FreeMethod);

	CDataStructs_List_Print(animals);

	CDataStructs_List_Destroy(animals, FreeMethod);

	getchar(); //hold console
	return 0;
}