

























































































































//Tuujou no puyo ga jiyuu ni ugoku
	case NORMAL:
		kx1 = px1; ky1 = py1;
		kx2 = px2; ky2 = py2;    //kari no zahyou ni puyo no zahyou wo ireru
		elSystem::GetKey(VK_LEFT, &keyLeft);
		elSystem::GetKey(VK_RIGHT, &keyRight);
		elSystem::GetKey(VK_DOWN, &keyDown);
		elSystem::GetKey(VK_SPACE, &keySpace);    //migi hidari sita space no key no atai wo yomitoru
		flag = false;    //sita ya kyouseirakka de otiteirunara true ni naru flag
		if (keySpace == PUSH_KEY) {
			if (kx2 > kx1) {kx2 = kx1; ky2 = ky1 + 1;}
			else if (kx2 < kx1) {kx2 = kx1; ky2 = ky1 - 1;}
			else if (ky2 > ky1) {ky2 = ky1; kx2 = kx1 - 1;}
			else {ky2 = ky1; kx2 = kx1 -1;}    //Space wo osu to kaitenn
		} else if (keyDown == PUSH_KEY || keyDown == HOLD_KEY && nowTime - rpt > 10) {
			ky1++; ky2++; flag = true; rpt = nowTime;
		} else if (keyLeft == PUSH_KEY || keyLeft == HOLD_KEY && nowTime - rpt > 150) {
			kx1--; kx2--; rpt = nowTime;
		} else if (keyRight == PUSH_KEY || keyRight == HOLD_KEY && nowTime -rpt > 150) {
			kx1++; kx2++; rpt = nowTime;
		} else if (nowTime - downCount > downTime) {
			ky1++; ky2++; flag = true; downCount = nowTime;
		}
		if (field[ky1][kx1] == -1 && field[ky2][kx2] == -1) {
			px1 = kx1; py1 = ky1;
			px2 = kx2; py2 = ky2;
		} else if (flag) {
			field[py1][px1] = pno1;
			field[py2][px2] = pno2;
			status = FALL;
		}
		break;
//puyo rakka
	case FALL:
		Sleep(50);
		flag = false;
		for (y =12; y > 0; y--) {
			for (x = 1; x < 7; x++) {
				if (field[y][x] != -1 && field[y + 1][x] == -1) {
					field[y + 1][x] = field[y][x];
					field[y][x] = -1;
					flag = true;
				}
			}
		}
		if (flag == false) status = ERASE1;
		break;
