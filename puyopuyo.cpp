///////////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
//	�Ղ�Ղ�
=======
//	ぷよぷよ

>>>>>>> 4f70561af625d676e1d35afd7d39c65e571353d3
include "el.h"

#define MAIN_SCREEN 1

//��ʗp�̊֐��̃v���g�^�C�v
///////////////////////////////////////////////////////////////////////////////
//	�Ղ�Ղ�

#include "el.h"

#define MAIN_SCREEN 1

//��ʗp�̊֐��̃v���g�^�C�v
void MainScreen(void);

DDOBJ puyo;				// �Ղ�̃r�b�g�}�b�v
int field[15][8];		// ��ʃf�[�^
int cmb[15][8];			// �����`�F�b�N�p
bool elist[30];			// �������X�g

///////////////////////////////////////////////////////////////////////////////
//	���C���֐�

//�v���O�����N����A��ԍŏ��ɌĂяo�����֐��B
int elMain("�Ղ�Ղ�");
{
	elWindow(256, 448, FALSE);
	//���̃��[�v���ŏ����������B
	//���̒����O���O���Ɖ�]���邱�ƂŁA���A���^�C���ł̏����������B
	elLoop()
	{
�@�@//��قǒ�`����MAIN_SCREEN���A�錾����MainScreen�֐��Ƀ����N�B
	//����ŁA�ȒP�ɔC�ӂ̉�ʂ��Ăяo�����Ƃ��ł���B
		elSetScreen(MAIN_SCREEN,MainScreen());
	}	
	//���C���֐��I���Ŏ����I�ɏI�������B
	elExitMain();
}

///////////////////////////////////////////////////////////////////////////////
//	�E�C���h�E�����֐�

void elCreate(void)
{
	elDraw::Screen(256, 448);�@//256�~448�h�b�g�̃E�B���h�E
	// �Ղ�摜�ǂݍ���
	puyo = elDraw::LoadObject("puyo.bmp");
	// �t�B�[���h���N���A
	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 8; x++) {
    //�Ղ悪�S�����܂�܂ł̃E�C���h�E����
			if (x == 0 || x == 7 || y == 14) field[y][x] = 5;
			else field[y][x] = -1;
		}
	}
	elCallScreen(MAIN_SCREEN);
}

///////////////////////////////////////////////////////////////////////////////
//	�L�[�{�[�h�֐�

// �@�����L�[���͂�����ƁA�Ăяo�����֐��B
// Windows�������L�[���͂��󂯎��ƁA�����ɉ����ꂽ�L�[��n���B
void elKeyboard(void)
{
	//[ESC]�L�[��������Ă���B
	// VK_ESCAPE�Ƃ́A[ESC]�L�[�̉��z�L�[�R�[�h�B
case VK_ESCAPE:
	{
�@�@//�v���O�������I���B
		elDraw::Exit();
		break;
	}
  //�L�[�{�[�h�֐��I���B
	elExitKeyboard();
}

///////////////////////////////////////////////////////////////////////////////
//	�C�x���g�֐�

//Windows�ł̃C�x���g���󂯎��ƁA�Ăяo�����֐��B
//Windows�̃��b�Z�[�W���E�������ꍇ�̒�`�B���elKeyboard�֐����l�A�����ŏ����B
long elEvent(void)
{
//�C�x���g�I���B
	elExitEvent();
}

///////////////////////////////////////////////////////////////////////////////
//	���C�����

// �Ղ挋���`�F�b�N�֐��i�ċA�j
// ���� x, y:���ׂ�Ղ���W pno:�Ղ�ԍ� cno:�����ԍ�
int CheckCombine(int x, int y, int pno, int cno)
{
	if (field[y][x] != pno || cmb[y][x] != 0) return 0;�@�@�@�@�@//�ŏ��̋�i?�j���
	int ret = 1;
	cmb[y][x] = cno;
	if (y > 0) ret += CheckCombine(x, y - 1, pno, cno);		// ��
	ret += CheckCombine(x + 1, y, pno, cno);		         // �E
	ret += CheckCombine(x, y + 1, pno, cno);			// ��
	ret += CheckCombine(x - 1, y, pno, cno);			// ��
	return ret;
}

