#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int fibo(int n)
{
    int a = 0;
    int b = 1;
    while (n > 1) {
        long t =a;
        a = b;
        b= b+ t;
        n--;
    }
    
}

int main()
{
    int n;
    cout << "enter n:";
    cin >> n;
    cout << "fibonacci(" << n <<")" << fibonacci(n) << endl;
    cout << "fibo(" << n <<")" << fibo(n) << endl;
    return 0;

}