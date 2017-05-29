/*
 *  This file is a part of Fission ( fiene ) Game Engine
 *  Copyright (C) 2016 - 2017  Stelmach Rostislav
 *  stelmach.ro[at]gmail.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//Engine Internal
#include "Core/IOManager.hpp"
#include "Utils/FDebug.hpp"
#include "ShaderProgram.hpp"

//C++ Includes
#include <fstream>
#include <iostream>
#include <vector>


namespace Fiene {


    ShaderProgram::ShaderProgram()
    {


    }

    ShaderProgram::~ShaderProgram()
    {
        //Empty
    }

    void ShaderProgram::startUp()
    {
        m_ProgramId = 0;
        m_VertexShaderId = 0;
        m_FramgetShaderId = 0;
        m_AttributesCounter = 0;
        m_ProgramId = glCreateProgram();
    }

    void ShaderProgram::compileVertexShader(const std::string &vertexShaderFilePath)
    {
        std::string vertexSource;
        if ( !IOManager::readFileToBuffer(vertexShaderFilePath, vertexSource) ) {
            errorLog("Could not Load Vertex Shader from source");
            IOManager::iostreamErrorOutput("Could not Load Vertex Shader from source [ shader file: %s ]\n",
                                           vertexShaderFilePath);
            Exit(1);
        }



        compileVertexShaderSource(vertexSource.c_str());

    }

    void ShaderProgram::compileFragmentShader(const std::string &fragmentShaderFilePath)
    {
        std::string fragmentShader;
        if ( !IOManager::readFileToBuffer(fragmentShaderFilePath, fragmentShader) ) {
            errorLog("Could not Load Fragment Shader from source");
            IOManager::iostreamErrorOutput("Could not Load Fragment Shader from source [ shader file: %s ]\n",
                                           fragmentShaderFilePath);
            Exit(1);
        }

        compileFragmentShaderSource(fragmentShader.c_str());
    }

    void ShaderProgram::compileVertexShaderSource(const char *source)
    {
        //Create Vertex Shader object, and store it's ID
        m_VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
        if ( m_VertexShaderId == 0) {
            errorLog("Vertex Shader failed to be created\n");
            IOManager::iostreamErrorOutput("Vertex Shader failed to be created\n");
            Exit(1);
        }

        //Compile Vertex Shader
        compileShader(source, "Vertex Shader", m_VertexShaderId);
    }

    void ShaderProgram::compileFragmentShaderSource(const char *source)
    {

        //Create Framgment Shader object, and store it's ID
        m_FramgetShaderId = glCreateShader(GL_FRAGMENT_SHADER);
        if ( m_FramgetShaderId == 0) {
            errorLog("Fragment Shader faild to be created\n");
            IOManager::iostreamErrorOutput("Fragment Shader failed to be created\n");
            Exit(1);
        }

        //Compile Fragment Shader
        compileShader(source, "Fragment Shader", m_FramgetShaderId);
    }

    void ShaderProgram::linkShaders()
    {
        //Attach our shaders to our program
        glAttachShader(m_ProgramId, m_VertexShaderId);
        glAttachShader(m_ProgramId, m_FramgetShaderId);

        //Link our program
        glLinkProgram(m_ProgramId);

        //Note the different functions here: glGetProgram* instead of glGetShader*.
        GLint isLinked = 0;
        glGetProgramiv(m_ProgramId, GL_LINK_STATUS, (int *)&isLinked);
        if (isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(m_ProgramId, GL_INFO_LOG_LENGTH, &maxLength);

            //The maxLength includes the NULL character
            std::vector<char> errorLog(maxLength);
            glGetProgramInfoLog(m_ProgramId, maxLength, &maxLength, &errorLog[0]);

            //We don't need the program anymore.
            glDeleteProgram(m_ProgramId);
            //Don't leak shaders either.
            glDeleteShader(m_VertexShaderId);
            glDeleteShader(m_FramgetShaderId);

            //print the error log and quit
            Fiene::errorLog("%s\n", &(errorLog[0]));
            Fiene::errorLog("Shaders failed to link!");
            IOManager::iostreamErrorOutput("%s\n", &(errorLog[0]));
            IOManager::iostreamErrorOutput("Shaders failed to link!");
            Exit();
        }

        //Always detach shaders after a successful link.
        glDetachShader(m_ProgramId, m_VertexShaderId);
        glDetachShader(m_ProgramId, m_FramgetShaderId);
        glDeleteShader(m_VertexShaderId);
        glDeleteShader(m_FramgetShaderId);
    }

    void ShaderProgram::addAttribute(const std::string &attributeName)
    {
        glBindAttribLocation(m_ProgramId, m_AttributesCounter++, attributeName.c_str());
    }

    void ShaderProgram::use()
    {
        glUseProgram(m_ProgramId);

        //Enable all the attributes we added
        for (GLuint i = 0; i < m_AttributesCounter; i++) {
            glEnableVertexAttribArray(i);
        }
    }

    void ShaderProgram::unuse()
    {
        glUseProgram(0);
        for (GLuint i = 0; i < m_AttributesCounter; i++) {
            glDisableVertexAttribArray(i);
        }
    }

    GLint ShaderProgram::getUniformLocation(const std::string &uniformName)
    {
        GLint location = glGetUniformLocation(m_ProgramId, uniformName.c_str());

        if ( location == GL_INVALID_INDEX ) {
            errorLog("Uniform %s not found in Shader %s.\n", uniformName);
            IOManager::iostreamErrorOutput("Uniform %s not found in Shader %s.\n", uniformName);
            Exit(1);
        }

        return location;
    }

    void ShaderProgram::compileShader(const char *source, const std::string &name, const GLuint id)
    {
        //Tell OpenGL that we want use fileContents as the contents of the shader file
        glShaderSource(id, 1, &source, nullptr);

        //Compile The Shader
        glCompileShader(id);

        //Check for errors
        GLint success = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);

        if ( success == GL_FALSE ) {

            GLint maxLength = 0;
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

            //The maxLength includes the NULL Character
            std::vector<char> errorLog(static_cast<size_t>(maxLength));
            glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

            //Provide the infolog in whatever manor you deem best.
            //Exit with failoure.
            //Dont leak the Shader
            glDeleteShader(id);

            //Print error log and quit
            Fiene::errorLog("%s\n", &(errorLog[0]));
            Fiene::errorLog("Shader %s faild to compile.\n", name);
            IOManager::iostreamErrorOutput("%s\n", &(errorLog[0]));
            IOManager::iostreamErrorOutput("Shader %s faild to compile.\n", name);
            Exit(1);
        }
    }

    void ShaderProgram::terminate()
    {
        if (m_ProgramId)
            glDeleteProgram(m_ProgramId);

    }

    void ShaderProgram::setBool(const std::string &name, bool value) const
    {
        glUniform1i(glGetUniformLocation(m_ProgramId, name.c_str()),
                    static_cast<int>(value));
    }

    void ShaderProgram::setInt(const std::string &name, int value) const
    {
        glUniform1i(glGetUniformLocation(m_ProgramId, name.c_str()), value);
    }

    void ShaderProgram::setFlaot(const std::string &name, float value) const
    {
        glUniform1f(glGetUniformLocation(m_ProgramId, name.c_str()), value);
    }

    void ShaderProgram::setVec2(const std::string &name, const Vec2 &value) const
    {
        glUniform2fv(glGetUniformLocation(m_ProgramId, name.c_str()), 1, &value[0]);
    }

    void ShaderProgram::setVec3(const std::string &name, const Vec3 &value) const
    {
        glUniform3fv(glGetUniformLocation(m_ProgramId, name.c_str()),1, &value[0]);
    }

    void ShaderProgram::setVec4(const std::string &name, const Vec4 &value) const
    {
        glUniform4fv(glGetUniformLocation(m_ProgramId, name.c_str()),1, &value[0]);
    }

    void ShaderProgram::setMat4(const std::string &name, const Matrix4 &value) const
    {
        glUniformMatrix4fv(glGetUniformLocation(m_ProgramId, name.c_str()), 1, GL_FALSE, &value[0][0]);
    }

    void ShaderProgram::setVec2(const std::string &name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(m_ProgramId, name.c_str()), x, y);
    }

    void ShaderProgram::setVec3(const std::string &name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(m_ProgramId, name.c_str()), x, y, z);
    }

    void ShaderProgram::setVec4(const std::string &name, float x, float y, float z, float w) const
    {
        glUniform4f(glGetUniformLocation(m_ProgramId, name.c_str()), x, y, z , w);
    }

}
