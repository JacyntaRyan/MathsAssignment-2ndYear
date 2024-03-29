// mathsAss1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
using namespace std;
#include <vector>

typedef unsigned long long big;
vector<int> remainders;
int privateKey= RSAEncryption();
big decrypted=RSAEncryption();

vector<int> primeFactorisation(int a)
{
	vector<int> listOfFactors;
	int lastFactor = 2;

	while (lastFactor < a)
	{
		if (a %lastFactor == 0) {
			listOfFactors.push_back(lastFactor);
			a = a / lastFactor;
		}
		else
			++lastFactor;
	}
	//add the last prime to the vector after exiting the loop
	if (a != 1)
	{
		listOfFactors.push_back(a);
	}
	return listOfFactors;
}

int gcd(int x, int y)
{
	int a;
	int b;
	if (x < y)
	{
		b = x;
		a = y;
	}
	else
	{
		a = x;
		b = y;
	}
	if (b == 0)
	{
		return a;
	}
	remainders.push_back (b);
	return gcd(b, a%b);

}
vector<double> extendedEuclidean(int a,int b)
{
	vector<double> out;
	int d = 0;
	int x = a;
	int y = b;
	int ans = 0;
	int ans2 = 0;

	cout<<"gcd of "<<x<<" and "<<y<<" is "<< gcd(x,y);
	remainders.clear();
	return out;
}

int RSAEncryption()
{
	double plaintext;
	char choice ='p';
	/*I set the type def for unsigned long long to be called big to save me typing*/
	big n = 0;
	big q = 0;
	big p = 0;
	big e = 0;
	big phi = 0;
	big d = 0;
	big ciphertext;
	big v = 3;
	
	bool ed = false;

	cout << "Please type the message to be encrypted" << endl;
	cin >> plaintext;
	cout << "Would you like to enter public key (type'n') or p&q (type 'p')" << endl;
	cin >> choice;
	if (choice == 'n')
	{
		cout << "enter n" << endl;
		cin >> n;
		vector<int> pAndq =primeFactorisation(n);
		p = pAndq[0];
		q = pAndq[1];
	}
	else if (choice == 'p')
	{
		cout << "enter p" << endl;
		cin >> p;
		cout << "enter q" << endl;
		cin >> q;
	}
	cout << "enter e" << endl;
	cin >> e;
	
	n = p * q;
	phi = (p - 1) * (q - 1);
	
	//calculate d  => /*this is the private key*/
	
	while (ed==false)
	{
		d = ((phi * v) + 1) / e;
		big equation =( d * e) -( phi * v);
		if (equation!=0)
		{
			ed = false;
			cout << "v" << v << endl;
			v++;
		}
		else
		{
			ed = true;
		}
				
	} 
	//cout << d << "d&v " << v << endl;
	d = ((phi*v) + 1) / e;
	
	//deleting value for p+q by setting to 0
	p = 0;
	q = 0;
	
	//encrypt message c=m^e mod n
	ciphertext = ((big)pow(plaintext, e)) % n;//casting the pow result so i can use the mod function
	cout << "cipertext = " << ciphertext << endl;
	cout << "public Key = " << n << endl;
	cout << "private key = " << d<< endl;

	return d;

}

void RSADecryption()
{
	big cipher = 0;
	big pubKey = 0;
	big privKey = 0;

	cout << "please enter the cipher" << endl;
	cin >> cipher;
	cout << "enter public key" << endl;
	cin >> pubKey;
	cout << "enter private key" << endl;
	cin >> privKey;
	

	//decrypt message m=c^d mod n
	big plaintext = ((big)pow(cipher, privKey)) % pubKey;
	cout << plaintext << endl;
	
}



int main()
{
	
	
	int userInput;
    
	cout << "----------Menu----------" << endl;
	cout << "please select from the following:" << endl;
	cout << "1.Prime factorisation of a natural number" << endl;
	cout<<"2.Extended Euclidean algorithm" << endl;
	cout<<"3.RSA Encryption" << endl;
	cout<<"4.RSA Decryption" << endl;
	cin >> userInput;

		if (userInput == 1)
		{
			int j = 0;
			cout << "please enter a number" << endl;
			cin >> j;
			
			vector<int> factors = primeFactorisation(j);
			
			for (auto i : factors)
			{
				std::cout << i << ' '  ;
			}
		}
		else if (userInput == 2)
		{	// ive coded a method to get the gcd I just cant figure out the extended euclidean
			int x;
			int y;
			cout << "please enter a number for x" << endl;
			cin >> x;
			cout << "please enter a number for y" << endl;
			cin >> y;
			 extendedEuclidean(x,y);
		}
		else if (userInput == 3)
		{
			RSAEncryption();
		}
		else if (userInput == 4)
		{
			RSADecryption();
		}
		else
		{
			cout << "invalid choice" << endl;
		}
}




