#include <bits/stdc++.h>

using namespace std;

class LinearRecurrence
{
    using ll = long long;
    using vec = vector<long long>;

  private:
    static const int N = 50010; // 多项式系数最大值

    vec init, coef;
    ll res[N], base[N], c[N], md[N], mod;
    vector<int> Md;

    ll exgcd(ll a, ll b, ll &x, ll &y)
    {
        if (!b)
        {
            x = 1, y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }

    ll inv(ll a, ll mod)
    {
        ll x, y;
        return exgcd(a, mod, x, y) == 1 ? (x % mod + mod) % mod : -1;
    };

    void mul(ll *a, ll *b, int k)
    {
        fill(c, c + 2 * k, 0);
        for (int i = 0; i < k; i++)
            if (a[i])
                for (int j = 0; j < k; j++)
                    c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
        for (int i = 2 * k - 1; i >= k; i--)
            if (c[i])
                for (size_t j = 0; j < Md.size(); j++)
                    c[i - k + Md[j]] = (c[i - k + Md[j]] - c[i] * md[Md[j]]) % mod;
        copy(c, c + k, a);
    }

    ll solve(ll n, vec a, vec b) // a系数 b初值 b[n+1]=a[0]*b[n]+a[1]*b[n-1]+...
    {
        ll ans = 0, cnt = 0;
        int k = a.size();
        for (int i = 0; i < k; i++)
            md[k - i - 1] = -a[i];
        md[k] = 1;
        Md.clear();
        for (int i = 0; i < k; i++)
        {
            res[i] = base[i] = 0;
            if (md[i])
                Md.push_back(i);
        }
        res[0] = 1;
        while ((1LL << cnt) <= n)
            cnt++;
        for (int p = cnt; ~p; p--)
        {
            mul(res, res, k);
            if ((n >> p) & 1)
            {
                for (int i = k - 1; ~i; i--)
                    res[i + 1] = res[i];
                res[0] = 0;
                for (size_t j = 0; j < Md.size(); j++)
                    res[Md[j]] = (res[Md[j]] - res[k] * md[Md[j]]) % mod;
            }
        }
        for (int i = 0; i < k; i++)
            ans = (ans + res[i] * b[i]) % mod;
        return ans + (ans < 0 ? mod : 0);
    }

    // ****************************************
    // 模数是质数
    vec BerlekampMassey(vec s)
    {
        vec C = {1}, B = {1};
        int L = 0, m = 1, b = 1;
        for (size_t n = 0; n < s.size(); n++)
        {
            ll d = 0;
            for (int i = 0; i <= L; i++)
                d = (d + (ll)C[i] * s[n - i]) % mod;
            if (!d)
                m++;
            else
            {
                vec Y(C);
                ll c = mod - d * inv(b, mod) % mod;
                while (C.size() < B.size() + m)
                    C.push_back(0);
                for (size_t i = 0; i < B.size(); i++)
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                if (2 * L <= (int)n)
                {
                    L = n + 1 - L;
                    B = Y;
                    b = d;
                    m = 1;
                }
                else
                    m++;
            }
        }
        return C;
    }
    // ****************************************

    // ****************************************
    // 模数不是质数
    void extand(vec &a, size_t d, ll value = 0)
    {
        if (d <= a.size())
            return;
        a.resize(d, value);
    }

    ll crt(const vec &c, const vec &m)
    {
        int n = c.size();
        ll M = 1, ans = 0;
        for (int i = 0; i < n; i++)
            M *= m[i];
        for (int i = 0; i < n; i++)
        {
            ll x, y, tM = M / m[i];
            exgcd(tM, m[i], x, y);
            ans = (ans + tM * x * c[i] % M) % M;
        }
        return (ans + M) % M;
    }

    int L(const vec &a, const vec &b)
    {
        int da = (a.size() > 1 || (a.size() == 1 && a[0])) ? a.size() - 1 : -1000;
        int db = (b.size() > 1 || (b.size() == 1 && b[0])) ? b.size() - 1 : -1000;
        return max(da, db + 1);
    }

    pair<vec, vec> prime_power(const vec &s, ll mod, ll p, ll e)
    {
        // linear feedback shift register mod p^e, p is prime
        vector<vec> a(e), b(e), an(e), bn(e), ao(e), bo(e);
        vec t(e), u(e), r(e), to(e, 1), uo(e), pw(e + 1);
        pw[0] = 1;
        for (int i = 1; i <= e; i++)
            pw[i] = pw[i - 1] * p;
        for (ll i = 0; i < e; i++)
        {
            a[i] = {pw[i]};
            an[i] = {pw[i]};
            b[i] = {0};
            bn[i] = {s[0] * pw[i] % mod};
            t[i] = s[0] * pw[i] % mod;
            if (!t[i])
                t[i] = 1, u[i] = e;
            else
                for (u[i] = 0; t[i] % p == 0; t[i] /= p, ++u[i])
                    ;
        }
        for (size_t k = 1; k < s.size(); ++k)
        {
            for (int g = 0; g < e; ++g)
            {
                if (L(an[g], bn[g]) > L(a[g], b[g]))
                {
                    ao[g] = a[e - 1 - u[g]];
                    bo[g] = b[e - 1 - u[g]];
                    to[g] = t[e - 1 - u[g]];
                    uo[g] = u[e - 1 - u[g]];
                    r[g] = k - 1;
                }
            }
            a = an;
            b = bn;
            for (int o = 0; o < e; ++o)
            {
                ll d = 0;
                for (size_t i = 0; i < a[o].size() && i <= k; i++)
                    d = (d + a[o][i] * s[k - i]) % mod;
                if (d == 0)
                {
                    t[o] = 1;
                    u[o] = e;
                }
                else
                {
                    for (u[o] = 0, t[o] = d; !(t[o] % p); t[o] /= p, ++u[o])
                        ;
                    int g = e - 1 - u[o];
                    if (!L(a[g], b[g]))
                    {
                        extand(bn[o], k + 1);
                        bn[o][k] = (bn[o][k] + d) % mod;
                    }
                    else
                    {
                        ll coef = t[o] * inv(to[g], mod) % mod * pw[u[o] - uo[g]] % mod;
                        int m = k - r[g];
                        extand(an[o], ao[g].size() + m);
                        extand(bn[o], bo[g].size() + m);
                        auto fun = [&](vector<vec> &vn, vector<vec> &vo, bool f) {
                            for (size_t i = 0; i < vo[g].size(); i++)
                            {
                                vn[o][i + m] -= coef * vo[g][i] % mod;
                                if (vn[o][i + m] < 0)
                                    vn[o][i + m] += mod * (f ? 1 : -1);
                            }
                            while (vn[o].size() && !vn[o].back())
                                vn[o].pop_back();
                        };
                        fun(an, ao, 1);
                        fun(bn, bo, -1);
                    }
                }
            }
        }
        return make_pair(an[0], bn[0]);
    }

    vec ReedsSloane(const vec &s, ll mod)
    {
        vector<tuple<ll, ll, int>> fac;
        for (ll i = 2; i * i <= mod; i++)
        {
            if (!(mod % i))
            {
                ll cnt = 0, pw = 1;
                while (!(mod % i))
                {
                    mod /= i;
                    ++cnt;
                    pw *= i;
                }
                fac.emplace_back(pw, i, cnt);
            }
        }
        if (mod > 1)
            fac.emplace_back(mod, mod, 1);
        vector<vec> as;
        size_t n = 0;
        for (auto &&x : fac)
        {
            ll mod, p, e;
            vec a, b;
            tie(mod, p, e) = x;
            auto ss = s;
            for (auto &&x : ss)
                x %= mod;
            tie(a, b) = prime_power(ss, mod, p, e);
            as.emplace_back(a);
            n = max(n, a.size());
        }
        vec a(n), c(as.size()), m(as.size());
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < as.size(); j++)
            {
                m[j] = get<0>(fac[j]);
                c[j] = i < as[j].size() ? as[j][i] : 0;
            }
            a[i] = crt(c, m);
        }
        return a;
    }
    // ****************************************

  public:
    // 已知初始项求系数
    LinearRecurrence(const vec &a, ll m, bool prime = true) : init(a), mod(m)
    {
        if (prime)
            coef = BerlekampMassey(init);
        else
            coef = ReedsSloane(init, mod);
        coef.erase(coef.begin());
        for (auto &i : coef)
            i = (mod - i) % mod;
    }

    // 已知系数和初始项
    LinearRecurrence(const vec &a, const vec &c, ll m) : init(a), coef(c), mod(m) {}

    ll calc(ll n)
    {
        return solve(n, coef, vec(init.begin(), init.begin() + coef.size()));
    }

    void printcoef()
    {
        printf("f[n] = ");
        for (size_t i = 0; i < coef.size(); i++)
            printf("%lld*f[n-%d]%s", coef[i], (int)i + 1, i + 1 == coef.size() ? "\n" : " + ");
    }
};

const int mod = 1e9;

long long qpow(long long x, long long n, long long mod = mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> f = {0, 1};
    for (int i = 2; i < 2 * m + 5; i++)
    {
        f.push_back((f[i - 1] + f[i - 2]) % mod);
    }
    for (int i = 0; i < 2 * m + 5; i++)
    {
        f[i] = qpow(f[i], m);
    }
    for (int i = 1; i < 2 * m + 5; i++)
    {
        f[i] = (f[i - 1] + f[i]) % mod;
    }
    LinearRecurrence solver(f, mod, false);
    printf("%lld\n", solver.calc(n));
    return 0;
}