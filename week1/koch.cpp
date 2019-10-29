#include<GLUT/glut.h>
#include<math.h>

void drowkoch(double initpx,double initpy,int finipx,double finipy,int n){
    double lengthx = finipx -initpx;
    double lengthy = finipy -initpy;
    double length = sqrt(lengthx * lengthx + lengthy * lengthy)/3.0;
    double secpx = initpx + (finipx - initpx) / 3.0;
    double secpy = initpy + (finipy - initpy) /3.0;
    double forpx = initpx + ((finipx - initpx) * 2.0) /3.0;
    double forpy = initpy +((finipy - finipy) * 2.0) /3.0; 
    double thipx = cos(3.1415926/3.0) * (forpx - secpx) - sin(3.1415926/3.0) * (forpy - secpy) + secpx;
    double thipy = sin(3.1415926/3.0) * (forpx - secpx) + cos(3.1415926/3.0) * (forpy - secpy) + secpy;
    if(n == 0)
    {
        glColor3b(0.0,0.0,1.0);
        glBegin(GL_LINE_STRIP);
        glVertex2d(initpx,initpy);
        glVertex2d(secpx,secpy);
        glVertex2d(thipx,thipy);
        glVertex2d(forpx,forpy) ;
        glVertex2d(finipx,finipy);
        glEnd();
        glFlush(); 
   }else//再帰を行う
    {
        
        drowkoch(initpx,initpy,secpx,secpy,n-1);
        drowkoch(secpx,secpy,thipx,thipy,n-1);
        drowkoch(thipx,thipy,forpx,forpy,n-1);
        drowkoch(forpx,forpy,finipx,finipy,n-1);
        /* drowkoch(initpx, initpy, initpx + length, initpy + length, arg, n - 1);
        arg += M_PI / 3.0;
        drowkoch(initpx, initpy, initpx + length, initpy + length, arg, n - 1);
        arg -= 2.0 * M_PI / 3.0;
        drowkoch(initpx, initpy, initpx + length, initpy + length, arg, n - 1);
        arg += M_PI / 3.0;
        drowkoch(initpx, initpy, initpx + length, initpy + length, arg, n - 1); */
    }
    
}
void display(void){
    glClearColor (1.0, 1.0, 1.0, 1.0); // 消去色指定
    glClear (GL_COLOR_BUFFER_BIT ); // 画面消去
    double firstpoint_x = -0.8;//左側描画開始座標
    double firstpoint_y = 0.0;
    double endpoint_x = 0.8;
    double endpoint_y = 0.0;
    double angle = 0.0;
    drowkoch(firstpoint_x,firstpoint_y,endpoint_x,endpoint_y,3);//n回繰り返す
}



int main(int argc,char *argv[]){
	glutInit(&argc, argv);          // ライブラリの初期化
	glutInitWindowSize(400 , 400);  // ウィンドウサイズを指定
	glutCreateWindow(argv[0]);      // ウィンドウを作成
	glutDisplayFunc(display);       // 表示関数を指定
	glutMainLoop();                 // イベント待ち
	return 0;
}