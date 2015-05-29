///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
//	‚Õ‚æ‚Õ‚æ
=======
//	ã·ã‚ˆã·ã‚ˆ

>>>>>>> 4f70561af625d676e1d35afd7d39c65e571353d3
include "el.h"

#define MAIN_SCREEN 1

//‰æ–Ê—p‚ÌŠÖ”‚Ìƒvƒƒgƒ^ƒCƒv
///////////////////////////////////////////////////////////////////////////////
//	‚Õ‚æ‚Õ‚æ

#include "el.h"

#define MAIN_SCREEN 1

//‰æ–Ê—p‚ÌŠÖ”‚Ìƒvƒƒgƒ^ƒCƒv
void MainScreen(void);

DDOBJ puyo;				// ‚Õ‚æ‚Ìƒrƒbƒgƒ}ƒbƒv
int field[15][8];		// ‰æ–Êƒf[ƒ^
int cmb[15][8];			// Œ‹‡ƒ`ƒFƒbƒN—p
bool elist[30];			// Á‚·ƒŠƒXƒg

///////////////////////////////////////////////////////////////////////////////
//	ƒƒCƒ“ŠÖ”

//ƒvƒƒOƒ‰ƒ€‹N“®ŒãAˆê”ÔÅ‰‚ÉŒÄ‚Ño‚³‚ê‚éŠÖ”B
int elMain("‚Õ‚æ‚Õ‚æ");
{
	elWindow(256, 448, FALSE);
	//‚±‚Ìƒ‹[ƒv“à‚Åˆ—‚ª‚³‚ê‚éB
	//‚±‚Ì’†‚ğƒOƒ‹ƒOƒ‹‚Æ‰ñ“]‚·‚é‚±‚Æ‚ÅAƒŠƒAƒ‹ƒ^ƒCƒ€‚Å‚Ìˆ—‚ªÀŒ»B
	elLoop()
	{
@@//æ‚Ù‚Ç’è‹`‚µ‚½MAIN_SCREEN‚ğAéŒ¾‚µ‚½MainScreenŠÖ”‚ÉƒŠƒ“ƒNB
	//‚±‚ê‚ÅAŠÈ’P‚É”CˆÓ‚Ì‰æ–Ê‚ğŒÄ‚Ño‚·‚±‚Æ‚ª‚Å‚«‚éB
		elSetScreen(MAIN_SCREEN,MainScreen());
	}	
	//ƒƒCƒ“ŠÖ”I—¹‚Å©“®“I‚ÉI—¹ˆ—B
	elExitMain();
}

///////////////////////////////////////////////////////////////////////////////
//	ƒEƒCƒ“ƒhƒE¶¬ŠÖ”

void elCreate(void)
{
	elDraw::Screen(256, 448);@//256~448ƒhƒbƒg‚ÌƒEƒBƒ“ƒhƒE
	// ‚Õ‚æ‰æ‘œ“Ç‚İ‚İ
	puyo = elDraw::LoadObject("puyo.bmp");
	// ƒtƒB[ƒ‹ƒh‚ğƒNƒŠƒA
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 8; x++) {
    //‚Õ‚æ‚ª‘S•”–„‚Ü‚é‚Ü‚Å‚ÌƒEƒCƒ“ƒhƒE“®ì
			if (x == 0 || x == 7 || y == 14) field[y][x] = 5;
			else field[y][x] = -1;
		}
	}
	elCallScreen(MAIN_SCREEN);
}

///////////////////////////////////////////////////////////////////////////////
//	ƒL[ƒ{[ƒhŠÖ”

// @‰½‚©ƒL[“ü—Í‚ª‚ ‚é‚ÆAŒÄ‚Ño‚³‚ê‚éŠÖ”B
// Windows‚ª‰½‚©ƒL[“ü—Í‚ğó‚¯æ‚é‚ÆA‚±‚±‚É‰Ÿ‚³‚ê‚½ƒL[‚ğ“n‚·B
void elKeyboard(void)
{
	//[ESC]ƒL[‚ª‰Ÿ‚³‚ê‚Ä‚¢‚éB
	// VK_ESCAPE‚Æ‚ÍA[ESC]ƒL[‚Ì‰¼‘zƒL[ƒR[ƒhB
case VK_ESCAPE:
	{
@@//ƒvƒƒOƒ‰ƒ€‚ğI—¹B
		elDraw::Exit();
		break;
	}
  //ƒL[ƒ{[ƒhŠÖ”I—¹B
	elExitKeyboard();
}

///////////////////////////////////////////////////////////////////////////////
//	ƒCƒxƒ“ƒgŠÖ”

