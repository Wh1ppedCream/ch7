#include "sales_data.h"

using std::cin;
using std::endl;

int main()
{
	cout << "Sales_data obj1:\n";
	Sales_data obj1;
	obj1.sales_print(cout) << endl;
	print(cout, obj1);
	cout << endl;
	cout << "\nSales_data obj2(""gaoxiangnumber1""):\n";
	Sales_data obj2("gaoxiangnumber1");
	obj2.sales_print(cout) << endl;
	print(cout, obj2);
	cout << endl;
	cout << "\nSales_data obj3(cin):\n";
	Sales_data obj3(cin);
	obj3.sales_print(cout) << endl;
	print(cout, obj3);
	cout << endl;
	cout << "\nSales_data obj4(""gao"", 71, 8.8):\n";
	Sales_data obj4("gao", 71, 8.8);
	obj4.sales_print(cout) << endl;
	print(cout, obj4);
	cout << endl;

	return 0;
}
