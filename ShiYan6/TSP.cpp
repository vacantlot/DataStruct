///****************算法总框架*****************************/
//int i;
//gs.search_init(adaptee.list_place.getSelectedIndex(), adaptee.list_fun.getSelectedIndex());
//do { i = gs.search_step(); } while (i == 0);
///***************searchinit**************************/
//public void search_init(int startindex, int strategy)
//{
//	this.strategy = strategy;
//	AStar.graph = G;
//	G.setSize(AStar.len);
//	start.index = startindex;
//	Vertex s = new Vertex();
//	s.index = start.index;
//	s.parent = -1;
//	n = null;
//	s.value = f(s.index); //s的估价函数值
//	G.add(s);
//	start.parentpos = -1;
//	start.value = s.value;
//	open.add(start);
//	step = 0;
//}
///***************searchstep**************************/
//public int search_step()
//{
//	Open m;
//	Vertex old_m;
//	int i, j;
//	int f;
//	int parentpos;
//	if (open.next == null)
//		return -1;//查找失败
//				  //扩展的步骤数增加
//	step++;
//	//Open 表非空
//	//Open 表中移出第一个
//	n = open.removeFirst();
//	//n放入 CLOSE 中 ,返回放入的位置
//	parentpos = close.Add(n.index, n.parentpos);
//	if (n.index == start.index&&step != 1) //结束状态
//		return 1;
//	//扩展n结点
//	i = n.index;
//	for (j = 0; j < len; j++)
//	{
//		if (i != j&&value[j] != -1) //对于所有n的后继结点 m(j)
//		{
//			if (j == start.index&&isAll(n)) //所有城市已访问过，且回到出发城市
//			{
//				f = f(j); //计算此时的f值
//				old_m = G.getVertex(j);
//				if (old_m != null)
//					if (old_m.value > f || old_m.value == 0)
//						G.add(j, i, f); //j(m) i(n),G中添加j(m),父节点为i(n),估价函数值为f
//				G.addSub(i, j); //i(n)的后继中添加j(m)
//				m = new Open(j, parentpos, f); //Open表中添加m(j)
//				open.add(m);
//				continue;
//			}
//			if (!isExist(n, j)) //m(j)不在n(i)的祖先中(不扩张n的祖先结点)
//			{
//				f = f(j); //计算f值
//						  //取得旧的m(j) 中value最小的,G中的节电保存了从出发城市到此地最小估价函数
//				old_m = G.getVertex(j);
//				// m(j)不再G中,m(j) 也就不在Close中
//				if (old_m == null)
//				{
//					//j(m) i(n),G中添加j(m),父节点为i(n),估价函数值为f
//					G.add(j, i, f);
//					//n(i) 添加后继 m(j)
//					G.addSub(i, j);
//					//加入Open表
//					m = new Open(j, parentpos, f);
//					open.add(m); //m添加入 Open 表中
//				}
//				else //m(j)在G中,表示Close 表中有m(j) 结点
//				{
//					if (old_m.value > f) //新值比较小，采用新值
//					{
//						//更新G中的估价函数值，以及相关指针
//						old_m.value = f;
//						old_m.parent = i;
//						//添加相关从Close中删除的代码,不删除亦可
//					}
//					G.addSub(i, j); //n(i) 添加后继 m(j)
//									//从Close 中删除，移入Open表中，实际上Close表中仍然保留
//					m = new Open(j, parentpos, f);
//					open.add(m);
//				}
//			}
//		}
//	}
//	//本次没查找到解，请继续
//	return 0;
//}