//Windows‚Å‚ÌƒCƒxƒ“ƒg‚ğó‚¯æ‚é‚ÆAŒÄ‚Ño‚³‚ê‚éŠÖ”B
//Windows‚ÌƒƒbƒZ[ƒW‚ğE‚¢‚½‚¢ê‡‚Ì’è‹`Bã‚ÌelKeyboardŠÖ”“¯—lA“à•”‚Åˆ—B
long elEvent(void)
{
//ƒCƒxƒ“ƒgI—¹B
	elExitEvent();
}

///////////////////////////////////////////////////////////////////////////////
//	ƒƒCƒ“‰æ–Ê

// ‚Õ‚æŒ‹‡ƒ`ƒFƒbƒNŠÖ”iÄ‹Aj
// ˆø” x, y:’²‚×‚é‚Õ‚æÀ•W pno:‚Õ‚æ”Ô† cno:Œ‹‡”Ô†
int CheckCombine(int x, int y, int pno, int cno)
{
	if (field[y][x] != pno || cmb[y][x] != 0) return 0;@@@@@//Å‰‚Ì‹ói?jó‘Ô
	int ret = 1;
	cmb[y][x] = cno;
	if (y > 0) ret += CheckCombine(x, y - 1, pno, cno);		// ã
	ret += CheckCombine(x + 1, y, pno, cno);		         // ‰E
	ret += CheckCombine(x, y + 1, pno, cno);			// ‰º
	ret += CheckCombine(x - 1, y, pno, cno);			// ¶
	return ret;
}

