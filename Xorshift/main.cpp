#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	unsigned int num, repeat;
	cout << "Enter the seed: ";
	cin >> num;
	cout << "How many random numbers: ";
	cin >> repeat;

	long long unsigned int sum = 0;

	for (int i = 0; i < repeat; i++)
	{
		num ^= num << 13;
		num ^= num >> 17;
		num ^= num << 5;

		sum += num;

		//cout << num << endl;
	}

	cout << endl << "Average: " << double(sum) / repeat << endl;
	cout << (double(sum) / repeat) / 0xFFFFFFFF << endl;

	return 0;
}