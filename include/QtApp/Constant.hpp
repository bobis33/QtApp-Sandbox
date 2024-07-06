#pragma once

#include <cctype>
#include <string_view>

namespace qta {

    using return_type_t = enum ReturnType : uint8_t {
        QTA_SUCCESS = 0,
        QTA_FAILURE = 1
    };

    static constexpr int DEFAULT_WIDTH = 1280;
    static constexpr int DEFAULT_HEIGHT = 720;

    static const std::string WINDOW_TITLE = "QtAppSandbox";

    static constexpr const std::string_view DEFAULT_PAGE_NAME = "Default page name";

} // namespace qta
