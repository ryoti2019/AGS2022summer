#include <DxLib.h>
#include "main.h"
#include "_debug/_DebugConOut.h"
#include "_debug/_DebugDispOut.h"

// �v���C���[�֘A
int playerImage[DIR_MAX][ANIM_MAX];		// �O���t�B�b�N�n���h��
int shadowImage[DIR_MAX][ANIM_MAX];		// �O���t�B�b�N�n���h��
int playerPosX;							// X���W
int playerPosY;							// Y���W
int playerSpeed;						// �ړ���
int playerAnimCnt;						// �A�j���[�V�����J�E���^�[
int playerAnimData[4];					// �A�j���[�V�����̍Đ��ԍ�
int playerDir;							// ����
bool playerFlag;						// ���
bool playerFlag2;
int playerLife;							// �v���C���[�̃��C�t
int playerUpKey;						// �ړ�����L�[�̏��
int playerUpKeyOld;						// �ړ�����L�[�̏��(1�t���[���O)
int playerDownKey;						// �ړ�����L�[�̏��
int playerDownKeyOld;					// �ړ�����L�[�̏��(1�t���[���O)
int heartImage;

// �G�֘A
int enemyAnimCnt;						// �A�j���[�V�����J�E���^�[
int enemyAnimData[4];					// �A�j���[�V�����̍Đ��ԍ�
int enemyDir;							// ����


int goblinImage[DIR_MAX][ANIM_MAX];		// �O���t�B�b�N�n���h��
int goblinPosX;							// X���W
int goblinPosY;							// Y���W
int goblinSpeed;						// �ړ���
bool goblinFlag;						// ���

int pumpkinImage[DIR_MAX][ANIM_MAX];	// �O���t�B�b�N�n���h��
int pumpkinPosX;						// X���W
int pumpkinPosY;						// Y���W
int pumpkinSpeed;						// �ړ���
bool pumpkinFlag;						// ���

int darkpriestImage[DIR_MAX][ANIM_MAX];	// �O���t�B�b�N�n���h��
int darkpriestPosX;						// X���W
int darkpriestPosY;						// Y���W
int darkpriestSpeed;					// �ړ���
bool darkpriestFlag;					// ���

int zombieImage[DIR_MAX][ANIM_MAX];		// �O���t�B�b�N�n���h��
int zombiePosX;							// X���W
int zombiePosY;							// Y���W
int zombieSpeed;						// �ړ���
bool zombieFlag;						// ���

int skeletonImage[DIR_MAX][ANIM_MAX];	// �O���t�B�b�N�n���h��
int skeletonPosX;						// X���W
int skeletonPosY;						// Y���W
int skeletonSpeed;						// �ړ���
bool skeletonFlag;						// ���

int enemyRespawn[3];					// �G�̃��X�|�[���ʒu

// �A�C�e���֘A

int bowImage;							// �O���t�B�b�N�n���h��
int bowImage2;							// �O���t�B�b�N�n���h��
int bowPosX;							// X���W
int bowPosY;							// Y���W
int bowSpeed;							// �ړ����x
bool bowFlag;							// ���

int arrowImage;							// �O���t�B�b�N�n���h��
int arrowPosX;							// X���W
int arrowPosY;							// Y���W
int arrowSpeed;							// �ړ����x
bool arrowFlag;							// ���
bool arrowFlag2;						// ���
int arrowKey;							// �e�����L�[�̏��
int arrowKeyOld;						// �e�����L�[�̏��(1�t���[���O)

int barrierImage;						// �O���t�B�b�N�n���h��
int barrierImage2;						// �O���t�B�b�N�n���h��
int barrierPosX;						// X���W
int barrierPosY;						// Y���W
int barrierSpeed;						// �ړ����x
bool barrierFlag;						// ���

int barrierOnImage[BARRIER_IMAGE_MAX];	// �O���t�B�b�N�n���h��
int barrierImage3[BARRIER_IMAGE_MAX];	// �O���t�B�b�N�n���h��
int barrierOnAnimCnt;					// �A�j���[�V�����J�E���^�[
int barrierOnCnt;						// ���Ԃ̃J�E���^�[
int barrierOnPosX;						// X���W
int barrierOnPosY;						// Y���W
int barrierOnFlag;						// ���

// �w�i�֘A
int bgImage;							// �O���t�B�b�N�n���h��
int bgPosX1;							// 1���ڂ̍��W
int bgPosX2;							// 2���ڂ̍��W
int bgPosX1speed;						// 1���ڂ̃X�s�[�h
int bgPosX2speed;						// 2���ڂ̃X�s�[�h

// ���y�֘A
int titleSound;
int bgmSound;
int gameoverSound;
int bowSound;
int enemySound;
int deathSound;
int barrierSound;
int aitemSound;

