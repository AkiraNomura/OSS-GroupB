///////////////////////////////////////////////////////////////////////////////
//	�Ղ�Ղ�
include "el.h"

define MAIN_SCREEN 1

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
void MainScreen(void);

	elExitMain();
}

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
>>>>>>> s15002
			else if (ky2 > ky1) {
	ky2 = ky1; 
	kx2 = kx1 - 1;
	}
<<<<<<< HEAD
	//���̈ʒu�ɖ߂�
=======
	//元の位置に戻る
>>>>>>> s15002
			else {
	ky2 = ky1; 
	kx2 = kx1 + 1;
	}
		} 
<<<<<<< HEAD
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
