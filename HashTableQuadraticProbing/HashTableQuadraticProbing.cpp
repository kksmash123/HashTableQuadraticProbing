// HashTableQuadraticProbing.cpp 



#include <iostream>
#define sh 10

using namespace std;

int Hash(int key);
int QuadraticProbing(int ht[], int i);
void insert(int ht[], int key);
int search(int ht[], int key);



int Hash(int key)
{
	return key % sh;
}


int QuadraticProbing(int ht[],int i)
{
	int k = 1;

	while (ht[(i + (k * k)) % sh] != 0)
		k++;

	return (i + (k * k)) % sh;
}


void insert(int ht[], int key)
{
	int i = Hash(key);

	if (ht[i] != 0)
	{
		i = QuadraticProbing(ht, i);
	}
	ht[i] = key;
}


int search(int ht[], int key)
{
	int i = Hash(key);
	int k = 0;
	while (ht[(i+(k*k))%sh] != key)
	{
		k++;
		if (ht[(i + (k * k)) % sh] == 0)
			return -1;
	}
	return (i + (k * k)) % sh;
}


int main()
{
	//hashtable
	int ht[10] = { 0 };

	int a[4] = {23,43,13,27};
	int n = sizeof(a) / sizeof(a[0]);

	//inserting in the hashtable

	for (int i = 0;i < n;i++)
		insert(ht, a[i]);

	//searching in the hashtable
	search(ht,27);




	return 0;

}
