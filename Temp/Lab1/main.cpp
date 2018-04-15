#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int lin(int*mas,int N,int vale)
{
    for (int i=0; i<N; i++)
        if (mas[i]==vale) return i;
    return -1;
}

int bin (int *arr,int N, int val)
{
    int left=0, right=N-1;
    while (1)
    {
        int midl = (left+right) / 2;
        if (val<arr[midl]) right = midl-1;
        else if (val>arr[midl]) left = midl+1;
        else return midl;
        if (left>right) return -1;
    }

}

void sortb(int *arr, int N)
{
    for (int i=0; i<N-1; i++)
        for (int j=i; j<N; j++)
            if (arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
}

int main()
{
    srand(time(0));

    int N;
    cout << "Введите длинну массива << ";
    cin>>N;

    int arr[N];

    cout <<"1 - пользовательский ввод, 2 - заполнение случайными числами ... ";
    char s;
    cin >> s;

    switch (s)
    {
        case '1':
        {
            for (int i=0; i<N; i++)
                cin>>arr[i];

        } break;
        case '2':
        {
            for (int i=0; i<N; i++) arr[i] = rand() % 100;
        } break;
        default:
        {
            cout << "Ошибка!" << endl;
            return 0;
        }
    }

    sortb(arr,N);
    for (int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    cout << endl << "Введите искомое число << ";
    int val;
    cin >> val;
    cout << "Индекс искомого числа в массиве(лин. поиск): " << lin(arr, N, val) << endl;
    cout << "Индекс искомого числа в массиве(бин. поиск): " << bin(arr, N, val) << endl;

    return 0;
}

