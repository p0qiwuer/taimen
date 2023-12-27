#include <fstream>
#include <string>

struct ConfInfo {
    int screen_width;
    int screen_height;
    int font_pixel_size;
    std::string font_name;
};

ConfInfo read_conf(const std::string file_name);
void remove_unnecessary_whitespaces(std::string& string);
