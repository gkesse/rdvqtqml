#pragma once

#include <string>

#define oConfig Config::Instance()

struct _Config
{
    std::string app_name;
    std::string app_logo;
    std::string app_toolbar_icon;
    std::string app_maximize_on_icon;
    std::string app_maximize_off_icon;
};

class Config
{
private:
    Config();

public:
    static _Config &Instance();

private:
    _Config m_config;
};
