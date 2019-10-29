#include <math.h>
#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み

// 定数πの定義
#ifndef M_PI
#define M_PI 3.14159265358979
#endif

// ディスプレイリストの学習
// 星を描画する描画命令一式を、ディスプレイリストとして作成しておき
// 必要な時に、その命令を呼び出す

#define ID_DRAW_CIRCLE 1 //  glNewList 関数で使用する識別ID。値は何でも構わない

int rotateAngle; // 回転角度を記録しておく変数
double scale;
int count;

// 表示部分をこの関数で記入
void display(void) {        
	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear(GL_COLOR_BUFFER_BIT);       // 画面と奥行き情報を初期化

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glPushMatrix();
    glColor3b(1.0,0.0,0.0);
    glCallList(ID_DRAW_CIRCLE);
    glColor3b(0,0,1.0);
    glRotated(rotateAngle,0,0,1);
    glTranslated(0.3,0.3,0);
    glCallList(ID_DRAW_CIRCLE);
    glRotated(rotateAngle *2,0,0,1);
    glTranslated(0.1,0.1,0);
    glCallList(ID_DRAW_CIRCLE);
    glPopMatrix();
    glRotated(-rotateAngle *3,0,0,1);
    glTranslated(0.5,0.5,0);
    glScaled(scale,scale,0);
    glCallList(ID_DRAW_CIRCLE);


	glutSwapBuffers(); // バッファの入れ替え
}

// 一定時間ごとに呼び出される関数
void timer(int value) {
	rotateAngle++; // 回転角度の更新
    if(count <= 60){
        scale +=0.1;
    }
    if(count >60 && count<=180){
        scale -=0.05;
    }
    count++;
    if(count >180){
        count =0;
    }
    
    
	glutPostRedisplay(); // 再描画命令
	glutTimerFunc(1 , timer , 0); // 100ミリ秒後に自身を実行する
}

// ディスプレイリストを作成する
void buildDisplayList() {
	glNewList(ID_DRAW_CIRCLE,GL_COMPILE);

	glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
    double x = cos(i * 3.1415927 /180.0);
    double y = sin(i * 3.1415927 / 180.0);
    glVertex2d(x * 0.05,y * 0.05);
    }
	glEnd();               

	glEndList();

}


// メインプログラム
int main (int argc, char *argv[]) { 
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);

	glutInitWindowSize(400 , 400);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定

	glutTimerFunc(100 , timer , 0); // 100ミリ秒後に実行する関数の指定

	buildDisplayList();
	
	rotateAngle = 0;                // 変数の初期値の設定
    scale=0.5;
    count =0;

	glutMainLoop();                 // イベント待ち
}