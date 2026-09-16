#pragma once

#include <vector>
#include <string>
#include <stack>
#include <glm/glm.hpp>

// Represents a single 3D vertex sent to the GPU
struct Vertex {
    glm::vec3 position;
    glm::vec3 color;
};

// Tracks the current state of the turtle during L-System evaluation
struct TurtleState {
    glm::vec3 position{0.0f, 0.0f, 0.0f};
    glm::vec3 direction{0.0f, 1.0f, 0.0f}; // Initial orientation (facing up)
    float stepLength = 0.2f;
};

class PlantGenerator {
public:
    // Converts an L-System string into a list of 3D line vertices
    static std::vector<Vertex> generateMesh(const std::string& lsystem_str, float angle);
};