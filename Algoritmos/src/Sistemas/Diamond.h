// Diamond In C
/* C program to display a diamond using arrays */

#include <iostream>
#include <conio.h>

using namespace std;

int main(int argc, char **argv) {
	int i, j;
	clrscr();
	int no;
	cout << "Enter A Value";
	cin >> no;
	for (i = no; i >= 1; i--) {
		cout << endl;
		for(int k=1;k< =i;k++
				)
				cout << " ";

				for(j=i;j< =no;j++
			)
			cout << "*";

			for(j=i;j< no;j++)
			cout << "*";
		}
//SECOND PART

		for (i = no; i >= 1; i--) {
			cout << endl;
			cout << " ";
			for (int k = no; k >= i; k--)
				cout << " ";

			for(j=i-1;j>=1;j--)
			cout << "*";

			for (j = i - 1; j > 1; j--)
				cout << "*";
		}
		getch();
	}
