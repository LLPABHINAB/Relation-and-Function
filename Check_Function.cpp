// Program return the type of Function is a Proper Function..

/*

1. One-one Function(Injective)
2. Many-one Function
3. onto Function(surjective)
4. into Function
5. Bijective Fucntion

*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector <pair<string, string>> Function; // Decleareing the Variable..
unordered_set <string> set_A;
unordered_set <string> set_B; // Co-domain of Function. f(x)
int nR, nA, nB;
bool flag = false, one_one = false, many_one = false, onto = false, into = false;

int main()
{
	cout << "f: A -> B\n";
	cout << "Cardinality of set A : ";
	cin >> nA;
	cout << "Enter the elements of set A : ";
	for(int i = 0;i < nA;i++)
	{
		string temp; cin >> temp;
		set_A.insert(temp);
	}

	cout << "Cardinality of set B : ";
	cin >> nB;
	cout << "Enter the elements of set B : ";
	for(int i = 0;i < nB;i++)
	{
		string temp; cin >> temp;
		set_B.insert(temp);
	}

	cout << "Cardinality of Relaion :";
	cin >> nR;
	cout << "\nAnd give the input of the Relation in Roaster Format\n{(a,b),(b,c),....} : ";
    for(int i = 0;i < nR;i++)
	{
		string a; cin >> a;
		string b; cin >> b;
		Function.push_back(make_pair(a,b));
	}

	
	// Printing the Relaion..
	cout << "{";
	for(int i = 0;i < nR;i++)
		cout << " (" << Function.at(i).first << "," << Function.at(i).second << ") ";

	cout << "}\n";

	cout << "Set A : \n{ ";
	for(auto const &i : set_A)	cout << i << " ";
	cout << "}\n";

	cout << "Set B : \n{ ";
	for(auto const &i : set_B)	cout << i << " ";
	cout << "}\n";

	// Logic Part for Checking if the Function entered in a function one-one or Many-one
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	for(int i = 0;i < nR;i++)
	{
		string a = Function.at(i).first;
		int cnt = 0;
		for(int i = 0;i < nR;i++)
			if(a == Function.at(i).first) cnt++;

		// cout << a << " count -> " << cnt << endl;
		if(cnt > 1) {
			cout << "Many-one ";
			flag = true;
			many_one = true;
			break;
		}
 	
	}
	if(!flag) {
		one_one = true;
		cout << "One-one ";
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////


	// Checking for onto Function and Into Function
	//////////////////////////////////////////////////////////////////////////////////////////////

	unordered_set <string> range;
	for(int i = 0;i < nR;i++)
		range.insert(Function.at(i).second);

	// cout << "Range : \n{ ";
	// for(itr = range.begin();itr != range.end();itr++)
	// 	cout << *itr << " ";
	// cout << " }\n";
	
	if(range == set_B) {
		onto = true;
		cout << "onto Function.\n";
	} else {
		into = true;
		cout << "into Function.\n";
	}

	// cout << "One-one : " << one_one << "\nMany-one : " << many_one << "\nOnto : " << onto << "\nInto : " << into << endl; 

	if(one_one and onto)
		cout << "Bijective Function.\n";

	//////////////////////////////////////////////////////////////////////////////////////////////

	return 0;
}