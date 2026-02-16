#include "../include/QEngine/QEngine.h"
#include <iostream>
#include <vulkan/vulkan_core.h>

using namespace std;

void QEngine::runTest() {
    initWindow();
    initVulkan();
    mainLoopTest();
    cleanup();
}

void QEngine::initWindow() {

    if(cameraModeInit == 1){
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        window = glfwCreateWindow(WindowWidth, WindowHeight, "Vulkan", nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, QEngine::framebufferResizeCallback);

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwMakeContextCurrent(window);
    } else if(cameraModeInit == 0){
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

        window = glfwCreateWindow(WindowWidth, WindowHeight, "Vulkan", nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
        glfwSetFramebufferSizeCallback(window, QEngine::framebufferResizeCallback);

        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        glfwMakeContextCurrent(window);
    }
}

void QEngine::drawPassEnd(){
    vkDeviceWaitIdle(device);
}

void QEngine::mainLoopTest() {
    drawPassStart();

    while (!glfwWindowShouldClose(window)) {
        updateFrameTimeStart();

        updateCameraDefault3D();

        drawFrame();

        updateFrameTimeEnd();
    }

    drawPassEnd();
}

void QEngine::updateFrameTimeEnd(){
    auto end = std::chrono::high_resolution_clock::now();
    auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    totalFrameTime += frameDuration;

    if (currentTime - previousTime >= 1.0) {
        double averageFrameTime = totalFrameTime.count() / static_cast<double>(frameCount);

        std::cout << "FPS: " << frameCount 
                  << " | Avg Frame Time: " << averageFrameTime << " ms\n";

        frameCount = 0;
        previousTime = currentTime;
        totalFrameTime = std::chrono::milliseconds(0);
    }
}

void QEngine::drawPassStart(){
    previousTime = glfwGetTime();
    frameCount = 0;

    std::chrono::milliseconds totalFrameTime(0);

    vertexBufferSize = sizeof(Vertex) * vertices.size();
    indexBufferSize = sizeof(uint32_t) * indices.size();
}

void QEngine::updateFrameTimeStart(){
    start = std::chrono::high_resolution_clock::now();

    currentTime = glfwGetTime();
    frameCount++;
    glfwPollEvents();
}



void QEngine::uploadVerticesIndices(const std::vector<uint32_t> Indices, const std::vector<Vertex> Vertices){
    std::cout << "Sorry uploadVerticesIndices fonction is not available yet, we are working on it\n";
}

void QEngine::drawMod(int mod){
    drawModSet = mod;
}

void QEngine::setMaxVertciesIndicesSize(VkDeviceSize maxsize){
    stagingBufferSize = maxsize;
    stagingBuffer2Size = maxsize;
}