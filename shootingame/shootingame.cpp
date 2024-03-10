// shootingame.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

#include <stdio.h>
#include <conio.h> // _getch()関数
#include <stdlib.h> // rand()関数

// キャンバスのサイズ
const int canvasWidth = 50;
const int canvasHeight = 20;

// プレイヤーの座標
int playerX = 25;
int playerY = 15;

// 敵の座標
int enemyX = 25;
int enemyY = 5;

// 体力
int playerHealth = 3;
int enemyHealth = 3;

// アイテムの取得状態
int hasItem = 0;

// 弾の座標
int bulletX = -1;
int bulletY = -1;

int enemybulletX = -1;
int enemybulletY = -1;


// キャンバスを表示
void displayCanvas() {
    for (int y = 0; y <= canvasHeight; y++) {
        for (int x = 0; x <= canvasWidth; x++) {
            if (x == playerX && y == playerY) {
                printf("A"); // プレイヤー
            }
            else if (x == enemyX && y == enemyY) {
                printf("V"); // 敵
            }
            else if (x == bulletX && y == bulletY) {
                printf("|"); // 弾
            }
            else if (x == enemybulletX && y == enemybulletY) {
                printf("$"); // 敵の弾
            }
            else if (x == canvasWidth || x == 0) {
                printf("|"); // キャンバスの左右
            }
            else if (y == canvasHeight || y == 0) {
                printf("-"); // キャンバスの上下
            }
            else {
                printf(" "); // 空白
            }
        }
        printf("\n");
    }
}

// ゲームループ
void gameLoop() {
    while (1) {
        displayCanvas();

        // キー入力を待つ
        char key = _getch();

        // キーに応じてプレイヤーを移動
        switch (key) {
        case 'w':
            playerY--;
            if (playerY < 0) {
                playerY++; // プレイヤーが画面外に出たら戻す
            }
            break;
        case 's':
            playerY++;
            if (playerY > canvasHeight) {
                playerY--;
            }
            break;
        case 'a':
            playerX--;
            if (playerX < 0) {
                playerX++;
            }
            break;
        case 'd':
            playerX++;
            if (playerX > canvasWidth) {
                playerX--;
            }
            break;
        case ' ':
            // スペースキーで弾を発射
            bulletX = playerX;
            bulletY = playerY;
            break;
        case 'q':
            exit(0); // ゲーム終了
        }

        // 弾の移動
        if (bulletY >= 0) {
            bulletY--;
            if (bulletY < 0) {
                // 弾が画面外に出たらリセット
                bulletX = -1;
            }
        }

        // 敵のランダム移動
        enemyX += rand() % 3 - 1;
        if (enemyX > canvasWidth) {
            enemyX--;
        }
        else if (enemyX < 0) {
            enemyX++; // 敵が画面外に出たら戻す
        }
        enemyY += rand() % 3 - 1;
        if (enemyY > canvasHeight) {
            enemyY--;
        }
        else if (enemyY < 0) {
            enemyY++;
        }

        // 敵の弾を発射
        if (rand() % 10 == 0) {
            enemybulletX = enemyX;
            enemybulletY = enemyY + 1;
        }

        // 敵の弾の移動
        if (enemybulletY >= 0) {
            enemybulletY++;
            if (enemybulletY < 0) {
                // 弾が画面外に出たらリセット
                enemybulletX = -1;
            }
        }

        // 表示をクリア
        system("cls");

        // 弾との衝突判定
        if (enemybulletX == playerX && enemybulletY == playerY) {
            playerHealth--;
            if (playerHealth <= 0) {
                printf("You defeated! Game over!\n");// 負け
                exit(0);
            }
        }

        // 敵との衝突判定
        if (bulletX == enemyX && bulletY == enemyY) {
            enemyHealth--;
            if (enemyHealth <= 0) {
                printf("Enemy defeated! Game cleared!\n");// 勝ち
                exit(0);
            }
        }

        //体力表示
        printf("playerHealth: %d\n", playerHealth);
        printf("EnemyHealth: %d\n", enemyHealth);
    }
}

int main() {
    printf("Welcome to Shooting Game!\n");
    printf("Controls:\n");
    printf("W: Move Up\n");
    printf("S: Move Down\n");
    printf("A: Move Left\n");
    printf("D: Move Right\n");
    printf("Space: Shoot\n");
    printf("Q: Quit\n");
    printf("\nYour character: A\n");
    printf("Enemy character: V\n");

    printf("\nPush any key\n");

    char start = _getch();

    // ゲームループを開始
    gameLoop();

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
