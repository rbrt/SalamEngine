#pragma once
#define GLFW_INCLUDE_VULKAN

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <vulkan/vulkan.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <glad/glad.h> 
#include <glfw/glfw3.h>

#include <iostream>
#include <chrono>
#include <thread>

#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std;

class Renderer
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_LUNARG_standard_validation"
    };

    #ifdef NDEBUG
    const bool enableValidationLayers = false;
    #else
    const bool enableValidationLayers = true;
    #endif

    public:
        Renderer();
        int run();

    private:
        void initialize();
        void drawTriangle();
        void renderLoop();
        void cleanUp();
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createSurface();
        
        void createVulkanInstance();
        bool checkValidationLayerSupport();
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        vector<const char*> getRequiredExtensions();
        void setupDebugCallback();
        bool isDeviceSuitable(VkPhysicalDevice device);

        GLFWwindow* window;
        VkInstance instance;
        VkDebugUtilsMessengerEXT callback;
        
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkDevice device;
        VkPhysicalDeviceFeatures deviceFeatures = {};
        VkDeviceCreateInfo createInfo = {};

        VkQueue graphicsQueue;
        VkQueue presentQueue;

        VkSurfaceKHR surface;
        
        const char** glfwExtensions;
        std::vector<const char*> extensions;

        static VkResult createDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pCallback);
        static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT callback, const VkAllocationCallbacks* pAllocator);
        static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                            VkDebugUtilsMessageTypeFlagsEXT messageType,
                                                            const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                            void* pUserData);

        struct QueueFamilyIndices 
        {
            int graphicsFamily = -1;
            int presentFamily = -1;

            bool isComplete() 
            {
                return graphicsFamily >= 0 && presentFamily >= 0;
            }
        };
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        
        bool running;
        bool initialized;

        unsigned int vertexShader;
        unsigned int fragmentShader;
        unsigned int shaderProgram;

        const std::vector<const char*> deviceExtensions =
        {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };

        const char* vertexShaderSource = "#version 140\r\n"
            "#extension GL_ARB_explicit_attrib_location : require \n"
            "#extension GL_ARB_explicit_uniform_location : require \n"
            "in layout(location=0) vec3 aPos;"
            ""
            "void main()"
            "{"
            "	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
            "}";

        const char* fragmentShaderSource = "#version 330 core\n"
            "#extension GL_ARB_explicit_attrib_location : require \n"
            "#extension GL_ARB_explicit_uniform_location : require \n"
            "out vec4 fragColor;"
            ""
            "void main()"
            "{"
            "	fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
            "}";
};
