///****************�㷨�ܿ��*****************************/
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
//	s.value = f(s.index); //s�Ĺ��ۺ���ֵ
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
//		return -1;//����ʧ��
//				  //��չ�Ĳ���������
//	step++;
//	//Open ��ǿ�
//	//Open �����Ƴ���һ��
//	n = open.removeFirst();
//	//n���� CLOSE �� ,���ط����λ��
//	parentpos = close.Add(n.index, n.parentpos);
//	if (n.index == start.index&&step != 1) //����״̬
//		return 1;
//	//��չn���
//	i = n.index;
//	for (j = 0; j < len; j++)
//	{
//		if (i != j&&value[j] != -1) //��������n�ĺ�̽�� m(j)
//		{
//			if (j == start.index&&isAll(n)) //���г����ѷ��ʹ����һص���������
//			{
//				f = f(j); //�����ʱ��fֵ
//				old_m = G.getVertex(j);
//				if (old_m != null)
//					if (old_m.value > f || old_m.value == 0)
//						G.add(j, i, f); //j(m) i(n),G�����j(m),���ڵ�Ϊi(n),���ۺ���ֵΪf
//				G.addSub(i, j); //i(n)�ĺ�������j(m)
//				m = new Open(j, parentpos, f); //Open�������m(j)
//				open.add(m);
//				continue;
//			}
//			if (!isExist(n, j)) //m(j)����n(i)��������(������n�����Ƚ��)
//			{
//				f = f(j); //����fֵ
//						  //ȡ�þɵ�m(j) ��value��С��,G�еĽڵ籣���˴ӳ������е��˵���С���ۺ���
//				old_m = G.getVertex(j);
//				// m(j)����G��,m(j) Ҳ�Ͳ���Close��
//				if (old_m == null)
//				{
//					//j(m) i(n),G�����j(m),���ڵ�Ϊi(n),���ۺ���ֵΪf
//					G.add(j, i, f);
//					//n(i) ��Ӻ�� m(j)
//					G.addSub(i, j);
//					//����Open��
//					m = new Open(j, parentpos, f);
//					open.add(m); //m����� Open ����
//				}
//				else //m(j)��G��,��ʾClose ������m(j) ���
//				{
//					if (old_m.value > f) //��ֵ�Ƚ�С��������ֵ
//					{
//						//����G�еĹ��ۺ���ֵ���Լ����ָ��
//						old_m.value = f;
//						old_m.parent = i;
//						//�����ش�Close��ɾ���Ĵ���,��ɾ�����
//					}
//					G.addSub(i, j); //n(i) ��Ӻ�� m(j)
//									//��Close ��ɾ��������Open���У�ʵ����Close������Ȼ����
//					m = new Open(j, parentpos, f);
//					open.add(m);
//				}
//			}
//		}
//	}
//	//����û���ҵ��⣬�����
//	return 0;
//}