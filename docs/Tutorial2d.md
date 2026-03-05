Welcome to the HammerEngine documentation. This tutorial will walk you through the evolution of a HammerEngine project, starting with basic 2D rendering and moving into complex 3D grids and physics-based movement.
1. Getting Started: The Basic 2D Setup

The foundation of any HammerEngine project involves configuring the engine settings, initializing Vulkan, and setting up a basic camera.
Key Concepts:

    cameraMode2dOr3d: Set to 1 for 2D (orthographic) and 0 for 3D (perspective).

    initWindow() & initVulkan(): These must be called after configuration but before mesh creation.

    HammerPipeline: Manages your shaders (.spv files).

C++

HammerEngine Engine;

// Configuration
Engine.WindowWidth = 1000;
Engine.WindowHeight = 1000;
Engine.cameraMode2dOr3d = 1; // 2D Mode
Engine.texturePath = "textures/texture.png";

Engine.initWindow();
Engine.initVulkan();

// Draw loop
Engine.drawPassStart();
while (!glfwWindowShouldClose(Engine.window)) {
    Engine.updateFrameTimeStart();
    Engine.updateCameraDefault2D();
    Engine.drawFrame();
    Engine.updateFrameTimeEnd();
}
Engine.drawPassEnd();

2. Dynamic Geometry and Movement

HammerEngine allows you to update vertex data on the fly. This is useful for moving objects that don't use standard transformations, or for procedural geometry.
Updating Buffers

By capturing a pointer to your HammerMesh, you can call updateBuffers() inside the main loop to move vertices based on user input (e.g., GLFW keys).
C++

// Inside the loop
if (glfwGetKey(Engine.window, GLFW_KEY_I) == GLFW_PRESS) { 
    player.y += 0.1f; 
    meshPtr->updateBuffers(getVertices(player), localIndices); 
}

3. Entering 3D: Cubes and Collision

When moving to 3D, you define vertices with depth (Z coordinates) and use updateCameraDefault3D().
Collision Detection

The engine provides helper structures like HammerRectCubeF for AABB (Axis-Aligned Bounding Box) collision. This is often used to toggle gravity or prevent movement through walls.
C++

// Define a cube and a camera collider
HammerRectCubeF cube{0, 0, 0, 1, 1, 1};
HammerRectCubeF cameraCollider{
    Engine.cameraPosition.x,
    Engine.cameraPosition.y - 1.0f,
    Engine.cameraPosition.z, 
    1, 1, 1
};

// Check for collision
bool isColliding = cameraCollider.HammerRectCollideCubeF(cube);

// Apply gravity based on collision
Engine.updateCameraDefaultGravety3D(isColliding);

4. Advanced: Procedural Grid Generation

For large environments, you can procedurally generate vertex and index arrays. By looping through X, Y, and Z coordinates, you can build a massive mesh of cubes in a single HammerMesh object.
The Face-by-Face Approach

To build a cube grid efficiently, define the 6 faces of a cube as a static array and offset their positions during generation.
C++

void generateCubeGrid(std::vector<Vertex>& outVertices, std::vector<uint32_t>& outIndices, int width, int height, int depth) {
    uint32_t vertexOffset = 0;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            for (int z = 0; z < depth; ++z) {
                glm::vec3 worldPos = glm::vec3((float)x, (float)y, (float)z);
                // Add 6 faces...
                // Offset vertices by worldPos...
            }
        }
    }
}