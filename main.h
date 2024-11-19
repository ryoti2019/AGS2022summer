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
#define SCREEN_SIZE_X 800		// 画面の横サイズ
#define SCREEN_SIZE_Y 600		// 画面の縦サイズ

#define BG_SIZE_X 1440			// 背景の横サイズ

#define PLAYER_SIZE_X 64		// 自機の横サイズ
#define PLAYER_SIZE_Y 64		// 自機の縦サイズ
#define PLAYER_STANDARD 396		// 自機のY座標の基準点

#define ENEMY_SIZE_X 64			// 敵の横サイズ
#define ENEMY_SIZE_Y 64			// 敵の縦サイズ

#define AITEM_SIZE_X 32			// アイテムの横サイズ
#define AITEM_SIZE_Y 32			// アイテムの縦サイズ
#define ARROW_SIZE_X 64			// 矢の横サイズ
#define ARROW_SIZE_Y 15			// 矢の縦サイズ

#define SHADOW_SIZE_X 128		// 影の横サイズ
#define SHADOW_SIZE_Y 128		// 影の縦サイズ

#define ANIM_MAX 3				// アニメーション総数
#define DIR_MAX 4				// キャラの向き総数


#define BARRIER_SIZE_X 90		// バリアの横サイズ
#define BARRIER_SIZE_Y 90		// バリアの縦サイズ
#define BARRIER_IMAGE_X 5		// バリアのイメージの横の数
#define BARRIER_IMAGE_Y 2		// バリアのイメージの縦の数
#define BARRIER_IMAGE_MAX (BARRIER_IMAGE_X*BARRIER_IMAGE_Y)			// バリアのイメージの最大数

#define EFFECT_SIZE_X 128		// エフェクトの横サイズ
#define EFFECT_SIZE_Y 128		// エフェクトの縦サイズ
#define EFFECT_IMAGE_X 5		// エフェクトのイメージの横サイズ
#define EFFECT_IMAGE_Y 2		// エフェクトのイメージの縦サイズ
#define EFFECT_IMAGE_MAX (EFFECT_IMAGE_X * EFFECT_IMAGE_Y)			// エフェクトのイメージの最大数

#define DIR_DOWN 0
#define DIR_LEFT 1
#define DIR_RIGHT 2
#define DIR_UP 3

bool SysInit(void);				// システム系の初期化
bool GameInit(void);			// ゲーム系の初期化
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