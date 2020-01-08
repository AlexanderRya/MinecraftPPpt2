#ifndef NMINECRAFTPP_CAMERA_HPP
#define NMINECRAFTPP_CAMERA_HPP

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "GLFW/glfw3.h"

#include "globals.hpp"

namespace minecraft {
    struct camera {
        static constexpr float speed = 5.f;
        static constexpr float sensitivity = 8.0e-2f;
        static const inline auto proj_mat = glm::perspective(glm::radians(60.f), static_cast<float>(WIDTH) / static_cast<float>(HEIGHT), 0.1f, 100.f);

        double yaw;
        double pitch;

        glm::vec3 prec_pos = glm::vec3(-5.0f, 0.0f, 0.0f);
        glm::vec3 cam_pos = glm::vec3(-5.0f, 5.0f, 0.0f);
        glm::vec3 cam_front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 cam_up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 cam_right = glm::vec3();
        glm::vec3 cam_wup = glm::vec3(0.0f, 1.0f, 0.0f);

        camera();
        bool has_moved();
        void move(GLFWwindow* window);
        glm::mat4 get_view_mat() const;
        void process(double xoffset, double yoffset);
        void update();

    } static inline cam{};
}

#endif //NMINECRAFTPP_CAMERA_HPP
