/****************算法总框架*****************************/
int i;
gs.search_init(adaptee.list_place.getSelectedIndex(), adaptee.list_fun.getSelectedIndex());
do { i = gs.search_step(); } while (i == 0);
/***************searchinit**************************/
public void search_init(int startindex, int strategy)
{
	this.strategy = strategy;
	AStar.graph = G;
	G.setSize(AStar.len);
	start.index = startindex;
	Vertex s = new Vertex();
	s.index = start.index;
	s.parent = -1;
	n = null;
	s.value = f(s.index); //s的估价函数值
	G.add(s);
	start.parentpos = -1;
	start.value = s.value;
	open.add(start);
	step = 0;
}
/***************searchstep**************************/
public int search_step()
{
	Open m;
	Vertex old_m;
	int i, j;
	int f;
	int parentpos;
	if (open.next == null)
		return -1;//查找失败
				  //扩展的步骤数增加
	step++;
	//Open 表非空
	//Open 表中移出第一个
	n = open.removeFirst();
	//n放入 CLOSE 中 ,返回放入的位置
	parentpos = close.Add(n.index, n.parentpos);
	if (n.index == start.index&&step != 1) //结束状态
		return 1;
	//扩展n结点
	i = n.index;
	for (j = 0; j < len; j++)
	{
		if (i != j&&value[j] != -1) //对于所有n的后继结点 m(j)
		{
			if (j == start.index&&isAll(n)) //所有城市已访问过，且回到出发城市
			{
				f = f(j); //计算此时的f值
				old_m = G.getVertex(j);
				if (old_m != null)
					if (old_m.value > f || old_m.value == 0)
						G.add(j, i, f); //j(m) i(n),G中添加j(m),父节点为i(n),估价函数值为f
				G.addSub(i, j); //i(n)的后继中添加j(m)
				m = new Open(j, parentpos, f); //Open表中添加m(j)
				open.add(m);
				continue;
			}
			if (!isExist(n, j)) //m(j)不在n(i)的祖先中(不扩张n的祖先结点)
			{
				f = f(j); //计算f值
						  //取得旧的m(j) 中value最小的,G中的节电保存了从出发城市到此地最小估价函数
				old_m = G.getVertex(j);
				// m(j)不再G中,m(j) 也就不在Close中
				if (old_m == null)
				{
					//j(m) i(n),G中添加j(m),父节点为i(n),估价函数值为f
					G.add(j, i, f);
					//n(i) 添加后继 m(j)
					G.addSub(i, j);
					//加入Open表
					m = new Open(j, parentpos, f);
					open.add(m); //m添加入 Open 表中
				}
				else //m(j)在G中,表示Close 表中有m(j) 结点
				{
					if (old_m.value > f) //新值比较小，采用新值
					{
						//更新G中的估价函数值，以及相关指针
						old_m.value = f;
						old_m.parent = i;
						//添加相关从Close中删除的代码,不删除亦可
					}
					G.addSub(i, j); //n(i) 添加后继 m(j)
									//从Close 中删除，移入Open表中，实际上Close表中仍然保留
					m = new Open(j, parentpos, f);
					open.add(m);
				}
			}
		}
	}
	//本次没查找到解，请继续
	return 0;
}


#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <algorithm>  
using namespace std;
#define MIN (1<<17)  
#define MAX 110000  
#define INF (1<<29)  
#define min(a,b) ((a)<(b)?(a):(b))  


int tot, ans1, ans2, n, m; //总合法物品数，第一、第二问答案  
int x[20], y[20], val[20]; //左边和点权  
int dp[MAX], state[MIN]; //第一问用到  
int map[20][20], isok[MIN]; //边权、合法物品集合  
int cost[17][MIN], np[MIN]; //第二问用到  

void Initial() {

	int i, j;
	tot = 0;
	memset(map, 0, sizeof(map));
	for (i = 0; i < (1 << n); ++i)
		dp[i] = np[i] = INF;
	for (i = 0; i <= n; ++i)
		for (j = 0; j < (1 << n); ++j)
			cost[i][j] = INF;
	cost[0][1] = 0;
}

int cmp1(int a, int b) {

	return a > b;
}

int Solve_Tanxin() {

	int i, j, mmin = INF;
	int tp[20], vis[20];

	for (i = 0; i < n; ++i)
		vis[i] = 0, tp[i] = val[i];
	sort(tp, tp + n, cmp1);
	for (i = 1; i <= n; ++i) {

		int rest = m;
		for (j = 0; j < n; ++j)
			if (!vis[j] && tp[j] <= rest)
				rest -= tp[j], vis[j] = 1;
		;
		for (j = 0; j < n && vis[j] == 1; ++j);
		if (j == n) return i;
	}
	return INF;
}
void GetDist() {

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {

			double xx = x[i] - x[j];
			double yy = y[i] - y[j];
			xx *= xx, yy *= yy;
			map[i][j] = map[j][i] = ceil(sqrt(xx + yy));
		}
}

int ok(int x) {

	int sum = 0, i;
	for (i = 0; i < n; ++i)
		if (x & (1 << i)) sum += val[i];
	return sum <= m;
}

int TSP_Second() {

	int i, j, k;

	GetDist();
	for (i = 1; i < (1 << n); ++i) if (isok[i]) {
		for (j = 0; j < n; ++j) if (i & (1 << j)) {
			np[i] = min(np[i], cost[j][i] + map[j][0]);
			for (k = 0; k < n; ++k) if (((i & (1 << k)) == 0) && (isok[i | (1 << k)]))
				cost[k][i | (1 << k)] = min(cost[k][i | (1 << k)], cost[j][i] + map[j][k]);
		}
	}

	for (i = 1; i < (1 << n); ++i)
		if (i & 1) for (j = (i - 1) & i; j; j = (j - 1) & i)
			np[i] = min(np[i], np[j | 1] + np[(i - j) | 1]);
	return np[(1 << n) - 1];
}

int main() {
	int i;

	while (scanf("%d%d", &n, &m) != EOF) {

		Initial();
		for (i = 0; i < n; ++i)
			scanf("%d%d", &x[i], &y[i]);
		for (i = 0; i < n; ++i)
			scanf("%d", &val[i]);



		for (i = 1; i < (1 << n); ++i) {

			isok[i] = ok(i);
			if (isok[i]) state[tot++] = i;
		}

		ans1 = Solve_Tanxin();
		if (ans1 == INF)
			ans1 = ans2 = -1;
		else ans2 = TSP_Second();
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}