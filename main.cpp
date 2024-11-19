#include <DxLib.h>
#include "main.h"
#include "_debug/_DebugConOut.h"
#include "_debug/_DebugDispOut.h"

// プレイヤー関連
int playerImage[DIR_MAX][ANIM_MAX];		// グラフィックハンドル
int shadowImage[DIR_MAX][ANIM_MAX];		// グラフィックハンドル
int playerPosX;							// X座標
int playerPosY;							// Y座標
int playerSpeed;						// 移動量
int playerAnimCnt;						// アニメーションカウンター
int playerAnimData[4];					// アニメーションの再生番号
int playerDir;							// 向き
bool playerFlag;						// 状態
bool playerFlag2;
int playerLife;							// プレイヤーのライフ
int playerUpKey;						// 移動するキーの状態
int playerUpKeyOld;						// 移動するキーの状態(1フレーム前)
int playerDownKey;						// 移動するキーの状態
int playerDownKeyOld;					// 移動するキーの状態(1フレーム前)
int heartImage;

// 敵関連
int enemyAnimCnt;						// アニメーションカウンター
int enemyAnimData[4];					// アニメーションの再生番号
int enemyDir;							// 向き


int goblinImage[DIR_MAX][ANIM_MAX];		// グラフィックハンドル
int goblinPosX;							// X座標
int goblinPosY;							// Y座標
int goblinSpeed;						// 移動量
bool goblinFlag;						// 状態

int pumpkinImage[DIR_MAX][ANIM_MAX];	// グラフィックハンドル
int pumpkinPosX;						// X座標
int pumpkinPosY;						// Y座標
int pumpkinSpeed;						// 移動量
bool pumpkinFlag;						// 状態

int darkpriestImage[DIR_MAX][ANIM_MAX];	// グラフィックハンドル
int darkpriestPosX;						// X座標
int darkpriestPosY;						// Y座標
int darkpriestSpeed;					// 移動量
bool darkpriestFlag;					// 状態

int zombieImage[DIR_MAX][ANIM_MAX];		// グラフィックハンドル
int zombiePosX;							// X座標
int zombiePosY;							// Y座標
int zombieSpeed;						// 移動量
bool zombieFlag;						// 状態

int skeletonImage[DIR_MAX][ANIM_MAX];	// グラフィックハンドル
int skeletonPosX;						// X座標
int skeletonPosY;						// Y座標
int skeletonSpeed;						// 移動量
bool skeletonFlag;						// 状態

int enemyRespawn[3];					// 敵のリスポーン位置

// アイテム関連

int bowImage;							// グラフィックハンドル
int bowImage2;							// グラフィックハンドル
int bowPosX;							// X座標
int bowPosY;							// Y座標
int bowSpeed;							// 移動速度
bool bowFlag;							// 状態

int arrowImage;							// グラフィックハンドル
int arrowPosX;							// X座標
int arrowPosY;							// Y座標
int arrowSpeed;							// 移動速度
bool arrowFlag;							// 状態
bool arrowFlag2;						// 状態
int arrowKey;							// 弾を撃つキーの状態
int arrowKeyOld;						// 弾を撃つキーの状態(1フレーム前)

int barrierImage;						// グラフィックハンドル
int barrierImage2;						// グラフィックハンドル
int barrierPosX;						// X座標
int barrierPosY;						// Y座標
int barrierSpeed;						// 移動速度
bool barrierFlag;						// 状態

int barrierOnImage[BARRIER_IMAGE_MAX];	// グラフィックハンドル
int barrierImage3[BARRIER_IMAGE_MAX];	// グラフィックハンドル
int barrierOnAnimCnt;					// アニメーションカウンター
int barrierOnCnt;						// 時間のカウンター
int barrierOnPosX;						// X座標
int barrierOnPosY;						// Y座標
int barrierOnFlag;						// 状態

// 背景関連
int bgImage;							// グラフィックハンドル
int bgPosX1;							// 1枚目の座標
int bgPosX2;							// 2枚目の座標
int bgPosX1speed;						// 1枚目のスピード
int bgPosX2speed;						// 2枚目のスピード

// 音楽関連
int titleSound;
int bgmSound;
int gameoverSound;
int bowSound;
int enemySound;
int deathSound;
int barrierSound;
int aitemSound;

