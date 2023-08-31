#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

const char* vertexShaderSource = 
        "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";

const char* fragmentShaderSource =
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 variableColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = variableColor;\n"
        "}\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);

int main() 
{
    // ################################### GLFW/Glad Setup
    // Initialize and configure glfw, add error cb function
    glfwSetErrorCallback(error_callback);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // glfw: Window creation
    GLFWwindow* window = glfwCreateWindow(800, 600, "MyFirstWindow", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: Load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // ################################### Vertex, frament, and shader program setup
    // Compile vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Compile first fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Create and link shader program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // ################################### VAO, VBO
    float firstTriangle[] = {
        -0.5f, -0.5f, 0.0f,  // left 
        0.5f, -0.5f, 0.0f,  // right
        0.0f, 0.5f, 0.0f,  // top 
    };

    // Generate vertex array, and vertex buffer objects
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the VAO we just made to modify its VBOs and EBO
    glBindVertexArray(VAO);

    // Bind VBO to GL_ARRAY_BUFFER type and copy in data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);

    // Link vertext attributes
    // Tell OpenGL how to interpret the data in the currently bound VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    // ################################### Render loop
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // float timeValue = glfwGetTime();
        // float colorValue = (sin(timeValue) / 2.0f) + 0.5f;
        float rValue = ((float)rand()) / RAND_MAX;
        float gValue = ((float)rand()) / RAND_MAX;
        float bValue = ((float)rand()) / RAND_MAX;

        int vertexColorLocation = glGetUniformLocation(shaderProgram, "variableColor");
        glUseProgram(shaderProgram);
        glUniform4f(vertexColorLocation, rValue, gValue, bValue, 1.0f);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);



        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // ################################### Program cleanup/termination
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}

// Adjusts the viewport size based on window resizing events
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Outputs encountered GLFW errors with their descriptions
void error_callback(int error, const char* description) 
{
    std::cerr << "Error: " << description << std::endl;
}
