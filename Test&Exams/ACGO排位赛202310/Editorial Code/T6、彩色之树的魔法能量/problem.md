## 彩色之树的魔法能量

### 题目描述

在遥远的狗星上，一颗神秘的彩色之树作为守护神镇守在这片大地。每个结点上都有一种独特的颜色，相传这些颜色都蕴藏着某种神秘的魔法能量。

狗星的居民们发现，这棵树有 $n$ 个彩色点，点与点两两可达。当他们选中树上两个颜色相同的不同结点时，它们之间会产生魔法连接。这种连接的能量来自于这两个结点简单路径上所有与路径端点具有相同颜色的结点。对于一个点对（$(x,y)$ 与 $(y,x)$ 视为同一点对），能量值即为它们之间的简单路径上这种颜色的结点数。

现在，为了更好地利用这种魔法能量，请计算出这棵彩色之树的所有不同点对能产生的总魔法能量是多少？

### 输入格式

第一行包含一个正整数 $n$，表示树的结点个数.

第二行包含 $n$ 个用空格分隔的正整数, 第 $i$ 个数 $c_i$ 表示编号为 $i$ 的结点的颜色.

接下来 $n - 1$ 行，每行包含两个正整数 $u_i, v_i (1 \leq u_i, v_i \leq n)$ - 表示 $u$ 和 $v$ 间存在一条边.

### 输出格式

输出仅一行，包含一个整数，表示能产生的总魔法能量。

### 样例输入

```
5
1 1 1 1 1
1 2
1 3
3 4
3 5
```

### 样例输出

```
28
```

### 说明

样例描述的树为：
```
        1
      /   \
     1     1
          /  \
         1    1
```
产生的权值为：
$(1, ?)：2 + 2 + 3 + 3 = 10$

$(2, ?)：3 + 4 + 4 = 11$

$(3, ?)：2 + 2 = 4$

$(4, ?)：3$

总和为 $28$。

### 评测数据规模

保证对于所有数据满足：$1 \leq n \leq 10^5$，$1 \leq c_i \leq 100$，$1 \leq u, v \leq n$。

| 测试点编号 | $n \leq$ | $c_i \leq$ |
| :-----------: | :-----------: | :-----------: | 
| $1 \sim 4$ | $1000$ | $2$ |
| $5 \sim 8$ | $10^5$ | $2$ |
| $9 \sim 14$ | $1000$ | $100$ |
| $15 \sim 20$ | $10^5$ | $100$ |