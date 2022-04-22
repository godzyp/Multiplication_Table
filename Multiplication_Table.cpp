#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//题目乘法表
//  a b c
//a b b a
//b c b a
//c a c c
int arr[100][100][3];
int main()
{
	int n;//n为字符串长度
	string str;
	freopen("./input.txt", "r", stdin);		//输入重定向，从input.txt读取数据
	freopen("./output.txt", "w", stdout);	//输出重定向，向output.txt输出数据 
	cin >> str;
	n = str.length();
	for (int i = 0; i < n; i++)		//初始化起始值为1
		arr[i][i][str[i] - 'a'] = 1;
	for (int r = 1; r < n; r++)		//计算字符串长度为r时所需乘法次数
	{	for (int i = 0; i < n - r; i++)		//从i开始长r的序列所需乘法次数
		{	int j = i + r;
			for (int k = i; k < j; k++)		//k取值从i+1到j-1时的划分情况
			{	arr[i][j][0] += arr[i][k][0] * arr[k + 1][j][2]		//a = ac
							+ arr[i][k][1] * arr[k + 1][j][2]		//a = bc
							+ arr[i][k][2] * arr[k + 1][j][0];		//a = ca

				arr[i][j][1] += arr[i][k][0] * arr[k + 1][j][0]		//b = aa
							+ arr[i][k][0] * arr[k + 1][j][1]		//b = ab
							+ arr[i][k][1] * arr[k + 1][j][1];		//b = bb

				arr[i][j][2] += arr[i][k][1] * arr[k + 1][j][0]		//c = ba
							+ arr[i][k][2] * arr[k + 1][j][1]		//c = cb
							+ arr[i][k][2] * arr[k + 1][j][2];		//c = cc
			}
		}
	}
	cout<<arr[0][n - 1][0]<<endl;		//返回所有结果为a的可能数

	freopen("CON", "w", stdout);		//输出重定向，将输出流重定向到控制台
	ifstream input("./input.txt");		//将input.txt文件内容显示在控制台中
	cout << "文件input.txt" << endl;
	while (getline(input, str))			//逐行输出
		cout << str << endl;
	ifstream output("./output.txt");	//将output.txt文件内容显示在控制台中
	cout << "文件output.txt" << endl;
	while (getline(output, str))
		cout << str << endl;
	fclose(stdin);			//关闭重定向输入
	fclose(stdout);			//关闭重定向输出
	return 0;
}