void MainScreen(void)
{
	int i, x, y;
	int kx1, ky1, kx2, ky2;			// ‰¼‚ÌÀ•W
	bool flag;						// ”Ä—pƒtƒ‰ƒO
	static int pnext1, pnext2;		// ƒlƒNƒXƒg‚Õ‚æ”Ô†i‚O`‚Sj
	static int pno1, pno2;			// Œ»İ‚Ì‚Õ‚æ”Ô†i‚O`‚Sj
	static int px1, py1, px2, py2;	// ‚Õ‚æ‚Ì‚wA‚xÀ•W
	static int keyLeft = FREE_KEY;	// ¶ƒL[
	static int keyRight = FREE_KEY;	// ‰EƒL[
	static int keyDown = FREE_KEY;	// ‰ºƒL[
	static int keySpace = FREE_KEY;	// ƒXƒy[ƒXƒL[
	static bool overFlag = false;	// ƒQ[ƒ€ƒI[ƒo[ƒtƒ‰ƒO
	static int score = 0;			// “¾“_
	static DWORD rpt = 0;			// ƒL[ƒŠƒs[ƒgŠÔ
	static DWORD downTime = 1000;	// 1ƒuƒƒbƒN—‰º‚·‚éŠÔ(ms)
	static DWORD downCount;			// —‰ºŠÔ‚Ü‚Å‚Ì—P—\(ms)
	static enum {					// ó‘Ô
		NEXT,						// ƒlƒNƒXƒg‚Õ‚æoŒ»
		NORMAL,						// ’Êí
		FALL,						// ‚Õ‚æ—‰º
		ERASE1,						// ‚Õ‚æÁ‚µ‘O
		ERASE2,						// ‚Õ‚æÁ‚µ
	} status = NEXT;
	if (elChangeScreen()) {
@@@@@pnext1 = rand() % 5; pnext2 = rand() % 5;
@@@@@@}
	elDraw::Clear();
	DWORD nowTime = timeGetTime();@@
	switch (status) {
	// ƒlƒNƒXƒg‚Õ‚æoŒ»
	case NEXT:
		px1 = 3; py1 = 1; px2 = 3; py2 = 0;@@@@@@
		pno1 = pnext1; pno2 = pnext2;
		pnext1 = rand() % 5; pnext2 = rand() % 5;
	//ƒtƒB[ƒ‹ƒh‚É—‚¿‚½‚Õ‚æ‚ª‰º‚É‚Â‚¢‚½‚ÉŸ‚Ì‚Õ‚æ‚ª—‰º‚ğn‚ß‚éB
		downCount = timeGetTime();
		if (downTime > 100) downTime -= 10;
		else downTime--;
		if (downTime < 10) downTime = 10;
		status = NORMAL;
		break;
	// ’Êí
	case NORMAL:
		kx1 = px1; ky1 = py1;
		kx2 = px2; ky2 = py2;
		elSystem::GetKey(VK_LEFT, &keyLeft);    //¶‘€ì
		elSystem::GetKey(VK_RIGHT, &keyRight);@//‰E‘€ì
		elSystem::GetKey(VK_DOWN, &keyDown);@@//—‰º‘€ì
	@	elSystem::GetKey(VK_SPACE, &keySpace);@//“ü‚ê‘Ö‚¦‘€ì
		flag = false;
@@@//space‘€ì‚Å‚Õ‚æ‚Ì“ü‚ê‘Ö‚¦i‰ñ“]j‚ğ‚µ‚Ä‚¢‚é‚Æ‚±‚ë
		if (keySpace == PUSH_KEY) {
@@@//‰E‰ñ“]‚Å‚¤‚µ‚ë‚Ì‚Õ‚æ‚ª¡‚ÌˆÊ’u‚©‚ç‰E‚É‚¸‚ê‚é
			if (kx2 > kx1) {@
@@@@@@@@@@kx2 = kx1; 
		ky2 = ky1 + 1;
@@@@@@@@@@@}
	//‰E‰ñ“]‚Å‚¤‚µ‚ë‚Ì‚Õ‚æ‚ª¡‚ÌˆÊ’u‚©‚ç¶Œã‚ë‚É‚Ü‚í‚Á‚½
			else if (kx2 < kx1) {@@@@
	@kx2 = kx1; 
@@@@@ky2 = ky1 - 1;
	}
    //‰E‰ñ“]‚Å‚¤‚µ‚ë‚Ì‚Õ‚æ‚ª‘O‚Ì‚Õ‚æ‚Ì‰º‚É‚Ü‚í‚Á‚½
			else if (ky2 > ky1) {
	ky2 = ky1; 
	kx2 = kx1 - 1;
	}
	//Œ³‚ÌˆÊ’u‚É–ß‚é
			else {
	ky2 = ky1; 
	kx2 = kx1 + 1;
	}
		} 
	//‰ºƒL[‚Åƒ_ƒEƒ“ƒL[‚Å‚Õ‚æ‚Ì—‰º‚ğ‚·‚éB‰ºƒL[‚ğ—£‚¹‚ÎŒ³‚Ì‘¬“x‚Å—‚¿‚éB
	else if (keyDown == PUSH_KEY || keyDown == HOLD_KEY && nowTime - rpt > 10) {
			ky1++; ky2++; flag = true; rpt = nowTime;
		} 
@@@@//¶ƒL[‚Å¶‚ÉˆÚ“®‚·‚éB¶ƒL[‚ğ—£‚¹‚ÎŒ³‚Ì‘¬“x‚Å—‚¿‚éB
	else if (keyLeft == PUSH_KEY || keyLeft == HOLD_KEY && nowTime - rpt > 150) {
			kx1--; kx2--; rpt = nowTime;
		} 
@	//‰EƒL[‚Å¶‚ÉˆÚ“®‚·‚éB‰EƒL[‚ğ—£‚¹‚ÎŒ³‚Ì‘¬“x‚Å—‚¿‚éB
	else if (keyRight == PUSH_KEY || keyRight == HOLD_KEY && nowTime - rpt > 150) {
			kx1++; kx2++; rpt = nowTime;
		} 
	//ˆê”Ô‰º‚Ü‚Å—‚¿‚½‚çÏ‚İã‚°‚½‚Æ‚µ‚Ä‚Ü‚½‚Õ‚æ‚ğ‰Šú‚Ì‘‚³‚Å—‚Æ‚·
	else if (nowTime - downCount > downTime) {
			ky1++; ky2++; flag = true; downCount = nowTime;
		}
@@@@//‰½‚à‘€ì‚µ‚È‚¯‚ê‚Î‚»‚Ì‚Ü‚Ü—‚¿‚éB
		if (field[ky1][kx1] == -1 && field[ky2][kx2] == -1) {
			px1 = kx1; py1 = ky1;
			px2 = kx2; py2 = ky2;
		} else if (flag) {
	//NEXT‚Õ‚æ—‰º€”õ
			field[py1][px1] = pno1;
			field[py2][px2] = pno2;
			status = FALL;
		}
		break;
	// ‚Õ‚æ—‰º
	case FALL:
		Sleep(50);
		flag = false;
	//ŠJn‚©‚çˆê”Ô‰º‚Ü‚Å‚Ì—‰º
		for (y = 12; y >= 0; y--) {
	//¶’[‚©‚ç‰E’[‚Ü‚Å‚Ì‘€ì
			for (x = 1; x < 7; x++) {
        //‚Õ‚æÏ‚İã‚°‚½êŠ‚ğˆê”Ô‰º‚Æ‚µ‚ÄÄ‚Ñ—‰º
				if (field[y][x] != -1 && field[y + 1][x] == -1) {
					field[y + 1][x] = field[y][x];
					field[y][x] = -1;
					flag = true;
				}
			}
		}
@@@@//İ’è‚µ‚½F”‚ªd‚È‚é‚Æu‚Õ‚æÁ‚µ‘Ov‚Ìì‹Æ‚ÉˆÚ‚éB
		if (flag == false){     
@@@@@@@@status = ERASE1;
		break;
}
	// ‚Õ‚æÁ‚µ‘O
	case ERASE1:
		// ‚Õ‚æŒ‹‡ƒ`ƒFƒbƒN
		flag = false;
		for (y = 0; y < 15; y++) for (x = 0; x < 8; x++) cmb[y][x] = 0;
		for (i = 0; i < 30; i++) elist[i] = false;
		for (y = 13, i = 0; y >= 0; y--) {
			for (x = 1; x < 7; x++) {
		//“¯‚¶‚Õ‚æ‚ÌŒ‹‡‹ï‡iHj
				if (cmb[y][x] == 0 && field[y][x] != -1) {
					i++;
					int ret = CheckCombine(x, y, field[y][x], i);
	                               //“¯‚¶‚Õ‚æ‚ª‚S‚Â‚»‚ë‚¤‚ÆÁ‚¦‚ÄƒXƒRƒAƒAƒbƒv
					if (ret >= 4) {
						flag = true;
						elist[i] = true;
						score += ret * 10;
					}
				}
			}
		}
		if (flag) {
			// Œ‹‡‚Õ‚æ‚ª‚ ‚éê‡‚ÍÁ‚µ‚½‚Õ‚æ‚ÆêŠ‚Ì“ü‚ê‘Ö‚¦
			for (y = 13; y >= 0; y--) {
				for (x = 1; x < 7; x++) {
					if (elist[cmb[y][x]]) field[y][x] = 5;
				}
			}
			status = ERASE2;@@
		} else {
			// Œ‹‡‚Õ‚æ‚ª‚È‚¢ê‡‚ÍƒQ[ƒ€ƒI[ƒo[ƒ`ƒFƒbƒN‚µ‚ÄŸ‚Ö
			for (y = 0; y < 2; y++) {
				for (x = 1; x < 7; x++) {
					if (field[y][x] != -1) overFlag = true;
				}
			}
			status = NEXT;
		}
		break;
	// ‚Õ‚æÁ‚µ
	case ERASE2:
		Sleep(500);@//ˆê“I‚ÉƒtƒŠ[ƒY”½‰
@@@@//‚È‚­‚È‚Á‚Ä—‚¿‚½êŠ‚ÍÁ‚¦‚é‘O‚ÌÀ•W‚æ‚è‚Õ‚æ‚ª‰º‚É‚¨‚¿‚éB
		for (y = 13; y >= 0; y--) {
			for (x = 1; x < 7; x++) {
				if (field[y][x] == 5) field[y][x] = -1;
			}
		}
		status = FALL;
		break;
	}
	// ‰æ–Ê•\¦@iƒ‰ƒCƒ“‚Í”’A‰E‚Í‚Ë‚¸‚İFj
	elDraw::Box(192, 0, 256, 448, RGB(150, 150, 150), RGB(150, 150, 150), 0);
	elDraw::Line(0, 64, 192, 64, RGB(255, 255, 255), 1);
	//ƒXƒRƒA•\¦(ÂFj
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
	// Œ»İ‚Ì‚Õ‚æ•\¦ (ƒlƒNƒXƒg“¯—l‚ÉF‚ÍÔE—ÎEÂEÔEƒsƒ“ƒNB4‚Âd‚È‚Á‚½‚çƒVƒ‹ƒo[j
	if (status == NORMAL) {
		elDraw::Layer((px1 - 1) * 32, py1 * 32,
			puyo, pno1 * 32, 0, pno1 * 32 + 32, 32);
		elDraw::Layer((px2 - 1) * 32, py2 * 32,
			puyo, pno2 * 32, 0, pno2 * 32 + 32, 32);
	}
	// ƒlƒNƒXƒg‚Õ‚æ•\¦
	elDraw::Layer(208, 144, puyo, pnext2 * 32, 0, pnext2 * 32 + 32, 32);
	elDraw::Layer(208, 144 + 32, puyo, pnext1 * 32, 0, pnext1 * 32 + 32, 32);
	elDraw::Refresh();
	// ƒQ[ƒ€ƒI[ƒo[ˆ—Bˆ—ŒãAƒEƒCƒ“ƒhƒE‚ğ•Â‚¶‚é
	if (overFlag) {
		elSystem::Message("ƒQ[ƒ€ƒI[ƒo[");
		elDraw::Exit();
	}
}


