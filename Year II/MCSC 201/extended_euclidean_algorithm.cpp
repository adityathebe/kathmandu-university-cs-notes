#include <iostream>
using namespace std;

int gcd(int, int);
int gcd_main(int, int);

int s[3], t[3];

int main() {
	int a = 1800, b=240, GCD;
	while(1) {
		cout << "\na: ";
		cin >> a;
		cout << "b:";
		cin >> b;
		
		s[0] = t[1] = 1;
		s[1] = t[0] = 0;
		cout << "=====================================" << endl;
		GCD = gcd(a,b);
		cout << "=====================================" << endl;
		cout << "GCD = " << GCD  << endl;
		cout << GCD << " = " << s[0] << "x" << a << " + " << t[0] <<"x" << b << endl;
	}
}

int gcd(int m, int n) {	
	/* Validating that m>n */	
	if (n > m) {
		int temp = m;
		m = n;
		n = temp;
	}
	return gcd_main(m,n);
}

int gcd_main(int m, int n) {
	int temp = n;
	int r = m % n;
	int q = m / n;
	cout << m << " = " << n << "x" << q << " + " << r << endl;
	
	/* ====== Extended GCD ====== */	
	s[2] = s[0] - q*s[1];
	t[2] = t[0] - q*t[1];
	
	s[0] = s[1];
	s[1] = s[2];	
	t[0] = t[1];
	t[1] = t[2];
	
	if(r == 0) {
		return temp;
	}
	gcd_main(n, r);
}
