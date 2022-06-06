#include <iostream>


void printMatrix(int** arr, int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            std::cout << arr[i][j] << " ";
        std::cout << '\n';
    }
}
int ** rotateMatrix(int** a, int N)
{


    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N- i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
    return a;
  
}


int main()
{
    
    int N, M;
    std::cout << "Please enter the mass size -> \nN=";
    std::cin >> N; 

    int** a = new int* [N];
    for (int i = 0; i < N; ++i)
        a[i] = new int[N];

    for (int i = 0; i < N; i++) {
        std::cout << "Enter the " << i << "rd line, consisting of " << N << "numbers\n";
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }
    std::cout << "______________________________________________\n";
    printMatrix(a, N);
    a= rotateMatrix(a, N);
    std::cout << "______________________________________________\n";
    printMatrix(a, N);
    return 0;
}