using System;
class Abydos
{
    static void Main(string[] args)
    {
        Hoshino a = new Hoshino();
        a.main(args);
    }
}

class Hoshino
{
    const long mod = (long)1e9;
    int n;
    string s;
    long[, ] dp;
    public void main(string[] args)
    {
        s = ' ' + Console.ReadLine();
        n = s.Length - 1;
        dp = new long[n + 5, n + 5];
        for (int i = 1; i <= n; i++)
            dp[i, i] = 1;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1, j; (j = i + len - 1) <= n; i++)
            {
                if (s[i] != s[j])
                    continue;
                for (int k = i + 1; k < j; k++)
                    if (s[i] == s[k])
                        dp[i, j] = (dp[i, j] + dp[i, k] * dp[k + 1, j - 1]) % mod;
                dp[i, j] = (dp[i, j] + dp[i + 1, j - 1]) % mod;
            }
        }
        Console.Write(dp[1, n]);
    }
}