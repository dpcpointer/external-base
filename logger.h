#pragma once

#include <cstdint>
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <memory>

class _logger {
public:
    enum class level { _INFO, _WARN, _ERROR };

    void info(const char* format, ...) {
        va_list args;
        va_start(args, format);
        log(level::_INFO, format, args);
        va_end(args);
    }

    void warn(const char* format, ...) {
        va_list args;
        va_start(args, format);
        log(level::_WARN, format, args);
        va_end(args);
    }

    void error(const char* format, ...) {
        va_list args;
        va_start(args, format);
        log(level::_ERROR, format, args);
        va_end(args);
    }

private:
    void log(level level, const char* format, va_list args) {
        const char* level_string = {};
        const char* color = {};
        switch (level) {
        case level::_INFO:  level_string = "info";  color = "\x1b[32m"; break;
        case level::_WARN:  level_string = "warn";  color = "\x1b[33m"; break;
        case level::_ERROR: level_string = "error"; color = "\x1b[31m"; break;
        }

        char time_buffer[64];
        std::time_t now = std::time(nullptr);
        std::tm time_info{};
        localtime_s(&time_info, &now);
        std::strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", &time_info);

        printf("\x1b[37m[%s] ", time_buffer);
        printf("%s[%s] ", color, level_string);
        printf("\x1b[37m");
        vprintf(format, args);
        printf("\x1b[0m\n");
    }
};

inline std::unique_ptr<_logger> logger = std::make_unique<_logger>();
