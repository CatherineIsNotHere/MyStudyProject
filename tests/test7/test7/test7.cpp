#include "iostream"
#include "iomanip"
using namespace std;

/*
	dec
*/

void main(){
	double a = 22 / 7;
	cout << a<<endl;
	cout << setprecision(0) << a << endl
		<< setprecision(1) << a << endl
		<< setprecision(2) << a << endl
		<< setprecision(3) << a << endl
		<< setprecision(4) << a << endl;
	cout << setiosflags(ios::fixed);
	cout << setprecision(8) << a << endl;
	cout << setiosflags(ios::scientific) << a << endl;
	cout << setprecision(6);//重新设置成原默认设置

	//这段代码运行中出现非预期结果
	/*
	预期结果：
		3.14286
		3
		3
		3.1
		3.14
		3.143
		3.14285714
		3.14285714e+00
	*/
}