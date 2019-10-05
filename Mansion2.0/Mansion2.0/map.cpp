#include "pch.h"
#include "map.h"
#include <stdlib.h>
int inputE;
void Map::draw()
{
	/* kolonlarý gez */
	for (int i = 0; i < 30; i++)
	{	/* satirlari gez */
		for (int j = 0; j < 30; j++)
		{	/* satir ve kolonu belli degeri kontrol et */
			checkMap(m_Map[i][j]);
		}
		println(""); /* satiri bitir*/
	}


}

void Map::setMap(int  map[MapW1][MapH1])
{
	init(); /* haritayi sifirla */

	for (int i = 0; i < m_Width; i++)
	{	/* kolonlari gez */
		for (int j = 0; j < m_Height; j++)
		{	/* satirlari gez */
			// uygun kolondaki satiri girilen haritaya esitle
			m_Map[i][j] = map[i][j];
		}
	}
}

void Map::setMap(int  map[MapW2][MapH2])
{
	init(); /* haritayi sifirla */

	for (int i = 0; i < m_Width; i++)
	{	/* kolonlari gez */
		for (int j = 0; j < m_Height; j++)
		{	/* satirlari gez */
			// uygun kolondaki satiri girilen haritaya esitle
			m_Map[i][j] = map[i][j];
		}
	}
}

void Map::setMap(int  map[MapW3][MapH3])
{
	init(); /* haritayi sifirla */

	for (int i = 0; i < m_Width; i++)
	{	/* kolonlari gez */
		for (int j = 0; j < m_Height; j++)
		{	/* satirlari gez */
			// uygun kolondaki satiri girilen haritaya esitle
			m_Map[i][j] = map[i][j];
		}
	}
}

void Map::setMap(int  map[MapW4][MapH4])
{
	init(); /* haritayi sifirla */

	for (int i = 0; i < m_Width; i++)
	{	/* kolonlari gez */
		for (int j = 0; j < m_Height; j++)
		{	/* satirlari gez */
			// uygun kolondaki satiri girilen haritaya esitle
			m_Map[i][j] = map[i][j];
		}
	}
}

void Map::placePlayer(int x, int y)
{
	// haritaya oyuncuyu koy
	m_Map[x][y] = 8;
	// oyuncunun konumu kaydet
	m_PlayerX = x; m_PlayerY = y;
}

void Map::placeEnemy(int ex, int ey)
{
	// haritaya oyuncuyu koy
	m_Map[ex][ey] = 9;
	// oyuncunun konumu kaydet
	m_EX = ex; m_EY = ey;
}
void Map::update()
{
	system("cls"); /* ekrani temizle */
	draw(); /* haritayi ciz */
	input(); /* girisi bekle */

}

void Map::input()
{
	char temp; /* kullanici icin input */
	getInput(temp); /* input u al */
	movePlayer(temp); /* input a göre oyuncuyu yürüt */
}

void Map::specialPile(pile target)
{	/* özel pile i kaydet */
	m_specialPile = m_Map[target.x][target.y];
}

void Map::movePlayer(char input)
{

	if (input == 'w')
	{	/*eger girdi w ise*/
		// hedef pile oyuncunun üstündeki pile,

		pile targetPile(m_PlayerX - 1, m_PlayerY);
		if (pileOkay(targetPile))
		{	/* eger hedef uygunsa */
			if (pileSpecial(targetPile))
			{	/* eger hedef özelse */
				specialPile(targetPile); /* özelligi kaydet */
			}
			else
				initSpecialPile(); /* degilse özelligi sýfýrla */
			// oyuncuyu hedef pile a yaz ve önceki konumunu bosalt
			m_Map[m_PlayerX][m_PlayerY] = 0;
			m_Map[targetPile.x][targetPile.y] = 8;
			m_PlayerX = targetPile.x;
			m_PlayerY = targetPile.y;
		}
	}
	if (input == 'a')
	{
		pile targetPile(m_PlayerX, m_PlayerY - 1);
		if (pileOkay(targetPile))
		{
			if (pileSpecial(targetPile))
			{
				specialPile(targetPile);
			}
			else
				initSpecialPile();
			m_Map[m_PlayerX][m_PlayerY] = 0;
			m_Map[targetPile.x][targetPile.y] = 8;
			m_PlayerX = targetPile.x;
			m_PlayerY = targetPile.y;
		}
	}
	if (input == 's')
	{
		pile targetPile(m_PlayerX + 1, m_PlayerY);
		if (pileOkay(targetPile))
		{
			if (pileSpecial(targetPile))
			{
				specialPile(targetPile);
			}
			else
				initSpecialPile();
			m_Map[m_PlayerX][m_PlayerY] = 0;
			m_Map[targetPile.x][targetPile.y] = 8;
			m_PlayerX = targetPile.x;
			m_PlayerY = targetPile.y;
		}
	}
	if (input == 'd')
	{
		pile targetPile(m_PlayerX, m_PlayerY + 1);
		if (pileOkay(targetPile))
		{
			if (pileSpecial(targetPile))
			{
				specialPile(targetPile);
			}
			else
				initSpecialPile();
			m_Map[m_PlayerX][m_PlayerY] = 0;
			m_Map[targetPile.x][targetPile.y] = 8;
			m_PlayerX = targetPile.x;
			m_PlayerY = targetPile.y;
		}
	}


}

