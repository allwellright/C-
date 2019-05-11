#include<iostream>
#include<algorithm>
using namespace std;
class Table
{
	public:
	Table();
	Table(int a, int b);
	void show();
	int addRow();
	void delRow(int n);
	int addColumn();
	void delColumn(int n);
	void set(int a, int b, int n);
	void set(int a, int b, string n);
	private:
	int row;
	int column;
	string res[100][100];
};
int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}
Table::Table()
{
	row = 0;
	column = 0;
}
Table::Table(int a, int b)
{
	row = a;
	column = b;
}
int Table::addRow()
{
	row++;
	return row;
}
void Table::delRow(int n)
{
	for (int i = n;i<row - 1;i++)
	{
		for (int j = 0;j<column;j++)
		{
			res[i][j] = res[i + 1][j];
		}
	}
}
int Table::addColumn()
{
	column++;
	return column;
}
void Table::delColumn(int n)
{
	for (int i = n;i<column - 1;i++)
	{
		for (int j = 0;j<row;j++)
		{
			res[j][i] = res[j][i + 1];
		}
	}
}
void Table::set(int a, int b, string n)
{
	res[a][b] = n;
}
void Table::set(int a, int b, int n)
{
	string temp;
	temp.clear();
	int num = 0;
	while (n != 0)
	{
		temp += (n % 10) + '0';
		n = n / 10;
	}
	reverse(temp.begin(), temp.end());
	set(a, b, temp);
}
void Table::show()
{
	for (int i = 0;i<row;i++)
	{
		for (int j = 0;j<column;j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}
