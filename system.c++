
#include <graphics.h>
#include <math.h>
#include <conio.h>


#define PI 3.14159
//distances of each planet from the Sun
int mercuryOrbit = 50;
int venusOrbit = 80;
int earthOrbit = 120;
int marsOrbit = 160;
int jupiterOrbit = 220;
int saturnOrbit = 280;
int uranusOrbit = 340;
int neptuneOrbit = 400;
int plutoOrbit = 460;


//define how fast each planet revolves around the Sun.
float mercurySpeed = 0.05f;
float venusSpeed = 0.03f;
float earthSpeed = 0.02f;
float marsSpeed = 0.01f;
float jupiterSpeed = 0.008f;
float saturnSpeed = 0.006f;
float uranusSpeed = 0.004f;
float neptuneSpeed = 0.003f;
float plutoSpeed = 0.001f;


//coordinates of a planet based on the orbit radius and the angle of rotation
void drawPlanet(int xCenter, int yCenter, int orbitRadius, float angle, int color, int size, const char* name) {
    int x = xCenter + (int)(orbitRadius * cos(angle));
    int y = yCenter + (int)(orbitRadius * sin(angle));
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    circle(x, y, size);  
    floodfill(x, y, color);
    
    // Draw planet name near the planet
    setcolor(WHITE);
    outtextxy(x + size + 5, y - size - 5, (char*)name);

}

// draws all planetary orbits (from Mercury to Pluto) around the Sun.
void drawOrbit(int xCenter, int yCenter, int orbitRadius) {
    setcolor(WHITE);
    circle(xCenter, yCenter, orbitRadius);  
}

int main() {
    // Set up a larger window size to fit all planets
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);  // For larger window
    // Resize window
    int maxWidth = 1000;
    int maxHeight = 1000;
    initwindow(maxWidth, maxHeight); 

    int sunX = getmaxx() / 2;
    int sunY = getmaxy() / 2;

    //angles represent the current position of the planet in its orbit
    float mercuryAngle = 0;
    float venusAngle = 0;
    float earthAngle = 0;
    float marsAngle = 0;
    float jupiterAngle = 0;
    float saturnAngle = 0;
    float uranusAngle = 0;
    float neptuneAngle = 0;
    float plutoAngle = 0;

    while (!kbhit()) {  
        cleardevice();  

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(sunX, sunY, 30);  // Draw the Sun
        floodfill(sunX, sunY, YELLOW);

        // Draw orbits
        drawOrbit(sunX, sunY, mercuryOrbit);
        drawOrbit(sunX, sunY, venusOrbit);
        drawOrbit(sunX, sunY, earthOrbit);
        drawOrbit(sunX, sunY, marsOrbit);
        drawOrbit(sunX, sunY, jupiterOrbit);
        drawOrbit(sunX, sunY, saturnOrbit);
        drawOrbit(sunX, sunY, uranusOrbit);
        drawOrbit(sunX, sunY, neptuneOrbit);
        drawOrbit(sunX, sunY, plutoOrbit);

        // Draw planets with their names
        drawPlanet(sunX, sunY, mercuryOrbit, mercuryAngle, LIGHTGRAY, 4, "Mercury");  // Mercury
        drawPlanet(sunX, sunY, venusOrbit, venusAngle, LIGHTCYAN, 6, "Venus");     // Venus
        drawPlanet(sunX, sunY, earthOrbit, earthAngle, BLUE, 6, "Earth");          // Earth
        drawPlanet(sunX, sunY, marsOrbit, marsAngle, RED, 5, "Mars");             // Mars
        drawPlanet(sunX, sunY, jupiterOrbit, jupiterAngle, LIGHTRED, 10, "Jupiter"); // Jupiter
        drawPlanet(sunX, sunY, saturnOrbit, saturnAngle, LIGHTRED, 9, "Saturn"); // Saturn
        drawPlanet(sunX, sunY, uranusOrbit, uranusAngle, LIGHTBLUE, 7, "Uranus");   // Uranus
        drawPlanet(sunX, sunY, neptuneOrbit, neptuneAngle, LIGHTMAGENTA, 7, "Neptune"); // Neptune
        drawPlanet(sunX, sunY, plutoOrbit, plutoAngle, WHITE, 3, "Pluto");         // Pluto

        // Update angles for each planet to rotate around the Sun
        mercuryAngle += mercurySpeed;
        venusAngle += venusSpeed;
        earthAngle += earthSpeed;
        marsAngle += marsSpeed;
        jupiterAngle += jupiterSpeed;
        saturnAngle += saturnSpeed;
        uranusAngle += uranusSpeed;
        neptuneAngle += neptuneSpeed;
        plutoAngle += plutoSpeed;

        delay(50);  // Create smooth animation
    }

    closegraph();
    return 0;
}