void Map::moveEnemy(int inputE)
{

	if (inputE == 1)
	{	/*eger girdi w ise*/
		// hedef pile oyuncunun üstündeki pile,
		pile targetPile(m_EX - 1, m_EY);
		if (pileOkay(targetPile))
		{	/* eger hedef uygunsa */
			if (pileSpecial(targetPile))
			{	/* eger hedef özelse */
				specialPile(targetPile); /* özelligi kaydet */
			}
			else
				initSpecialPile(); /* degilse özelligi sýfýrla */
			// oyuncuyu hedef pile a yaz ve önceki konumunu bosalt
			m_Map[m_EX][m_EY] = 0;
			m_Map[targetPile.x][targetPile.y] = 9;
			m_EX = targetPile.x;
			m_EY = targetPile.y;
		}
	}
	if (inputE == 2)
	{
		pile targetPile(m_EX, m_EY - 1);
		if (pileOkay(targetPile))
		{
			if (pileSpecial(targetPile))
			{
				specialPile(targetPile);
			}
			else
				initSpecialPile();
			m_Map[m_EX][m_EY] = 0;
			m_Map[targetPile.x][targetPile.y] = 9;
			m_EX = targetPile.x;
			m_EY = targetPile.y;
		}
	}
	if (inputE == 3)
	{
		pile targetPile(m_EX + 1, m_EY);
		if (pileOkay(targetPile))
		{
			if (pileSpecial(targetPile))
			{
				specialPile(targetPile);
			}
			else
				initSpecialPile();
			m_Map[m_EX][m_EY] = 0;
			m_Map[targetPile.x][targetPile.y] = 9;
			m_EX = targetPile.x;
			m_EY = targetPile.y;
		}
	}
	if (inputE == 4)
	{
		pile targetPile(m_EX, m_EY + 1);
		if (pileOkay(targetPile))
		{
			if (pileSpecial(targetPile))
			{
				specialPile(targetPile);
			}
			else
				initSpecialPile();
			m_Map[m_EX][m_EY] = 0;
			m_Map[targetPile.x][targetPile.y] = 9;
			m_EX = targetPile.x;
			m_EY = targetPile.y;
		}
	}


}

void Map::checkMap(int pile)
{
	/* 1 ise duvar */
	if (pile == 1)
		std::cout << "# ";
	/* 0 ise bosluk */
	if (pile == 0)
		std::cout << "  ";
	/* 2 ise U (kapi) */
	if (pile == 2)
		std::cout << "U ";
	/* 8 ise oyuncu */
	if (pile == 8)
		std::cout << "8 ";
	/* 4 ise 4. özellik */
	if (pile == 4)
		std::cout << "K ";
	/* 5 ise 5. özellik */
	if (pile == 5)
		std::cout << "K ";
	/* 6 ise 6. özellik */
	if (pile == 6)
		std::cout << "K ";
	if (pile == 9)
		std::cout << "X ";
}

void Map::init()
{

	for (int i = 0; i < 30; i++)
	{	/* kolonlari gez */
		for (int j = 0; j < 30; j++)
		{	/* satirlari gez */
			m_Map[i][j] = 1; /* hepsini 1 (duvar) yap */
		}
	}


}
