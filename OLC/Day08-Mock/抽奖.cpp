/*****************************************
Editorial Code
Name: 王盛祺
Tags: Enumeration, Simulation
*****************************************/
#include <iostream>
using namespace std;

long long n, sum, ans;
long long arr[10005];
long long cnt[505];

/*
注意：
由于排列组合问题的结果一般都是成指数增长的，因此考虑使用long long存储数据。
减少枚举的两个策略：
    1. 缩小枚举范围 将枚举范围从n降低到了sum。
    2. 减少for循环层数 删除了最后一个for循环。
*/

int main(){
    // freopen("ticket.in", "r", stdin);
    // freopen("ticket.out", "w", stdout);
    cin >> n >> sum;
    for (long long i=1; i<=n; i++) {
        cin >> arr[i];
        // cnt[arr[i]] += 1;  // 记录每一个数字的出现次数。
    }

    /*
    暴力版本：
    通过4个for循环，对arr数组中所有的数字进行枚举，
    找到arr[i]数字中的四个数字，并尝试将四个数字相加判断四个数之和是否等于sum。
    暴力函数的时间频度大约为：T(10000^4)，绝对超时，因此考虑优化。
    for (long long i=1; i<=n; i++){
        for (long long j=1; j<=n; j++){
            for (long long k=1; k<=n; k++){
                for(long long l=1; l<=n; l++){
                    long long t = arr[i] + arr[j] + arr[k] + arr[l];
                    if (t == sum){
                        ans += 1;
                    }
                }
            }
        }
    }
    */

    /*
    减少枚举层数优化：
    由于需要让四个数之和等于sum，即可以通过逆向推理的思路得出：
    当确定三个数之后，第四个数字就直接能确定下来了。
    因此可以通过记录每一个数字的出现次数来实现所有的排列组合。
    for (long long i=1; i<=n; i++){
        for (long long j=1; j<=n; j++){
            for (long long k=1; k<=n; k++){
                long long remain = sum - arr[i] - arr[j] - arr[k];
                if (remain >= 1 && cnt[remain] != 0){
                    ans += remain;
                }
            }
        }
    }
    */

    /*
    减少枚举次数和枚举范围的优化：
    根据排列组合原理，四个数字所能组合出所有和为sum的情况就是这四种数字出现的次数，
    因此可以用cnt数组记录每一个数字出现的次数。
    同时将枚举每一个数字改成枚举每一种数字。

    特别优化 - 可行性剪枝：
    如果在第一层for循环已经知道答案为0或者已经知道答案非法，
    则就直接跳出循环，不继续执行下去，因为再下去已经没有任何意义了。
    以此类推，对每一层for循环都应用该剪枝。
    */
    for (long long i=1; i<=sum; i++){
        if (cnt[i] == 0) continue;  // 可行性剪枝。
        for (long long j=1; j<=sum-i; j++){
            if (cnt[j] == 0) continue;
            for (long long k=1; k<=sum-i-j; k++){
                if (cnt[k] == 0) continue;
                long long remain = sum - i - j - k;  // 通过前面三个数推导出第四个数（定值）。
                if (remain >= 1 && cnt[remain] != 0){
                    ans += cnt[i] * cnt[j] * cnt[k] * cnt[remain];  // 排列组合原理。
                }
            }
        }
    }

    cout << ans << endl;  // 输出答案。
    fclose(stdin);
    fclose(stdout);
    return 0;
}