#include <iostream>
#include <limits>
using namespace std;
int main()
{
	cout<<"Welcome to stone grab.\n";//by 21007 李 逸 馳 
	cout<<"There are three piles of stones, each pile containing 0 to 2147483647 stones\n";
	cout<<"The computer and you take turns removing at least 1 stone from an arbitrary pile,\nprovided that the chosen pile has enough stones left. The computer goes first.\n";
	cout<<"Whoever removes the last stone loses. If there are 0 stones at the beginning, the computer wins.\n";
	cout<<"Please input the number of stones of each pile.";
	int a, b, c, t, a2, b2, c2, s, k; //a, b, c for each pile of stones; a2, b2, c2 for user input; t, s, k for determining which move to play in a losing position
	while(1)
	{
		cin>>a;
		if(cin.fail() || a<0) //If the user tries to mess around, such as inputting non-int or negative numbers, we can handle it in style
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Invalid input for the 1st pile! Input the three numbers again.";
			continue;
		}
		cin>>b;
		if(cin.fail() || b<0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Invalid input for the 2nd pile! Input the three numbers again.";
			continue;
		}
		cin>>c;
		if(cin.fail() || c<0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Invalid input for the 3rd pile! Input the three numbers again.";
			continue;
		}
		break;
	}
	cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear redundant inputs from the user
	while(1)
	{
		if(0ll+a+b+c==0){cout<<"The computer wins! You lose!\n"; system("pause"); break;} //If "a=b=c=0", the computer wins
		if(!((1ll*a*b)|(1ll*b*c)|(1ll*c*a))) //Checks if there are two zeros among a, b, c
		{
			if(0ll+a+b+c==1) //The computer encounters two 0s and a 1 and is forced to remove the last stone and lose
			{
				if(a) cout<<"Remove 1 stone from the 1st pile.\n";
				else if(b) cout<<"Remove 1 stone from the 2nd pile.\n";
				else cout<<"Remove 1 stone from the 3rd pile.\n";
				cout<<"0 0 0\n"<<"You win! The computer loses!\n";
				system("pause");
				break;
			}
			if(a) //If there are two 0s and the other pile has more than 1 stone, it's obvious that the computer should remove all but one stone to win
			{
				cout<<"Remove "<<a-1<<(a==2 ? " stone" : " stones")<<" from the 1st pile.\n";
				a=1;
			}
			else if(b)
			{
        		cout<<"Remove "<<b-1<<(b==2 ? " stone" : " stones")<<" from the 2nd pile.\n";
				b=1;
			}
			else
			{
				cout<<"Remove "<<c-1<<(c==2 ? " stone" : " stones")<<" from the 3rd pile.\n";
				c=1;
			}
		}
		else if(0ll+a+b==1 || 0ll+b+c==1 || 0ll+c+a==1) //If there are a 0 and a 1 and the other pile has at least 1 stone, it's obvious that the computer should remove all stones of the biggest pile to win
		{
			if(a>1 || (a==1 && 0ll+a+b+c==2))
			{
				cout<<"Remove "<<a<<(a==1 ? " stone" : " stones")<<" from the 1st pile.\n";
				a=0;
			}
			else if(b>1 || (b==1 && 0ll+a+b+c==2))
			{
        		cout<<"Remove "<<b<<(b==1 ? " stone" : " stones")<<" stones from the 2nd pile.\n";
				b=0;
			}
			else if(c>1 || (c==1 && 0ll+a+b+c==2))
			{
				cout<<"Remove "<<c<<(c==1 ? " stone" : " stones")<<" stones from the 3rd pile.\n";
				c=0;
			}
		}
		else if((1ll*a*b==1 || 1ll*b*c==1 || 1ll*c*a==1) && 1ll*a*b*c>1) //If there are two 1s and the other pile has more than 1 stone, it's also obvious that the computer should make every pile have one stone to win
		{
			if(a>1)
			{
				cout<<"Remove "<<a-1<<(a==2 ? " stone" : " stones")<<" from the 1st pile.\n";
				a=1;
			}
			else if(b>1)
			{
        		cout<<"Remove "<<b-1<<(b==2 ? " stone" : " stones")<<" from the 2nd pile.\n";
				b=1;
			}
			else if(c>1)
			{
				cout<<"Remove "<<c-1<<(c==2 ? " stone" : " stones")<<" from the 3rd pile.\n";
				c=1;
			}
		}
		else
		{
			if((b^c) < a) //It can be proven that except for positions metioned above, if a position is a losing position and the numbers of stones of the three piles are x, y and z, then x^y^z == 0, which means x==y^z, y==z^x, z==x^y
			{
				t = a - (b^c); a -= t;
				cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 1st pile.\n";
			}
			else if((c^a) < b)
			{
				t = b - (c^a); b -= t;
				cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 2nd pile.\n";
			}
			else if((a^b) < c)
			{
				t = c - (a^b); c -= t;
				cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 3rd pile.\n";
			}
			else
			{ //If we reach here, the computer must be in a losing position. In this case the computer will play a seemingly random move, but it will always play the same move if the position is the same, regardless of the order of the three numbers
				if(a>=b+c)
				{
					t = 1ll*((a%11 < 4) ? 3 : 11 - a%11)*a/11; if(a/7%5+t<a)t+=a/7%5; if(t==0)t++;
					a -= t;
					cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 1st pile.\n";
				}
				else if(b>=c+a)
				{
					t = 1ll*((b%11 < 4) ? 3 : 11 - b%11)*b/11; if(b/7%5+t<b)t+=b/7%5; if(t==0)t++;
					b -= t;
					cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 2nd pile.\n";
				}
				else if(c>=a+b)
				{
					t = 1ll*((c%11 < 4) ? 3 : 11 - c%11)*c/11; if(c/7%5+t<c)t+=c/7%5; if(t==0)t++;
					c -= t;
					cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 3rd pile.\n";
				}
				else
				{
					k = (a/3 + b/3 + c/3) % 3; s = 1;
					if(a>=b&&a>=c){t=0;if(c>=b){s=-1;}}
					if(b>=a&&b>=c){t=1;if(a>=c){s=-1;}}
					if(c>=a&&c>=b){t=2;if(b>=a){s=-1;}}
					t+=s*k; if(t<0)t+=3; else t%=3;
					while(1)
					{
						if(t==0)
						{
							if(a==0){t+=s; if(t<0)t+3; else t%=3;}
							else
							{
								t = 1ll*((a%13 < 8) ? 3 : 13 - a%13)*a/13; if(t==0)t++;
								a -= t;
								cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 1st pile.\n";
								break;
							}
						}
						if(t==1)
						{
							if(b==0){t+=s; if(t<0)t+3; else t%=3;}
							else
							{
								t = 1ll*((b%13 < 8) ? 3 : 13 - b%13)*b/13; if(t==0)t++;
								b -= t;
								cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 2nd pile.\n";
								break;
							}
						}
						if(t==2)
						{
							if(c==0){t+=s; if(t<0)t+3; else t%=3;}
							else
							{
								t = 1ll*((c%13 < 8) ? 3 : 13 - c%13)*c/13; if(t==0)t++;
								c -= t;
								cout<<"Remove "<<t<<(t==1 ? " stone" : " stones")<<" from the 3rd pile.\n";
								break;
							}
						}
					} 
				}
			}
		}
		cout<<a<<" "<<b<<" "<<c<<"\n";
		cout<<"Please input the number of stones of each pile after your move.";
		while(1)
		{
			cin>>a2;
			if(cin.fail() || a2>a || a2<0) //The user must input int and can't increase the number of stones nor input negative numbers
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Invalid input for the 1st pile! Input the three numbers again.";
				continue;
			}
			cin>>b2;
			if(cin.fail() || b2>b || b2<0 || (a2<a && b2<b)) //Only one pile can be altered
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Invalid input for the 2nd pile! Input the three numbers again.";
				continue;
			}
			cin>>c2;
			if(cin.fail() || c2>c || c2<0 || (a2==a?1:0) + (b2==b?1:0) + (c2==c?1:0) != 2) //Exactly two piles have to remain the same
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout<<"Invalid input for the 3rd pile! Input the three numbers again.";
				continue;
			}
			break;
		}
		a=a2; b=b2; c=c2; cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Assign user input to a, b, c, ignore redundant input, start another turn
	}
}
