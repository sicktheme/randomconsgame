#include <iostream>

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int sum(int* a, int size = 3)
{
    int result{ 0 };
    for (int i = 0; i < size; i++)
        result += a[i];
    return result;
}

int main()
{
    setlocale(0, "ru");
    int arr[5][3]{
        {6,7,8},
        {7,8,9},
        {6,9,10},
        {6,9,8},
        {7,6,10} };

    for (int i = 0; i < 5; i++)
    {
        cout << "Array #" << i + 1 << ": ";
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    int num{ 0 };

    while (num < 1 || num > 5)
    {
        cout << "\nSelect number array (1-5): ";
        cin >> num;
    }

    cout << "You select array #" << num << ": ";

    for (int& i : arr[num - 1])
        cout << i << ' ';

    cout << '\n';

    srand(static_cast<unsigned int>(time(0)));
    getRandomNumber(rand(), rand());
    int rand = getRandomNumber(1, 5);
    cout << "Computer select array # " << rand << ": ";
    for (int& i : arr[rand - 1])
        cout << i << ' ';

    int player = sum(arr[num - 1]);
    cout << "\nSum your array #" << num << " is: " << player;
    int pc = sum(arr[rand - 1]);
    cout << "\nSum computer array # " << rand << " is: " << pc;

    cout << '\n';
    player > pc ? cout << "You Win!" : player < pc ? cout << "Computer Win!" : cout << "Draw!";

    char ch = 'a';
    while (true)
    {
        cout << "\n\nWant repeat? Press: Y or N: ";
        cin >> ch;

        if (ch == 'Y')
        {
            system("cls");
            // int main();
        }

        if (ch == 'N')
        {
            cout << "\nGame Over!";
            break;
        }
    }
}