// その他
SCN_ID scnID;							// シーン管理用
int titleImage;							// タイトル画面のグラフィックハンドル
int userGuideImage;						// 操作説明のグラフィックハンドル
int gameOverImage;						// ゲームオーバー画面のグラフィックハンドル
bool zKeyFlag;							// Zキーの押下フラグ
bool zKeyFlagOld;						// Zキーの押下フラグ(1フレーム前)
bool spaceKeyFlag;						// SPACEキーの押下フラグ
bool spaceKeyFlagOld;					// SPACEキーの押下フラグ(1フレーム前)
int blinkCnt;							// 明滅用カウンター
int speedCnt;							// スピードのカウンター
int scrCnt[SCR_MAX];					// ハイスコア用
int Scr;								// スコア加算1
int Scr2;								// スコア加算2
int Scr3;								// スコア加算3
int count;
int timeCnt;
int effectImage[EFFECT_IMAGE_MAX];
int effectPosX;
int effectPosY;
int effectAnimCnt;						// アニメーションカウンター
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
			//シーンID異常
			TRACE("シーンIDが異常\n");
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
	int titleSizeX = GetDrawStringWidth("ＰＬＥＡＳＥ　'Ｚ'　ＫＥＹ", 13);
	blinkCnt++;
	if ((blinkCnt / 30) % 2)
	{
		DrawString(((600 - titleSizeX) / 2), 350, "ＰＬＥＡＳＥ　'Ｚ'　ＫＥＹ", 0x000000);
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
	int userguideSizeX = GetDrawStringWidth("ＰＬＥＡＳＥ　'ＳＰＡＣＥ'　ＫＥＹ", 17);
	blinkCnt++;
	if ((blinkCnt / 30) % 2)
	{
		DrawString(((600 - userguideSizeX) / 2), 500, "ＰＬＥＡＳＥ　'ＳＰＡＣＥ'　ＫＥＹ", 0xffffff);
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
		DrawString(275, 350, "コンティニュー？", 0xffffff);
		DrawString(250, 380, "'ＳＰＡＣＥ'ＫＥＹ", 0xffffff);
	}
	DrawFormatString(275, 300, 0xffff00, "ＳＣＯＲＥ");
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


	// プレイヤーの移動処理
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
	// 敵の再出現処理
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

	// 敵の移動処理
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
	//弾の発射用のキー情報処理
	arrowKeyOld = arrowKey;
	arrowKey = CheckHitKey(KEY_INPUT_SPACE);

	// アイテムの再出現処理
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

	// アイテムの移動処理
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

	//弾の発射処理
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

	//弾の移動処理
	if (arrowPosX >= SCREEN_SIZE_X)
	{
		arrowFlag2 = false;
	}
	arrowPosX += arrowSpeed;


}

void BgCtl(void)
{
	// 背景の処理
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
	// プレイヤーと敵の当たり判定
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

	// 矢と敵の当たり判定
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

	// 弓矢の当たり判定
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

	// バリアの玉の当たり判定
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

	// バリアと敵の当たり判定
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
	ScreenFlip();												//バックバッファとフロントバッファの入れ替え
}

