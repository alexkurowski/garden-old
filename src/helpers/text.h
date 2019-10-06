#define MAX_TEXT_BUFFER_LENGTH 1024

static const char *format(const char *text, ...)
{
    static char buffer[MAX_TEXT_BUFFER_LENGTH] = {0};

    va_list args;
    va_start(args, text);
    vsprintf(buffer, text, args);
    va_end(args);

    return buffer;
}

