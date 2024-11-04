//3D transformations 

#include <graphics.h>
#include <cmath>
#include <iostream>

using namespace std;

void Translation(int tx, int ty);
void Scaling(float Sx, float Sy, float Sz);
void Rotation(int theta);

int maxx, maxy, midx, midy;

int main() {
    int gdriver = DETECT, gm;
    initgraph(&gdriver, &gm, "");

    maxx = getmaxx();
    maxy = getmaxy();
    midx = maxx / 2;
    midy = maxy / 2;

    cout << "\nPerforming Transformations with predefined values:\n";

    // Predefined values for transformations
    Translation(100, 50); // tx = 100, ty = 50
    Scaling(1.5f, 1.5f, 1.0f); // Sx = 1.5, Sy = 1.5, Sz = 1.0
    Rotation(45); // theta = 45 degrees

    getch(); // Wait for a key press to see the results
    closegraph(); // Close the graphics window
    return 0;
}

void Translation(int tx, int ty) {
    setcolor(GREEN);
    bar(midx + 50, midy - 100, midx + 60, midy - 90); // Original shape
    bar(midx + tx + 50, midy - (ty + 100), midx + tx + 60, midy - (ty + 90)); // Translated shape
    cout << "Translation performed with tx: " << tx << ", ty: " << ty << endl;
}

void Scaling(float Sx, float Sy, float Sz) {
    setcolor(RED);
    bar(midx + 50, midy - 100, midx + 60, midy - 90); // Original shape
    bar(midx + static_cast<int>(Sx * 50), midy - static_cast<int>(Sy * 100),
        midx + static_cast<int>(Sx * 60), midy - static_cast<int>(Sy * 90)); // Scaled shape
    cout << "Scaling performed with Sx: " << Sx << ", Sy: " << Sy << ", Sz: " << Sz << endl;
}

void Rotation(int theta) {
    setcolor(YELLOW);
    bar(midx + 50, midy - 100, midx + 60, midy - 90); // Original shape
    
    // Rotation calculations
    int x1 = 50 * cos(theta * M_PI / 180) - 100 * sin(theta * M_PI / 180);
    int y1 = 50 * sin(theta * M_PI / 180) + 100 * cos(theta * M_PI / 180);
    int x2 = 60 * cos(theta * M_PI / 180) - 90 * sin(theta * M_PI / 180);
    int y2 = 60 * sin(theta * M_PI / 180) + 90 * cos(theta * M_PI / 180);

    cout << "\nAfter rotation about X axis:";
    bar(midx + 50, midy - x1, midx + 60, midy - x2); // Rotated shape
    cout << "\nAfter rotation about Y axis:";
    bar(midx + x1, midy - 100, midx + x2, midy - 90); // Rotated shape
}
