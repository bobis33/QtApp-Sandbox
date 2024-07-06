#pragma once

#include "QtApp/Abstraction/APage.hpp"

namespace qta {

    class MainPage : public APage {

        public:

            explicit MainPage(const std::string& title = "Main Page");
            ~MainPage() override = default;
        
    }; // class MainPage

} // namespace qta
