# include <cstdio>
# include <cstring>
# include <algorithm>
using namespace std;
const int NR = 5050;
struct lld{
    int l, r;
    int s[NR + 505];
    lld(){
        l = r = 0;
        memset(s, 0, sizeof(s));
    }
    void operator = (const int &x) {
        int p = x;
        while (p){
            s[NR + r++] = p % 10;
            p /= 10;
        }
    }
    lld operator + (const lld &x) const{
        lld q;
        bool flag = false;
        q.l = min(x.l, l);
        int c = 0;
        for (int i = q.l; i < 505; i++){
            if (i >= r && i >= x.r && c == 0) break;
            int p = s[NR + i] + x.s[NR + i] + c;
            q.s[NR + i] = p % 10;
            c = p / 10;
            if (q.s[NR + i] != 0) flag  = true;
            if (!flag) q.l++;
            q.r = i + 1;
        }
        return q;
    }
    lld operator * (const int &x) const{
        lld q;
        int c = 0;
        bool flag = false;
        for (int i = l; i < 505; i++){
            if (i >= r && c == 0) break;
            int p = s[NR + i] * x + c;
            q.s[NR + i] = p % 10;
            c = p / 10;
            if (q.s[NR + i] != 0) flag = true;
            if (!flag) q.l++;
            q.r = i + 1;
        }
        return q;
    }
    lld operator / (const int &x) const{
        lld q;
        q.r = r;
        bool flag = false;
        int o = 0;
        for (int i = r - 1; i >= -NR; i--){
            if (i < l && o == 0) break;
            o = o * 10 + s[NR + i];
            q.s[NR + i] = o / x;
            o = o % x;
            if (q.s[NR + i] != 0) flag = true;
            if (!flag) q.r--;
            q.l = i;
        }
        return q;
    }
    void print(int x){
        if (r == 0) printf("0");
        for (int i = r - 1; i >= x; i--){
            if (i == -1) printf(".");
            printf("%d", s[NR + i]);
        }
        puts("");
    }
    void print(){
        print(l);
    }
};
int main(){
    lld pi, t;
    t = 2;
    pi = 2;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        t = t * (i + 1);
        printf("%d ", i + 1);
        t.print();
        t = t / (2 * i + 3);
        t.print();
        pi = pi + t;
    }
    return 0;
}