// ���̑�
SCN_ID scnID;							// �V�[���Ǘ��p
int titleImage;							// �^�C�g����ʂ̃O���t�B�b�N�n���h��
int userGuideImage;						// ��������̃O���t�B�b�N�n���h��
int gameOverImage;						// �Q�[���I�[�o�[��ʂ̃O���t�B�b�N�n���h��
bool zKeyFlag;							// Z�L�[�̉����t���O
bool zKeyFlagOld;						// Z�L�[�̉����t���O(1�t���[���O)
bool spaceKeyFlag;						// SPACE�L�[�̉����t���O
bool spaceKeyFlagOld;					// SPACE�L�[�̉����t���O(1�t���[���O)
int blinkCnt;							// ���ŗp�J�E���^�[
int speedCnt;							// �X�s�[�h�̃J�E���^�[
int scrCnt[SCR_MAX];					// �n�C�X�R�A�p
int Scr;								// �X�R�A���Z1
int Scr2;								// �X�R�A���Z2
int Scr3;								// �X�R�A���Z3
int count;
int timeCnt;
int effectImage[EFFECT_IMAGE_MAX];
int effectPosX;
int effectPosY;
int effectAnimCnt;						// �A�j���[�V�����J�E���^�[
int effectFlag;

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	if (SysInit() == false)
	{

		return -1;
	}

	if (GameInit() == false)
	{
		return -1;
	}

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		_dbgStartDraw();
		GetKeyState();
		switch (scnID)
		{
		case SCN_ID_TITLE:
			TitleScene();
			break;
		case SCN_ID_USERGUIDE:
			UserGuideScene();
			break;
		case SCN_ID_GAME:
			GameScene();
			break;
		case SCN_ID_GAMEOVER:
			GameOverScene();
			break;
		default:
			//�V�[��ID�ُ�
			TRACE("�V�[��ID���ُ�\n");
			break;
		}
	}
	TitleScene();
	DxLib_End();
	return 0;
}

void TitleScene(void)
{	
	if (zKeyFlag && !zKeyFlagOld)
	{
		PlaySoundMem(titleSound, DX_PLAYTYPE_BACK, true);
		scnID = SCN_ID_USERGUIDE;
	}
	TitleDraw();
}

void TitleDraw(void)
{

	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	SetFontSize(30);
	DrawGraph(0, 0, titleImage, true);
	int titleSizeX = GetDrawStringWidth("�o�k�d�`�r�d�@'�y'�@�j�d�x", 13);
	blinkCnt++;
	if ((blinkCnt / 30) % 2)
	{
		DrawString(((600 - titleSizeX) / 2), 350, "�o�k�d�`�r�d�@'�y'�@�j�d�x", 0x000000);
	}
	ScreenFlip();

}

void UserGuideScene(void)
{
	if (spaceKeyFlag && !spaceKeyFlagOld)
	{
		StopSoundMem(titleSound);
		PlaySoundMem(bgmSound, DX_PLAYTYPE_LOOP, true);
		scnID = SCN_ID_GAME;
	}
	UserGuideDraw();
}

void UserGuideDraw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	DrawGraph(0, 0, userGuideImage, true);
	int userguideSizeX = GetDrawStringWidth("�o�k�d�`�r�d�@'�r�o�`�b�d'�@�j�d�x", 17);
	blinkCnt++;
	if ((blinkCnt / 30) % 2)
	{
		DrawString(((600 - userguideSizeX) / 2), 500, "�o�k�d�`�r�d�@'�r�o�`�b�d'�@�j�d�x", 0xffffff);
	}
	ScreenFlip();
}



void GameOverScene(void)
{
	if (spaceKeyFlag && !spaceKeyFlagOld)
	{
		StopSoundMem(gameoverSound);
		GameInit();
		scnID = SCN_ID_TITLE;
	}
	GameOverDraw();
}

void GameOverDraw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	DrawGraph((SCREEN_SIZE_X - 345) / 2, 200, gameOverImage, true);
	blinkCnt++;
	if ((blinkCnt / 30) % 2)
	{
		DrawString(275, 350, "�R���e�B�j���[�H", 0xffffff);
		DrawString(250, 380, "'�r�o�`�b�d'�j�d�x", 0xffffff);
	}
	DrawFormatString(275, 300, 0xffff00, "�r�b�n�q�d");
	DrawFormatString(450, 300, 0xffff00, "%dm", scrCnt[SCR_PL1]);
	ScreenFlip();
}

void GameScene(void)
{
	PlayerCtl();
	EnemyCtl();
	AitemCtl();
	CheckHitObj();
	BgCtl();
	SpeedCtl();
	GameDraw();
	AddScr();
	PlayerDeathProc();
}

void PlayerCtl(void)
{
	playerUpKeyOld = playerUpKey;
	playerUpKey = CheckHitKey(KEY_INPUT_UP);

	playerDownKeyOld = playerDownKey;
	playerDownKey = CheckHitKey(KEY_INPUT_DOWN);


	// �v���C���[�̈ړ�����
	if (playerUpKey && !playerUpKeyOld)
	{
		if (playerPosY == PLAYER_STANDARD)
		{
			playerPosY -= playerSpeed;
		}
	}

	if (playerUpKey && !playerUpKeyOld)
	{
		if (playerPosY == PLAYER_STANDARD + playerSpeed)
		{
			playerPosY -= playerSpeed;
		}
	}

	if (playerDownKey && !playerDownKeyOld)
	{
		if (playerPosY == PLAYER_STANDARD)
		{
			playerPosY += playerSpeed;
		}
	}

	if (playerDownKey && !playerDownKeyOld)
	{
		if (playerPosY == PLAYER_STANDARD - playerSpeed)
		{
			playerPosY += playerSpeed;
		}
	}

}

