#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <iomanip>

const uint32_t WIDTH = 640;
const uint32_t HEIGHT = 480;

class HTApp {
public:
    void run() {
        initWindow();
        initVulkan();
        mainLoop();
        cleanup();
    }

private:
    GLFWwindow* window;
    VkInstance instance;
    VkPhysicalDevice pDev = VK_NULL_HANDLE;
    VkDevice dev;

    void createLogicalDev() {
        int count=0;
        VkDeviceCreateInfo deviceInfo{};
        deviceInfo.pQueueCreateInfos = &queueInfo;
        count += sizeof(*queueInfo)/sizeof(VkDeviceQueueCreateInfo);
    }

    void createInstance() {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo makeInfo{};
        makeInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        makeInfo.pApplicationInfo = &appInfo;
    }

    void pickPhysDev() {
        uint32_t devCount = 0;
        vkEnumeratePhysicalDevices(instance, &devCount, nullptr);
        
        if (!devCount) {
            throw std::runtime_error("Found no GPUs w/ Vulkan Support");
        }

        std::vector<VkPhysicalDevice> devices(devCount);
        vkEnumeratePhysicalDevices(instance, &devCount, devices.data());

        uint32_t counter = 0;
        std::cout << "+" << std::setfill('-') << std::setw(80) << "+\n";
        std::cout << "| Adapter #" << std::setfill(' ') << std::setw(30) << '|'
            << std::setw(41) << "Log.Devices |\n";
        std::cout << "|" << std::setfill('-') << std::setw(8)) << "|\n";




    }

    void initVulkan() {
        createInstance();
        pickPhysDev();
        createLogicalDev();
    }

    void initWindow() {
        glfwInit();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment #4", nullptr, nullptr);
    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }

    void cleanup() {
        glfwDestroyWindow(window);

        glfwTerminate();
    }
};

int main() {
    HTApp app;

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

