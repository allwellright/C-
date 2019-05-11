#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
class Cell {
public:
	Cell(char con[]);
	Cell() { }
	Cell(Cell &a);
	~Cell() {}
	void show();
	void set(string a);
	string get();
private:
	string content;
};

class Table {
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
	Cell cells[100][100];
	int row;
	int column;
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
Cell::Cell(char con[])
{
	content = con;
}
Cell::Cell(Cell &a)
{
	content = a.get();
}
void Cell::show()
{
	cout << content << endl;
}
void Cell::set(string a)
{
	content = a;
}
string Cell::get()
{
	return content;
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
			cells[i][j] = cells[i + 1][j];
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
			cells[j][i] = cells[j][i + 1];
		}
	}
}
void Table::set(int a, int b, string n)
{
	cells[a][b].set(n);
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
			cout << cells[i][j].get() << " ";
		cout << endl;
	}
}
