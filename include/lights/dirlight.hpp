#pragma once
#include <glm/glm.hpp>

class DirLight {
    public:
        DirLight();
        glm::vec3 position;
        glm::vec3 direction;
        glm::vec3 ambient; // Ambient color
        glm::vec3 diffuse; // Diffuse color
        glm::vec3 specular; // Specular color
};
