# spdlog_FOUND
# spdlog::spdlog

find_path(spdlog_INCLUDE_DIR NAMES spdlog/spdlog.h)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
    spdlog
    DEFAULT_MSG
    spdlog_INCLUDE_DIR
)

mark_as_advanced(spdlog_INCLUDE_DIR)

if(spdlog_FOUND)
    add_library(spdlog::spdlog INTERFACE IMPORTED)
    target_link_libraries(spdlog::spdlog INTERFACE fmt::fmt)
    set_target_properties(spdlog::spdlog
        PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES ${spdlog_INCLUDE_DIR}
    )
    target_compile_definitions(spdlog::spdlog INTERFACE SPDLOG_FMT_EXTERNAL)
endif()