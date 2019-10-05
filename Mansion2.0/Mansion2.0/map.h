#pragma once
#include <iostream>
#include <conio.h>

#define print(x) std::cout << x
#define println(x) std::cout << x << std::endl
#define getInput(x) x = _getch()

#define MapW1 12
#define MapH1 12

#define MapW2 12
#define MapH2 18

#define MapW3 10
#define MapH3 27

#define MapW4 30
#define MapH4 30


struct pile
{
	int x, y; /* kordinat sistemi için 2 li deger */
	pile(int a, int b) { x = a; y = b; }; /* pile constructor */
};

class Map
{
private:
	int m_Map[30][30]; /* harita bilgisi */
	int m_Width, m_Height; /* genislik ve yükseklik bilgisi */
	int m_PlayerX, m_PlayerY; /* oyuncunun konumunu */
	int m_EX, m_EY;
	int m_specialPile = 0; /* hedef pile in özelligi */
	bool m_isWon = false; /* map kazanildi mi */

public:

	// constructor
	Map(int width, int height) { m_Width = width; m_Height = height; };

	// genisligi ver
	int getWidth() { return m_Width; }
	// yüksekligi ver
	int getHeight() { return m_Height; }
	// pile in özelligini ver
	int getSpecPile() { return m_specialPile; }

	// harita da hedef pile da ne var
	int getPileInfo(pile target) { return m_Map[target.x][target.y]; }
	// haritada hedefteki pile a info yaz
	void setPileInfo(pile target, int info) { m_Map[target.x][target.y] = info; }

	// map kazanildi mi ver
	bool getIsWon() { return m_isWon; }
	// map kazanildi mi yaz
	void setIsWon(bool result) { m_isWon = result; }

	// haritayi ekrana çiz
	void draw();
	void setMap(int map[MapW1][MapH1]); /* haritayi ekle */
	void setMap(int map[MapW2][MapH2]); /* haritayi ekle */
	void setMap(int map[MapW3][MapH3]); /* haritayi ekle */
	void setMap(int map[MapW4][MapH4]);
	void placePlayer(int x, int y); /* oyuncuyu haritaya yerlestir */
	void placeEnemy(int ex, int ey);

	void init(); /* haritayi 0 la, bütün haritayi duvar yap */

	void update(); /* haritayi güncelle */
	void input(); /* kullanicidan girdi al */
	void specialPile(pile target); /* hedef pile in özelligini kaydet */
	void initSpecialPile() { m_specialPile = 0; }; /* hedef pile özelligini sýfýrla */

private:

	void moveEnemy(int inputE);
	void checkMap(int pile); /* hedef kordinattaki degeri sorgula */
	void movePlayer(char input); /* oyuncuyu yürüt */
	/* hedef pile uygun mu, 1 (duvar) ise degil */
	bool pileOkay(pile targetPile) { return m_Map[targetPile.x][targetPile.y] != 1; };
	/* hedef pile özel mi, 0 (bosluk) ise degil */
	bool pileSpecial(pile targetPile) { return m_Map[targetPile.x][targetPile.y] != 0; };

};

