#pragma once

#include <cctype>
#include <string_view>

namespace qta {

    using return_type_t = enum ReturnType : uint8_t {
        QTA_SUCCESS = 0,
        QTA_FAILURE = 1
    };

    static constexpr uint32_t DEFAULT_WIDTH = 1280;
    static constexpr uint32_t DEFAULT_HEIGHT = 720;

    static constexpr const std::string_view DEFAULT_TITLE = "QtApp";

} // namespace qta
