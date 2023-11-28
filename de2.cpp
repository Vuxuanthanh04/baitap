#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define faster                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);

class OperatorInsertion
{
private:
    int n, s;
    vector<int> a;
    int sum;

public:
    OperatorInsertion(int n, int s) : n(n), s(s), a(n + 1), sum(n * (n + 1) / 2) {}

    void insertOperators()
    {
        FOD(i, n, 1)
        {
            if (sum - 2 * i >= s)
            {
                a[i] = 1;
                sum -= 2 * i;
            }
        }
    }

    bool hasSolution()
    {
        return sum == s;
    }

    void generateSolution()
    {
        if (hasSolution())
        {
            if (a[1])
            {
                FOR(i, 4, n)
                {
                    if (a[1] == 0)
                        break;
                    if (a[i])
                    {
                        FOR(j, 2, i / 2)
                        if (a[j] == 0 && a[i + 1 - j] == 0)
                        {
                            a[j] = a[i + 1 - j] = 1;
                            a[1] = a[i] = 0;
                            break;
                        }
                    }
                }
                if (a[1])
                {
                    cout << "Impossible";
                    return;
                }
            }
            cout << "1";
            FOR(i, 2, n)
            cout << ((a[i] == 1) ? '-' : '+') << i;
        }
        else
        {
            cout << "Impossible";
        }
    }
};

int main()
{
    // freopen("INP.TXT", "r", stdin);
    // freopen("OUT.TXT", "w", stdout);

    int n, s;
    scanf("%d%d", &n, &s);

    OperatorInsertion operatorInsertion(n, s);

    operatorInsertion.insertOperators();
    operatorInsertion.generateSolution();

    return 0;
}

