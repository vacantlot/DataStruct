#pragma once
template<typename T>
struct Element
{
	T data;
	int weight;
	int lchild, rchild, parent;
};

template<typename T>
class HuffmanTree
{
public:
	HuffmanTree(T data[], int w[], int n);
	~HuffmanTree();
	void Bulid();
	void Print();

private:
	Element<T> *m_huffTree;        //基地址指针
	int m_size;                    // 哈夫曼树的叶子节点的数量
	void Select(int & i1, int & i2, int loc);

};


//************************************
// Method:    HuffmanTree
// FullName:  HuffmanTree<T>::HuffmanTree
// Access:    public 
// Parameter: T data[]
// Parameter: int w[]
// Parameter: int n
//************************************
template<typename T>
HuffmanTree<T>::HuffmanTree(T data[], int w[], int n)
{
	m_size = n;
	m_huffTree = new Element<char>[2 * m_size - 1];
	for (size_t i = 0; i < 2 * m_size - 1; i++)
	{
		m_huffTree[i].lchild = -1;
		m_huffTree[i].rchild = -1;
		m_huffTree[i].parent = -1;
		if (i < n)
		{
			m_huffTree[i].data = data[i];
			m_huffTree[i].weight = w[i];
		}
	}
}

template<typename T>
HuffmanTree<T>::~HuffmanTree()
{
	delete[] m_huffTree;
}

template<typename T>
void HuffmanTree<T>::Bulid()
{
	int i1, i2;
	for (size_t i = m_size; i < 2 * m_size - 1; i++)
	{
		Select(i1, i2, i);
		m_huffTree[i1].parent = i;
		m_huffTree[i2].parent = i;
		m_huffTree[i].weight = m_huffTree[i1].weight + m_huffTree[i2].weight;
		m_huffTree[i].lchild = i1;
		m_huffTree[i].rchild = i2;
	}
}

template<typename T>
void HuffmanTree<T>::Print()
{
	for (size_t i = 0; i < 2 * m_size - 1; i++)
	{
		cout << m_huffTree[i].data << ":" << m_huffTree[i].weight << ":" << m_huffTree[i].parent << ":" << m_huffTree[i].lchild << ":" << m_huffTree[i].rchild << endl;
	}
}

template<typename T>
void HuffmanTree<T>::Select(int &i1, int &i2, int loc)
{
	i1 = -1;
	i2 = -1;
	for (size_t i = 0; i < loc; i++)
	{
		if (m_huffTree[i].parent == -1)
		{
			int tempWeight = m_huffTree[i].weight;
			if (i1 == -1)
			{
				i1 = i;
			}
			else if (i2 == -1)
			{
				i2 = i;
			}
			else if (tempWeight < m_huffTree[i1].weight)
			{
				i1 = i;
			}
			else if (tempWeight < m_huffTree[i2].weight)
			{
				i2 = i;
			}
		}
	}
}
