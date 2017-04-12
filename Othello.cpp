#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<Windows.h>
using namespace std;
class Table
{
public:
	int steak, opponent, hand;
	int bigTable[9][9],chessTable[9][9];
	bool checkStep(int x, int y)
	{
		int xi, yi;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		if (bigTable[x][y]!=0) return false;
		for (int i = 1; i <= 8; i++)
		{
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			if ((bigTable[xi][yi] != opponent) || (xi < 1) || (xi>8) || (yi < 1) || (yi>8)) continue;
			while (bigTable[xi][yi] == opponent)
			{
				xi += MoveX[i];
				yi += MoveY[i];
				if ((bigTable[xi][yi] == 0) || ((xi < 1) || (xi > 8) || (yi < 1) || (yi > 8))) break;
				if (bigTable[xi][yi] == steak) return true;
			}
		}
		return false;
	}
	void setStep(int x, int y)
	{
		int xi, yi, count;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		for (int i = 1; i <= 8; i++)
		{
			count = 0;
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			count++;
			if ((bigTable[xi][yi] != opponent) || (xi < 1) || (xi>8) || (yi < 1) || (yi>8)) continue;
			while (bigTable[xi][yi] == opponent)
			{
				xi += MoveX[i];
				yi += MoveY[i];
				count++;
				if ((bigTable[xi][yi] == 0)||(xi < 1) || (xi > 8) || (yi < 1) || (yi > 8)) break;
				if (bigTable[xi][yi] == steak)
				{
					for (int j = 1; j <= count-1; j++)
						bigTable[x + j*MoveX[i]][y + j*MoveY[i]] = steak;
					break;
				}
			}
		}
		bigTable[x][y] = steak;
		hand++;
	}
	void pretendStep(int x, int y)
	{
		int xi, yi, count;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		for (int i = 1; i <= 8; i++)
		{
			count = 0;
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			count++;
			if ((chessTable[xi][yi] != opponent) || (xi < 1) || (xi>8) || (yi < 1) || (yi>8)) continue;
			while (chessTable[xi][yi] == opponent)
			{
				xi += MoveX[i];
				yi += MoveY[i];
				count++;
				if ((chessTable[xi][yi] == 0) || (xi < 1) || (xi > 8) || (yi < 1) || (yi > 8)) break;
				if (chessTable[xi][yi] == steak)
				{
					for (int j = 1; j <= count - 1; j++)
						chessTable[x + j*MoveX[i]][y + j*MoveY[i]] = steak;
					break;
				}
			}
		}
		chessTable[x][y] = steak;
	}
	bool checkMove()
	{
		for (int x = 1; x <= 8; x++)
			for (int y = 1; y <= 8; y++)
				if (checkStep(x, y))
					return true;
		return false;
	}
	int calcDivergence(int x, int y)
	{
		int xi, yi, count=0;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		count = 0;
		for (int i = 1; i <= 8; i++)
		{
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			if ((xi >= 1) && (xi <= 8) && (yi >= 1) && (yi <= 8) && (chessTable[xi][yi] == 0))
				count++;
		}
		return count;
	}
	bool checkSurrounding(int x, int y)
	{
		int xi, yi;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		for (int i = 1; i <= 8; i++)
		{
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			if ((xi >= 1) && (xi <= 8) && (yi >= 1) && (yi <= 8) && (chessTable[xi][yi] == 0))
				return false;
		}
		return true;
	}
	int calcSteady()
	{
		int xi, yi, count, count1=0;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		for (int x = 1; x <= 8; x++)
			for (int y = 1; y <= 8; y++)
				for (int i = 1; i <= 8; i++)
				{
					if (chessTable[x][y] != 0)
					{
						count = 0;
						xi = x + MoveX[i];
						yi = y + MoveY[i];
						count++;
						if ((chessTable[xi][yi] == 0) || (xi < 1) || (xi>8) || (yi < 1) || (yi>8))
						{
							if (checkSurrounding(x, y))
								count1 += (chessTable[x][y] == steak) ? 1 : -1;
							continue;
						}
						while (chessTable[xi][yi] != 0)
						{
							xi += MoveX[i];
							yi += MoveY[i];
							count++;
							if ((chessTable[xi][yi] == 0) || (xi < 1) || (xi > 8) || (yi < 1) || (yi > 8))
							{
								for (int j = 0; j <= count - 1; j++)
									if (checkSurrounding(x + j*MoveX[i], y + j*MoveY[i]))
										count1 += (chessTable[x + j*MoveX[i]][y + j*MoveY[i]] == steak) ? 1 : -1;
								break;
							}
						}
					}
				}
		return count1 / 4;
	}
	int calcTurning(int x, int y)
	{
		int xi, yi, count, turning = 0;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		for (int i = 1; i <= 8; i++)
		{
			count = 0;
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			count++;
			if ((bigTable[xi][yi] != opponent) || (xi < 1) || (xi>8) || (yi < 1) || (yi>8)) continue;
			while (bigTable[xi][yi] == opponent)
			{
				xi += MoveX[i];
				yi += MoveY[i];
				count++;
				if ((bigTable[xi][yi] == 0) || (xi < 1) || (xi > 8) || (yi < 1) || (yi > 8)) break;
				if (bigTable[xi][yi] == steak)
				{
					turning += count - 1;
					break;
				}
			}
		}
		return turning;
	}
	int calcEatDivergence(int x, int y)
	{
		int xi, yi, count, count1;
		MoveX[1] = 0;
		MoveX[2] = 0;
		MoveX[3] = -1;
		MoveX[4] = 1;
		MoveX[5] = -1;
		MoveX[6] = 1;
		MoveX[7] = -1;
		MoveX[8] = 1;
		MoveY[1] = -1;
		MoveY[2] = 1;
		MoveY[3] = 0;
		MoveY[4] = 0;
		MoveY[5] = -1;
		MoveY[6] = -1;
		MoveY[7] = 1;
		MoveY[8] = 1;
		count1 = 0;
		for (int i = 1; i <= 8; i++)
		{
			count = 0;
			xi = x + MoveX[i];
			yi = y + MoveY[i];
			count++;
			if ((chessTable[xi][yi] != opponent) || (xi < 1) || (xi>8) || (yi < 1) || (yi>8)) continue;
			while (chessTable[xi][yi] == opponent)
			{
				xi += MoveX[i];
				yi += MoveY[i];
				count++;
				if ((chessTable[xi][yi] == 0) || (xi < 1) || (xi > 8) || (yi < 1) || (yi > 8)) break;
				if (chessTable[xi][yi] == steak)
				{
					for (int j = 1; j <= count - 1; j++)
						count1 += calcDivergence(x + j*MoveX[i], y + j*MoveY[i]);
					break;
				}
			}
		}
		return count1;
	}
	int calcOutDivergence(Table Table1)
	{
		int min = 100,a;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 1; j++)
				if ((i >= 1) && (i <= 8) && (j >= 1) && (j <= 8) && (Table1.chessTable[i][j] == opponent))
				{
					a = calcDivergence(i, j);
					min = min > a ? a : min;
				}
		return min;
	}
	void displayTable(int x,int y,int steak)
	{
		int flag = -1,xi,yi;
		cout << "  1  2  3  4  5  6  7  8 " << endl;
		for (int j = 1; j <= 8; j++)
		{
			cout << "  ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
			cout << j;
			for (int i = 1; i <= 9; i++)
			{
				if (i == 9)
				{
					cout << "|" << endl;
					break;
				}
				if ((j == y) && (i == x)&& (x > 0) && (y > 0))
				{
					if (steak==2)
					{
						cout << "|¡ï";
					}
					else
					{
						cout << "|¡î";
					}
					continue;
				}
				if ((x < 0) && (y < 0) && (j == fabs((double)y)) && (i == fabs((double)x)))
				{
					if (bigTable[i][j] == 0)
						flag = 0;
					else
						flag = bigTable[i][j];
					cout << "|¡Á";
					continue;
				}
				switch (bigTable[i][j])
				{
				case 0:
					cout << "|  ";
					break;
				case 1:
					cout << "|¡ð";
					break;
				case 2:
					cout << "|¡ñ";
					break;
				}
			}
		}
		cout << "  ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª" << endl;
		cout << endl;
		if (flag > 0)
		{
			xi = (int)fabs((double)x);
			yi = (int)fabs((double)y);
		}
		if (flag == 0)
		{
			cout << "Sorry, you don't reverse a ";
			if (steak == 1)
				cout << "¡ñ chess. ";
			else
				cout << "¡ð chess. ";
		}
		else if (flag > 0)
		{
			cout << "Sorry, there is a ";
			if (flag == 2)
				cout << "¡ñ chess ";
			else
				cout << "¡ð chess ";
			cout << "in (" << (int)fabs((double)x) << " , " << (int)fabs((double)y) << "). ";
		}
	}
	void newTable()
	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				bigTable[i][j] = 0;
		bigTable[4][4] = 2;
		bigTable[4][5] = 1;
		bigTable[5][4] = 1;
		bigTable[5][5] = 2;
	}
