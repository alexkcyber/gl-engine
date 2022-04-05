#include "../../include/lights/dirlight.hpp"

DirLight::DirLight() {
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    direction = glm::vec3(0.0f, 0.0f, -1.0f);
    ambient = glm::vec3(0.2f, 0.2f, 0.2f); // Ambient color
    diffuse = glm::vec3(1.0f, 1.0f, 1.0f); // Diffuse color
    specular = glm::vec3(0.5f, 0.5f, 0.5f); // Specular color
}
