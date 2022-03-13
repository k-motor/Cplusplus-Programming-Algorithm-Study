#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	int r = a % b;
	if(r == 0){
		return b;
	}
	gcd(b, r);
}

int main(void){
	cout << gcd(192,162) << '\n';
}
