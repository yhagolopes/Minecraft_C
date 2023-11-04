cmake_minimum_required(VERSION 3.5.9)

project(Minecraft)

set(CMAKE_CXX_STANDARD 17)

add_executable(Minecraft
	Src/Main.cpp
	Src/App.cpp
	Src/Shader.cpp
	Src/Texture.cpp
	Src/TextureAtlas.cpp
	Src/Camera.cpp
	Src/Player.cpp
	Src/Renderer.cpp
	Src/World/Block.cpp
	Src/World/ChunkMesh.cpp
	Src/World/Chunk.cpp
	Src/World/World.cpp
	Src/World/Generation.cpp
)

add_subdirectory(Lib/glfw)
add_subdirectory(Lib/glad)
add_subdirectory(Lib/glm)

include_directories(Include)

target_link_libraries(Minecraft
	glfw
	glad
	glm
)