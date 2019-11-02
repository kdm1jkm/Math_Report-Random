#include <iostream>

using namespace std;

int howLongNum(int num);

int main()
{
	int seed;
	int a;
	int repeat;

	//시드(Seed)입력받기
	cout << "Enter the seed: ";
	cin >> seed;
	a = howLongNum(seed);

	//난수 갯수 입력받기
	cout << "How many random numbers: ";
	cin >> repeat;

	int sum = 0;

	for (int i = 0; i < repeat; i++)
	{
		seed = pow(seed, 2);
		int len = howLongNum(seed) - a;

		seed = seed / pow(10, len - (len / 2));
		seed = seed % int(pow(10, a));
		sum += seed;

		cout << seed << endl;
	}
	
	cout << endl << "Average: " << double(sum) / repeat << endl;

	return 0;
}

int howLongNum(int num)
{
	int sum = 0;
	while (num != 0)
	{
		num /= 10;
		sum += 1;
	}
	return sum;
}