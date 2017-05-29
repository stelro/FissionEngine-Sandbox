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

#ifndef PROJECT_GLSLPROGRAM_HPP
#define PROJECT_GLSLPROGRAM_HPP

//OpenGL Includes
#include <GL/glew.h>
#include <Math/Vector.hpp>
#include <Math/Matrix.hpp>


//C++ Includes
#include <string>

namespace Fiene {

    class ShaderProgram {

    public:

                                ShaderProgram();
                                ~ShaderProgram();

        void                    startUp();
        void                    compileVertexShader(const std::string& vertexShaderFilePath);
        void                    compileFragmentShader(const std::string& fragmentShaderFilePath);
        void                    compileVertexShaderSource(const char* source);
        void                    compileFragmentShaderSource(const char* source);
        void                    linkShaders();
        void                    addAttribute(const std::string& attributeName);

        void                    use();
        void                    unuse();

        GLint                   getUniformLocation(const std::string& uniformName);
        GLuint                  getProgramID() const { return m_ProgramId; }

        void                    setBool(const std::string& name, bool value) const;
        void                    setInt(const std::string& name, int value) const;
        void                    setFlaot(const std::string& name, float value) const;
        void                    setVec2(const std::string& name, const Vec2& value) const;
        void                    setVec3(const std::string& name, const Vec3& value) const;
        void                    setVec4(const std::string& name, const Vec4& value) const;
        void                    setVec2(const std::string& name, float x, float y) const;
        void                    setVec3(const std::string& name, float x, float y, float z) const;
        void                    setVec4(const std::string& name, float x, float y, float z, float w) const;
        void                    setMat4(const std::string& name, const Matrix4& value) const;

        void                    terminate();

    private:

        void                    compileShader(const char* source, const std::string& name, const GLuint id);

        GLuint                  m_ProgramId;
        GLuint                  m_VertexShaderId;
        GLuint                  m_FramgetShaderId;
        GLuint                  m_AttributesCounter;
    };

}


#endif //PROJECT_GLSLPROGRAM_HPP