void DrawTexts(void)
{	
	DrawString(0, 0, "ＬＩＦＥ", 0xffffff);
	DrawString(400, 0, "アイテム", 0xffffff);
	DrawString(200, 0, "スコア", 0xffffff);
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
	// システム系初期化
	SetWindowText("2216008_寺師 遼");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);
	ChangeWindowMode(true);		//true:ウィンドウ false:フルスクリーン
	if (DxLib_Init() == -1)
	{
		/*TRACE("DXLIBの初期化失敗");*/
		return -1;
	}

	srand((unsigned int)time(NULL));

	// 画像の読み込み
	titleImage = LoadGraph("Resource/image/titlelogo.png");
	if (titleImage == -1)
	{
		TRACE("title.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/hero.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		PLAYER_SIZE_X, PLAYER_SIZE_Y, &playerImage[0][0]) == -1)
	{
		TRACE("hero.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/goblin.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &goblinImage[0][0]) == -1)
	{
		TRACE("goblin.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/pumpkinman.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &pumpkinImage[0][0]) == -1)
	{
		TRACE("pumpkinman.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/darkpriest.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &darkpriestImage[0][0]) == -1)
	{
		TRACE("darkpriest.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/zombie.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &zombieImage[0][0]) == -1)
	{
		TRACE("zombie.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/skeleton.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		ENEMY_SIZE_X, ENEMY_SIZE_Y, &skeletonImage[0][0]) == -1)
	{
		TRACE("skeleton.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/shadow.png",
		ANIM_MAX * DIR_MAX,
		ANIM_MAX, DIR_MAX,
		SHADOW_SIZE_X, SHADOW_SIZE_Y, &shadowImage[0][0]) == -1)
	{
		TRACE("shadow.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/barrier3.png",
		BARRIER_IMAGE_MAX,
		BARRIER_IMAGE_X, BARRIER_IMAGE_Y,
		BARRIER_SIZE_X, BARRIER_SIZE_Y,
		&barrierImage3[0]) == -1)
	{
		TRACE("barrier3.pngの読み込み失敗\n");
	}

	if (LoadDivGraph("Resource/image/effect.png",
		EFFECT_IMAGE_MAX,
		EFFECT_IMAGE_X, EFFECT_IMAGE_Y,
		EFFECT_SIZE_X, EFFECT_SIZE_Y,
		&effectImage[0]) == -1)
	{
		TRACE("effect.pngの読み込み失敗\n");
	}

	userGuideImage = LoadGraph("Resource/image/userguide.png");
	if (userGuideImage == -1)
	{
		TRACE("userguide.pngの読み込み失敗\n");
	}

	bgImage = LoadGraph("Resource/image/bg.png");
	if (bgImage == -1)
	{
		TRACE("bg.pngの読み込み失敗\n");
	}

	gameOverImage = LoadGraph("Resource/image/gameover.png");
	if (gameOverImage == -1)
	{
		TRACE("gameover.pngの読み込み失敗\n");
	}

	heartImage = LoadGraph("Resource/image/heart.png");
	if (heartImage == -1)
	{
		TRACE("heart.pngの読み込み失敗\n");
	}

	bowImage = LoadGraph("Resource/image/bow.png");
	if (bowImage == -1)
	{
		TRACE("bow.pngの読み込み失敗\n");
	}

	arrowImage = LoadGraph("Resource/image/arrow.png");
	if (arrowImage == -1)
	{
		TRACE("arrow.pngの読み込み失敗\n");
	}

	bowImage2 = LoadGraph("Resource/image/bow2.png");
	if(bowImage2 == -1)
	{
		TRACE("bow2.pngの読み込み失敗\n");
	}

	barrierImage = LoadGraph("Resource/image/barrier.png");
	if (barrierImage == -1)
	{
		TRACE("barrier.pngの読み込み失敗\n");
	}

	barrierImage2 = LoadGraph("Resource/image/barrier2.png");
	if (barrierImage2 == -1)
	{
		TRACE("barrier2.pngの読み込み失敗\n");
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
	// プレイヤーの初期化
	playerPosX = 100;									// X座標
	playerPosY = 396;									// Y座標
	playerSpeed = 86;									// 移動量
	playerAnimCnt = 0;									// アニメーションカウンター
	playerDir = DIR_RIGHT;								// 向き
	playerAnimData[0] = 0;
	playerAnimData[1] = 1;
	playerAnimData[2] = 2;
	playerAnimData[3] = 1;
	playerFlag = true;									// 状態
	playerFlag2 = false;									// 状態
	playerLife = 3;										// ライフ
	playerUpKey = 0;									// 上方向キーの状態
	playerUpKeyOld = 0;									// 上方向キーの状態(1フレーム前)
	playerDownKey = 0;									// 下方向キーの状態
	playerDownKeyOld = 0;								// 下方向キーの状態(1フレーム前)

	// 敵の初期化
	enemyAnimCnt = 0;									// アニメーションカウンター
	enemyDir = DIR_LEFT;								// 向き
	enemyAnimData[0] = 0;
	enemyAnimData[1] = 1;
	enemyAnimData[2] = 2;
	enemyAnimData[3] = 1;

	goblinPosX = 800;										// X座標
	goblinPosY = 600;									// Y座標
	goblinSpeed = 5;									// 移動量
	goblinFlag = true;									// 状態

	pumpkinPosX = 800;									// X座標
	pumpkinPosY = 600;									// Y座標
	pumpkinSpeed = 5;									// 移動量
	pumpkinFlag = true;									// 状態

	darkpriestPosX = 800;									// X座標
	darkpriestPosY = 600;								// Y座標
	darkpriestSpeed = 5;								// 移動量
	darkpriestFlag = true;								// 状態

	zombiePosX = 800;										// X座標
	zombiePosY = 600;									// Y座標
	zombieSpeed = 5;									// 移動量
	zombieFlag = true;									// 状態


	skeletonPosX = 800;									// X座標
	skeletonPosY = 600;									// Y座標
	skeletonSpeed = 5;									// 移動量
	skeletonFlag = true;								// 状態

	enemyRespawn[0] = PLAYER_STANDARD - playerSpeed;	// 1本目のラインの座標
	enemyRespawn[1] = PLAYER_STANDARD;					// 2本目のラインの座標
	enemyRespawn[2] = PLAYER_STANDARD + playerSpeed;	// 3本目のラインの座標

	// アイテムの初期化
	bowPosX = 800;									// X座標
	bowPosY = 600;									// Y座標
	bowSpeed = 5;									// 移動量
	bowFlag = true;									// 状態

	arrowPosX = 0;
	arrowPosY = 0;
	arrowSpeed = 10;
	arrowFlag = false;
	arrowFlag2 = false;
	arrowKey = 0;
	arrowKeyOld = 0;

	barrierPosX = 800;									// X座標
	barrierPosY = 600;									// Y座標
	barrierSpeed = 5;									// 移動量
	barrierFlag = true;									// 状態

	barrierOnPosX = 800;
	barrierOnPosY = 600;
	barrierOnAnimCnt = BARRIER_IMAGE_MAX * 2;
	barrierOnFlag = false;


	// 背景の初期化
	bgPosX1 = 0;										// １枚目のX座標
	bgPosX2 = bgPosX1 + BG_SIZE_X;						// ２枚目のY座標
	bgPosX1speed = 4;									// １枚目のスピード
	bgPosX2speed = 4;									// ２枚目のスピード
	speedCnt = 0;										// スピードのカウンター

	Scr = 0;
	Scr2 = 199;
	Scr3 = 233;

	effectPosX = 0;
	effectPosY = 0;
	effectAnimCnt = 0;
	effectFlag = false;
	return true;
}