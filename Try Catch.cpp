#include<bits/stdc++.h>

using namespace std;

/*int divi(int a, int b)
{
	try
	{
		if(b == 0)
			throw b;


		return a / b;
	}
	catch (...)
	{
		cout << "Exceeption";
	}


}




void insertText(int n, string text)
{

	try {

		if (text.size() == 0)
			throw "No text input";


		if (n < 0 || n > 10)
			throw n;


	}

	catch (int a)
	{
		cout << a << "this line number input is incorrect"<<endl;
	}

	catch (char * error)
	{
		cout << error << endl;
	}

} */


/*int main()
{
	insertText(-1, "abcd");
	divi(1, 0);
	system("pause");
	return 0;
}*/

/*struct MyException : public exception {
	const char * what() const throw ()
	{
		return "C++ Exception";
	}
};

int main()
{
	try
	{
		throw MyException();
	}

	catch (MyException& e)
	{
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	}

	catch (std::exception& e) {
		//Other error
	}
} */

/* #define SIZE 10

enum year {
	Jan, Feb, Mar, Apr, May, Jun, Jul,
	Aug, Sep, Oct, Nov, Dec
};

int main()
{
	int i;
	for (i = Jan; i <= Dec; i++)
		printf("%d ", i);

	cout <<endl<< size << endl;

	system("pause");


	return 0;
} */

int main()
{
	list<int> dll;

	dll.push_back(2);
	dll.push_front(1);
	dll.push_back(3);
	dll.insert(dll.begin(), 0);

	dll.push_back(0);
	dll.remove(0);

	list<int>::iterator it;

	for (it = dll.begin(); it != dll.end(); ++it)
		cout << *it << " ";

	cout <<endl<< dll.front();
	//system("pause");

	return 0;
}
