/*
 * Copyright (c) 2026 MidnightHammer-code
 * This source code is licensed under the GPL 3.0 license
 * LICENSE file in the root directory of this source tree.
 */

#version 450

// 1. Add the push constant block. 
// This must match the size of the data you send in HammerMesh::bindAndDraw
layout(push_constant) uniform MeshData {
    vec3 globalPosition;
} push;

layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;

void main() {
    // 2. Apply the global position.
    // Adding push.globalPosition to inPosition moves the vertex in world space.
    vec3 worldPos = inPosition + push.globalPosition;

    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(worldPos, 1.0);
    
    fragColor = inColor;
    fragTexCoord = inTexCoord;
}