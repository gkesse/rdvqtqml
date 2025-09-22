#include "Config.hpp"
#include <iostream>

Config::Config()
{
    std::cout << "(rdvdicom): initialisation des configurations" << std::endl;
    m_config.app_name = "rdvdicom";
    m_config.app_logo = ":/img/app-logo.png";
    m_config.app_toolbar_icon = ":/img/app-icon.png";
    m_config.app_maximize_on_icon = ":/img/maximize-button2.png";
    m_config.app_maximize_off_icon = ":/img/maximize-button1.png";
}

_Config &Config::Instance()
{
    static Config m_instance;
    return m_instance.m_config;
}
