#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み
#include <math.h>

// 表示部分をこの関数で記入
void display() {
    double x[5];
    double y[5];
    x[0] = 0.0;
    y[0] = 0.7;      
	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear (GL_COLOR_BUFFER_BIT );     // 画面消去

	glColor3d(0.0, 0.0, 1.0);   // 色指定(R,G,B)で0～1まで
	glBegin(GL_LINE_LOOP);      // 描画するものを指定
    for(int i=0;i<4;i++){
        x[i+1] = cos(72.0* M_PI/180.0) * x[i] - sin(72.0* M_PI/ 180.0) * y[i];
        y[i+1] = sin(72.0* M_PI/ 180.0) * x[i] + cos(72.0* M_PI/ 180.0) * y[i];
        glVertex2d(x[i],y[i]);
        glVertex2d(x[i+1],y[i+1]);
    }
    
	glEnd();                               

	glFlush(); // 画面出力
}

// メインプログラム
int main (int argc, char *argv[]) { 
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(400 , 400);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glutMainLoop();                 // イベント待ち
	return 0;
}