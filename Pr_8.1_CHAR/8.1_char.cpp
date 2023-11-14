#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


int Count(char* s)
{
	int k = 0;
	char* t = s;

	while ((t = strstr(t, "!!!")) != nullptr) // Using strstr to find "!!!"
	{
		k++;
		t += 3; // Move the pointer to the next position after "!!!"
	}

	return k;
}



char* Change(char* s)
{
	char* t = new char[strlen(s) * 3 + 1];  // Allocate enough space for the modified string
	char* p;
	int pos1 = 0,  // pos1 = позиція початку пошуку
		pos2 = 0;
	*t = '\0';

	while ((p = strstr(s + pos1, "!!!")) != nullptr)  // Using strstr to find "!!!"
	{
		pos2 = p - s + 3;  // pos2 = позиція наступного символа після "!!!"
		strncat(t, s + pos1, pos2 - pos1 - 3);
		strcat(t, "** ");
		pos1 = pos2;
	}

	strcat(t, s + pos1);
	strcpy(s, t);
	delete[] t;
	return s;
}



int main()
{
	char str[101];

		cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str) << " groups of '!!!'" << endl;

	char* dest = new char[151];
	dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}