#include<bits/stdc++.h>
using namespace std;
vector<int> d;
vector<int> a;
vector<int> b;
void build(int s,int t,int p){
    //对区间[s,t]建立线段树，当前根的编号为p
    if(s == t){
        d[p] = a[s];
    }

    int m  = s + ((t - s) >> 1);
    // 移位运算符的优先级小于加减法，所以加上括号
    // 如果写成 (s + t) >> 1 可能会超出 int 范围
    build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
    // 递归对左右区间建树
    d[p] = d[p * 2] + d[(p * 2) + 1];
}
//关于线段树的空间，首先假定使用堆式存储(2p 是p的左儿子,2p + 1是p的右儿子)，有n个叶子节点
//容易知道线段树深度是ceil(log(n))的,则在堆式存储情况下叶子节点(包括无用叶子节点)
//数量为2^( ceil( log(n) ) ) 个，总节点数量根据等比数列前n项和算出。
//懒得算直接设置为4n

//最初版本：
int getsum(int l,int r,int s,int t,int p){
    //[l,r] 为查询区间，[s,t]为当前节点包含的区间，p为当前节点的编号

    if(l <= s && t <= r) return d[p];
    //当前区间为询问区间的子集时直接返回当前区间的和

    int m = s + ((t - s) >> 1),sum = 0;
    // 如果左儿子代表的区间 [l, m] 与询问区间有交集, 则递归查询左儿子
    if(l <= m) sum += getsum(l,r,s,m,p*2);
    if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
    // 如果右儿子代表的区间 [m + 1, r] 与询问区间有交集, 则递归查询右儿子
    return sum;
}

//需要修改某个区间的值：
// C++ Version
void update(int l, int r, int c, int s, int t, int p) {
    // [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
    // 为当前节点的编号
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c, b[p] += c;
        return;
    }  // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    int m = s + ((t - s) >> 1);
    if (b[p] && s != t) {
        // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
        b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
        b[p] = 0;                                // 清空当前节点的标记
    }
    if (l <= m) update(l, r, c, s, m, p * 2);
    if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}
// C++ Version
int getsum(int l, int r, int s, int t, int p) {
    // [l, r] 为查询区间, [s, t] 为当前节点包含的区间, p 为当前节点的编号
    if (l <= s && t <= r) return d[p];
    // 当前区间为询问区间的子集时直接返回当前区间的和
    int m = s + ((t - s) >> 1);
    if (b[p]) {
        // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
        d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m),
            b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
        b[p] = 0;                                    // 清空当前节点的标记
    }
    int sum = 0;
    if (l <= m) sum = getsum(l, r, s, m, p * 2);
    if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
    return sum;
}

//如果你是要实现区间修改为某一个值而不是加上某一个值的话，代码如下：
// C++ Version
void update(int l, int r, int c, int s, int t, int p) {
    if (l <= s && t <= r) {
        d[p] = (t - s + 1) * c, b[p] = c;
        return;
    }
    int m = s + ((t - s) >> 1);
    if (b[p]) {
        d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m),
            b[p * 2] = b[p * 2 + 1] = b[p];
        b[p] = 0;
    }
    if (l <= m) update(l, r, c, s, m, p * 2);
    if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

int getsum(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int m = s + ((t - s) >> 1);
    if (b[p]) {
        d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m),
            b[p * 2] = b[p * 2 + 1] = b[p];
        b[p] = 0;
    }
    int sum = 0;
    if (l <= m) sum = getsum(l, r, s, m, p * 2);
    if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
    return sum;
}