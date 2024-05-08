#include <conio.h>
#include <graphics.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
void scanFill(int x[], int y[], int edges) {
 int i, j, temp;
 for (i = 0; i < edges; i++) {
 for (j = i + 1; j < edges; j++) {
 if (y[i] > y[j]) {
 temp = y[i];
 y[i] = y[j];
 y[j] = temp;
 temp = x[i];
 x[i] = x[j];
 x[j] = temp;
 }
 }
 }
 for (int i = 0; i < edges - 1; i++) {
 if (y[i] == y[i + 1]) {
 if (x[i] > x[i + 1]) {
 temp = y[i];
 y[i] = y[i + 1];
 y[i + 1] = temp;
 temp = x[i];
 x[i] = x[i + 1];
 x[i + 1] = temp;
 }
 }
 }
 for (int i = 0; i < edges; i++) {
 if (y[i] != y[i + 1]) {
 for (int j = y[i]; j < y[i + 1]; j++) {
 int x1 = x[i] + ((x[i + 1] - x[i]) * (j - y[i])) / (y[i + 1] - y[i]);
 line(x1, j, x[i + 1], j);
 }
 }
 }
}
int main() {
 int gd = DETECT, gm, n;
 int x[20], y[20];
 initgraph(&gd, &gm, "");
 cout << "Enter the number of edges of the polygon: ";
 cin >> n;
 cout << "Enter the coordinates of polygon: ";
 for (int i = 0; i < n; i++) {
 cin >> x[i] >> y[i];
 }
 x[n] = x[0];
 y[n] = y[0];
 scanFill(x, y, n);
 getch();
 closegraph();
 return 0;
}
