///////////////////////////////////////////////////////////////////////////////
//	‚Õ‚æ‚Õ‚æ
include "el.h"

define MAIN_SCREEN 1

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
	//‚±‚Ì’†‚ðƒOƒ‹ƒOƒ‹‚Æ‰ñ“]‚·‚é‚±‚Æ‚ÅAƒŠƒAƒ‹ƒ^ƒCƒ€‚Å‚Ìˆ—‚ªŽÀŒ»B
	elLoop()
	{
@@//æ‚Ù‚Ç’è‹`‚µ‚½MAIN_SCREEN‚ðAéŒ¾‚µ‚½MainScreenŠÖ”‚ÉƒŠƒ“ƒNB
	//‚±‚ê‚ÅAŠÈ’P‚É”CˆÓ‚Ì‰æ–Ê‚ðŒÄ‚Ño‚·‚±‚Æ‚ª‚Å‚«‚éB
		elSetScreen(MAIN_SCREEN,MainScreen());
	}	
	//ƒƒCƒ“ŠÖ”I—¹‚ÅŽ©“®“I‚ÉI—¹ˆ—B
void MainScreen(void);

	elExitMain();
}

	// ’Êí
	case NORMAL:
		kx1 = px1; ky1 = py1;
		kx2 = px2; ky2 = py2;
		elSystem::GetKey(VK_LEFT, &keyLeft);    //¶‘€ì
		elSystem::GetKey(VK_RIGHT, &keyRight);@//‰E‘€ì
		elSystem::GetKey(VK_DOWN, &keyDown);@@//—Ž‰º‘€ì
	@	elSystem::GetKey(VK_SPACE, &keySpace);@//“ü‚ê‘Ö‚¦‘€ì
		flag = false;
@@@//space‘€ì‚Å‚Õ‚æ‚Ì“ü‚ê‘Ö‚¦i‰ñ“]j‚ð‚µ‚Ä‚¢‚é‚Æ‚±‚ë
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
>>>>>>> s15002
			else if (ky2 > ky1) {
	ky2 = ky1; 
	kx2 = kx1 - 1;
	}
<<<<<<< HEAD
	//Œ³‚ÌˆÊ’u‚É–ß‚é
=======
	//å…ƒã®ä½ç½®ã«æˆ»ã‚‹
>>>>>>> s15002
			else {
	ky2 = ky1; 
	kx2 = kx1 + 1;
	}
		} 
<<<<<<< HEAD
	//‰ºƒL[‚Åƒ_ƒEƒ“ƒL[‚Å‚Õ‚æ‚Ì—Ž‰º‚ð‚·‚éB‰ºƒL[‚ð—£‚¹‚ÎŒ³‚Ì‘¬“x‚Å—Ž‚¿‚éB
	else if (keyDown == PUSH_KEY || keyDown == HOLD_KEY && nowTime - rpt > 10) {
			ky1++; ky2++; flag = true; rpt = nowTime;
		} 
@@@@//¶ƒL[‚Å¶‚ÉˆÚ“®‚·‚éB¶ƒL[‚ð—£‚¹‚ÎŒ³‚Ì‘¬“x‚Å—Ž‚¿‚éB
	else if (keyLeft == PUSH_KEY || keyLeft == HOLD_KEY && nowTime - rpt > 150) {
			kx1--; kx2--; rpt = nowTime;
		} 
@	//‰EƒL[‚Å¶‚ÉˆÚ“®‚·‚éB‰EƒL[‚ð—£‚¹‚ÎŒ³‚Ì‘¬“x‚Å—Ž‚¿‚éB
	else if (keyRight == PUSH_KEY || keyRight == HOLD_KEY && nowTime - rpt > 150) {
			kx1++; kx2++; rpt = nowTime;
		} 
	//ˆê”Ô‰º‚Ü‚Å—Ž‚¿‚½‚çÏ‚Ýã‚°‚½‚Æ‚µ‚Ä‚Ü‚½‚Õ‚æ‚ð‰Šú‚Ì‘‚³‚Å—Ž‚Æ‚·
	else if (nowTime - downCount > downTime) {
			ky1++; ky2++; flag = true; downCount = nowTime;
		}
@@@@//‰½‚à‘€ì‚µ‚È‚¯‚ê‚Î‚»‚Ì‚Ü‚Ü—Ž‚¿‚éB
		if (field[ky1][kx1] == -1 && field[ky2][kx2] == -1) {
			px1 = kx1; py1 = ky1;
			px2 = kx2; py2 = ky2;
		} else if (flag) {
	//NEXT‚Õ‚æ—Ž‰º€”õ
			field[py1][px1] = pno1;
			field[py2][px2] = pno2;
			status = FALL;
		}
		break;
	// ‚Õ‚æ—Ž‰º
	case FALL:
		Sleep(50);
		flag = false;
	//ŠJŽn‚©‚çˆê”Ô‰º‚Ü‚Å‚Ì—Ž‰º
		for (y = 12; y >= 0; y--) {
	//¶’[‚©‚ç‰E’[‚Ü‚Å‚Ì‘€ì
			for (x = 1; x < 7; x++) {
        //‚Õ‚æÏ‚Ýã‚°‚½êŠ‚ðˆê”Ô‰º‚Æ‚µ‚ÄÄ‚Ñ—Ž‰º
