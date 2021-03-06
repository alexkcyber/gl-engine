#version 460 core
in vec3 Normal;
in vec3 VertPos;
in vec2 TexCoords;
uniform vec3 viewPos;

struct Material { // Our mesh's material
	sampler2D diffuse; // Color
	sampler2D specular; // Specular color
	float shininess; // How shiny
};
uniform Material material;

struct DirLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};
uniform DirLight dirLight;

out vec4 FragColor;

// Calculate the shading based on the directional light
// light is the light
// normal is the normal vector
// viewDir is the view direction
vec3 CalcDirLight(DirLight l, vec3 n, vec3 vD);

void main() {
	vec3 norm = normalize(Normal);
	vec3 viewDir = normalize(viewPos - VertPos);

	vec3 result = CalcDirLight(dirLight, norm, viewDir);

	FragColor = vec4(result, 1.0f);
}

// Calculate the shading based on the directional light
// light is the light
// normal is the normal vector
// viewDir is the view direction
vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir) {
	vec3 lightDir = normalize(-light.direction);

	float diff = max(dot(normal, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0f), material.shininess);
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
	return (ambient + diffuse + specular);
}
