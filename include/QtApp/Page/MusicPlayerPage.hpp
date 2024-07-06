#pragma once

#include "QtApp/Abstraction/APage.hpp"
#include "QtApp/Constant.hpp"

namespace qta {

    class MusicPlayerPage : public APage {

        public:

            explicit MusicPlayerPage(const std::string& title = "Music Player");
            ~MusicPlayerPage() override = default;

    }; // class MusicPlayerFile

} // namespace qta
