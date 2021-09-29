// disatest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
#include <iostream>
#include <omp.h>
#include <chrono>
#include <stdlib.h>

const int SIZE = 10; //or Number of Particles
int timeSteps = 10; // Number of steps to simulate

struct vec3
{
    float x;
    float y;
    float z;
};
struct particle
{
    vec3 position;
    float mass;
    vec3 velocity;

};

void initParticles(particle particles[]) //Only more efficient in size > 1million
{
#pragma omp parallel for
    for (int i = 0; i < SIZE; i++)
    {
        particles[i].mass = 10;
        particles[i].position = { 1.0,0.0,0.0 };
        particles[i].velocity = { 1.0,0.0,0.0 };
    }
}
void initParticlesSerial(particle particles[])
{
    for (int i = 0; i < SIZE; i++)
    {
        particles[i].mass = 10;
        particles[i].position = { 1.0,0.0,0.0 };
        particles[i].velocity = { 1.0,0.0,0.0 };
    }
}
void printParticles(particle particles[])
{
    for (int i = 0; i < SIZE; i++) 
    {
        std::cout << "Hello from particle " << i << ": " << particles[i].position.x << std::endl;
    }
}
void updateParticles(particle particles[]) 
{
    for (int i = 0; i < SIZE; i++) 
    {
        //Update Forces
        //Fnet will be the Sum of all forces acting upon the particle

        //Update Acceleration 
        //Acceleration is equal to Fnet / Mass

        //Update Velocity
        //Velocity is equal to previous velocity + (previous velocity

        //Update Position
        float newPositionX = particles[i].position.x + (particles[i].velocity.x * 1); //WARNING 1 is hard coded as the time difference for dumb reasons make sure to change later!!! probably to variable const dt
        particles[i].position.x = newPositionX;

        float newPositionY = particles[i].position.y + (particles[i].velocity.y * 1);//WARNING 1 is hard coded as the time difference for dumb reasons make sure to change later!!! probably to variable const dt
        particles[i].position.y = newPositionY;

        //Detect & Solve Collision

    }
}

int main()
{
    particle* particles = new particle[SIZE];

    auto start = std::chrono::high_resolution_clock::now();
    initParticlesSerial(particles);
    auto finish = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
    std::cout << "Serial: " << duration.count() << std::endl;


    //printParticles(particles);
    
    while (timeSteps != 0)
    {
        updateParticles(particles);
        std::cout << "Particle 0 Position X: " << particles[0].position.x << std::endl;
        timeSteps--;

    }


    return 0;
}


