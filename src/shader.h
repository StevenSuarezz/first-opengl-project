#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader
{
    public:
        unsigned int id;

        Shader(const std::string vertexPath, const std::string fragmentPath);

        void use();
        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
};

#endif