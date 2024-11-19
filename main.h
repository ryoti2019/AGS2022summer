#pragma once

enum SCN_ID {
	SCN_ID_TITLE,
	SCN_ID_USERGUIDE,
	SCN_ID_GAME,
	SCN_ID_GAMEOVER,
	SCN_ID_MAX
};

enum SCR {
	SCR_PL1,
	SCR_HIGH,
	SCR_MAX
};
#define SCREEN_SIZE_X 800		// ��ʂ̉��T�C�Y
#define SCREEN_SIZE_Y 600		// ��ʂ̏c�T�C�Y

#define BG_SIZE_X 1440			// �w�i�̉��T�C�Y

#define PLAYER_SIZE_X 64		// ���@�̉��T�C�Y
#define PLAYER_SIZE_Y 64		// ���@�̏c�T�C�Y
#define PLAYER_STANDARD 396		// ���@��Y���W�̊�_

#define ENEMY_SIZE_X 64			// �G�̉��T�C�Y
#define ENEMY_SIZE_Y 64			// �G�̏c�T�C�Y

#define AITEM_SIZE_X 32			// �A�C�e���̉��T�C�Y
#define AITEM_SIZE_Y 32			// �A�C�e���̏c�T�C�Y
#define ARROW_SIZE_X 64			// ��̉��T�C�Y
#define ARROW_SIZE_Y 15			// ��̏c�T�C�Y

#define SHADOW_SIZE_X 128		// �e�̉��T�C�Y
#define SHADOW_SIZE_Y 128		// �e�̏c�T�C�Y

#define ANIM_MAX 3				// �A�j���[�V��������
#define DIR_MAX 4				// �L�����̌�������


#define BARRIER_SIZE_X 90		// �o���A�̉��T�C�Y
#define BARRIER_SIZE_Y 90		// �o���A�̏c�T�C�Y
#define BARRIER_IMAGE_X 5		// �o���A�̃C���[�W�̉��̐�
#define BARRIER_IMAGE_Y 2		// �o���A�̃C���[�W�̏c�̐�
#define BARRIER_IMAGE_MAX (BARRIER_IMAGE_X*BARRIER_IMAGE_Y)			// �o���A�̃C���[�W�̍ő吔

#define EFFECT_SIZE_X 128		// �G�t�F�N�g�̉��T�C�Y
#define EFFECT_SIZE_Y 128		// �G�t�F�N�g�̏c�T�C�Y
#define EFFECT_IMAGE_X 5		// �G�t�F�N�g�̃C���[�W�̉��T�C�Y
#define EFFECT_IMAGE_Y 2		// �G�t�F�N�g�̃C���[�W�̏c�T�C�Y
#define EFFECT_IMAGE_MAX (EFFECT_IMAGE_X * EFFECT_IMAGE_Y)			// �G�t�F�N�g�̃C���[�W�̍ő吔

#define DIR_DOWN 0
#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 3

bool SysInit(void);				// �V�X�e���n�̏�����
bool GameInit(void);			// �Q�[���n�̏�����
void GetKeyState(void);			// 
void TitleScene(void);			// 
void TitleDraw(void);			// 
void UserGuideScene(void);		// 
void UserGuideDraw(void);		// 
void GameScene(void);			// 
void GameDraw(void);			// 
void GameOverScene(void);		// 
void GameOverDraw(void);		// 
void DrawTexts(void);			// 
void PlayerCtl(void);			// 
void EnemyCtl(void);			// 
void AitemCtl(void);			// 
void BgCtl(void);				// 
void SpeedCtl(void);			// 
void CheckHitObj(void);			// 
void AddScr(void);				// 
void PlayerDeathProc(void);		// 