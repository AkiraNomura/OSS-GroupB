///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
//	ÕæÕæ
=======
//	ã·ãã·ã

>>>>>>> 4f70561af625d676e1d35afd7d39c65e571353d3
include "el.h"

#define MAIN_SCREEN 1

//æÊpÌÖÌvg^Cv
///////////////////////////////////////////////////////////////////////////////
//	ÕæÕæ

#include "el.h"

#define MAIN_SCREEN 1

//æÊpÌÖÌvg^Cv
void MainScreen(void);

DDOBJ puyo;				// ÕæÌrbg}bv
int field[15][8];		// æÊf[^
int cmb[15][8];			// `FbNp
bool elist[30];			// Á·Xg

///////////////////////////////////////////////////////////////////////////////
//	CÖ

//vON®ãAêÔÅÉÄÑo³êéÖB
int elMain("ÕæÕæ");
{
	elWindow(256, 448, FALSE);
	//±Ì[vàÅª³êéB
	//±ÌðOOÆñ]·é±ÆÅAA^CÅÌªÀ»B
	elLoop()
	{
@@//æÙÇè`µ½MAIN_SCREENðAé¾µ½MainScreenÖÉNB
	//±êÅAÈPÉCÓÌæÊðÄÑo·±ÆªÅ«éB
		elSetScreen(MAIN_SCREEN,MainScreen());
	}	
	//CÖI¹Å©®IÉI¹B
	elExitMain();
}

///////////////////////////////////////////////////////////////////////////////
//	EChE¶¬Ö

void elCreate(void)
{
	elDraw::Screen(256, 448);@//256~448hbgÌEBhE
	// ÕææÇÝÝ
	puyo = elDraw::LoadObject("puyo.bmp");
	// tB[hðNA
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 8; x++) {
    //ÕæªSÜéÜÅÌEChE®ì
			if (x == 0 || x == 7 || y == 14) field[y][x] = 5;
			else field[y][x] = -1;
		}
	}
	elCallScreen(MAIN_SCREEN);
}

///////////////////////////////////////////////////////////////////////////////
//	L[{[hÖ

// @½©L[üÍª éÆAÄÑo³êéÖB
// Windowsª½©L[üÍðó¯æéÆA±±É³ê½L[ðn·B
void elKeyboard(void)
{
	//[ESC]L[ª³êÄ¢éB
	// VK_ESCAPEÆÍA[ESC]L[Ì¼zL[R[hB
case VK_ESCAPE:
	{
@@//vOðI¹B
		elDraw::Exit();
		break;
	}
  //L[{[hÖI¹B
	elExitKeyboard();
}

///////////////////////////////////////////////////////////////////////////////
//	CxgÖ

//WindowsÅÌCxgðó¯æéÆAÄÑo³êéÖB
//WindowsÌbZ[WðE¢½¢êÌè`BãÌelKeyboardÖ¯lAàÅB
long elEvent(void)
{
//CxgI¹B
	elExitEvent();
}

///////////////////////////////////////////////////////////////////////////////
//	CæÊ

// Õæ`FbNÖiÄAj
// ø x, y:²×éÕæÀW pno:ÕæÔ cno:Ô
int CheckCombine(int x, int y, int pno, int cno)
{
	if (field[y][x] != pno || cmb[y][x] != 0) return 0;@@@@@//ÅÌói?jóÔ
	int ret = 1;
	cmb[y][x] = cno;
	if (y > 0) ret += CheckCombine(x, y - 1, pno, cno);		// ã
	ret += CheckCombine(x + 1, y, pno, cno);		         // E
	ret += CheckCombine(x, y + 1, pno, cno);			// º
	ret += CheckCombine(x - 1, y, pno, cno);			// ¶
	return ret;
}

