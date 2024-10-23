import java.io.*;

public class Main {

    static BufferedReader ins = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer in = new StreamTokenizer(ins);
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

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

    public static void main(String[] args) throws IOException {
        in.nextToken();
        int N = (int)in.nval;
        int n = 1, rest = N, cnt = 0;
        while (n <= N)
        {
            if (getd(n) % 2 == 1)
            {
                cnt += Math.min(9 * n, rest);
            }
            rest -= 9 * n;
            n *= 10;
        }
        out.println(cnt);
        out.close();
    }
}