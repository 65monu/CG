#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>
// Function for finding absolute value
int abs(int n)
{
    return ((n > 0) ? n : (n * (-1)));
}
// DDA Function for Line Generation
void DDA(int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel(X, Y, GREEN); // put pixel at (X,Y)
        X += Xinc;             // increment in X at each step
        Y += Yinc;             // increment in Y at each step
        delay(100);            // for visualization of line generation at
        each step
    }
}
// Driver Program
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C://TURBOC3//BGI");
    int X0 = 20, Y0 = 20, X1 = 140, Y1 = 160;
    // Function Call
    DDA(X0, Y0, X1, Y1);
    getch();
    return 0;
}