void EnemyCtl(void)
{
	// �G�̍ďo������
	if (!goblinFlag)
	{
		if (rand() % 300 == 0)
		{
			goblinPosX = SCREEN_SIZE_X + ENEMY_SIZE_X;
			goblinPosY = enemyRespawn[rand() % 3];
			goblinFlag = true;
			effectFlag = false;
		}
	}

	if (!pumpkinFlag)
	{
		if (rand() % 300 == 0)
		{
			pumpkinPosX = SCREEN_SIZE_X + ENEMY_SIZE_X;
			pumpkinPosY = enemyRespawn[rand() % 3];
			pumpkinFlag = true;
			effectFlag = false;
		}
	}

	if (!darkpriestFlag)
	{
		if (rand() % 300 == 0)
		{
			darkpriestPosX = SCREEN_SIZE_X + ENEMY_SIZE_X;
			darkpriestPosY = enemyRespawn[rand() % 3];
			darkpriestFlag = true;
			effectFlag = false;
		}
	}

	if (!zombieFlag)
	{
		if (rand() % 300 == 0)
		{
			zombiePosX = SCREEN_SIZE_X + ENEMY_SIZE_X;
			zombiePosY = enemyRespawn[rand() % 3];
			zombieFlag = true;
			effectFlag = false;
		}
	}

	if (!skeletonFlag)
	{
		if (rand() % 300 == 0)
		{
			skeletonPosX = SCREEN_SIZE_X + ENEMY_SIZE_X;
			skeletonPosY = enemyRespawn[rand() % 3];
			skeletonFlag = true;
			effectFlag = false;
		}
	}

	// �G�̈ړ�����
	if (goblinFlag)
	{
		goblinPosX -= goblinSpeed;
		if (goblinPosX + ENEMY_SIZE_X <= 0)
		{
			goblinFlag = false;
		}
	}

	if (pumpkinFlag)
	{
		pumpkinPosX -= pumpkinSpeed;
		if (pumpkinPosX + ENEMY_SIZE_X <= 0)
		{
			pumpkinFlag = false;
		}
	}

	if (darkpriestFlag)
	{
		darkpriestPosX -= darkpriestSpeed;
		if (darkpriestPosX + ENEMY_SIZE_X <= 0)
		{
			darkpriestFlag = false;
		}
	}

	if (zombieFlag)
	{
		zombiePosX -= zombieSpeed;
		if (zombiePosX + ENEMY_SIZE_X <= 0)
		{
			zombieFlag = false;
		}
	}

	if (skeletonFlag)
	{
		skeletonPosX -= skeletonSpeed;
		if (skeletonPosX + ENEMY_SIZE_X <= 0)
		{
			skeletonFlag = false;
		}
	}
}

void AitemCtl(void)
{
	//�e�̔��˗p�̃L�[��񏈗�
	arrowKeyOld = arrowKey;
	arrowKey = CheckHitKey(KEY_INPUT_SPACE);

	// �A�C�e���̍ďo������
	if (!bowFlag && !arrowFlag)
	{
		if (rand() % 1800 == 0)
		{
			bowPosX = SCREEN_SIZE_X + AITEM_SIZE_X;
			bowPosY = enemyRespawn[rand() % 3];
			bowFlag = true;
		}
	}

	if (!barrierFlag && !barrierOnFlag)
	{
		if (rand() % 1800 == 0)
		{
			barrierPosX = SCREEN_SIZE_X + AITEM_SIZE_X;
			barrierPosY = enemyRespawn[rand() % 3];
			barrierFlag = true;
		}
	}

	if (!barrierOnFlag)
	{
		barrierOnAnimCnt = 0;
		barrierOnCnt = 0;
	}

	// �A�C�e���̈ړ�����
	if (bowFlag)
	{
		bowPosX -= bowSpeed;
		if (bowPosX + AITEM_SIZE_X <= 0)
		{
			bowFlag = false;
		}
	}

	if (barrierFlag)
	{
		barrierPosX -= barrierSpeed;
		if (barrierPosX + AITEM_SIZE_X <= 0)
		{
			barrierFlag = false;
		}
	}

	if (barrierOnFlag)
	{
			barrierOnPosX = playerPosX - (BARRIER_SIZE_X - PLAYER_SIZE_X) / 2;
			barrierOnPosY = playerPosY - (BARRIER_SIZE_Y - PLAYER_SIZE_Y) / 2;
		if (barrierOnCnt / 600)
		{
			barrierOnFlag = false;
			barrierFlag = true;
			barrierOnCnt++;
		}
	}

	//�e�̔��ˏ���
	if (arrowKey && !arrowKeyOld)
	{
		if (arrowFlag && !arrowFlag2)
		{
			arrowPosX = playerPosX;
			arrowPosY = playerPosY + 32;
			arrowFlag2 = true;
			arrowFlag = false;
			PlaySoundMem(bowSound, DX_PLAYTYPE_BACK, true);
		}
	}

	//�e�̈ړ�����
	if (arrowPosX >= SCREEN_SIZE_X)
	{
		arrowFlag2 = false;
	}
	arrowPosX += arrowSpeed;


}

