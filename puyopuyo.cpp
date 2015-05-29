///////////////////////////////////////////////////////////////////////////////
//	ぷよぷよ
include "el.h"

define MAIN_SCREEN 1

//画面用の関数のプロトタイプ
void MainScreen(void);

DDOBJ puyo;				// ぷよのビットマップ
int field[15][8];		// 画面データ
int cmb[15][8];			// 結合チェック用
bool elist[30];			// 消すリスト

///////////////////////////////////////////////////////////////////////////////
//	メイン関数

//プログラム起動後、一番最初に呼び出される関数。
int elMain("ぷよぷよ");
{
	elWindow(256, 448, FALSE);
	//このループ内で処理がされる。
	//この中をグルグルと回転することで、リアルタイムでの処理が実現。
	elLoop()
	{
　　//先ほど定義したMAIN_SCREENを、宣言したMainScreen関数にリンク。
	//これで、簡単に任意の画面を呼び出すことができる。
		elSetScreen(MAIN_SCREEN,MainScreen());
	}	
	//メイン関数終了で自動的に終了処理。
void MainScreen(void);

	elExitMain();
}

	// 通常
	case NORMAL:
		kx1 = px1; ky1 = py1;
		kx2 = px2; ky2 = py2;
		elSystem::GetKey(VK_LEFT, &keyLeft);    //左操作
		elSystem::GetKey(VK_RIGHT, &keyRight);　//右操作
		elSystem::GetKey(VK_DOWN, &keyDown);　　//落下操作
	　	elSystem::GetKey(VK_SPACE, &keySpace);　//入れ替え操作
		flag = false;
　　　//space操作でぷよの入れ替え（回転）をしているところ
		if (keySpace == PUSH_KEY) {
　　　//右回転でうしろのぷよが今の位置から右にずれる
			if (kx2 > kx1) {　
　　　　　　　　　　kx2 = kx1; 
		ky2 = ky1 + 1;
　　　　　　　　　　　}
	//右回転でうしろのぷよが今の位置から左後ろにまわった
			else if (kx2 < kx1) {　　　　
	　kx2 = kx1; 
　　　　　ky2 = ky1 - 1;
	}
    //右回転でうしろのぷよが前のぷよの下にまわった
>>>>>>> s15002
			else if (ky2 > ky1) {
	ky2 = ky1; 
	kx2 = kx1 - 1;
	}
<<<<<<< HEAD
	//元の位置に戻る
=======
	//蜈�縺ｮ菴咲ｽｮ縺ｫ謌ｻ繧�
>>>>>>> s15002
			else {
	ky2 = ky1; 
	kx2 = kx1 + 1;
	}
		} 
<<<<<<< HEAD
	//下キーでダウンキーでぷよの落下をする。下キーを離せば元の速度で落ちる。
	else if (keyDown == PUSH_KEY || keyDown == HOLD_KEY && nowTime - rpt > 10) {
			ky1++; ky2++; flag = true; rpt = nowTime;
		} 
　　　　//左キーで左に移動する。左キーを離せば元の速度で落ちる。
	else if (keyLeft == PUSH_KEY || keyLeft == HOLD_KEY && nowTime - rpt > 150) {
			kx1--; kx2--; rpt = nowTime;
		} 
　	//右キーで左に移動する。右キーを離せば元の速度で落ちる。
	else if (keyRight == PUSH_KEY || keyRight == HOLD_KEY && nowTime - rpt > 150) {
			kx1++; kx2++; rpt = nowTime;
		} 
	//一番下まで落ちたら積み上げたとしてまたぷよを初期の早さで落とす
	else if (nowTime - downCount > downTime) {
			ky1++; ky2++; flag = true; downCount = nowTime;
		}
　　　　//何も操作しなければそのまま落ちる。
		if (field[ky1][kx1] == -1 && field[ky2][kx2] == -1) {
			px1 = kx1; py1 = ky1;
			px2 = kx2; py2 = ky2;
		} else if (flag) {
	//NEXTぷよ落下準備
			field[py1][px1] = pno1;
			field[py2][px2] = pno2;
			status = FALL;
		}
		break;
	// ぷよ落下
	case FALL:
		Sleep(50);
		flag = false;
	//開始から一番下までの落下
		for (y = 12; y >= 0; y--) {
	//左端から右端までの操作
			for (x = 1; x < 7; x++) {
        //ぷよ積み上げた場所を一番下として再び落下
