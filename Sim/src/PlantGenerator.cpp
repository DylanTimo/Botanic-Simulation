#include "PlantGenerator.h"
#include <glm/gtc/matrix_transform.hpp>

std::vector<Vertex> PlantGenerator::generateMesh(const std::string& lsystem_str, float angle) {
    std::vector<Vertex> vertices;
    std::stack<TurtleState> stateStack;
    TurtleState currentState;

    for (char c : lsystem_str) {
        if (c == 'F') { // Advance forward and draw a segment (branch)
            glm::vec3 startPos = currentState.position;
            currentState.position += currentState.direction * currentState.stepLength;

            // Append segment start and end points
            vertices.push_back({ startPos, glm::vec3(0.4f, 0.25f, 0.1f) }); // Base branch color (brown)
            vertices.push_back({ currentState.position, glm::vec3(0.2f, 0.8f, 0.2f) }); // Tip color (green)
        }
        else if (c == '+') { // Yaw right around Z-axis
            glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
            currentState.direction = glm::vec3(rot * glm::vec4(currentState.direction, 0.0f));
        }
        else if (c == '-') { // Yaw left around Z-axis
            glm::mat4 rot = glm::rotate(glm::mat4(1.0f), glm::radians(-angle), glm::vec3(0.0f, 0.0f, 1.0f));
            currentState.direction = glm::vec3(rot * glm::vec4(currentState.direction, 0.0f));
        }
        else if (c == '[') { // Push current state onto stack (branching point)
            stateStack.push(currentState);
        }
        else if (c == ']') { // Pop state from stack (return to branch point)
            if (!stateStack.empty()) {
                currentState = stateStack.top();
                stateStack.pop();
            }
        }
    }

    return vertices;
}