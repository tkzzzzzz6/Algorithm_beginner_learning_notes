#include <iostream>
#include <string>
using namespace std;

void showICPC() {
	cout << "I love ICPC!" << endl;
	cout << "-------------------------" << endl;
	cout << "-#####-#####-#####-#####-" << endl;
	cout << "---#---#-----#---#-#-----" << endl;
	cout << "---#---#-----#####-#-----" << endl;
	cout << "-#####-#####-#-----#####-" << endl;
	cout << "-------------------------" << endl;
}

void showCCPC() {
	cout << "I love CCPC!" << endl;
	cout << "-------------------------" << endl;
	cout << "-#####-#####-#####-#####-" << endl;
	cout << "-#-----#-----#---#-#-----" << endl;
	cout << "-#-----#-----#####-#-----" << endl;
	cout << "-#####-#####-#-----#####-" << endl;
	cout << "-------------------------" << endl;
}


int main()
{
	string judge;
	cin >> judge;
	if (judge == "ICPC")
		showICPC();
	if (judge == "CCPC")
		showCCPC();
	else {
		cout << "input error!";
	}
	return 0;
}