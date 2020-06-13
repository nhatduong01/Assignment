#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
bool shield = false;
bool hair = false;
bool spear = false;
bool utimetialoses = false;
bool petal = false;
bool excalibur = false;
bool tornberypoison = false;
bool lionheart = false;
int times = 0;
bool odinisdeath = false;
int lionhearttime = 0;
bool meetodin = false;
int timeodin = 0;
bool dragonknight = false;
bool defeatomega = false;
bool hadesmythil = false;
bool externallove = false;
bool arthur = false;
bool lancelot = false;
bool guinevere = false;
bool scarlet = false;
bool paladin = false;
bool mode2 = false;
bool meetnina = false;
int timenina = 0;
bool markodin = false;
int markmeetodin = 0;
bool mode3 = false;
bool FriendlyNumbers(int num1, int num2)
{
	if (num1 == 0 || num2 == 0)
		return false;
	int abundancy1 = 0, abundancy2 = 0;
	for (int i = 1;i <= num1;i++)
	{
		if (num1 % i == 0)
			abundancy1 += i;
	}
	for (int i = 1;i <= num2;i++)
	{
		if (num2 % i == 0)
			abundancy2 += i;
	}
	return (abundancy1*num2==abundancy2*num1) ? true : false;
}
int callPhoenix2(knight& woundedKnight, int MaxHP)
{
	int nTimes = 0;
	woundedKnight.HP = MaxHP / 2;
	woundedKnight.gil = woundedKnight.gil < 100 ? 0 : woundedKnight.gil - 100;
	return ++nTimes;
}
bool PrimeNumber(int n)
{
	bool PrimeNumber1 = true;
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			PrimeNumber1 = false;
			break;
		}
	}
	return PrimeNumber1;
}
bool IsInteger(double a)
{
	return (a == static_cast<int>(a)) ? true : false;
}
bool IsDragonKnight(int n)
{
	if (n % 2 == 1)
		return false;
	int temp = n * 0.5;
	for (int i = 1;i <= temp;i++)
	{
		double a = (double)(temp - i * i) / i;
		if (IsInteger(a) == true && a < i&&a>0)
		{
			return true;
		}
	}
	return false;
}
int OponentLevel(int i)
{
	int b = i % 10;
	int level0 = i > 6 ? (b > 5 ? b : 5) : b;
	return level0;
}
void TakeGil(int& gil, int moregil)
{
	gil += moregil;
	if (gil > 999) gil = 999;
}
void TakeDamage(knight& theKnight , int level0, float basedamage,int MAXHP)
{
	if (hadesmythil == true&&tornberypoison==false)
	{
		return;
	}
	else
	{
		int damage = basedamage * 10 * level0;
		theKnight.HP -= damage;
		if (theKnight.HP <= 0&&mode3==false)
		{
			callPhoenix(theKnight, MAXHP);
			times = 0;
			tornberypoison = false;
		}
		if (theKnight.HP <= 0 && mode3 == true)
		{
			callPhoenix2(theKnight, MAXHP);
			times = 0;
			tornberypoison = false;
		}
	}
}
void UseAntidote(knight& theKnight)
{
	tornberypoison = false;
	theKnight.antidote--;
	times = 0;
}
void SwapCastle(castle& a, castle& b)
{
	castle temp = a;
	a = b;
	b = temp;
}
void heapPermutation(castle a[], int size, int nCastle, castle**path)
{
	static int i = 0;
	if (size == 1)
	{
		for (int j = 0;j < nCastle;j++)
			path[i][j] = a[j];
		i++;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		heapPermutation(a, size - 1, nCastle,path);
		if (size % 2 == 1)
			SwapCastle(a[0], a[size - 1]);
		else
			SwapCastle(a[i], a[size - 1]);
	}
}
int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
report* Mode2(knight& theKnight, castle arrCastle[], int nCastle, int nPetal)
{
	int situation = factorial(nCastle);
	castle** path = new castle*[situation];
	for (int i = 0; i < situation;i++)
		path[i] = new castle[nCastle];
	knight* tempknight = new knight[situation];
	for (int i = 0;i < situation;i++)
		tempknight[i] = theKnight;
	report** result = new report * [situation];
	heapPermutation(arrCastle, nCastle, nCastle, path);
	for (int i = 0; i < situation;i++)
	{
		result[i] = walkthrough(tempknight[i], path[i], nCastle, 0, nPetal);
	}
	report tempresult;
	tempresult.nLose = 0;
	tempresult.nWin = 0;
	tempresult.nPetal = 0;
	for (int i = 0;i < situation;i++)
	{
		if (result[i] == NULL)
			result[i] = &tempresult;
	}
	int maxPetal = 0;
	for (int i = 0;i < situation;i++)
	{
		if (maxPetal < result[i]->nPetal)
			maxPetal = result[i]->nPetal;
	}
	for (int i = 0; i < situation;i++)
	{
		if (maxPetal == result[i]->nPetal)
		{
			mode3 = false;
			walkthrough(theKnight, path[i], nCastle, 0, nPetal);
			return result[i];
		}
	}

}
report*  walkthrough (knight& theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
  report* pReturn;
  int bFlag = 1;
  report result;
  result.nLose = 0;
  result.nWin = 0;
  result.nPetal = nPetal;
  int maxHP1 = theKnight.HP;
  if (maxHP1 == 999)
	  arthur = true;
  if (maxHP1 == 888)
  {
	  lancelot = true;
	  spear = true;
  }
  if (maxHP1 == 777)
  {
	  guinevere = true;
	  hair = true;
  }
  if (PrimeNumber(maxHP1) == true)
  {
	  paladin = true;
	  shield = true;
  }
  if (IsDragonKnight(maxHP1) == true&&maxHP1!=888)
  {
	  dragonknight = true;
  }
  //fighting for the existence of mankind here
  //Determine the mode of the programme
  int harshshield = 0;
  int harshhair = 0;
  int harshspear = 0;
  if (mode == 2)
  {
	  mode3 = true;
	  return Mode2(theKnight, arrCastle, nCastle, nPetal);
  }
	  while (utimetialoses == false && petal == false)
	  {
		  if (mode == 1)
		  {
			  harshshield = hash(95);
			  harshhair = hash(97);
			  harshspear = hash(96);
			  mode2 = true;
		  }
		  for (int i = 0;i < nCastle;i++)
		  {
			  if (utimetialoses == true) break;
			  castle cc = arrCastle[i];
			  for (int j = 0;j < cc.nEvent;j++)
			  {
				  static int  marknina = 0;
				  if (marknina == 6)
					  marknina = 0;
				  if ((spear == true && hair == true&&excalibur==false) || (arthur == true && hair == true) || (lancelot == true && hair == true) || (spear == true && guinevere == true))
					  externallove = true;
				  if (tornberypoison == true)
				  {
					  times++;
					  if (times == 6)
					  {
						  times = 0;
						  tornberypoison = false;
					  }
				  }
				  if (lionheart == true && paladin == false)
				  {
					  lionhearttime++;
					  if (lionhearttime == 6)
					  {
						  lionhearttime = 0;
						  lionheart = false;
					  }
				  }
				  if (meetodin == true)
				  {
					  timeodin++;
					  if (timeodin == 6)
					  {
						  timeodin = 0;
						  meetodin = false;
					  }
				  }
				  if (meetnina == true)
				  {
					  timenina++;
					  if (timenina == 6)
					  {
						  timenina = 0;
						  meetnina = false;
					  }
				  }
				  if (markodin == true)
				  {
					  markmeetodin++;
					  if (markmeetodin == 6)
					  {
						  markmeetodin = 0;
						  markodin = false;
					  }
				  }
				  if (utimetialoses == true) break;
				  else if (cc.arrEvent[j] == 95)
				  {
					  if (paladin == true)
					  {
						  if (result.nPetal > 0)result.nPetal--;
						  continue;
					  }
					  if (mode2 ==true)
					  {

						  if ((harshshield > harshhair && hair == false) || (harshshield > harshspear && spear == false))
						  {
							  if (result.nPetal > 0)result.nPetal--;
							  continue;
						  }
						  else
						  { 
							  shield = true; 
						  }
					  }
					  else 
					  { 
						  shield = true;
					  }
				  }
				  else if (cc.arrEvent[j] == 96)
				  {
	
					  if (lancelot == true)
					  {
						  if (result.nPetal > 0)result.nPetal--;
						  continue;
					  }
					  if (mode2)
					  {
						  if ((harshspear > harshhair && hair == false) || (harshspear > harshshield && shield == false))
						  {
							  if (result.nPetal > 0)result.nPetal--;
							  continue;
						  }
						  else 
						  {
							  spear = true;
						  }
					  }
					  else spear = true;
				  }
				  else if (cc.arrEvent[j] == 97)
				  {
					  if (guinevere == true)
					  {
						  if (result.nPetal > 0)result.nPetal--;
						  continue;
					  }
					  if (mode2)
					  {
						  if ((harshhair > harshshield && shield == false) || (harshhair > harshspear && spear == false))
						  {
							  if (result.nPetal > 0)result.nPetal--;
							  continue;
						  }
						  else
						  { 
							  hair = true; 
						  }
					  }
					  else hair = true;
				  }
				  else if (cc.arrEvent[j] == 98)
				  {
					  if ((shield == true && hair == true && spear == true) || arthur == true)
					  {
						  excalibur = true;
						  externallove = false;
					  }
				  }
				  else if (cc.arrEvent[j] == 99)
				  {
					  if (excalibur == true || lionheart == true)
					  {
						  utimetialoses = true;
						  result.nWin++;
						  if (tornberypoison)
						  {
							  if (theKnight.HP <= 3)
								  theKnight.HP = 1;
							  else theKnight.HP /= 3;
						  }
					  }
					  else
					  {
						  if (tornberypoison == true)
						  {
							  if (theKnight.HP <= 3)
								  theKnight.HP = 1;
							  else {
								  theKnight.HP /= 3;
							  }
						  }
						  if (hadesmythil == true || (guinevere == true ))
						  {
							  result.nLose++;
							  if (result.nPetal > 0)result.nPetal--;
							  continue;
						  }
						  else
						  {
							  if (theKnight.HP <= 3)
								  theKnight.HP = 1;
							  else 
							  {
								  theKnight.HP /= 3;
							  }
						  }
						  result.nLose++;
					  }
				  }
				  else if (cc.arrEvent[j] >= 1 && cc.arrEvent[j] <= 5)
				  {
					  switch (cc.arrEvent[j])
					  {
					  case 1:
						  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true || paladin == true)
						  {
							  TakeGil(theKnight.gil, 100);
							  result.nWin++;
							  if (tornberypoison == true)
								  TakeDamage(theKnight, OponentLevel(j + 1), 1, maxHP1);
						  }
						  else
						  {
							  if (tornberypoison)
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 1 * 2, maxHP1);
								  result.nLose++;
							  }
							  else
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 1, maxHP1);
								  result.nLose++;
							  }
							 
						  }
						  break;
					  case 2:
						  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true || paladin == true)
						  {
							  TakeGil(theKnight.gil, 150);
							  result.nWin++;
							  if (tornberypoison == true)
								  TakeDamage(theKnight, OponentLevel(j + 1), 1.5, maxHP1);
						  }
						  else
						  {
							  if (tornberypoison==true&&guinevere==false)
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 1.5 * 2, maxHP1);
								  result.nLose++;
							  }
							  else
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 1.5, maxHP1);
								  result.nLose++;
							  }
						  }
						  break;
					  case 3:
						  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true || paladin == true)
						  {
							  TakeGil(theKnight.gil, 450);
							  result.nWin++;
							  if (tornberypoison == true)
								  TakeDamage(theKnight, OponentLevel(j + 1), 4.5, maxHP1);
						  }
						  else
						  {
							  if (tornberypoison)
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 4.5 * 2, maxHP1);
								  result.nLose++;
							  }
							  else
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 4.5, maxHP1);
								  result.nLose++;
							  }
						  }
						  break;
					  case 4:
						  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true || paladin == true)
						  {
							  TakeGil(theKnight.gil, 650);
							  result.nWin++;
							  if (tornberypoison == true)
								  TakeDamage(theKnight, OponentLevel(j + 1), 6.5, maxHP1);
						  }
						  else
						  {
							  if (tornberypoison)
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 6.5* 2, maxHP1);
								  result.nLose++;
							  }
							  else
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 6.5, maxHP1);
								  result.nLose++;
							  }
						  }
						  break;
					  case 5:
						  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true || paladin == true)
						  {
							  TakeGil(theKnight.gil, 850);
							  result.nWin++;
							  if (tornberypoison == true)
								  TakeDamage(theKnight, OponentLevel(j + 1), 8.5, maxHP1);
						  }
						  else
						  {
							  if (tornberypoison)
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 8.5 * 2, maxHP1);
								  result.nLose++;
							  }
							  else
							  {
								  TakeDamage(theKnight, OponentLevel(j + 1), 8.5, maxHP1);
								  result.nLose++;
							  }
						  }
						  break;
					  }
				  }
				  else if (cc.arrEvent[j] == 6)
				  {
					  if (tornberypoison == true)
					  {
						  result.nPetal--;
						  continue;
					  }
					  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true)
					  {
						  if (theKnight.level < 10)
						  {
							  theKnight.level++;
							  maxHP1 += 100;
							  if (maxHP1 > 999) maxHP1 = 999;
						  }
						  result.nWin++;
					  }
					  else
					  {
						  if (paladin == false && dragonknight == false) tornberypoison = true;
						  result.nLose++;
					  }
				  }
				  else if (cc.arrEvent[j] == 7)
				  {
					  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || meetodin == true || arthur == true || lancelot == true)
					  {
						  result.nWin++;
						  theKnight.gil *= 2;
						  if (theKnight.gil > 999)
							  theKnight.gil = 999;
					  }
					  else
					  {
						  result.nLose++;
						  if (scarlet == false && guinevere == false)theKnight.gil /= 2;
					  }
				  }
				  else if (cc.arrEvent[j] == 8)
				  {
				  meetnina = true;
				  if (timenina != 0)
				  {
					  if (result.nPetal > 0)result.nPetal--;
					  timenina = 0;
					  continue;
				  }
					  if (FriendlyNumbers(theKnight.gil, theKnight.HP) == false)
					  {
						  if (theKnight.gil < 50&& scarlet == false && guinevere == false && paladin == false)
						  {
							  if (result.nPetal > 0)result.nPetal--;
							  continue; 
						  }
						  if (scarlet == false && guinevere == false && paladin == false)
						  {
							  if (tornberypoison)
							  {
								  tornberypoison = false;
								  times = 0;
								  theKnight.gil -= 50;
							  }
							  if (theKnight.gil > 0)
							  {
								  for (;theKnight.gil > 0;theKnight.gil--)
								  {
									  theKnight.HP++;
									  if (theKnight.HP == maxHP1)
									  {
										  theKnight.gil--;
										  break;

									  }
								  }
							  }
						  }
						  else
						  {
							  tornberypoison = false;
							  times = 0;
							  theKnight.HP = maxHP1;
						  }
					  }
					  else
					  {
				
						  tornberypoison = false;
						  times = 0;
						  theKnight.HP = maxHP1;
						  lionheart = true;
					  }
					  if (guinevere == true)
					  {
						  theKnight.gil += 50;
						  if (theKnight.gil > 999)
							  theKnight.gil = 999;
					  }
				  }
				  else if (cc.arrEvent[j] == 9)
				  {
					  tornberypoison = false;
					  times = 0;
					  theKnight.HP = maxHP1;
					  result.nPetal += 5;
					  if (nPetal > 99) result.nPetal = 99;
					  if (scarlet == true)
					  {
						  result.nPetal = 99; 
					  }
				  }
				  else if (cc.arrEvent[j] == 10)
				  {
					  theKnight.antidote++;
					  if (theKnight.antidote > 99)
						  theKnight.antidote = 99;
				  }
				  else if (cc.arrEvent[j] == 11)
				  {
				  markodin = true;
				  if (markmeetodin != 0)
				  {
					  if (result.nPetal > 0)result.nPetal--;
					  markmeetodin = 0;
						  continue;
				  }
					  if (odinisdeath == false)
					  {
						  meetodin = true;
					  }
				  }
				  else if (cc.arrEvent[j] == 12)
				  {
					  times = 0;
					  tornberypoison = false;
					  if (theKnight.level < 10)
					  {
						  theKnight.level++;
						  maxHP1 += 100;
					  }
					  if (maxHP1 > 999) maxHP1 = 999;
					  theKnight.HP = maxHP1;
				  }
				  else if (cc.arrEvent[j] == 13)
				  {
					  if (defeatomega == false)
					  {
						  if ((theKnight.level == 10 && excalibur == true) || (dragonknight == true && lionheart == true))
						  {
							  if (theKnight.level != 10)
							  {
								  int n = 10 - theKnight.level;
								  theKnight.level = 10;
								  maxHP1 += n * 100;
								  if (maxHP1 > 999) maxHP1 = 999;
							  }
							  theKnight.gil = 999;
							  result.nWin++;
							  defeatomega = true;
						  }
						  else
						  {
							  if (hadesmythil == false)
							  {
								  theKnight.HP = 0;
								  if (mode3 == false)
									  callPhoenix(theKnight, maxHP1);
								  else callPhoenix2(theKnight, maxHP1);
							  }
							  result.nLose++;
						  }
					  }
				  }
				  else if (cc.arrEvent[j] == 14)
				  {
				  if (meetodin == true && dragonknight == false)
				  {
					  timeodin = 0;
					  meetodin = false;
					  odinisdeath = true;
				  }
					  if (theKnight.level >= OponentLevel(j + 1) || lionheart == true || externallove == true || (dragonknight == true && meetodin == true))
					  {
						  result.nWin++;
						  hadesmythil = true;
					  }
					  else
					  {
						  result.nLose++;
						  if (hadesmythil == false)
						  {
							  theKnight.HP = 0;
							  if (mode3 == false)
								  callPhoenix(theKnight, maxHP1);
							  else callPhoenix2(theKnight, maxHP1);
						  }
					  }
				  }
				  else if (cc.arrEvent[j] == 15)
				  {
					  scarlet = true;
				  }
				  else if (cc.arrEvent[j] == 16)
				  {
					  if ((theKnight.level <= ((j+1)%10)) && lancelot == false && dragonknight == false)
					  {
						  j = cc.nEvent - 1;
					  }
				  }
				  if (tornberypoison == true)
					  if (theKnight.antidote > 0&&times!=5)
						  UseAntidote(theKnight);
				  if (result.nPetal > 0) result.nPetal--;
				  if (result.nPetal <= 0 && utimetialoses == false && arthur == false)
				  {
					  bFlag = 0;
					  petal = true;
					  break;
				  }
			  }
			  if (utimetialoses == false)
			  {
				  if (theKnight.level < 10) 
				  {
					  theKnight.level++;
					  maxHP1 += 100;
					  if (maxHP1 > 999) maxHP1 = 999;
				  }
			  }
		  }
	  } 
  // success or failure?	
  pReturn = (bFlag)? new  report (result)  : NULL;
  shield = false;
  hair = false;
  spear = false;
 utimetialoses = false;
  petal = false;
  excalibur = false;
  tornberypoison = false;
  lionheart = false;
   times = 0;
   odinisdeath = false;
  lionhearttime = 0;
   meetodin = false;
  timeodin = 0;
  dragonknight = false;
  defeatomega = false;
  hadesmythil = false;
   externallove = false;
  arthur = false;
  lancelot = false;
  guinevere = false;
  scarlet = false;
  paladin = false;
   mode2 = false;
   meetnina = false;
   timenina = 0;
   markodin = false;
   markmeetodin = 0;
  return pReturn;
}