#include <iostream>
#include "sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
	Sales_data total(cin);
	while (cin) {
		Sales_data transf(cin);
		if (total.isbn() == transf.isbn()) {
			total.combine(transf);
		} else {
			print(cout, total) << endl;
			total = transf;
		}
		cout << "Press enter to enter next val: ";
	}
	print(cout, total) << endl;
	return 0;
}