void MainScreen(void)
{
	int i, x, y;
	int kx1, ky1, kx2, ky2;			// ���̍��W
	bool flag;						// �ėp�t���O
	static int pnext1, pnext2;		// �l�N�X�g�Ղ�ԍ��i�O�`�S�j
	static int pno1, pno2;			// ���݂̂Ղ�ԍ��i�O�`�S�j
	static int px1, py1, px2, py2;	// �Ղ�̂w�A�x���W
	static int keyLeft = FREE_KEY;	// ���L�[
	static int keyRight = FREE_KEY;	// �E�L�[
	static int keyDown = FREE_KEY;	// ���L�[
	static int keySpace = FREE_KEY;	// �X�y�[�X�L�[
	static bool overFlag = false;	// �Q�[���I�[�o�[�t���O
	static int score = 0;			// ���_
	static DWORD rpt = 0;			// �L�[���s�[�g����
	static DWORD downTime = 1000;	// 1�u���b�N�������鎞��(ms)
	static DWORD downCount;			// �������Ԃ܂ł̗P�\(ms)
	static enum {					// ���
		NEXT,						// �l�N�X�g�Ղ�o��
		NORMAL,						// �ʏ�
		FALL,						// �Ղ旎��
		ERASE1,						// �Ղ�����O
		ERASE2,						// �Ղ����
	} status = NEXT;
	if (elChangeScreen()) {
�@�@�@�@�@pnext1 = rand() % 5; pnext2 = rand() % 5;
�@�@�@�@�@�@}
	elDraw::Clear();
	DWORD nowTime = timeGetTime();�@�@
	switch (status) {
	// �l�N�X�g�Ղ�o��
	case NEXT:
		px1 = 3; py1 = 1; px2 = 3; py2 = 0;�@�@�@�@�@�@
		pno1 = pnext1; pno2 = pnext2;
		pnext1 = rand() % 5; pnext2 = rand() % 5;
	//�t�B�[���h�ɗ������Ղ悪���ɂ������Ɏ��̂Ղ悪�������n�߂�B
		downCount = timeGetTime();
		if (downTime > 100) downTime -= 10;
		else downTime--;
		if (downTime < 10) downTime = 10;
		status = NORMAL;
		break;
	// �ʏ�
	case NORMAL:
		kx1 = px1; ky1 = py1;
		kx2 = px2; ky2 = py2;
		elSystem::GetKey(VK_LEFT, &keyLeft);    //������
		elSystem::GetKey(VK_RIGHT, &keyRight);�@//�E����
		elSystem::GetKey(VK_DOWN, &keyDown);�@�@//��������
	�@	elSystem::GetKey(VK_SPACE, &keySpace);�@//����ւ�����
		flag = false;
�@�@�@//space����łՂ�̓���ւ��i��]�j�����Ă���Ƃ���
		if (keySpace == PUSH_KEY) {
�@�@�@//�E��]�ł�����̂Ղ悪���̈ʒu����E�ɂ����
			if (kx2 > kx1) {�@
�@�@�@�@�@�@�@�@�@�@kx2 = kx1; 
		ky2 = ky1 + 1;
�@�@�@�@�@�@�@�@�@�@�@}
	//�E��]�ł�����̂Ղ悪���̈ʒu���獶���ɂ܂����
			else if (kx2 < kx1) {�@�@�@�@
	�@kx2 = kx1; 
�@�@�@�@�@ky2 = ky1 - 1;
	}
    //�E��]�ł�����̂Ղ悪�O�̂Ղ�̉��ɂ܂����
			else if (ky2 > ky1) {
	ky2 = ky1; 
	kx2 = kx1 - 1;
	}
	//���̈ʒu�ɖ߂�
			else {
	ky2 = ky1; 
	kx2 = kx1 + 1;
	}
		} 
	//���L�[�Ń_�E���L�[�łՂ�̗���������B���L�[�𗣂��Ό��̑��x�ŗ�����B
	else if (keyDown == PUSH_KEY || keyDown == HOLD_KEY && nowTime - rpt > 10) {
			ky1++; ky2++; flag = true; rpt = nowTime;
		} 
�@�@�@�@//���L�[�ō��Ɉړ�����B���L�[�𗣂��Ό��̑��x�ŗ�����B
	else if (keyLeft == PUSH_KEY || keyLeft == HOLD_KEY && nowTime - rpt > 150) {
			kx1--; kx2--; rpt = nowTime;
		} 
�@	//�E�L�[�ō��Ɉړ�����B�E�L�[�𗣂��Ό��̑��x�ŗ�����B
	else if (keyRight == PUSH_KEY || keyRight == HOLD_KEY && nowTime - rpt > 150) {
			kx1++; kx2++; rpt = nowTime;
		} 
	//��ԉ��܂ŗ�������ςݏグ���Ƃ��Ă܂��Ղ�������̑����ŗ��Ƃ�
	else if (nowTime - downCount > downTime) {
			ky1++; ky2++; flag = true; downCount = nowTime;
		}
�@�@�@�@//�������삵�Ȃ���΂��̂܂ܗ�����B
		if (field[ky1][kx1] == -1 && field[ky2][kx2] == -1) {
			px1 = kx1; py1 = ky1;
			px2 = kx2; py2 = ky2;
		} else if (flag) {
	//NEXT�Ղ旎������
			field[py1][px1] = pno1;
			field[py2][px2] = pno2;
			status = FALL;
		}
		break;
	// �Ղ旎��
	case FALL:
		Sleep(50);
		flag = false;
	//�J�n�����ԉ��܂ł̗���
		for (y = 12; y >= 0; y--) {
	//���[����E�[�܂ł̑���
			for (x = 1; x < 7; x++) {
        //�Ղ�ςݏグ���ꏊ����ԉ��Ƃ��čĂї���
				if (field[y][x] != -1 && field[y + 1][x] == -1) {
					field[y + 1][x] = field[y][x];
					field[y][x] = -1;
					flag = true;
				}
			}
		}
�@�@�@�@//�ݒ肵���F�����d�Ȃ�Ɓu�Ղ�����O�v�̍�ƂɈڂ�B
		if (flag == false){     
�@�@�@�@�@�@�@�@status = ERASE1;
		break;
}
	// �Ղ�����O
	case ERASE1:
		// �Ղ挋���`�F�b�N
		flag = false;
		for (y = 0; y < 15; y++) for (x = 0; x < 8; x++) cmb[y][x] = 0;
		for (i = 0; i < 30; i++) elist[i] = false;
		for (y = 13, i = 0; y >= 0; y--) {
			for (x = 1; x < 7; x++) {
		//�����Ղ�̌�����i�H�j
				if (cmb[y][x] == 0 && field[y][x] != -1) {
					i++;
					int ret = CheckCombine(x, y, field[y][x], i);
	                               //�����Ղ悪�S���낤�Ə����ăX�R�A�A�b�v
					if (ret >= 4) {
						flag = true;
						elist[i] = true;
						score += ret * 10;
					}
				}
			}
		}
		if (flag) {
			// �����Ղ悪����ꍇ�͏������Ղ�Əꏊ�̓���ւ�
			for (y = 13; y >= 0; y--) {
				for (x = 1; x < 7; x++) {
					if (elist[cmb[y][x]]) field[y][x] = 5;
				}
			}
			status = ERASE2;�@�@
		} else {
			// �����Ղ悪�Ȃ��ꍇ�̓Q�[���I�[�o�[�`�F�b�N���Ď���
			for (y = 0; y < 2; y++) {
				for (x = 1; x < 7; x++) {
					if (field[y][x] != -1) overFlag = true;
				}
			}
			status = NEXT;
		}
		break;
	// �Ղ����
	case ERASE2:
		Sleep(500);�@//�ꎞ�I�Ƀt���[�Y����
�@�@�@�@//�Ȃ��Ȃ��ė������ꏊ�͏�����O�̍��W���Ղ悪���ɂ�����B
		for (y = 13; y >= 0; y--) {
			for (x = 1; x < 7; x++) {
				if (field[y][x] == 5) field[y][x] = -1;
			}
		}
		status = FALL;
		break;
	}
	// ��ʕ\���@�i���C���͔��A�E�͂˂��ݐF�j
	elDraw::Box(192, 0, 256, 448, RGB(150, 150, 150), RGB(150, 150, 150), 0);
	elDraw::Line(0, 64, 192, 64, RGB(255, 255, 255), 1);
	//�X�R�A�\��(�F�j
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
	// ���݂̂Ղ�\�� (�l�N�X�g���l�ɐF�͐ԁE�΁E�E�ԁE�s���N�B4�d�Ȃ�����V���o�[�j
	if (status == NORMAL) {
		elDraw::Layer((px1 - 1) * 32, py1 * 32,
			puyo, pno1 * 32, 0, pno1 * 32 + 32, 32);
		elDraw::Layer((px2 - 1) * 32, py2 * 32,
			puyo, pno2 * 32, 0, pno2 * 32 + 32, 32);
	}
	// �l�N�X�g�Ղ�\��
	elDraw::Layer(208, 144, puyo, pnext2 * 32, 0, pnext2 * 32 + 32, 32);
	elDraw::Layer(208, 144 + 32, puyo, pnext1 * 32, 0, pnext1 * 32 + 32, 32);
	elDraw::Refresh();
	// �Q�[���I�[�o�[�����B������A�E�C���h�E�����
	if (overFlag) {
		elSystem::Message("�Q�[���I�[�o�[");
		elDraw::Exit();
	}
}


