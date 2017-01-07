/****************�㷨�ܿ��*****************************/
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
	s.value = f(s.index); //s�Ĺ��ۺ���ֵ
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
		return -1;//����ʧ��
				  //��չ�Ĳ���������
	step++;
	//Open ��ǿ�
	//Open �����Ƴ���һ��
	n = open.removeFirst();
	//n���� CLOSE �� ,���ط����λ��
	parentpos = close.Add(n.index, n.parentpos);
	if (n.index == start.index&&step != 1) //����״̬
		return 1;
	//��չn���
	i = n.index;
	for (j = 0; j < len; j++)
	{
		if (i != j&&value[j] != -1) //��������n�ĺ�̽�� m(j)
		{
			if (j == start.index&&isAll(n)) //���г����ѷ��ʹ����һص���������
			{
				f = f(j); //�����ʱ��fֵ
				old_m = G.getVertex(j);
				if (old_m != null)
					if (old_m.value > f || old_m.value == 0)
						G.add(j, i, f); //j(m) i(n),G�����j(m),���ڵ�Ϊi(n),���ۺ���ֵΪf
				G.addSub(i, j); //i(n)�ĺ�������j(m)
				m = new Open(j, parentpos, f); //Open�������m(j)
				open.add(m);
				continue;
			}
			if (!isExist(n, j)) //m(j)����n(i)��������(������n�����Ƚ��)
			{
				f = f(j); //����fֵ
						  //ȡ�þɵ�m(j) ��value��С��,G�еĽڵ籣���˴ӳ������е��˵���С���ۺ���
				old_m = G.getVertex(j);
				// m(j)����G��,m(j) Ҳ�Ͳ���Close��
				if (old_m == null)
				{
					//j(m) i(n),G�����j(m),���ڵ�Ϊi(n),���ۺ���ֵΪf
					G.add(j, i, f);
					//n(i) ��Ӻ�� m(j)
					G.addSub(i, j);
					//����Open��
					m = new Open(j, parentpos, f);
					open.add(m); //m����� Open ����
				}
				else //m(j)��G��,��ʾClose ������m(j) ���
				{
					if (old_m.value > f) //��ֵ�Ƚ�С��������ֵ
					{
						//����G�еĹ��ۺ���ֵ���Լ����ָ��
						old_m.value = f;
						old_m.parent = i;
						//�����ش�Close��ɾ���Ĵ���,��ɾ�����
					}
					G.addSub(i, j); //n(i) ��Ӻ�� m(j)
									//��Close ��ɾ��������Open���У�ʵ����Close������Ȼ����
					m = new Open(j, parentpos, f);
					open.add(m);
				}
			}
		}
	}
	//����û���ҵ��⣬�����
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


int tot, ans1, ans2, n, m; //�ܺϷ���Ʒ������һ���ڶ��ʴ�  
int x[20], y[20], val[20]; //��ߺ͵�Ȩ  
int dp[MAX], state[MIN]; //��һ���õ�  
int map[20][20], isok[MIN]; //��Ȩ���Ϸ���Ʒ����  
int cost[17][MIN], np[MIN]; //�ڶ����õ�  

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