private:
	int MoveX[9], MoveY[9];
	bool flag = true;
};
class AI
{
public:
	int bigTable[9][9];
	void initialize(int steak,string name)
	{
		Nickname = name;
		AITable.steak = steak;
		AITable.opponent = steak == 1 ? 2 : 1;
		AITable.hand = 1;
		AITable.newTable();
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				bigTable[i][j] = AITable.bigTable[i][j];
	}
	string getNickname()
	{
		return Nickname;
	}
	bool checkSquare(int x, int y)
	{
		if ((y == 1) && ((x == 2) || (x == 7))) return true;
		if ((y == 2) && ((x == 1) || (x == 8) || (x == 2) || (x == 7))) return true;
		if ((y == 7) && ((x == 1) || (x == 8) || (x == 2) || (x == 7))) return true;
		if ((y == 8) && ((x == 2) || (x == 7))) return true;
		return false;
	}
	bool checkCorner(int x, int y)
	{
		if ((y == 1) && ((x == 1) || (x == 8))) return true;
		if ((y == 8) && ((x == 1) || (x == 8))) return true;
		return false;
	}
	bool checkSetCorner(Table Table1, int x, int y)
	{
		if (((y == 1) && (x == 2)) || ((y == 2) && (x == 1)) || ((y == 2)&&(x == 2)))
		{
			if (Table1.chessTable[1][1] != 0)
				return true;
			else 
				return false;
		}
		if (((y == 1) && (x == 7)) || ((y == 2) && (x == 7)) || ((y == 2) && (x == 8)))
		{
			if (Table1.chessTable[8][1] != 0)
				return true;
			else 
				return false;
		}
		if (((y == 8) && (x == 2)) || ((y == 7) && (x == 1)) || ((y == 7) && (x == 2)))
		{
			if (Table1.chessTable[1][8] != 0)
				return true;
			else 
				return false;
		}
		if (((y == 8) && (x == 7)) || ((y == 7) && (x == 7)) || ((y == 7 )&& (x == 8)))
		{
			if (Table1.chessTable[8][8] != 0)
				return true;
			else 
				return false;
		}
		return false;
	}
	int checkSetSquare(Table Table1)
	{
		int num = 0;
		if ((Table1.chessTable[1][2] == Table1.steak) && (Table1.chessTable[1][1] != Table1.steak))	num++;
		if ((Table1.chessTable[2][1] == Table1.steak) && (Table1.chessTable[1][1] != Table1.steak)) num++;
		if ((Table1.chessTable[2][2] == Table1.steak) && (Table1.chessTable[1][1] != Table1.steak)) num++;
		if ((Table1.chessTable[1][7] == Table1.steak) && (Table1.chessTable[1][8] != Table1.steak)) num++;
		if ((Table1.chessTable[2][7] == Table1.steak) && (Table1.chessTable[1][8] != Table1.steak)) num++;
		if ((Table1.chessTable[2][8] == Table1.steak) && (Table1.chessTable[1][8] != Table1.steak)) num++;
		if ((Table1.chessTable[7][1] == Table1.steak) && (Table1.chessTable[8][1] != Table1.steak)) num++;
		if ((Table1.chessTable[7][2] == Table1.steak) && (Table1.chessTable[8][1] != Table1.steak)) num++;
		if ((Table1.chessTable[8][2] == Table1.steak) && (Table1.chessTable[8][1] != Table1.steak)) num++;
		if ((Table1.chessTable[7][7] == Table1.steak) && (Table1.chessTable[8][8] != Table1.steak))	num++;
		if ((Table1.chessTable[8][7] == Table1.steak) && (Table1.chessTable[8][8] != Table1.steak))	num++;
		if ((Table1.chessTable[7][8] == Table1.steak) && (Table1.chessTable[8][8] != Table1.steak))	num++;
		return num;
	}
	void searchPossibleMove(Table Table1)
	{
		for (int i = 1; i <= 64; i++)
			for (int j = 1; j <= 2; j++)
				possibleMove[i][j] = 0;
		possibleMoves = 0;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8;j++)
				if (Table1.checkStep(i, j))
				{
					possibleMoves++;
					possibleMove[possibleMoves][1] = i;
					possibleMove[possibleMoves][2] = j;
				}
	}
	void searchEatDivergence(Table Table1)
	{
		int a;
		quietMoves = 0;
		for (int i = 1; i <= possibleMoves; i++)
		{
			if (!checkSquare(possibleMove[i][1], possibleMove[i][2]))
			{
				a = Table1.calcEatDivergence(possibleMove[i][1], possibleMove[i][2]);
				if (a == 0)
				{
					quietMoves++;
					quietMove[quietMoves] = i;
				}
			}
		}
	}
	int compareOutDivergence(Table Table1,int ans,int ans1)
	{
		int a, chessTable[9][9], b,num;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				Table1.chessTable[i][j] = bigTable[i][j];
				chessTable[i][j] = Table1.chessTable[i][j];
			}
		Table1.pretendStep(possibleMove[ans][1], possibleMove[ans][2]);
		a = Table1.calcOutDivergence(Table1);
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = chessTable[i][j];
		num = checkSetSquare(Table1);
		Table1.pretendStep(possibleMove[ans1][1], possibleMove[ans1][2]);
		if (num > checkSetSquare(Table1))
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
					Table1.chessTable[i][j] = chessTable[i][j];
			return ans;
		}
		b = Table1.calcOutDivergence(Table1);
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = chessTable[i][j];
		return (a > b) ? ans : ans1;
	}
	int compareEatDivergence(Table Table1, int ans, int ans1)
	{
		int a, b,chessTable[9][9],num;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				Table1.chessTable[i][j] = bigTable[i][j];
				chessTable[i][j] = Table1.chessTable[i][j];
			}
		a = Table1.calcEatDivergence(possibleMove[ans][1], possibleMove[ans][2]);
		num = checkSetSquare(Table1);
		Table1.pretendStep(possibleMove[ans1][1], possibleMove[ans1][2]);
		if (num > checkSetSquare(Table1))
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
					Table1.chessTable[i][j] = chessTable[i][j];
			return ans;
		}
		b = Table1.calcEatDivergence(possibleMove[ans1][1], possibleMove[ans1][2]);
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = chessTable[i][j];
		return (a > b) ? ans1 : ans;
	}
	int compareSteady(Table Table1, int ans, int ans1)
	{
		int a,chessTable[9][9],b,num;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				Table1.chessTable[i][j] = bigTable[i][j];
				chessTable[i][j] = Table1.chessTable[i][j];
			}
		Table1.pretendStep(possibleMove[ans][1], possibleMove[ans][2]);
		a = Table1.calcSteady();
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = chessTable[i][j];
		num = checkSetSquare(Table1);
		Table1.pretendStep(possibleMove[ans1][1], possibleMove[ans1][2]);
		if (num > checkSetSquare(Table1))
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
					Table1.chessTable[i][j] = chessTable[i][j];
			return ans;
		}
		b = Table1.calcSteady();
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = chessTable[i][j];
		return (b > a) ? ans1 : ans;
	}
	int compareTurning(Table Table1, int ans, int ans1)
	{
		int a, b;
		a = Table1.calcTurning(possibleMove[ans][1], possibleMove[ans][2]);
		b = Table1.calcTurning(possibleMove[ans1][1], possibleMove[ans1][2]);
		return (b > a) ? ans1 : ans;
	}
	int openingAnalysize(Table Table1)
	{
		int ans=-1, bad=0;
		bool check[64],flag;
		searchPossibleMove(Table1);
		if (possibleMoves == 1) return 1;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = Table1.bigTable[i][j];
		for (int i = 1; i <= possibleMoves; i++)
		{
			check[i] = checkSquare(possibleMove[i][1], possibleMove[i][2]);
			if (check[i])
			{
				if (checkSetCorner(Table1,possibleMove[i][1], possibleMove[i][2]))
					check[i] = false;
				if (check[i]) bad++;
			}
		}
		if (bad == possibleMoves)
		{
			ans = rand() % possibleMoves + 1;
			for (int i = 1; i <= possibleMoves; i++)
				ans = compareSteady(Table1, ans, i);
			return ans;
		}
		flag = false;
		ans = -1;
		for (int i = 1; i <= possibleMoves; i++)
			if (checkCorner(possibleMove[i][1], possibleMove[i][2]))
			{
				if (ans == -1)
				{
					ans = i;
					flag = true;
					continue;
				}
				ans = compareSteady(Table1, ans, i);
			}
		if (flag) return ans;
		ans = -1;
		for (int i = 1; i <= possibleMoves; i++)
			if (!check[i])
			{
				if (ans == -1)
				{
					ans = i;
					flag = true;
					continue;
				}
				ans = compareSteady(Table1, ans, i);
			}
		return ans;
	}
	int midAnalysize(Table Table1)
	{
		int ans=-1,bad=0,num,a1,a2;
		bool check[64], flag;
		srand(time(0));
		searchPossibleMove(Table1);
		if (possibleMoves == 1) return 1;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = Table1.bigTable[i][j];
		for (int i = 1; i <= possibleMoves; i++)
		{
			check[i] = checkSquare(possibleMove[i][1], possibleMove[i][2]);
			if (check[i])
			{
				if (checkSetCorner(Table1,possibleMove[i][1], possibleMove[i][2]))
					check[i] = false;
				if (check[i]) bad++;
			}
		}
		num = 0;
		for (int i = 1; i <= 1; i++)
			for (int j = 1; j <= 1; j++)
				if (bigTable[i][j] == Table1.opponent)
					num++;
		if ((num <= ((6 > Table1.hand / 3) ? 6 : Table1.hand / 3)) || (num >=(Table1.hand * 2 / 3)))
		{
			if (bad == possibleMoves)
			{
				ans = rand() % possibleMoves + 1;
				for (int i = 1; i <= possibleMoves; i++)
					ans = compareSteady(Table1, ans, i);
				return ans;
			}
			flag = false;
			ans = -1;
			for (int i = 1; i <= possibleMoves; i++)
				if (checkCorner(possibleMove[i][1], possibleMove[i][2]))
				{
					if (ans == -1)
					{
						ans = i;
						flag = true;
						continue;
					}
					a1 = compareSteady(Table1, ans, i);
					a2 = compareTurning(Table1, ans, i);
					ans = ((a1 != ans) && (a2 != ans)) ? i : ans;
				}
			if (flag) return ans;
			ans = -1;
			for (int i = 1; i <= possibleMoves; i++)
				if (!check[i])
				{
					if (ans == -1)
					{
						ans = i;
						flag = true;
						continue;
					}
					a1 = compareSteady(Table1, ans, i);
					a2 = compareTurning(Table1, ans, i);
					ans = ((a1 != ans) && (a2 != ans)) ? i : ans;
				}
			return ans;
		}
		else
		{
			if (bad == possibleMoves)
			{
				ans = rand() % possibleMoves + 1;
				for (int i = 1; i <= possibleMoves; i++)
					ans = compareEatDivergence(Table1, ans, i);
				return ans;
			}
			searchEatDivergence(Table1);
			if ((quietMoves == 1) && (!check[quietMove[1]])) return quietMove[1];
			if (quietMoves>1)
			{
				ans = -1;
				for (int i = 1; i <= possibleMoves; i++)
					if (!check[i])
					{
						if (ans == -1)
						{
							ans = i;
							flag = true;
							continue;
						}
						ans = compareOutDivergence(Table1, ans, i);
					}
				return ans;
			}
			flag = false;
			ans = -1;
			for (int i = 1; i <= possibleMoves; i++)
				if (checkCorner(possibleMove[i][1], possibleMove[i][2]))
				{
					if (ans == -1)
					{
						ans = i;
						flag = true;
						continue;
					}
					ans = compareOutDivergence(Table1, ans, i);
				}
			if (flag) return ans;
			ans = -1;
			for (int i = 1; i <= possibleMoves; i++)
				if (!check[i])
				{
					if (ans == -1)
					{
						ans = i;
						flag = true;
						continue;
					}
					ans = compareSteady(Table1, ans, i);
				}
			return ans;
		}
	}
	int endingAnalysize(Table Table1)
	{
		srand(time(0));
		int ans=-1,bad=0;
		bool flag = false , check[64];
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = Table1.bigTable[i][j];
		searchPossibleMove(Table1);
		if (possibleMoves == 1) return 1;
		for (int i = 1; i <= possibleMoves; i++)
		{
			check[i] = checkSquare(possibleMove[i][1], possibleMove[i][2]);
			if (check[i])
			{
				if (checkSetCorner(Table1,possibleMove[i][1], possibleMove[i][2]))
					check[i] = false;
				if (check[i]) bad++;
			}
		}
		if (bad == possibleMoves)
		{
			ans = rand() % possibleMoves + 1;
			for (int i = 1; i <= possibleMoves; i++)
				ans = compareSteady(Table1, ans, i);
			return ans;
		}
		ans = -1;
		for (int i = 1; i <= possibleMoves; i++)
			if (checkCorner(possibleMove[i][1], possibleMove[i][2]))
			{
				if (ans == -1)
				{
					ans = i;
					flag = true;
					continue;
				}
				ans = compareSteady(Table1, ans, i);
			}
		if (flag) return ans;
		ans = -1;
		for (int i = 1; i <= possibleMoves; i++)
			if (!check[i])
			{
				if (ans == -1)
				{
					ans = i;
					flag = true;
					continue;
				}
				ans = compareSteady(Table1, ans, i);
			}
		return ans;
	}
	int fight(Table Table1)
	{
		int ans, a1, a2;
		srand(time(0));
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				Table1.chessTable[i][j] = Table1.bigTable[i][j];
		searchPossibleMove(Table1);
		if (possibleMoves == 1) return 1;
		ans = rand() % possibleMoves + 1;
		for (int i = 1; i <= possibleMoves; i++)
		{
			a1 = compareSteady(Table1, ans, i);
			a2 = compareTurning(Table1, ans, i);
			ans = ((a1 != ans) && (a2 != ans)) ? i : ans;
		}
		return ans;
	}
	int evaluate()
	{
		int value = 0;
		value += AITable.calcSteady() * 5;
		value -= AITable.calcSteady() * 5;
		if (AITable.chessTable[1][1] > 0) value += (AITable.steak == AITable.chessTable[1][1]) ? 25 : -25;
		if (AITable.chessTable[1][8] > 0) value += (AITable.steak == AITable.chessTable[1][8]) ? 25 : -25;
		if (AITable.chessTable[8][1] > 0) value += (AITable.steak == AITable.chessTable[8][1]) ? 25 : -25;
		if (AITable.chessTable[8][8] > 0) value += (AITable.steak == AITable.chessTable[8][8]) ? 25 : -25;
		if (AITable.chessTable[1][2] > 0)
		{
			if (AITable.chessTable[1][1] == AITable.steak) 
				value += (AITable.steak == AITable.chessTable[1][2]) ? 0 : 25;
			else if (AITable.chessTable[1][1] == 0)
				value += (AITable.steak == AITable.chessTable[1][2]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[1][2]) ? -25 : 0;
		}
		if (AITable.chessTable[1][7] > 0)
		{
			if (AITable.chessTable[1][8] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[1][7]) ? 0 : 25;
			else if (AITable.chessTable[1][8] == 0)
				value += (AITable.steak == AITable.chessTable[1][7]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[1][7]) ? -25 : 0;
		}
		if (AITable.chessTable[2][1] > 0)
		{
			if (AITable.chessTable[1][1] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[2][1]) ? 0 : 25;
			else if (AITable.chessTable[1][1] == 0)
				value += (AITable.steak == AITable.chessTable[2][1]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[2][1]) ? -25 : 0;
		}
		if (AITable.chessTable[2][2] > 0)
		{
			if (AITable.chessTable[1][1] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[2][2]) ? 0 : 25;
			else if (AITable.chessTable[1][1] == 0)
				value += (AITable.steak == AITable.chessTable[2][2]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[2][2]) ? -25 : 0;
		}
		if (AITable.chessTable[2][7] > 0)
		{
			if (AITable.chessTable[1][8] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[2][7]) ? 0 : 25;
			else if (AITable.chessTable[1][8] == 0)
				value += (AITable.steak == AITable.chessTable[2][7]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[2][7]) ? -25 : 0;
		}
		if (AITable.chessTable[2][8] > 0)
		{
			if (AITable.chessTable[1][8] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[2][8]) ? 0 : 25;
			else if (AITable.chessTable[1][8] == 0)
				value += (AITable.steak == AITable.chessTable[2][8]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[2][8]) ? -25 : 0;
		}
		if (AITable.chessTable[7][1] > 0)
		{
			if (AITable.chessTable[8][1] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[7][1]) ? 0 : 25;
			else if (AITable.chessTable[8][1] == 0)
				value += (AITable.steak == AITable.chessTable[7][1]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[7][1]) ? -25 : 0;
		}
		if (AITable.chessTable[7][2] > 0)
		{
			if (AITable.chessTable[8][1] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[7][2]) ? 0 : 25;
			else if (AITable.chessTable[8][1] == 0)
				value += (AITable.steak == AITable.chessTable[7][2]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[7][2]) ? -25 : 0;
		}
		if (AITable.chessTable[7][7] > 0)
		{
			if (AITable.chessTable[8][8] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[7][7]) ? 0 : 25;
			else if (AITable.chessTable[8][8] == 0)
				value += (AITable.steak == AITable.chessTable[7][7]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[7][7]) ? -25 : 0;
		}
		if (AITable.chessTable[7][8] > 0)
		{
			if (AITable.chessTable[8][8] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[7][8]) ? 0 : 25;
			else if (AITable.chessTable[8][8] == 0)
				value += (AITable.steak == AITable.chessTable[7][8]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[7][8]) ? -25 : 0;
		}
		if (AITable.chessTable[8][2] > 0)
		{
			if (AITable.chessTable[8][1] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[1][2]) ? 0 : 25;
			else if (AITable.chessTable[8][1] == 0)
				value += (AITable.steak == AITable.chessTable[1][2]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[1][2]) ? -25 : 0;
		}
		if (AITable.chessTable[8][7] > 0)
		{
			if (AITable.chessTable[8][8] == AITable.steak)
				value += (AITable.steak == AITable.chessTable[8][7]) ? 0 : 25;
			else if (AITable.chessTable[8][8] == 0)
				value += (AITable.steak == AITable.chessTable[8][7]) ? -25 : 25;
			else
				value += (AITable.steak == AITable.chessTable[8][7]) ? -25 : 0;
		}
	}
	void set1()
	{
		int x, y;
		srand(time(0));
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				AITable.bigTable[i][j] = bigTable[i][j];
		if (!AITable.checkMove())
		{
			cout << getNickname()<<" can't move chess now." << endl;
			cout << "Change side." << endl;
			cout << endl;
			Sleep(900);
			return;
		}
		while (true)
		{
			x = rand() % 8 + 1;
			y = rand() % 8 + 1;
			if (AITable.checkStep(x, y))
			{
				AITable.setStep(x, y);
				break;
			}
		}
		cout << endl;
		cout << endl;
		cout << getNickname()<<" moves chess to (" << x << " , " << y << ")." << endl;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				bigTable[i][j] = AITable.bigTable[i][j];
		AITable.displayTable(x,y,AITable.steak);
	}
	void set2()
	{
		int hand,x,y,order;
		hand = AITable.hand;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				AITable.bigTable[i][j] = bigTable[i][j];
		searchPossibleMove(AITable);
		if (!AITable.checkMove())
		{
			cout << getNickname() << " can't move chess now." << endl;
			cout << "Change side." << endl;
			cout << endl;
			Sleep(900);
			return;
		}
		if (hand <= 10)
		{
			order = openingAnalysize(AITable);
		}
		else if ((hand > 10) && (hand <= 30))
		{
			order = midAnalysize(AITable);
		}
		else if ((hand>30) && (hand<=54))
		{
			order = endingAnalysize(AITable);
		}
		else
		{
			order = fight(AITable);
		}
		x = possibleMove[order][1];
		y = possibleMove[order][2];
		AITable.setStep(x, y);
		cout << endl;
		cout << endl;
		cout << getNickname() << " moves chess to (" << x << " , " << y << ")." << endl;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				bigTable[i][j] = AITable.bigTable[i][j];
		AITable.displayTable(x, y, AITable.steak);
	}
	/*void set3()
	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
			{
				AITable.chessTable[i][j] = AITable.bigTable[i][j];
				AITable.bigTable[i][j] = bigTable[i][j];
			}
	}*/
	bool endMove()
	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				AITable.bigTable[i][j] = bigTable[i][j];
		return (!AITable.checkMove());
	}
	int getSteak()
	{
		return AITable.steak;
	}
	void sethand(int hand)
	{
		AITable.hand = hand;
	}
	int gethand()
	{
		return AITable.hand;
	}
