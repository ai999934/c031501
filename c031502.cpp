#include <stdio.h>
#include <math.h>
#include "glibw32.h" // External reference http://www.asahi-net.or.jp/~uc3k-ymd/Glib32/glibw32.html

const int NUMBER = 360;
const double PI = 3.1415926535897932384626433832796;

main()
{
    int i, j;
    double t, p, x, y, z, r, R, N;
    ginit(500, 500, WHITE);
    GRAPH g;
    g.window(-PI, -PI, PI, PI);
    g.line(-PI, 0, PI, 0);
    g.line(0, PI, 0, -PI);
    g.setcolor(BLACK);
    r = 1.0;
    R = 2.0;
    i = 0;
    while(i < NUMBER)
    {
        t = i * (PI / (NUMBER / 2));
        j = 0;
        while(j < NUMBER)
        {
            p = j * (PI / (NUMBER / 2));
            x = R * cos(t) + r * cos(p) * cos(t);
            y = R * sin(t) + r * cos(p) * sin(t);
            z = r * sin(p);
            N = sqrt(x * x + y * y);  //NG?
            g.pset(N, z);
            j = j + 1;
        }
        i = i + 1;
    }
    gend();
  }
// cd c:\mingw-jp-20040217\bin
// g++ c031502.cpp libglibw32-3.a -IC:\mingw-jp-20040217\include\ -LC:\mingw-jp-2004021\lib\ -IC:\Glibw32\ -LC:\Glibw32\ -luser3
// 2 -lgdi32
// rename a.exe c031502.*
// トーラスの描画をしようとしたが、うまくいかなかった。
