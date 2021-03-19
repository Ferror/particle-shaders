#pragma once
#include "Scene.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
template <class GProgram, class VGenerator>
class SphereScene :
	public Scene<GProgram,VGenerator>
{
private:
	float sceneAngle = 45.0f;
	float modelAngle = 45.0f;
public:
	SphereScene();
	~SphereScene();

	// Inherited via Scene
	virtual void drawVertieces() override;
	virtual void addShaders() override;
	virtual void initializeScene() override;
	virtual void update() override;
};

template<class GProgram, class VGenerator>
inline SphereScene<GProgram, VGenerator>::SphereScene()
{
}

template<class GProgram, class VGenerator>
inline SphereScene<GProgram, VGenerator>::~SphereScene()
{
}

template<class GProgram, class VGenerator>
void SphereScene<GProgram, VGenerator>::drawVertieces()
{
	//***** TODO *****//
	glClear(GL_COLOR_BUFFER_BIT);

	//Rysujemy wierzcholki
	//glDrawArrays(GL_QUAD, 0, this->vGenerator.QuadSize() * this->vGenerator.Count());
	glDrawArrays(
		GL_LINES,
		this->vGenerator.QuadSize() * this->vGenerator.Count(),
		(this->vGenerator.Size() - this->vGenerator.QuadSize()) * this->vGenerator.Count()
	);
}

template<class GProgram, class VGenerator>
inline void SphereScene<GProgram, VGenerator>::addShaders()
{
	//***** TODO *****//
	this->program.addShader(std::static_pointer_cast<AShader>(std::make_shared<FragmentShader>()));
	this->program.addShader(std::static_pointer_cast<AShader>(std::make_shared<VertexShader>()));
}

template<class GProgram, class VGenerator>
inline void SphereScene<GProgram, VGenerator>::initializeScene()
{
	//***** TODO *****//
	glm::mat4 modelRot = glm::mat4(1.0f);

	this->program.addMatrix4x4f(glm::perspective(30.0, 10.0 / 6.0, 0.1, 5.0), "proj");
	this->program.addMatrix4x4f(glm::lookAt(glm::vec3(0, -1.0f, -2.3f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)), "view");
}

template<class GProgram, class VGenerator>
inline void SphereScene<GProgram, VGenerator>::update()
{
	//***** TODO *****//

}