void MainScreen(void)
{
	int i, x, y;
	int kx1, ky1, kx2, ky2;			// ¼ÌÀW
	bool flag;						// ÄptO
	static int pnext1, pnext2;		// lNXgÕæÔiO`Sj
	static int pno1, pno2;			// »ÝÌÕæÔiO`Sj
	static int px1, py1, px2, py2;	// ÕæÌwAxÀW
	static int keyLeft = FREE_KEY;	// ¶L[
	static int keyRight = FREE_KEY;	// EL[
	static int keyDown = FREE_KEY;	// ºL[
	static int keySpace = FREE_KEY;	// Xy[XL[
	static bool overFlag = false;	// Q[I[o[tO
	static int score = 0;			// ¾_
	static DWORD rpt = 0;			// L[s[gÔ
	static DWORD downTime = 1000;	// 1ubNº·éÔ(ms)
	static DWORD downCount;			// ºÔÜÅÌP\(ms)
	static enum {					// óÔ
		NEXT,						// lNXgÕæo»
		NORMAL,						// Êí
		FALL,						// Õæº
		ERASE1,						// ÕæÁµO
		ERASE2,						// ÕæÁµ
	} status = NEXT;
	if (elChangeScreen()) {
@@@@@pnext1 = rand() % 5; pnext2 = rand() % 5;
@@@@@@}
	elDraw::Clear();
	DWORD nowTime = timeGetTime();@@
	switch (status) {
	// lNXgÕæo»
	case NEXT:
		px1 = 3; py1 = 1; px2 = 3; py2 = 0;@@@@@@
		pno1 = pnext1; pno2 = pnext2;
		pnext1 = rand() % 5; pnext2 = rand() % 5;
	//tB[hÉ¿½ÕæªºÉÂ¢½ÉÌÕæªºðnßéB
		downCount = timeGetTime();
		if (downTime > 100) downTime -= 10;
		else downTime--;
		if (downTime < 10) downTime = 10;
		status = NORMAL;
		break;
	// Êí
	case NORMAL:
		kx1 = px1; ky1 = py1;
		kx2 = px2; ky2 = py2;
		elSystem::GetKey(VK_LEFT, &keyLeft);    //¶ì
		elSystem::GetKey(VK_RIGHT, &keyRight);@//Eì
		elSystem::GetKey(VK_DOWN, &keyDown);@@//ºì
	@	elSystem::GetKey(VK_SPACE, &keySpace);@//üêÖ¦ì
		flag = false;
@@@//spaceìÅÕæÌüêÖ¦iñ]jðµÄ¢éÆ±ë
		if (keySpace == PUSH_KEY) {
@@@//Eñ]Å¤µëÌÕæª¡ÌÊu©çEÉ¸êé
			if (kx2 > kx1) {@
@@@@@@@@@@kx2 = kx1; 
		ky2 = ky1 + 1;
@@@@@@@@@@@}
	//Eñ]Å¤µëÌÕæª¡ÌÊu©ç¶ãëÉÜíÁ½
			else if (kx2 < kx1) {@@@@
	@kx2 = kx1; 
@@@@@ky2 = ky1 - 1;
	}
    //Eñ]Å¤µëÌÕæªOÌÕæÌºÉÜíÁ½
			else if (ky2 > ky1) {
	ky2 = ky1; 
	kx2 = kx1 - 1;
	}
	//³ÌÊuÉßé
			else {
	ky2 = ky1; 
	kx2 = kx1 + 1;
	}
		} 
	//ºL[Å_EL[ÅÕæÌºð·éBºL[ð£¹Î³Ì¬xÅ¿éB
	else if (keyDown == PUSH_KEY || keyDown == HOLD_KEY && nowTime - rpt > 10) {
			ky1++; ky2++; flag = true; rpt = nowTime;
		} 
@@@@//¶L[Å¶ÉÚ®·éB¶L[ð£¹Î³Ì¬xÅ¿éB
	else if (keyLeft == PUSH_KEY || keyLeft == HOLD_KEY && nowTime - rpt > 150) {
			kx1--; kx2--; rpt = nowTime;
		} 
@	//EL[Å¶ÉÚ®·éBEL[ð£¹Î³Ì¬xÅ¿éB
	else if (keyRight == PUSH_KEY || keyRight == HOLD_KEY && nowTime - rpt > 150) {
			kx1++; kx2++; rpt = nowTime;
		} 
	//êÔºÜÅ¿½çÏÝã°½ÆµÄÜ½ÕæðúÌ³ÅÆ·
	else if (nowTime - downCount > downTime) {
			ky1++; ky2++; flag = true; downCount = nowTime;
		}
@@@@//½àìµÈ¯êÎ»ÌÜÜ¿éB
		if (field[ky1][kx1] == -1 && field[ky2][kx2] == -1) {
			px1 = kx1; py1 = ky1;
			px2 = kx2; py2 = ky2;
		} else if (flag) {
	//NEXTÕæºõ
			field[py1][px1] = pno1;
			field[py2][px2] = pno2;
			status = FALL;
		}
		break;
	// Õæº
	case FALL:
		Sleep(50);
		flag = false;
	//Jn©çêÔºÜÅÌº
		for (y = 12; y >= 0; y--) {
	//¶[©çE[ÜÅÌì
			for (x = 1; x < 7; x++) {
        //ÕæÏÝã°½êðêÔºÆµÄÄÑº
				if (field[y][x] != -1 && field[y + 1][x] == -1) {
					field[y + 1][x] = field[y][x];
					field[y][x] = -1;
					flag = true;
				}
			}
		}
@@@@//Ýèµ½FªdÈéÆuÕæÁµOvÌìÆÉÚéB
		if (flag == false){     
@@@@@@@@status = ERASE1;
		break;
}
	// ÕæÁµO
	case ERASE1:
		// Õæ`FbN
		flag = false;
		for (y = 0; y < 15; y++) for (x = 0; x < 8; x++) cmb[y][x] = 0;
		for (i = 0; i < 30; i++) elist[i] = false;
		for (y = 13, i = 0; y >= 0; y--) {
			for (x = 1; x < 7; x++) {
		//¯¶ÕæÌïiHj
				if (cmb[y][x] == 0 && field[y][x] != -1) {
					i++;
					int ret = CheckCombine(x, y, field[y][x], i);
	                               //¯¶ÕæªSÂ»ë¤ÆÁ¦ÄXRAAbv
					if (ret >= 4) {
						flag = true;
						elist[i] = true;
						score += ret * 10;
					}
				}
			}
		}
		if (flag) {
			// Õæª éêÍÁµ½ÕæÆêÌüêÖ¦
			for (y = 13; y >= 0; y--) {
				for (x = 1; x < 7; x++) {
					if (elist[cmb[y][x]]) field[y][x] = 5;
				}
			}
			status = ERASE2;@@
		} else {
			// ÕæªÈ¢êÍQ[I[o[`FbNµÄÖ
			for (y = 0; y < 2; y++) {
				for (x = 1; x < 7; x++) {
					if (field[y][x] != -1) overFlag = true;
				}
			}
			status = NEXT;
		}
		break;
	// ÕæÁµ
	case ERASE2:
		Sleep(500);@//êIÉt[Y½
@@@@//È­ÈÁÄ¿½êÍÁ¦éOÌÀWæèÕæªºÉ¨¿éB
		for (y = 13; y >= 0; y--) {
			for (x = 1; x < 7; x++) {
				if (field[y][x] == 5) field[y][x] = -1;
			}
		}
		status = FALL;
		break;
	}
	// æÊ\¦@iCÍAEÍË¸ÝFj
	elDraw::Box(192, 0, 256, 448, RGB(150, 150, 150), RGB(150, 150, 150), 0);
	elDraw::Line(0, 64, 192, 64, RGB(255, 255, 255), 1);
	//XRA\¦(ÂFj
	SHOW(210, 16, "SCORE");
	SHOW2(210, 32, "%d", score);
	SHOW(212, 128, "NEXT");
	for (y = 0; y < 14; y++) {
		for (x = 1; x < 7; x++) {
			if (field[y][x] != -1) {
				elDraw::Layer((x - 1) * 32, y * 32, puyo,
					field[y][x] * 32, 0, field[y][x] * 32 + 32, 32);
			}
		}
	}
	// »ÝÌÕæ\¦ (lNXg¯lÉFÍÔEÎEÂEÔEsNB4ÂdÈÁ½çVo[j
	if (status == NORMAL) {
		elDraw::Layer((px1 - 1) * 32, py1 * 32,
			puyo, pno1 * 32, 0, pno1 * 32 + 32, 32);
		elDraw::Layer((px2 - 1) * 32, py2 * 32,
			puyo, pno2 * 32, 0, pno2 * 32 + 32, 32);
	}
	// lNXgÕæ\¦
	elDraw::Layer(208, 144, puyo, pnext2 * 32, 0, pnext2 * 32 + 32, 32);
	elDraw::Layer(208, 144 + 32, puyo, pnext1 * 32, 0, pnext1 * 32 + 32, 32);
	elDraw::Refresh();
	// Q[I[o[BãAEChEðÂ¶é
	if (overFlag) {
		elSystem::Message("Q[I[o[");
		elDraw::Exit();
	}
}