void BgCtl(void)
{
	// �w�i�̏���
	bgPosX1 -= bgPosX1speed;
	bgPosX2 -= bgPosX2speed;
	if (bgPosX1 + BG_SIZE_X <= 0)
	{
		bgPosX1 = bgPosX2 + BG_SIZE_X;
	}
	if (bgPosX2 + BG_SIZE_X <= 0)
	{
		bgPosX2 = bgPosX1 + BG_SIZE_X;
	}
}

void SpeedCtl(void)
{
	speedCnt++;
	if (speedCnt / 1200)
	{	
		goblinSpeed = 10;
		pumpkinSpeed = 10;
		darkpriestSpeed = 10;
		zombieSpeed = 10;
		skeletonSpeed = 10;
		bgPosX1speed = 6;
		bgPosX2speed = 6;
	}

	if (speedCnt / 2400)
	{
		goblinSpeed = 15;
		pumpkinSpeed = 15;
		darkpriestSpeed = 15;
		zombieSpeed = 15;
		skeletonSpeed = 15;
		bgPosX1speed = 7;
		bgPosX2speed = 7;
	}
}

void CheckHitObj(void)
{
	// �v���C���[�ƓG�̓����蔻��
	if (goblinFlag && playerFlag)
	{
		if (playerPosX < goblinPosX + ENEMY_SIZE_X / 2 &&
			goblinPosX < playerPosX + PLAYER_SIZE_X / 2 &&
			playerPosY < goblinPosY + ENEMY_SIZE_Y / 2 &&
			goblinPosY < playerPosY + PLAYER_SIZE_Y / 2)
		{
			playerFlag = false;
			playerLife--;
			goblinFlag = false;
			timeCnt = 0;
			PlaySoundMem(deathSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (pumpkinFlag && playerFlag)
	{
		if (playerPosX < pumpkinPosX + ENEMY_SIZE_X / 2 &&
			pumpkinPosX < playerPosX + PLAYER_SIZE_X / 2 &&
			playerPosY < pumpkinPosY + ENEMY_SIZE_Y / 2 &&
			pumpkinPosY < playerPosY + PLAYER_SIZE_Y / 2)
		{
			playerFlag = false;
			playerLife--;
			pumpkinFlag = false;
			timeCnt = 0;
			PlaySoundMem(deathSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (darkpriestFlag && playerFlag)
	{
		if (playerPosX < darkpriestPosX + ENEMY_SIZE_X / 2 &&
			darkpriestPosX < playerPosX + PLAYER_SIZE_X / 2 &&
			playerPosY < darkpriestPosY + ENEMY_SIZE_Y / 2 &&
			darkpriestPosY < playerPosY + PLAYER_SIZE_Y / 2)
		{
			playerFlag = false;
			playerLife--;
			darkpriestFlag = false;
			timeCnt = 0;
			PlaySoundMem(deathSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (zombieFlag && playerFlag)
	{
		if (playerPosX < zombiePosX + ENEMY_SIZE_X / 2 &&
			zombiePosX < playerPosX + PLAYER_SIZE_X / 2 &&
			playerPosY < zombiePosY + ENEMY_SIZE_Y / 2 &&
			zombiePosY < playerPosY + PLAYER_SIZE_Y / 2)
		{
			playerFlag = false;
			playerLife--;
			zombieFlag = false;
			timeCnt = 0;
			PlaySoundMem(deathSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (skeletonFlag && playerFlag)
	{
		if (playerPosX < skeletonPosX + ENEMY_SIZE_X / 2 &&
			skeletonPosX < playerPosX + PLAYER_SIZE_X / 2 &&
			playerPosY < skeletonPosY + ENEMY_SIZE_Y / 2 &&
			skeletonPosY < playerPosY + PLAYER_SIZE_Y / 2)
		{
			playerFlag = false;
			playerLife--;
			skeletonFlag = false;
			timeCnt = 0;
			PlaySoundMem(deathSound, DX_PLAYTYPE_BACK, true);
		}
	}

	// ��ƓG�̓����蔻��
	if (goblinFlag)
	{
		if (arrowPosX < goblinPosX + ENEMY_SIZE_X &&
			goblinPosX < arrowPosX + ARROW_SIZE_X &&
			arrowPosY < goblinPosY + ENEMY_SIZE_Y &&
			goblinPosY < arrowPosY + ARROW_SIZE_Y)
		{
			goblinFlag = false;
			effectFlag = true;
			effectPosX = goblinPosX;
			effectPosY = goblinPosY;
			PlaySoundMem(enemySound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (pumpkinFlag)
	{
		if (arrowPosX < pumpkinPosX + ENEMY_SIZE_X &&
			pumpkinPosX < arrowPosX + ARROW_SIZE_X &&
			arrowPosY < pumpkinPosY + ENEMY_SIZE_Y &&
			pumpkinPosY < arrowPosY + ARROW_SIZE_Y)
		{
			pumpkinFlag = false;
			effectFlag = true;
			effectPosX = pumpkinPosX;
			effectPosY = pumpkinPosY;
			PlaySoundMem(enemySound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (darkpriestFlag)
	{
		if (arrowPosX < darkpriestPosX + ENEMY_SIZE_X &&
			darkpriestPosX < arrowPosX + ARROW_SIZE_X &&
			arrowPosY < darkpriestPosY + ENEMY_SIZE_Y &&
			darkpriestPosY < arrowPosY + ARROW_SIZE_Y)
		{
			darkpriestFlag = false;
			effectFlag = true;
			effectPosX = darkpriestPosX;
			effectPosY = darkpriestPosY;
			PlaySoundMem(enemySound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (zombieFlag)
	{
		if (arrowPosX < zombiePosX + ENEMY_SIZE_X &&
			zombiePosX < arrowPosX + ARROW_SIZE_X &&
			arrowPosY < zombiePosY + ENEMY_SIZE_Y &&
			zombiePosY < arrowPosY + ARROW_SIZE_Y)
		{
			zombieFlag = false;
			effectFlag = true;
			effectPosX = zombiePosX;
			effectPosY = zombiePosY;
			PlaySoundMem(enemySound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (skeletonFlag)
	{
		if (arrowPosX < skeletonPosX + ENEMY_SIZE_X &&
			skeletonPosX < arrowPosX + ARROW_SIZE_X &&
			arrowPosY < skeletonPosY + ENEMY_SIZE_Y &&
			skeletonPosY < arrowPosY + ARROW_SIZE_Y)
		{
			skeletonFlag = false;
			effectFlag = true;
			effectPosX = skeletonPosX;
			effectPosY = skeletonPosY;
			PlaySoundMem(enemySound, DX_PLAYTYPE_BACK, true);
		}
	}

	// �|��̓����蔻��
	if (bowFlag)
	{
		if (playerPosX < bowPosX + AITEM_SIZE_X &&
			bowPosX < playerPosX + PLAYER_SIZE_X &&
			playerPosY < bowPosY + AITEM_SIZE_Y &&
			bowPosY < playerPosY + PLAYER_SIZE_Y)
		{
			bowFlag = false;
			arrowFlag = true;
			PlaySoundMem(aitemSound, DX_PLAYTYPE_BACK, true);
		}
	}

	// �o���A�̋ʂ̓����蔻��
	if (barrierFlag && !barrierOnFlag)
	{
		if (playerPosX < barrierPosX + AITEM_SIZE_X &&
			barrierPosX < playerPosX + PLAYER_SIZE_X &&
			playerPosY < barrierPosY + AITEM_SIZE_Y &&
			barrierPosY < playerPosY + PLAYER_SIZE_Y)
		{
			barrierFlag = false;
			barrierOnFlag = true;
			PlaySoundMem(aitemSound, DX_PLAYTYPE_BACK, true);
		}
	}

	// �o���A�ƓG�̓����蔻��
	if (goblinFlag && barrierOnFlag)
	{
		if (barrierOnPosX < goblinPosX + ENEMY_SIZE_X &&
			goblinPosX < barrierOnPosX + BARRIER_SIZE_X &&
			barrierOnPosY < goblinPosY + ENEMY_SIZE_Y &&
			goblinPosY < barrierOnPosY + BARRIER_SIZE_Y)
		{
			goblinFlag = false;
			barrierOnFlag = false;
			barrierOnAnimCnt = 0;
			PlaySoundMem(barrierSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (pumpkinFlag && barrierOnFlag)
	{
		if (barrierOnPosX < pumpkinPosX + ENEMY_SIZE_X &&
			pumpkinPosX < barrierOnPosX + BARRIER_SIZE_X &&
			barrierOnPosY < pumpkinPosY + ENEMY_SIZE_Y &&
			pumpkinPosY < barrierOnPosY + BARRIER_SIZE_Y)
		{
			pumpkinFlag = false;
			barrierOnFlag = false;
			barrierOnAnimCnt = 0;
			PlaySoundMem(barrierSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (darkpriestFlag && barrierOnFlag)
	{
		if (barrierOnPosX < darkpriestPosX + ENEMY_SIZE_X &&
			darkpriestPosX < barrierOnPosX + BARRIER_SIZE_X &&
			barrierOnPosY < darkpriestPosY + ENEMY_SIZE_Y &&
			darkpriestPosY < barrierOnPosY + BARRIER_SIZE_Y)
		{
			darkpriestFlag = false;
			barrierOnFlag = false;
			barrierOnAnimCnt = 0;
			PlaySoundMem(barrierSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (zombieFlag && barrierOnFlag)
	{
		if (barrierOnPosX < zombiePosX + ENEMY_SIZE_X &&
			zombiePosX < barrierOnPosX + BARRIER_SIZE_X &&
			barrierOnPosY < zombiePosY + ENEMY_SIZE_Y &&
			zombiePosY < barrierOnPosY + BARRIER_SIZE_Y)
		{
			zombieFlag = false;
			barrierOnFlag = false;
			barrierOnAnimCnt = 0;
			PlaySoundMem(barrierSound, DX_PLAYTYPE_BACK, true);
		}
	}

	if (skeletonFlag && barrierOnFlag)
	{
		if (barrierOnPosX < skeletonPosX + ENEMY_SIZE_X &&
			skeletonPosX < barrierOnPosX + BARRIER_SIZE_X &&
			barrierOnPosY < skeletonPosY + ENEMY_SIZE_Y &&
			skeletonPosY < barrierOnPosY + BARRIER_SIZE_Y)
		{
			skeletonFlag = false;
			barrierOnFlag = false;
			barrierOnAnimCnt = 0;
			PlaySoundMem(barrierSound, DX_PLAYTYPE_BACK, true);
		}
	}
}

void GameDraw(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();

	DrawGraph(bgPosX1, 120, bgImage, true);
	DrawGraph(bgPosX2, 120, bgImage, true);



	if (goblinFlag)
	{
		DrawGraph(
			goblinPosX - 32,
			goblinPosY - 58,
			shadowImage[playerDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (pumpkinFlag)
	{
		DrawGraph(
			pumpkinPosX - 32,
			pumpkinPosY - 58,
			shadowImage[playerDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (darkpriestFlag)
	{
		DrawGraph(
			darkpriestPosX - 32,
			darkpriestPosY - 58,
			shadowImage[playerDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (zombieFlag)
	{
		DrawGraph(
			zombiePosX - 32,
			zombiePosY - 58,
			shadowImage[playerDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (skeletonFlag)
	{
		DrawGraph(
			skeletonPosX - 32,
			skeletonPosY - 58,
			shadowImage[playerDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (playerFlag)
	{
		DrawGraph(
			playerPosX - 32,
			playerPosY - 58,
			shadowImage[playerDir][playerAnimData[(playerAnimCnt / 10) % 4]], true);
	}

	if (goblinFlag)
	{
		DrawGraph(
			goblinPosX,
			goblinPosY,
			goblinImage[enemyDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (pumpkinFlag)
	{
		DrawGraph(
			pumpkinPosX,
			pumpkinPosY,
			pumpkinImage[enemyDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (darkpriestFlag)
	{
		DrawGraph(
			darkpriestPosX,
			darkpriestPosY,
			darkpriestImage[enemyDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (zombieFlag)
	{
		DrawGraph(
			zombiePosX,
			zombiePosY,
			zombieImage[enemyDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (skeletonFlag)
	{
		DrawGraph(
			skeletonPosX,
			skeletonPosY,
			skeletonImage[enemyDir][enemyAnimData[(enemyAnimCnt / 10) % 4]], true);
	}

	if (effectFlag)
	{
		DrawGraph(
			effectPosX,
			effectPosY,
			effectImage[(effectAnimCnt / 2) % EFFECT_IMAGE_MAX], true);
	}


	if (effectFlag)
	{
		DrawGraph(
			effectPosX,
			effectPosY,
			effectImage[(effectAnimCnt / 2) % EFFECT_IMAGE_MAX], true);
	}

	if (effectFlag)
	{
		DrawGraph(
			effectPosX,
			effectPosY,
			effectImage[(effectAnimCnt / 2) % EFFECT_IMAGE_MAX], true);
	}

	if (effectFlag)
	{
		DrawGraph(
			effectPosX,
			effectPosY,
			effectImage[(effectAnimCnt / 2) % EFFECT_IMAGE_MAX], true);
	}

	if (effectFlag)
	{
		DrawGraph(
			effectPosX,
			effectPosY,
			effectImage[(effectAnimCnt / 2) % EFFECT_IMAGE_MAX], true);
	}

	if (effectFlag)
	{
		DrawGraph(
			effectPosX,
			effectPosY,
			effectImage[(effectAnimCnt / 2) % EFFECT_IMAGE_MAX], true);
	}

	if (playerFlag)
	{
		DrawGraph(
			playerPosX,
			playerPosY,
			playerImage[playerDir][playerAnimData[(playerAnimCnt / 10) % 4]], true);
	}



	blinkCnt++;
	if (!playerFlag)
	{
		timeCnt++;
		if ((blinkCnt / 20) % 2)
		{
			DrawGraph(
				playerPosX,
				playerPosY,
				playerImage[playerDir][playerAnimData[(playerAnimCnt / 10) % 4]], true);
		}
		if (timeCnt > 180)
		{
			playerFlag = true;
		}
	}



	for (int j = 0; j < playerLife - 1; j++)
	{
		DrawGraph(PLAYER_SIZE_X * j, 25, heartImage, true);
	}

	if (bowFlag)
	{
		DrawGraph(bowPosX + 16, bowPosY + 16, bowImage, true);
	}

	if (arrowFlag)
	{
		DrawGraph(400, 40, bowImage2, true);
	}

	if (arrowFlag2)
	{
		DrawGraph(arrowPosX, arrowPosY, arrowImage, true);
	}

	if (barrierFlag)
	{
		DrawGraph(barrierPosX + 16, barrierPosY + 16, barrierImage, true);
	}

	if (barrierOnFlag)
	{
		DrawGraph(barrierOnPosX, barrierOnPosY, barrierImage3[(barrierOnAnimCnt / 5) % BARRIER_IMAGE_MAX], true);
		barrierOnAnimCnt++;
	}

	if (barrierOnFlag)
	{
		DrawGraph(500, 30, barrierImage2, true);
	}

	blinkCnt++;
	playerAnimCnt++;
	enemyAnimCnt++;
	effectAnimCnt++;

	DrawTexts();
	ScreenFlip();												//�o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�̓���ւ�
}

void DrawTexts(void)
{	
	DrawString(0, 0, "�k�h�e�d", 0xffffff);
	DrawString(400, 0, "�A�C�e��", 0xffffff);
	DrawString(200, 0, "�X�R�A", 0xffffff);
	DrawFormatString(200, 60, 0xffffff, "%dm", scrCnt[SCR_PL1]);
}

void AddScr(void)
{
	if (bgPosX1speed == 4)
	{
		Scr++;
		scrCnt[SCR_PL1] = Scr / 6;
	}

	if (bgPosX1speed == 6)
	{
		Scr2++;
		scrCnt[SCR_PL1] = Scr2;
	}

	if (bgPosX1speed == 7)
	{
		Scr3++;
		scrCnt[SCR_PL1] = Scr3 * 6;
	}
}

void PlayerDeathProc(void)
{
	if (playerLife <= 0)
	{
		StopSoundMem(bgmSound);
		PlaySoundMem(gameoverSound, DX_PLAYTYPE_BACK, true);
		scnID = SCN_ID_GAMEOVER;
	}
}

void GetKeyState(void)
{
	zKeyFlagOld = zKeyFlag;
	zKeyFlag = CheckHitKey(KEY_INPUT_Z);

	spaceKeyFlagOld = spaceKeyFlag;
	spaceKeyFlag = CheckHitKey(KEY_INPUT_SPACE);
}

bool SysInit(void)
{
	// �V�X�e���n������
	SetWindowText("2216008_���t ��");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
	ChangeWindowMode(true);		//true:�E�B���h�E false:�t���X�N���[��
	if (DxLib_Init() == -1)
	{
		/*TRACE("DXLIB�̏��������s");*/
		return -1;
	}

	srand((unsigned int)time(NULL));

	// �摜�̓ǂݍ���
	titleImage = LoadGraph("Resource/image/titlelogo.png");
	if (titleImage == -1)
	{
		TRACE("title.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/hero.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[0][0]) == -1)
	{
		TRACE("hero.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/goblin.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &goblinImage[0][0]) == -1)
	{
		TRACE("goblin.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/pumpkinman.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &pumpkinImage[0][0]) == -1)
	{
		TRACE("pumpkinman.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/darkpriest.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &darkpriestImage[0][0]) == -1)
	{
		TRACE("darkpriest.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/zombie.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &zombieImage[0][0]) == -1)
	{
		TRACE("zombie.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/skeleton.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &skeletonImage[0][0]) == -1)
	{
		TRACE("skeleton.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/shadow.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		SHADOW_SIZE_X, SHADOW_SIZE_Y, &shadowImage[0][0]) == -1)
	{
		TRACE("shadow.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/barrier3.png",
		BARRIER_IMAGE_MAX,
		BARRIER_IMAGE_X, BARRIER_IMAGE_Y,
		BARRIER_SIZE_X, BARRIER_SIZE_Y,
		&barrierImage3[0]) == -1)
	{
		TRACE("barrier3.png�̓ǂݍ��ݎ��s\n");
	}

	if (LoadDivGraph("Resource/image/effect.png",
		EFFECT_IMAGE_MAX,
		EFFECT_IMAGE_X, EFFECT_IMAGE_Y,
		EFFECT_SIZE_X, EFFECT_SIZE_Y,
		&effectImage[0]) == -1)
	{
		TRACE("effect.png�̓ǂݍ��ݎ��s\n");
	}

	userGuideImage = LoadGraph("Resource/image/userguide.png");
	if (userGuideImage == -1)
	{
		TRACE("userguide.png�̓ǂݍ��ݎ��s\n");
	}

	bgImage = LoadGraph("Resource/image/bg.png");
	if (bgImage == -1)
	{
		TRACE("bg.png�̓ǂݍ��ݎ��s\n");
	}

	gameOverImage = LoadGraph("Resource/image/gameover.png");
	if (gameOverImage == -1)
	{
		TRACE("gameover.png�̓ǂݍ��ݎ��s\n");
	}

	heartImage = LoadGraph("Resource/image/heart.png");
	if (heartImage == -1)
	{
		TRACE("heart.png�̓ǂݍ��ݎ��s\n");
	}

	bowImage = LoadGraph("Resource/image/bow.png");
	if (bowImage == -1)
	{
		TRACE("bow.png�̓ǂݍ��ݎ��s\n");
	}

	arrowImage = LoadGraph("Resource/image/arrow.png");
	if (arrowImage == -1)
	{
		TRACE("arrow.png�̓ǂݍ��ݎ��s\n");
	}

	bowImage2 = LoadGraph("Resource/image/bow2.png");
	if(bowImage2 == -1)
	{
		TRACE("bow2.png�̓ǂݍ��ݎ��s\n");
	}

	barrierImage = LoadGraph("Resource/image/barrier.png");
	if (barrierImage == -1)
	{
		TRACE("barrier.png�̓ǂݍ��ݎ��s\n");
	}

	barrierImage2 = LoadGraph("Resource/image/barrier2.png");
	if (barrierImage2 == -1)
	{
		TRACE("barrier2.png�̓ǂݍ��ݎ��s\n");
	}

	titleSound = LoadSoundMem("Resource/music/title.ogg");
	if (titleSound == -1)
	{
		return false;
	}

	bgmSound = LoadSoundMem("Resource/music/bgm.ogg");
	if (bgmSound == -1)
	{
		return false;
	}

	gameoverSound = LoadSoundMem("Resource/music/gameover.ogg");
	if (gameoverSound == -1)
	{
		return false;
	}

	bowSound = LoadSoundMem("Resource/music/bow.ogg");
	if (bowSound == -1)
	{
		return false;
	}

	enemySound = LoadSoundMem("Resource/music/enemy.ogg");
	if (enemySound == -1)
	{
		return false;
	}

	deathSound = LoadSoundMem("Resource/music/death.ogg");
	if (deathSound == -1)
	{
		return false;
	}

	barrierSound = LoadSoundMem("Resource/music/barrier.ogg");
	if (barrierSound == -1)
	{
		return false;
	}

	aitemSound = LoadSoundMem("Resource/music/aitem.ogg");
	if (aitemSound == -1)
	{
		return false;
	}
}

bool GameInit(void)
{
	// �v���C���[�̏�����
	playerPosX = 100;									// X���W
	playerPosY = 396;									// Y���W
	playerSpeed = 86;									// �ړ���
	playerAnimCnt = 0;									// �A�j���[�V�����J�E���^�[
	playerDir = DIR_RIGHT;								// ����
	playerAnimData[0] = 0;
	playerAnimData[1] = 1;
	playerAnimData[2] = 2;
	playerAnimData[3] = 1;
	playerFlag = true;									// ���
	playerFlag2 = false;									// ���
	playerLife = 3;										// ���C�t
	playerUpKey = 0;									// ������L�[�̏��
	playerUpKeyOld = 0;									// ������L�[�̏��(1�t���[���O)
	playerDownKey = 0;									// �������L�[�̏��
	playerDownKeyOld = 0;								// �������L�[�̏��(1�t���[���O)

	// �G�̏�����
	enemyAnimCnt = 0;									// �A�j���[�V�����J�E���^�[
	enemyDir = DIR_LEFT;								// ����
	enemyAnimData[0] = 0;
	enemyAnimData[1] = 1;
	enemyAnimData[2] = 2;
	enemyAnimData[3] = 1;

	goblinPosX = 800;										// X���W
	goblinPosY = 600;									// Y���W
	goblinSpeed = 5;									// �ړ���
	goblinFlag = true;									// ���

	pumpkinPosX = 800;									// X���W
	pumpkinPosY = 600;									// Y���W
	pumpkinSpeed = 5;									// �ړ���
	pumpkinFlag = true;									// ���

	darkpriestPosX = 800;									// X���W
	darkpriestPosY = 600;								// Y���W
	darkpriestSpeed = 5;								// �ړ���
	darkpriestFlag = true;								// ���

	zombiePosX = 800;										// X���W
	zombiePosY = 600;									// Y���W
	zombieSpeed = 5;									// �ړ���
	zombieFlag = true;									// ���


	skeletonPosX = 800;									// X���W
	skeletonPosY = 600;									// Y���W
	skeletonSpeed = 5;									// �ړ���
	skeletonFlag = true;								// ���

	enemyRespawn[0] = PLAYER_STANDARD - playerSpeed;	// 1�{�ڂ̃��C���̍��W
	enemyRespawn[1] = PLAYER_STANDARD;					// 2�{�ڂ̃��C���̍��W
	enemyRespawn[2] = PLAYER_STANDARD + playerSpeed;	// 3�{�ڂ̃��C���̍��W

	// �A�C�e���̏�����
	bowPosX = 800;									// X���W
	bowPosY = 600;									// Y���W
	bowSpeed = 5;									// �ړ���
	bowFlag = true;									// ���

	arrowPosX = 0;
	arrowPosY = 0;
	arrowSpeed = 10;
	arrowFlag = false;
	arrowFlag2 = false;
	arrowKey = 0;
	arrowKeyOld = 0;

	barrierPosX = 800;									// X���W
	barrierPosY = 600;									// Y���W
	barrierSpeed = 5;									// �ړ���
	barrierFlag = true;									// ���

	barrierOnPosX = 800;
	barrierOnPosY = 600;
	barrierOnAnimCnt = BARRIER_IMAGE_MAX * 2;
	barrierOnFlag = false;


	// �w�i�̏�����
	bgPosX1 = 0;										// �P���ڂ�X���W
	bgPosX2 = bgPosX1 + BG_SIZE_X;						// �Q���ڂ�Y���W
	bgPosX1speed = 4;									// �P���ڂ̃X�s�[�h
	bgPosX2speed = 4;									// �Q���ڂ̃X�s�[�h
	speedCnt = 0;										// �X�s�[�h�̃J�E���^�[

	Scr = 0;
	Scr2 = 199;
	Scr3 = 233;

	effectPosX = 0;
	effectPosY = 0;
	effectAnimCnt = 0;
	effectFlag = false;
	return true;
}