#include "core/camera.hpp"

namespace minecraft {
    camera::camera()
    : yaw(-90.0f),
      pitch(0.0f) {
        update();
    }

    bool camera::has_moved() {
        return prec_pos == cam_pos ? false : (prec_pos = cam_pos, true);
    }

    void camera::move(GLFWwindow* window) {
        float velocity = speed * delta_time;

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
            cam_pos.x += cos(glm::radians(yaw)) * velocity;
            cam_pos.z += sin(glm::radians(yaw)) * velocity;
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
            cam_pos.x -= cos(glm::radians(yaw)) * velocity;
            cam_pos.z -= sin(glm::radians(yaw)) * velocity;
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
            cam_pos -= cam_right * velocity;
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
            cam_pos += cam_right * velocity;
        }

        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            cam_pos += cam_wup * velocity;
        }

        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
            cam_pos -= cam_wup * velocity;
        }

        update();
    }

    glm::mat4 camera::get_view_mat() const {
        return glm::lookAt(cam_pos, cam_pos + cam_front, cam_up);
    }

    void camera::process(double xoffset, double yoffset) {
        xoffset *= sensitivity;
        yoffset *= sensitivity;
        yaw += xoffset;
        pitch += yoffset;
        if (pitch > 89.0f) {
            pitch = 89.0f;
        }
        if (pitch < -89.0f) {
            pitch = -89.0f;
        }
        update();
    }

    void camera::update() {
        glm::vec3 front{
            cos(glm::radians(yaw)) * cos(glm::radians(pitch)),
            sin(glm::radians(pitch)),
            sin(glm::radians(yaw)) * cos(glm::radians(pitch))
        };
        cam_front = glm::normalize(front);
        cam_right = glm::normalize(glm::cross(cam_front, cam_wup));
        cam_up = glm::normalize(glm::cross(cam_right, cam_front));
    }
}