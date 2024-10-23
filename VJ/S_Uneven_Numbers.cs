using System;

internal class Program
{
    private static int getd(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            ans++;
            n /= 10;
        }
        return ans;
    }

    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        int n = 1, rest = N, cnt = 0;
        while (n <= N)
        {
            if (getd(n) % 2 == 1)
            {
                cnt += Math.Min(9 * n, rest);
            }
            rest -= 9 * n;
            n *= 10;
        }
        Console.WriteLine(cnt);
    }
}