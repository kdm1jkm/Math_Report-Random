#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define A (1103515245)
#define C (12345)
#define M (long long int(pow(2, 31)))

using namespace std;

int main()
{
	FILE* f = fopen("data.txt", "w");
	long long unsigned int num;
	int repeat;
	cout << "Enter the Seed: ";
	cin >> num;
	cout << "How may random numbers: ";
	cin >> repeat;

	long long unsigned int sum = 0;

	for (int i = 0; i < repeat; i++)
	{
		num = (num * A + C) % M;
		sum += num;

		//cout << num << endl;
		fprintf(f, "%d\n", num);
	}
	cout << endl << "Average: " << double(sum) / repeat << endl;
	cout << M / (double(sum) / repeat) << endl;

	fclose(f);

	return 0;
}