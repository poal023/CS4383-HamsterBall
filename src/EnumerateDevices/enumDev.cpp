/*#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <vector>
#include <iostream>
#include <iomanip>

const uint32_t WIDTH = 640;
const uint32_t HEIGHT = 480;

class HTApp{
	public:
		void run(){
			initWindow();
			initVulkan();
			mainLoop();
			cleanup();
		}

	private:
		GLFWwindow* window;
		VkInstance instance;

		void initWindow(){
			glfwInit();

			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

			window = glfwCreateWindow(WIDTH, HEIGHT, "Assignment #4 - Enum Adapters", nullptr, nullptr);
		}
		
		void makeInstance(){

			VkApplicationInfo appInfo{};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pApplicationName = "Enum Adapters";
			appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
			appInfo.pEngineName = "No Engine";
			appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
			appInfo.apiVersion = VK_API_VERSION_1_0;
			
			VkInstanceCreateInfo makeInfo{};
			makeInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			makeInfo.pApplicationInfo = &appInfo;

			uint32_t glfwExtCount = 0;
			const char** glfwExts;

			glfwExts = glfwGetRequiredInstanceExtensions(&glfwExtCount);

			makeInfo.enabledExtensionCount = glfwExtCount;
			makeInfo.ppEnabledExtensionNames = glfwExts;

			makeInfo.enabledLayerCount = 0;

			VkResult result = vkCreateInstance(&makeInfo, nullptr, &instance);


			if(result != VK_SUCCESS){
				throw std::runtime_error("Failed to create instance!");
			}


		}
		void initVulkan(){
			makeInstance();
			setupDebugMsgr();
			pickPhysDevice();
						
		}

		void setupDebugMsgr(){
			
		}
		void pickPhysDevice(){
			VkPhysicalDevice pDev = VK_NULL_HANDLE;
			uint32_t devCount = 0;
			vkEnumeratePhysicalDevices(instance, &devCount, nullptr);
			if(devCount == 0){
				throw std::runtime_error("failed to find GPUs w/ Vulkan Support!");
			}

			std::vector<VkPhysicalDevice> devices(devCount);
			vkEnumeratePhysicalDevices(instance, &devCount, devices.data());
			
			uint32_t counter = 1;

			std::cout << "+" << std::setfill('-') << std::setw(80) << "+\n";
			std::cout << "| Device #" << std::setfill(' ') << std::setw(15) <<  "| Dev. Name" << std::setw(25) << '|' << std::setw(31) << "Device Type |\n";
			std::cout << "|" << std::setfill('-') << std::setw(80) << "|\n";

			for(const auto& dev : devices){
				physDevChecker(dev, counter);
				counter++;	
			}
			std::cout << "+" << std::setfill('-') << std::setw(80) << "+\n";


		}

		void physDevChecker(VkPhysicalDevice dev, uint32_t counter){
			VkPhysicalDeviceProperties devProps;
			VkPhysicalDeviceFeatures devFeatures;

			vkGetPhysicalDeviceProperties(dev, &devProps);
			vkGetPhysicalDeviceFeatures(dev, &devFeatures);
			
			std::cout << "| " << counter << std::setfill(' ') << std::setw(13) << "| " << std::setw(20) << devProps.deviceName << " |" << std::setw(29);
			
			switch(devProps.deviceType){
				case(VK_PHYSICAL_DEVICE_TYPE_OTHER):
					std::cout << "Other";
					break;
				case(VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU):
					std::cout << "Integerated GPU";
					break;
				case(VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU):
					std::cout << "Discrete GPU";
					break;
				case(VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU):
					std::cout << "Virtual GPU";
					break;
				case(VK_PHYSICAL_DEVICE_TYPE_CPU):
					std::cout << "Same process as host";
					break;
			}
			std::cout << " |\n";


		}

		void mainLoop(){
			while(!glfwWindowShouldClose(window)){
				glfwPollEvents();
			}
		}

		void cleanup(){
			vkDestroyInstance(instance, nullptr);
			glfwDestroyWindow(window);
			glfwTerminate();
		}

};

int main() {
	HTApp app;
	app.run();
	return 0;
}*/
