#include "raylib.h"
#include <cmath>
#include <vector>

// Constants
const float pi = PI;
const float g = 10.0f;       // Gravitational acceleration
const float m = 0.2f;        // Mass of the bob
const float k = 10.0f;       // Spring constant
const float lp = 4.0f;       // Pendulum string length
const float ls = 4.0f;       // Spring rest length
const float radius = 0.4f;   // Radius of the bob and pivot points
const float dt = 0.001f;     // Time step for simulation




int main() {
    // Initialize raylib
    InitWindow(800, 600, "Spring-Mounted Pendulum Simulation");
    SetTargetFPS(1000);

    // Initial conditions
    float theta = -pi / 4.0f;   // Initial angle of the pendulum
    float thetadot = 0.0f;      // Time derivative of theta
    float thetaddot = 0.0f;     // Second-order derivative of theta
    float s = 0.6f;             // Elongation of the spring
    float sdot = 0.0f;          // Time derivative of s
    float sddot = 0.0f;         // Second-order derivative of s
    float t = 0.0f;             // Time


    while (!WindowShouldClose()) {
        // Physics calculations
        thetaddot = sin(theta) * thetadot * thetadot / cos(theta) - k * s * sin(theta) / (lp * m * cos(theta) * cos(theta));
        sddot = lp * sin(theta) * sin(theta) * thetadot * thetadot / cos(theta)
            + lp * cos(theta) * thetadot * thetadot
            + g
            - k * s * sin(theta) * sin(theta) / (m * cos(theta) * cos(theta))
            - k * s / m;

        // Update s and theta
        sdot += sddot * dt;
        s += sdot * dt;
        thetadot += thetaddot * dt;
        theta += thetadot * dt;

        // Calculate bob position
        float x = lp * sin(theta);
        float y = ls + s + lp * cos(theta);


        // Update time
        t += dt;

        // Drawing
        BeginDrawing();
        ClearBackground(GRAY);

        // Draw pivot and spring
        DrawCircle(400, 100, radius * 20, RED);
        DrawLine(400, 100, 400, 100 + (ls + s) * 50, DARKGRAY);

        // Draw pivot1 and string
        DrawCircle(400, 100 + (ls + s) * 50, radius * 20, GOLD);
        DrawLine(400, 100 + (ls + s) * 50, 400 + x * 50, 100 + (ls + s + lp * cos(theta)) * 50, DARKGRAY);

        // Draw bob
        DrawCircle(400 + x * 50, 100 + (ls + s + lp * cos(theta)) * 50, radius * 50, GREEN);


        EndDrawing();
    }

    // Cleanup
    CloseWindow();
    return 0;
}
