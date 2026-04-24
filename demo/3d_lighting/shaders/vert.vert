#version 450

layout(set = 0, binding = 0) uniform UniformBufferObject {
    mat4 model; // Add this back so offsets match!
    mat4 view;
    mat4 proj;
    vec4 ambientLightColor;
    vec3 lightPosition;
    vec4 lightColor;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;
layout(location = 2) out vec3 fragWorldPos; // Just the position

layout(push_constant) uniform MeshData {
    mat4 modelMatrix;
} push;

void main() {
    vec4 worldPosition = push.modelMatrix * vec4(inPosition, 1.0);
    gl_Position = ubo.proj * ubo.view * worldPosition;
    
    fragColor = inColor;
    fragTexCoord = inTexCoord;
    fragWorldPos = vec3(worldPosition);
}