private:
	Table AITable;
	int MoveX[9], MoveY[9];
	int possibleMove[64][2],quietMove[64],eatDivergence[64];
	int possibleMoves,quietMoves;
	string Nickname;
};
class Player
{
public:
	int bigTable[9][9];
	void initialize(int steak,string name)
	{
		PlayerTable.steak = steak;
		PlayerTable.hand = 0;
		PlayerTable.opponent = steak == 1 ? 2 : 1;
		PlayerTable.newTable();
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				bigTable[i][j] = PlayerTable.bigTable[i][j];
		PlayerName = name;
	}
	void input()
	{
		int x, y;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				PlayerTable.bigTable[i][j]=bigTable[i][j];
		if (!PlayerTable.checkMove())
		{
			cout << "Sorry, you can't move now." << endl;
			cout << "Change side." << endl;
			cout << endl;
			Sleep(900);
			return;
		}
		cout << PlayerName << ", it is your turn now. And where do you want to move your chess?" << endl;
		cout << endl;
		cout << "X = ";
		cin >> x;
		cout << "Y = ";
		cin	>> y;
		while ((x<1)||(x>8)||(y<1)||(y>8)||(!PlayerTable.checkStep(x, y)))
		{
			if ((x >= 1) && (x <= 8) && (y >= 1) && (y <= 8))
			{
				cout << endl;
				cout << endl;
				cout << endl;
				PlayerTable.displayTable(-x, -y, PlayerTable.steak);
			}
			else
			{
				cout << endl;
				cout << endl;	
				cout << endl;
				PlayerTable.displayTable(0, 0, PlayerTable.steak);
				cout << "Sorry, chess can't reach there. ";
			}
			cout << "Please choose another position." << endl;
			cout << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
		}
		PlayerTable.setStep(x, y);
		cout << endl;
		cout << "It is done." << endl;
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				bigTable[i][j]= PlayerTable.bigTable[i][j];
		PlayerTable.displayTable(x,y,PlayerTable.steak);
		cout << endl;
		cout << endl;
		Sleep(900);
	}
	bool endMove()
	{
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				PlayerTable.bigTable[i][j] = bigTable[i][j];
		return (!PlayerTable.checkMove());
	}
	string getPlayerName()
	{
		return PlayerName;
	}
	int getSteak()
	{
		return PlayerTable.steak;
	}
	void sethand(int hand)
	{
		PlayerTable.hand=hand;
	}
	int gethand()
	{
		return PlayerTable.hand;
	}
	void displayTable()
	{
		PlayerTable.displayTable(0, 0, PlayerTable.steak);
	}
private:
	string PlayerName;
	Table PlayerTable;
	int chessTable[9][9];
};
class Game
{
public:
	void chooseMode()
	{
		cout << "Which mode do you want to play? (Enter 1 or 2)" << endl;
		cout << "1.Single Mode" << endl;
		cout << "2.Recreation Mode" << endl;
		cout << "3.Observer Mode" << endl;
		cin >> mode;
		while ((mode != 1) && (mode != 2)&&(mode!=3))
		{
			cout << "We don't have this mode for playing. Maybe you can create it." << endl;
			cout << endl;
			cout << "Which mode do you want to play? (Enter 1 or 2)" << endl;
			cout << "1.Single Mode" << endl;
			cout << "2.Recreation Mode" << endl;
			cout << "3.Observer Mode" << endl;
			cin >> mode;
		}
		cout << endl;
	}
	void judge(int mode)
	{
		int playnum1 = 0, playnum2 = 0, ainum1 = 0,ainum2=0;
		if (mode == 1)
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
				{
				if (bigTable[i][j] == Player1.getSteak())
					playnum1++;
				if (bigTable[i][j] == AI1.getSteak())
					ainum1++;
				}
			if (playnum1 > ainum1)
			{
				cout << Player1.getPlayerName() << " win!" << endl;
				cout << Player1.getPlayerName() << " wins over " << playnum1 - ainum1 << " chesses." << endl;
				win1++;
			}
			if (ainum1 > playnum1)
			{
				cout << "Master win!" << endl;
				cout << "Master wins over " << ainum1 - playnum1 << " chesses." << endl;
				winai2++;
			}
			if (ainum1 == playnum1)
			{
				cout << "It is equal." << endl;
			}
		}
		else if (mode==2)
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
				{
				if (bigTable[i][j] == Player1.getSteak())
					playnum1++;
				if (bigTable[i][j] == Player2.getSteak())
					playnum2++;
				}
			if (playnum1 > playnum2)
			{
				cout << Player1.getPlayerName() << " win!" << endl;
				cout << Player1.getPlayerName() << " wins over " << playnum1 - playnum2 << " chesses." << endl;
				win1++;
			}
			if (playnum1 < playnum2)
			{
				cout << Player2.getPlayerName() << " win!" << endl;
				cout << Player2.getPlayerName() << " wins over " << playnum2 - playnum1 << " chesses." << endl;
				win2++;
			}
			if (playnum2 == playnum1)
			{
				cout << "It is equal." << endl;
			}
		}
		else 
		{
			for (int i = 1; i <= 8; i++)
				for (int j = 1; j <= 8; j++)
				{
				if (bigTable[i][j] == AI1.getSteak())
					ainum1++;
				if (bigTable[i][j] == AI2.getSteak())
					ainum2++;
				}
			if (ainum1 > ainum2)
			{
				cout << AI1.getNickname() << " win!" << endl;
				cout << AI1.getNickname() << " wins over " << ainum1 - ainum2 << " chesses." << endl;
				winai1++;
			}
			if (ainum2 > ainum1)
			{
				cout << AI2.getNickname() << " win!" << endl;
				cout << AI2.getNickname() << " wins over " << ainum2 - ainum1 << " chesses." << endl;
				winai2++;
			}
			if (ainum1 == ainum2)
			{
				cout << "It is equal." << endl;
			}
		}
	}
	void Play()
	{
		string name1, name2;
		int steak1,steakJack,steakJason;
		if (mode == 1)
		{
			cout << "What's your name in the Game?" << endl;
			cin >> name1;
			cout << endl;
			cout << "Please choose a side." << endl;
			cout << "1.Black[ ¡ð ]" << endl;
			cout << "2.White[ ¡ñ ]" << endl;
			cin >> steak1;
			cout << endl;
			cout << endl;
			cout << endl;
			while ((steak1 != 1) && (steak1 != 2))
			{
				cout << "Sorry, you can only choose 1 or 2." << endl;
				cout << "1.Black[ ¡ð ]" << endl;
				cout << "2.White[ ¡ñ ]" << endl;
				cin >> steak1;
				cout << endl;
				cout << endl;
				cout << endl;
			}
			Player1.initialize(steak1,name1);
			Player1.displayTable();
			AI1.initialize((steak1==1?2:1),"Master");
			while (true)
			{
				if (steak1 == 1)
				{
					Player1.sethand(AI1.gethand());
					Player1.input();
					updateTable(1,1);
					if (check(1))
					{
						judge(1);
						break;
					}
					AI1.sethand(Player1.gethand());
					AI1.set2();
					updateTable(1,2);
					if (check(1))
					{
						judge(1);
						break;
					}
				}
				else
				{
					AI1.sethand(Player1.gethand());
					AI1.set2();
					updateTable(1, 2);
					if (check(1))
					{
						judge(1);
						break;
					}
					Player1.sethand(AI1.gethand());
					Player1.input();
					updateTable(1,1);
					if (check(1))
					{
						judge(1);
						break;
					}
				}
			}
		}
		else if (mode==2)
		{
			cout << "What's the name of the first player(the black one)?" << endl;
			cin >> name1;
			cout << endl;
			cout << "What's the name of the second player(the white one)?" << endl;
			cin >> name2;
			cout << endl;
			cout << endl;
			Player1.initialize(1, name1);
			Player2.initialize(2, name2);
			Player1.displayTable();
			while (true)
			{
				Player1.sethand(Player2.gethand());
				Player1.input();
				updateTable(2, 1);
				if (check(2))
				{
					judge(2);
					break;
				}
				Player2.sethand(Player1.gethand());
				Player2.input();
				updateTable(2, 2);
				if (check(2))
				{
					judge(2);
					break;
				}
			}
		}
		else
		{
			cout << "Who moves first? Novice or Master?" << endl;
			cout << "1.Novice" << endl;
			cout << "2.Master" << endl;
			cin >> steakJack;
			while ((steakJack != 1) && (steakJack != 2))
			{
				cout << "Sorry, you can only input 1 or 2." << endl;
				cin >> steakJack;
			}
			steakJason = steakJack == 1 ? 2 : 1;
			AI1.initialize(steakJack,"Novice");
			AI2.initialize(steakJason,"Master");
			while (true)
			{
				if (steakJack == 1)
				{
					AI1.sethand(AI2.gethand());
					AI1.set1();
					updateTable(3, 1);
					if (check(3))
					{
						judge(3);
						break;
					}
					Sleep(900);
					AI2.sethand(AI1.gethand());
					AI2.set2();
					updateTable(3, 2);
					if (check(3))
					{
						judge(3);
						break;
					}
					Sleep(900);
				}
				else
				{
					AI2.set2();
					AI1.sethand(AI2.gethand());
					updateTable(3, 2);
					if (check(3))
					{
						judge(3);
						break;
					}
					Sleep(900);
					AI1.set1();
					AI2.sethand(AI1.gethand());
					updateTable(3, 1);
					if (check(3))
					{
						judge(3);
						break;
					}
					Sleep(900);
				}
			}
		}
		
	}
	bool End()
	{
		int condition;
		cout << "Do you want to quit, or continue?" << endl;
		cout << "1.quit" << endl;
		cout << "2.continue" << endl;
		cin >> condition;
		cout << endl;
		while ((condition != 1) && (condition != 2))
		{
			cout << "Input wrong.You must input 1 or 2." << endl;
			cin >> condition;
			cout << endl;
		}
		if (condition == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Show()
	{
		cout << endl;
		cout << "The black side player has won " << win1 << " times." << endl;
		cout << "The white side player has won " << win2 << " times." << endl;
		cout << "Novice has won " << winai1 << " times." << endl;
		cout << "Master has won " << winai2 << " times." << endl;
		cout << endl;
		cout << "End." << endl;
	}
private:
	AI AI1,AI2;
	Player Player1, Player2;
	int bigTable[9][9];
	int mode, win1 = 0, win2 = 0, winai1 = 0, winai2 = 0;
	bool check(int mode)
	{
		if (mode == 1)
		{
			if ((Player1.endMove()) && (AI1.endMove()))
				return true;
			else 
				return false;
		}
		else if (mode==2)
		{
			if ((Player1.endMove()) && (Player2.endMove()))
				return true;
			else
				return false;
		}
		else
		{
			if ((AI1.endMove()) && (AI2.endMove()))
				return true;
			else
				return false;
		}
	}
	void updateTable(int mode,int steak)
	{
		if (mode == 1)
		{
			switch (steak)
			{
			case 1:
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
					{
						bigTable[i][j] = Player1.bigTable[i][j];
						AI1.bigTable[i][j] = bigTable[i][j];
					}
				break;
			case 2:
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
					{
						bigTable[i][j] = AI1.bigTable[i][j];
						Player1.bigTable[i][j] = bigTable[i][j];
					}
				break;
			}
		}
		else if (mode==2)
		{
			switch (steak)
			{
			case 1:
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
					{
						bigTable[i][j] = Player1.bigTable[i][j];
						Player2.bigTable[i][j] = bigTable[i][j];
					}
				break;
			case 2:
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
					{
						bigTable[i][j] = Player2.bigTable[i][j];
						Player1.bigTable[i][j] = bigTable[i][j];
					}
				break;
			}
		}
		else 
		{
			switch (steak)
			{
			case 1:
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
					{
					bigTable[i][j] = AI1.bigTable[i][j];
					AI2.bigTable[i][j] = bigTable[i][j];
					}
				break;
			case 2:
				for (int i = 1; i <= 8; i++)
					for (int j = 1; j <= 8; j++)
					{
					bigTable[i][j] = AI2.bigTable[i][j];
					AI1.bigTable[i][j] = bigTable[i][j];
					}
				break;
			}
		}
	}
};
int main()
{
	cout << endl;
	cout << "Welcome to the world of Othello! (Presented by SEU_Novice)" << endl;
	cout << endl;
	Game Game1;
	while (true)
	{
		Game1.chooseMode();
		Game1.Play();
		if (Game1.End())
		{
			Game1.Show();
			break;
		}
	}
	system("pause");
	return 0;
}