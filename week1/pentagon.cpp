#include <GLUT/glut.h> // ライブラリ用ヘッダファイルの読み込み

// 表示部分をこの関数で記入
void display() {        
	glClearColor (1.0, 1.0, 1.0, 1.0);  // 消去色指定
	glClear (GL_COLOR_BUFFER_BIT );     // 画面消去

	glColor3d(0.0, 0.0, 1.0);   // 色指定(R,G,B)で0～1まで
	glBegin(GL_LINE_LOOP);      // 描画するものを指定
        glVertex2d( 0.0,  0.8);
        glVertex2d( 0.9,0.0);
        glVertex2d( 0.5, -0.8); 
        glVertex2d(-0.5, -0.8); 
        glVertex2d(-0.9,0.0);
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