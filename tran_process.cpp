#include <iostream>
#include "sales_data.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
	Sales_data total;
	if (read(cin, total)) {
		total.revenue = total.units_sold * total.price_ave;
		Sales_data trans;
		while (read(cin, trans)) {
			trans.revenue = trans.price_ave * trans.units_sold;
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			} else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	} else {
		cerr << "NO DATA?" << endl;
		return 1;
	}
	return 0;
}
