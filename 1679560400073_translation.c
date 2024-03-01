#include<stdio.h>
#include <math.h>
#include <GL/glut.h>
void plot(int arr[3][4])
{
int i,j;
for(j=0;j<3;j++)
{
 glBegin(GL_LINES);
 glVertex2i(arr[0][j],arr[1][j]);
glVertex2i(arr[0][j+1],arr[1][j+1]);
 glEnd();
 
}
}
void translation(int obj[3][4], int tx,int ty)
{
 
int i,j,k,final[3][4],trans[3][3];
trans[0][0]= 1;
trans[0][1]= 0;
trans[0][2]= tx;
trans[1][0]= 0;
trans[1][1]= 1;
trans[1][2]= ty;
trans[2][0]= 0;
trans[2][1]= 0;
trans[2][2]= 1;
for(i=0;i<3;i++) 
{ 
for(j=0;j<3;j++) 
{ 
final[i][j]=0; 
for(k=0;k<3;k++) 
{ 
final[i][j]+=trans[i][k]*obj[k][j]; 
} 
} 
} 
final[0][3]=final[0][0];
 final[1][3]=final[1][0];
 final[2][3]=final[2][0]; 
printf("OBJECT MATRIX\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf(" %d ",obj[i][j]);

}
printf("\n");
}
printf("TRANSLATION MATRIX\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf(" %d ",trans[i][j]);
}
printf("\n");
}
printf("FINAL MATRIX WITH RESPECT TO ORIGIN\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf(" %d ",final[i][j]);
}
printf("\n");
}

 
 
 plot(obj);
 plot(final);
}
void user()
{
 int obj[3][4],tx,i,j,ty,trans[3][3];
printf("ENTER X COORDINATES THEN Y COORDINATES\n");
for(i=0;i<2;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&obj[i][j]);
}
}
obj[2][0]=1;
obj[2][1]=1;
obj[2][2]=1;
 obj[0][3]=obj[0][0];
 obj[1][3]=obj[1][0];
 obj[2][3]=obj[2][0];
printf("ENTER TRANSLATION FACTORS\n");
scanf("%d",&tx);
scanf("%d",&ty);
 plot(obj);
 translation(obj, tx, ty);
}
void output(void)
{
glClear(GL_COLOR_BUFFER_BIT);
user();
glFlush();
}
void Init()
{
 /* Set clear color to white */
 glClearColor(1.0,1.0,1.0,0);
 /* Set fill color to black */
 glColor3f(0.0,0.0,0.0);
 glViewport(0 , 0 , 640,480); 
 /* glMatrixMode(GL_PROJECTION); */
 /* glLoadIdentity(); */
 gluOrtho2D(0 ,640 , 0 , 480);
}
int main(int argc, char **argv)
{
 /* Initialise GLUT library */
 glutInit(&argc,argv);
 /* Set the initial display mode */
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 /* Set the initial window position and size */
 glutInitWindowPosition(0,0);
 glutInitWindowSize(640,480);
 /* Create the window with title "DDA_Line" */
 glutCreateWindow("2d transformation");
 /* Initialize drawing colors */
 Init();
 /* Call the displaying function */
 glutDisplayFunc(output);
 /* Keep displaying untill the program is closed */
 glutMainLoop();
}
