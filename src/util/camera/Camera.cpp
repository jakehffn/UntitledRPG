#include "Camera.h"

#include <stdio.h>

Camera::Camera() :
    position{ glm::vec3(0, 0, 0) }, viewMatrix{ glm::mat4(1.0f) } {

    // this->projectionMatrix = glm::perspective(glm::radians(90.0f), float(render_consts::SCREEN_WIDTH)/float(render_consts::SCREEN_HEIGHT), 0.1f, 1000.0f);
    this->projectionMatrix = glm::ortho(0.0f, float(render_consts::SCREEN_WIDTH), float(render_consts::SCREEN_HEIGHT), 0.0f, -1.0f, 1.0f);
}


Camera::Camera(CameraController* cameraController) :
    cameraController{ cameraController },
    position{ glm::vec3(0, 0, 0) }, viewMatrix{ glm::mat4(1.0f) } {

    // this->projectionMatrix = glm::perspective(glm::radians(90.0f), float(render_consts::SCREEN_WIDTH)/float(render_consts::SCREEN_HEIGHT), 0.1f, 1000.0f);
    this->projectionMatrix = glm::ortho(0.0f, float(render_consts::SCREEN_WIDTH), float(render_consts::SCREEN_HEIGHT), 0.0f, -1.0f, 1.0f);
}

glm::mat4 Camera::getViewMatrix() {
    // return glm::mat4(1.0f);
    return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix() {
    return projectionMatrix;
}

void Camera::setController(CameraController* cameraController) {
	this->cameraController = cameraController;
}

void Camera::update() {

    printf("x: %f, y: %f, z: %f ", this->position.x, this->position.y, this->position.z);

    cameraController->update(this->position);

	this->viewMatrix = glm::lookAt(
		position,           // Camera is here
		position + glm::vec3(0, 0, -1), // and looks here
		glm::vec3(0, 1, 0) // Head is up 
	);
}

