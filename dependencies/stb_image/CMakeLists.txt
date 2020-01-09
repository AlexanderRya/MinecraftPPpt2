project(stb_image C)

add_library(stb_image)

target_sources(stb_image 
    PRIVATE
    "include/stb_image.h"
    "src/stb_image.c"
)

target_include_directories(stb_image PUBLIC "include")
