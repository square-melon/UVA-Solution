#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
//#define DEBUG
using namespace std;
int acc = 0;
int flow[2000000];
bool cmpF(int a, int b)
{
    if (abs(a) == abs(b))
        return a > 0;//negative value last out
    else
        return abs(a) < abs(b);//small time value first out
}

struct RECT
{
    int h;
    int in, out;//L bound, R bound
}squence[2000000];

bool cmp(RECT A, RECT B)
{
    return A.h < B.h;
}

void addRect(int h, int i, int o)
{
    squence[acc].h = h;
    squence[acc].in = i;
    squence[acc].out = o;
    acc++;
    return;
}

int computeIn(double X, double Y, double R, int i)//left bound
{
    return max(0, (int)floor(X - sqrt(R * R - (Y - i) * (Y - i))));
}

int computeOut(double X, double Y, double R, int i, int size)//right bound
{
    return min((int)ceil(X + sqrt(R * R - (Y - i) * (Y - i))), size);
}

int computeFlow(int fn)
{
    int ans = 0;
    int innumber = 0, lastIn = 0;

    for (int i = 0; i < fn; i++)
    {

        if (flow[i] >= 0)
        {
            innumber++;
            if (innumber == 1)//0->1 recored
                lastIn = flow[i];
        }
        else
        {
            innumber--;
            if (innumber == 0)//1->0 ans+
                ans += (-flow[i] - lastIn);
        }

    }

    return ans;
}

void divideToRect(double X, double Y, double R, int size)
{
    //note the square computed only in 0~size

    int s = max(0, (int)floor(Y - R)), d = min(size, (int)ceil(Y + R)), mid = (int)floor(Y);
    //part1 h = i Range:but compute use i+1 s<=i<mid
    //part2 h = i Range:+-R i=mid
    //part3 h = i Range:compute use i (mid+1)<=i<d
    //part1
    for (int i = s; i < mid; i++)
        addRect(i, computeIn(X, Y, R, i + 1), computeOut(X, Y, R, i + 1, size));
    //part2
    addRect(mid, max(0, (int)floor(X - R)), min(size, (int)ceil(X + R)));
    for (int i = mid + 1; i < d; i++)
        addRect(i, computeIn(X, Y, R, i), computeOut(X, Y, R, i, size));

}

using namespace std;
int main()
{
    int T, n, size;
    scanf("%d", &T);
    for (int r = 0; r < T; r++)
    {
        acc = 0;//clear squence
        scanf("%d %d", &size, &n);
        double X, Y, R;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf %lf", &X, &Y, &R);
            divideToRect(X, Y, R, size);
        }
        sort(squence, squence + acc, cmp);
#ifdef DEBUG

        //display squence for testing
        printf("case %d\n", r);
        for (int i = 0; i < acc; i++)
            printf("h %d i %d o %d\n", squence[i].h, squence[i].in, squence[i].out);

#endif
        int maxH = squence[acc - 1].h;
        int h = 0, ans = 0, fn = 0;
        int run = 0;
        while (run < acc)
        {
            //put in flow
            fn = 0;
            while (h == squence[run].h && run < acc)
            {
                flow[fn++] = squence[run].in;
                flow[fn++] = -squence[run].out;
                run++;
            }
            sort(flow, flow + fn, cmpF);
#ifdef DEBUG
            for (int i = 0; i < fn; i++)
                printf("%d ", flow[i]);
            putchar('\n');
#endif DEBUG

            ans += computeFlow(fn);
            h++;
        }

        printf("%d\n", ans);

    }
    return 0;
}